#!/usr/bin/env bash
set -euo pipefail

# ---------------------------------------------------------------------------
# publish-release.sh
# Builds iOS xcframework + Android AAR, publishes both, and tags a release.
#
# Prerequisites:
#   - gh CLI installed and authenticated (gh auth login)
#   - Xcode command line tools installed (for swift, lipo)
#   - GITHUB_TOKEN env var set, OR gh CLI is authenticated
#
# Usage:
#   ./scripts/publish-release.sh
# ---------------------------------------------------------------------------

REPO_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
cd "$REPO_ROOT"

# Read version from gradle.properties
VERSION=$(grep '^hl7core.version=' gradle.properties | cut -d'=' -f2 | tr -d '[:space:]')
if [[ -z "$VERSION" ]]; then
    echo "ERROR: hl7core.version not found in gradle.properties"
    exit 1
fi

TAG="v${VERSION}"
XCFRAMEWORK_ZIP="hl7Core/swiftpackage/Hl7Core-${VERSION}.zip"

# Guard: fail if tag already exists remotely
if gh release view "$TAG" &>/dev/null; then
    echo "ERROR: GitHub Release $TAG already exists. Bump hl7core.version in gradle.properties."
    exit 1
fi

echo "==> Building release: $TAG"

# ---------------------------------------------------------------------------
# Step 1: Build iOS xcframework + zip
# ---------------------------------------------------------------------------
echo "==> Building iOS xcframework..."
./gradlew createSwiftPackage

if [[ ! -f "$XCFRAMEWORK_ZIP" ]]; then
    echo "ERROR: xcframework zip not found at $XCFRAMEWORK_ZIP"
    exit 1
fi
echo "==> xcframework zip built: $XCFRAMEWORK_ZIP"

# ---------------------------------------------------------------------------
# Step 2: Compute checksum (AFTER zip is fully built)
# ---------------------------------------------------------------------------
echo "==> Computing xcframework checksum..."
CHECKSUM=$(swift package compute-checksum "$XCFRAMEWORK_ZIP")
echo "==> Checksum: $CHECKSUM"

# ---------------------------------------------------------------------------
# Step 3: Update Package.swift with real URL + checksum
# ---------------------------------------------------------------------------
RELEASE_URL="https://github.com/bhushanrite/PillCount-Hl7/releases/download/${TAG}/Hl7Core.xcframework.zip"

echo "==> Updating Package.swift..."
sed -i '' "s|url: \".*\"|url: \"${RELEASE_URL}\"|" Package.swift
sed -i '' "s|checksum: \".*\"|checksum: \"${CHECKSUM}\"|" Package.swift
echo "==> Package.swift updated"

# ---------------------------------------------------------------------------
# Step 4: Publish Android to GitHub Packages
# ---------------------------------------------------------------------------
echo "==> Publishing Android to GitHub Packages..."
# Resolve credentials: CI uses GITHUB_ACTOR/GITHUB_TOKEN env vars.
# Local runs: read from ~/.gradle/gradle.properties (gpr.user / gpr.token).
if [[ -z "${GITHUB_ACTOR:-}" ]]; then
    GPR_PROPS="$HOME/.gradle/gradle.properties"
    if [[ ! -f "$GPR_PROPS" ]]; then
        echo "ERROR: GITHUB_ACTOR not set and ~/.gradle/gradle.properties not found."
        echo "       Add gpr.user and gpr.token to ~/.gradle/gradle.properties"
        exit 1
    fi
    export GITHUB_ACTOR=$(grep '^gpr.user=' "$GPR_PROPS" | cut -d'=' -f2 | tr -d '[:space:]')
    export GITHUB_TOKEN=$(grep '^gpr.token=' "$GPR_PROPS" | cut -d'=' -f2 | tr -d '[:space:]')
    if [[ -z "$GITHUB_ACTOR" || -z "$GITHUB_TOKEN" ]]; then
        echo "ERROR: gpr.user or gpr.token missing in ~/.gradle/gradle.properties"
        exit 1
    fi
fi
./gradlew :hl7Core:publishAllPublicationsToGitHubPackagesRepository

# ---------------------------------------------------------------------------
# Step 5: Create GitHub Release + upload xcframework zip
# ---------------------------------------------------------------------------
echo "==> Creating GitHub Release $TAG..."
gh release create "$TAG" \
    "$XCFRAMEWORK_ZIP" \
    --title "$TAG" \
    --notes "## Hl7Core $TAG

### iOS (Swift Package Manager)
Add in Xcode → File → Add Package Dependencies:
\`https://github.com/bhushanrite/PillCount-Hl7\`

Or in your Package.swift:
\`\`\`swift
.package(url: \"https://github.com/bhushanrite/PillCount-Hl7\", from: \"${VERSION}\")
\`\`\`

Also copy \`hl7Core/swiftshim/HL7Interop.swift\` into your app target for idiomatic Swift access.

### Android (GitHub Packages)
See \`docs/consumer/ANDROID_INTEGRATION.md\` for full setup.

\`\`\`kotlin
implementation(\"org.rite.hl7:hl7core:${VERSION}\")
\`\`\`"

# ---------------------------------------------------------------------------
# Step 6: Commit updated Package.swift + update tag to include this commit
# ---------------------------------------------------------------------------
echo "==> Committing Package.swift..."
git add Package.swift
git commit -m "chore: update Package.swift for release $TAG"

# Move the tag to point at this commit (includes the Package.swift update)
git tag -f "$TAG"

echo ""
echo "==> Release $TAG complete!"
echo ""
echo "    iOS:     Xcode → Add Package Dependencies"
echo "             https://github.com/bhushanrite/PillCount-Hl7"
echo ""
echo "    Android: implementation(\"org.rite.hl7:hl7core:${VERSION}\")"
echo "             (requires GitHub PAT with read:packages — see docs/consumer/ANDROID_INTEGRATION.md)"
echo ""
echo "    Next: push the updated Package.swift commit and tag:"
echo "      git push origin HEAD"
echo "      git push origin $TAG --force"
