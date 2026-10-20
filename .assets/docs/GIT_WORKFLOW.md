# Git workflow

<p align="center">
  <img src="../images/42_paris_banner_git_workflow.png" alt="Git workflow" width="100%">
</p>

## Why it matters

`42_Paris` is built around nested repositories and submodules. This means cloning, branching, committing and publishing require more care than a single-repo project.

## Standard workflow

### Clone everything

```bash
git clone --recurse-submodules git@github.com:Mechard-Organization/42_Paris.git
cd 42_Paris
```

### Initialize submodules later

```bash
git submodule update --init --recursive
```

## Personal Zsh wrapper

When my custom wrapper is installed, the following commands become workflow helpers:

```bash
git clone git@github.com:Mechard-Organization/42_Paris.git
git add -A
git commit -m "Your message"
git push
```

### Expected behavior

- `git clone` clones the full tree recursively
- `git branch` aligns the root on `main_42_Paris`, then uses `main_sub` when available, otherwise `main`
- `git add -A` prepares nested repositories
- `git commit -m` commits child repositories before parents when necessary
- `git push` publishes only repositories that actually changed
- logs are generated in the dedicated Git tooling area

## Recommendation

Always inspect the repositories you are about to publish when working with recursive automation.
