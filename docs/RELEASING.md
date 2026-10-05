# CI and releases

CI runs on pull requests and pushes to main, and can be run manually. It tests
both modules on Android and the iOS simulator, checks coverage, builds the sample
app, and verifies the Android release Maven publication. Existing advisory lint,
formatting, and dependency-scan checks remain advisory.

To release:

1. Bump `hl7core.version` in `gradle.properties` to an unused `X.Y.Z` version and
   commit the changes.
2. Create and push the matching tag (replace the example with your version):

   ```sh
   git tag v1.0.1
   git push origin v1.0.1
   ```

3. The workflow runs CI, builds and validates the XCFramework simulator/device
   binaries, archives the final framework, and calculates its Swift checksum.
4. It uses the pushed tag without moving it. The tag must match `hl7core.version`.
5. It publishes `org.rite.hl7:hl7core:X.Y.Z` to GitHub Packages and attaches the
   XCFramework ZIP and Swift manifest to the GitHub Release.

Tag pushes matching `v*` trigger Release, which runs CI before publishing.
The workflow file must be included in the tagged commit.

For tag-triggered releases, the generated `Package.swift` is attached to the
release, not committed back into the existing tag. Use the downloaded XCFramework
or the attached manifest as a local Swift package. Repository-based Swift Package
Manager installation requires the manifest already in the tag to match the ZIP's
URL and checksum; the workflow warns when it differs.

Manual release remains available through **Release → Run workflow** on a branch.
This path creates a new tag containing the generated Swift manifest, supporting
repository-based Swift Package Manager installation. Do not pre-create its tag.
Do not also run `scripts/publish-release.sh`; it publishes independently.

Repository rules must allow the workflow token to create version tags and write
packages/releases. No additional secret is needed beyond `GITHUB_TOKEN`.

If publishing fails after the tag is created, inspect which external artifacts
were published before taking recovery action. Manual branch runs reject existing
tags, and release creation rejects an already published release.
The uploaded `release-assets` Actions artifact retains the exact ZIP and manifest
for recovery. A full macOS run is required to validate Xcode and native packaging.
