# README assets & documentation

> [← Main README](../../README.md)

The root README uses **local files only** for its image and support-document references. There are no externally hosted image badges or visual dependencies.

## Directory conventions

```text
.assets/
├── docs/
│   ├── ASSETS.md                 # This document
│   ├── GIT_WORKFLOW.md           # Git & personal wrapper details
│   └── REPOSITORY_GUIDE.md      # Navigable repository inventory
├── images/                       # Existing banners and artwork
├── text/                         # Existing text tree exports
└── tree/                         # Existing Markdown directory trees
```

## Visuals referenced from the root README

| Image | Usage |
| :--- | :--- |
| `images/42_Paris_title_banner.png` | Main header |
| `images/42_Paris_2017_title_banner.png` | 2017 navigation card and section |
| `images/42_Paris_2023_title_banner.png` | 2023 navigation card and section |
| `images/Others_title_banner.png` | Personal-work navigation card and section |
| `images/mechard_round.png` | Footer profile artwork |

These assets were **already included in the original archive**. The README redesign does not alter their content.

## Maintenance guidelines

1. Keep the root `README.md` at the repository root; place supporting documents and all root-README images under `.assets/`.
2. Use **relative links** from `README.md` (for example, `.assets/images/name.png`) to keep references working across branches and forks.
3. Use `../` appropriately in links from `.assets/docs/`.
4. Update the directory-tree snapshots separately when the repository hierarchy changes. The existing `.assets/text/` and `.assets/tree/` files are **snapshots**, not live inventories.
5. Do not move or rewrite nested project assets and other submodules solely to satisfy the root README's asset convention.
6. Avoid committing generated logs or files containing passwords, keys, tokens, private documents or other sensitive material.

The supplemental documents are plain Markdown so they are easy to edit and render on GitHub.
