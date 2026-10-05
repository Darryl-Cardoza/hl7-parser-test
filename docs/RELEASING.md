# CI and releases

CI runs on pull requests and pushes to main, and can be run manually. It tests
both modules on Android and the iOS simulator, checks coverage, builds the sample
app, and verifies the Android release Maven publication. Existing advisory lint,
formatting, and dependency-scan checks remain advisory.

To release:

1. Bump `hl7core.version` in `gradle.properties` to an unused `X.Y.Z` version and
   commit the changes.
2. In GitHub Actions, select **Release**, then **Run workflow** on that branch.
3. The workflow runs CI, builds and validates the XCFramework simulator/device
   binaries, archives the final framework, and calculates its Swift checksum.
4. It commits the matching `Package.swift` on the release checkout and pushes a
   new `vX.Y.Z` tag. It does not push a commit to the source branch or move tags.
5. It publishes `org.rite.hl7:hl7core:X.Y.Z` to GitHub Packages and attaches the
   XCFramework ZIP and Swift manifest to the GitHub Release.

Release now uses manual dispatch instead of a tag-push trigger: the final Swift
manifest must be in the tagged commit for Swift Package Manager to consume it.
Do not pre-create the tag or run `scripts/publish-release.sh` for this workflow;
that older local script publishes independently and moves its local tag.

Repository rules must allow the workflow token to create version tags and write
packages/releases. No additional secret is needed beyond `GITHUB_TOKEN`.

If publishing fails after the tag is created, inspect which external artifacts
were published before taking recovery action. Automatic reruns reject existing
tags to avoid moving a version or overwriting a partially published release.
The uploaded `release-assets` Actions artifact retains the exact ZIP and manifest
for recovery. A full macOS run is required to validate Xcode and native packaging.
