# Android Integration Guide — Hl7Core

## Prerequisites

- Android Studio or any Gradle-based Android/KMP project
- GitHub account
- GitHub Personal Access Token (PAT) with `read:packages` scope
  - Create at: https://github.com/settings/tokens → "Generate new token (classic)"
  - Required scope: `read:packages` only

> **Note:** GitHub Packages requires authentication even for public repos.
> This is a GitHub platform requirement — your PAT stays on your machine only.

## One-time machine setup

Add credentials to `~/.gradle/gradle.properties` (your **home** directory — never inside any project folder):

```properties
gpr.user=YOUR_GITHUB_USERNAME
gpr.token=ghp_YOUR_PAT_TOKEN_HERE
```

This file lives outside every project. Git can never see it.

## Project setup

**`settings.gradle.kts`** — add the GitHub Packages repository:

```kotlin
dependencyResolutionManagement {
    repositories {
        google()
        mavenCentral()
        maven {
            url = uri("https://maven.pkg.github.com/Rite-Technologies-23/mobrite_hl7_parser_builder")
            credentials {
                username = providers.gradleProperty("gpr.user").orNull
                password = providers.gradleProperty("gpr.token").orNull
            }
        }
    }
}
```

**`app/build.gradle.kts`** — add the dependency:

```kotlin
dependencies {
    implementation("org.rite.hl7:hl7core:1.0.0")
}
```

Sync project. Gradle downloads the AAR automatically.

## Upgrading

Change the version string in `build.gradle.kts` and sync. Gradle downloads the new version automatically.

## Troubleshooting

| Error | Cause | Fix |
|---|---|---|
| `401 Unauthorized` | PAT missing, expired, or wrong username | Regenerate PAT at github.com/settings/tokens |
| `Could not resolve org.rite.hl7:hl7core` | Repository not added to `settings.gradle.kts` | Verify the `maven { }` block is present |
| `gpr.user` not found | `~/.gradle/gradle.properties` not set up | Follow "One-time machine setup" above |
| Network error to `maven.pkg.github.com` | Firewall/proxy blocking GitHub Packages | Configure proxy or use VPN |
