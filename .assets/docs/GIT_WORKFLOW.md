# Git workflow — `42_Paris`

> [← Main README](../../README.md) · [Repository guide](REPOSITORY_GUIDE.md)

This document distinguishes **normal Git behavior** from the **optional, personal Zsh wrapper** stored in the project workspace. The wrapper described below was found in the uploaded snapshot under `Others/Perso/GC/git-42-paris.zsh` and identifies itself as **v8.5** at the time of inspection. Its behavior may change in newer versions.

## 1. Standard Git: portable workflow

Clone the repository and initialize every nested submodule:

```bash
git clone --recurse-submodules git@github.com:Mechard-Organization/42_Paris.git
cd 42_Paris
```

For an existing clone:

```bash
git submodule sync --recursive
git submodule update --init --recursive
```

Git submodules normally check out the exact commit recorded in the parent repository (often a detached HEAD). This is intentional. A parent project does not automatically record a newer submodule commit until the new **gitlink** is staged and committed in the parent.

## 2. Optional Zsh wrapper

The personal Zsh wrapper customizes some **exact command forms** when executed inside the `42_Paris` root directory or one of its nested working directories. The name `42_Paris` is **case sensitive**.

| Exact command | Custom behavior inside `42_Paris` |
| :--- | :--- |
| `git clone git@github.com:Mechard-Organization/42_Paris.git` | Clones the root and recursively initializes its submodules, then aligns branches. |
| `git branch` | Aligns the root and nested repository branches. |
| `git pull` | Checks the workspace, then pulls recursively in **parent → child** order, using `--ff-only`. |
| `git add -A` | Runs `add -A` across the initialized repository tree; reports affected repositories and their parent chain. |
| `git commit -m "message"` | Commits staged changes in **child → parent** order and records updated submodule pointers in parents. |
| `git push` | Publishes only repositories with commits to push, in **child → parent** order, once the add/commit sequence has been completed. |

Other argument forms, such as `git status`, `git add some_file`, `git branch --list`, or `git push origin main`, retain normal Git behavior.

> The wrapper is **not required** to use the repository and is not installed automatically just by cloning it. Its activation depends on the user's own Zsh configuration.

### Branch policy

- Root repository: **`main_42_Paris`**.
- Nested submodules: **`main_sub`**, if available; otherwise **`main`**.
- The wrapper configures local tracking branches where possible. This differs from standard pinned submodule checkouts.

### Add → commit → push: one explicit cycle

```bash
# With the optional wrapper active, from 42_Paris or a nested repository:
git add -A
git commit -m "Update my 42 projects"
git push
```

The `add` and `commit` steps operate across the entire repository hierarchy, but **only repositories affected by changes are counted in the final progress summary**. When a nested repository produces a new commit, its parents may also need commits to record updated gitlinks.

After **every attempted custom `git push`**, the wrapper disables its add/commit activation flags, requiring a fresh `git add -A` and `git commit -m "..."` cycle before the next custom push. The push itself does **not** silently create additional commits.

### Example: change inside `Others`

```text
42_Paris/                 ← parent gitlink to Others is updated
└── Others/               ← changes are committed here first
```

The resulting push plan is normally `Others → 42_Paris`. Other submodules with no unpublished commits are skipped.

### Example: nested C++ project

```text
42_Paris/
└── 42_Paris_2023/
    └── Cursus_2023/
        └── Projects/
            └── Common_core/Cpp/
                └── cpp09_100/
```

Changed children are committed before their parents; Git stores the new child commit IDs as gitlinks in the corresponding parent commits.

## 3. Safety and review

**Before committing** an automatic `git add -A` sweep, inspect staged changes inside the relevant repositories. In particular, `Others/` may include personal material and local working files; automated staging does not assess whether a file is appropriate to publish.

Examples (native Git commands):

```bash
git status --short
git diff --cached --stat
git diff --cached
```

Use `git -C <submodule-path> ...` for checks in nested repositories. The recursive wrapper is built for convenience; it does not replace a code review or a secret scan.

- It does not use `reset --hard` or `git clean` as part of its standard synchronization logic.
- The custom `git pull` uses `--ff-only` to avoid unexpected merge commits.
- The custom `git push` selects locally ahead repositories after the explicit add/commit cycle.
- Failures are shown in the terminal; detailed Git commands and outputs are written to the local log.

## 4. Command log

The wrapper writes its own per-session command log to:

```text
42_Paris/Others/Perso/GC/data/git-42-paris.log
```

The journal records command lines, working directory, return codes, STDOUT and STDERR. It is intended to remain **local to the machine** and not be committed to Git. Because logs can capture sensitive command output, **do not publish the log**; review its contents before sharing it externally.

The script attempts to add a local ignore entry to the `Others` repository's Git `info/exclude`. If an older workflow accidentally tracked the log, stop tracking it while keeping the file on disk before publishing.

## 5. Troubleshooting

**Submodules are missing**

```bash
git submodule update --init --recursive
```

**Detached HEAD in an ordinary clone**

This is standard submodule behavior. Use regular Git commands for a pinned-submodule workflow, or the custom `git branch` alignment if you deliberately want the personal branch-based workflow.

**Custom push is refused**

Make sure the explicit `add → commit` sequence was completed and that there are no uncommitted changes. The wrapper's diagnostics and local command log give the specific blocking reason.

**An old remote URL redirects**

Some historical `.gitmodules` files can contain legacy organization URLs. Check `git remote -v`, confirm the correct destination and update your local `origin` if needed. Do not rewrite arbitrary repository URLs without verifying the target exists.
