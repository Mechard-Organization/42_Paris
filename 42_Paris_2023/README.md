<p align="center">
  <strong>🇬🇧 English</strong> &nbsp;·&nbsp;
  <a href="./README.fr.md">🇫🇷 Français</a> &nbsp;·&nbsp;
  <a href="./README.ja.md">🇯🇵 日本語</a>
</p>

<a id="top"></a>

<p align="center">
  <img src="../.assets/images/42_paris_banner_2023.png" alt="42 Paris 2023 — Piscine, Common Core and student life" width="100%">
</p>

<h1 align="center">42 Paris · 2023 Piscine, Cursus & Associations</h1>

<p align="center">
  <strong>The 2023 chapter of my journey at 42 Paris:</strong><br>
  from the <strong>Piscine</strong> to the <strong>Common Core</strong>, then post–Common Core projects, development tools and campus life.
</p>

<p align="center">
  <a href="#overview">Overview</a> ·
  <a href="#structure">Structure</a> ·
  <a href="#projects">Projects</a> ·
  <a href="#git-workflow">Git workflow</a> ·
  <a href="#documentation">Documentation</a>
</p>

---

<a id="overview"></a>
## ✨ At a glance

`42_Paris_2023/` is the **2023 section** of the [main `42_Paris` repository](../README.md). It connects my Piscine work, the curriculum and student associations through **three direct Git submodules**. The curriculum itself contains additional nested submodules, each with its own history.

<table>
<tr>
<td align="center" width="33%">
  <a href="#piscine"><strong>🏊 Piscine_C_2023</strong></a><br><br>
  <sub>Shell exercises, C modules and rushes: the foundations of the 2023 journey.</sub>
</td>
<td align="center" width="33%">
  <a href="#cursus"><strong>🚀 Cursus_2023</strong></a><br><br>
  <sub>Common Core projects, post–Common Core work and reusable tools.</sub>
</td>
<td align="center" width="33%">
  <a href="#associations"><strong>🤝 Association_2023</strong></a><br><br>
  <sub>Student initiatives, BDE and Blackout association materials.</sub>
</td>
</tr>
</table>

- 🎓 **School:** 42 Paris
- 🏁 **Milestone:** 2023 Common Core completed on **26 February 2026**
- 🧩 **Architecture:** three direct submodules, with further recursive submodules under `Cursus_2023`
- 🌍 **Languages:** English, French and Japanese
- 🔐 **Access:** the main repository is public, but several child repositories are private; their contents require permission

---

<a id="structure"></a>
## 🧭 Directory structure

This is a **navigation overview**, not an exhaustive list of files. Names reflect the current Git paths:

```text
42_Paris_2023/
├── Association_2023/                    # Git submodule
│   ├── BDE/
│   └── Blackout/
├── Piscine_C_2023/                      # Git submodule
│   ├── Shell_00/
│   ├── Shell_01/
│   ├── C_00/ ... C_09/
│   ├── C_11/
│   └── Rush/
├── Cursus_2023/                         # Git submodule
│   ├── Common_Core/                     # Git submodule (16 projects)
│   │   ├── Cpp/                         # Git submodule (cpp00 to cpp09)
│   │   └── ...                          # Other Common Core projects
│   ├── Post_Common_Core/               # Git submodule
│   │   ├── Realeased/
│   │   │   └── Internship_I_119/        # Git submodule
│   │   └── Unrealeased/
│   │       ├── Darkly/                  # Git submodule
│   │       ├── libasm/                  # Git submodule
│   │       └── snow-crash/              # Git submodule
│   └── Tools/
│       ├── Complete_libft ✅/           # Git submodule
│       └── Makefile_standard
├── README.md
├── README.fr.md
└── README.ja.md
```

> `42_Paris_2023/` is a directory in the parent repository, **not a separate Git repository**. Its three direct child directories are submodules. Git records a **specific commit** for each submodule; specifying a branch in `.gitmodules` does not make that pointer move automatically.

> The spellings `Realeased` and `Unrealeased` are preserved intentionally because they match the real paths. The Piscine list includes `C_11` but not a `C_10` directory.

---

<a id="projects"></a>
## 🧪 Projects & activities

<a id="piscine"></a>
### 🏊 Piscine C / Shell — 2023

The 2023 Piscine gathers early exercises in **Shell and C**, plus group challenges (rushes). It is preserved as a separate repository and may require access permission.

| Area | Content | Browse |
| :--- | :--- | :--- |
| **Shell** | `Shell_00`, `Shell_01` | [`Piscine_C_2023`](https://github.com/Mechard-Organization/Piscine_C_2023/tree/main_sub) |
| **C modules** | `C_00`–`C_09` and `C_11` | [C modules](https://github.com/Mechard-Organization/Piscine_C_2023/tree/main_sub) |
| **Rushes** | Collaborative and timed projects in `Rush/` | [Rush directory](https://github.com/Mechard-Organization/Piscine_C_2023/tree/main_sub/Rush) |

<a id="cursus"></a>
### 🚀 Cursus 2023

[`Cursus_2023`](https://github.com/Mechard-Organization/Cursus_2023/tree/main_sub) is the main curriculum repository. It contains **Common Core**, **Post_Common_Core** and **Tools** as separate areas, including nested Git submodules.

<a id="common-core"></a>
#### 🧱 Common Core

The **Common Core** covers C, C++, algorithms, Unix systems, graphics, networking and collaborative development. The [`Common_core`](https://github.com/Mechard-Organization/Common_core/tree/main) repository contains **16 project submodules**:

| Focus | Project directories |
| :--- | :--- |
| **C foundations** | `libft_125`, `ft_printf_110`, `get_next_line_112` |
| **Algorithms, processes & shells** | `push_swap_100`, `pipex_115`, `philo_100`, `minishell_101` |
| **Graphics** | `So_long_96`, `Cub3D_105` |
| **C++** | `Cpp` → `cpp00_80` through `cpp09_100` (nested inside `Cpp`) |
| **Systems & networking** | `Born2beroot_125`, `Netpractice_105`, `IRC_125`, `Inception_100` |
| **Web & collaboration** | `42_collaborative_resume_100`, `ft_transcendence_125` |

**Personal milestone:** the 2023 Common Core was completed on **26 February 2026**. Project folder names that include scores are preserved as part of the repository naming convention.

<a id="post-common-core"></a>
#### 🔭 Post–Common Core

The private [`Post_common_core`](https://github.com/Mechard-Organization/Post_common_core/tree/main) repository groups work beyond the Common Core and internship material.

| Directory | Git submodules |
| :--- | :--- |
| [`Realeased/`](https://github.com/Mechard-Organization/Post_common_core/tree/main/Realeased) | `Internship_I_119` |
| [`Unrealeased/`](https://github.com/Mechard-Organization/Post_common_core/tree/main/Unrealeased) | `Darkly`, `libasm`, `snow-crash` |

These directories describe the repository structure; **they do not claim that every project is validated or publicly released**.

#### 🛠️ Development tools

The `Tools/` directory currently contains:

- **[`Complete_libft ✅`](https://github.com/Mechard-Organization/Complete_Libft-/tree/main)** — a genuine Git submodule, stored in a private repository with its own commit history.
- **`Makefile_standard`** — a tracked file alongside the tools, inside [`Cursus_2023`](https://github.com/Mechard-Organization/Cursus_2023/tree/main_sub/Tools).

<a id="associations"></a>
### 🤝 Student associations

[`Association_2023`](https://github.com/Mechard-Organization/Associations/tree/main_sub) collects student-life materials in a private repository.

| Area | Contents |
| :--- | :--- |
| **`BDE/`** | Student association resources |
| **`Blackout/`** | Association materials organized into office, communication and visual resources |

---

<a id="git-workflow"></a>
## 🔀 Git workflow

<p align="center"><img src="../.assets/images/42_paris_banner_git_workflow.png" alt="Git submodule workflow — 42 Paris" width="100%"></p>

### Clone the complete project tree

Since `42_Paris_2023/` belongs to the parent repository, clone the parent **recursively**:

```bash
git clone --recurse-submodules git@github.com:Mechard-Organization/42_Paris.git
cd 42_Paris/42_Paris_2023
```

SSH access is required for private child repositories. Without it, the public parent can still be cloned, but some recursive submodule checkouts will fail.

### Synchronize an existing clone

From the **root of `42_Paris`**:

```bash
git submodule sync --recursive
git submodule update --init --recursive
git submodule status --recursive
```

### Updating submodule references

The parent pins **commits**, not live branches. To move a direct submodule to the latest commit of its configured branch, run from the root of `42_Paris`:

```bash
git submodule update --remote -- 42_Paris_2023/Cursus_2023
git add 42_Paris_2023/Cursus_2023
git commit -m "chore: update Cursus_2023 submodule"
```

When changing a **nested** submodule, commit its updated pointer in the immediate parent first, then commit the resulting pointer in the next parent, working from the deepest repository up to `42_Paris`.

📘 [Custom Git workflow guide](../.assets/docs/GIT_WORKFLOW.md)

---

<a id="documentation"></a>
## 🗂️ Documentation & navigation

<p align="center"><img src="../.assets/images/42_paris_banner_repository_guide.png" alt="42 Paris repository documentation" width="100%"></p>

The visual assets and shared guides are maintained centrally in the parent repository's `.assets/` directory.

| Resource | Link |
| :--- | :--- |
| Main repository overview | [42_Paris](../README.md) |
| French version of this page | [README.fr.md](./README.fr.md) |
| Japanese version of this page | [README.ja.md](./README.ja.md) |
| Repository guide | [REPOSITORY_GUIDE.md](../.assets/docs/REPOSITORY_GUIDE.md) |
| Git workflow guide | [GIT_WORKFLOW.md](../.assets/docs/GIT_WORKFLOW.md) |
| Images and visual assets | [`.assets/images/`](../.assets/images/) |

---

## 💡 Purpose

This section provides a **readable map of my 2023 experience at 42 Paris**, from the Piscine to the Common Core and beyond. Detailed technical information, project histories and validation context belong in the relevant child repositories.

<p align="center"><a href="#top">⬆️ Back to top</a></p>
