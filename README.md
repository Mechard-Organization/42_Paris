<p align="center">
  <strong>🇬🇧 English</strong> &nbsp;·&nbsp;
  <a href="./README.fr.md">🇫🇷 Français</a> &nbsp;·&nbsp;
  <a href="./README.ja.md">🇯🇵 日本語</a>
</p>

<a id="top"></a>

<p align="center">
  <img src=".assets/images/42_paris_banner_main.png" alt="42 Paris — projects, archives and experiments" width="100%">
</p>

<h1 align="center">42 Paris · Projects, Archives & Experiments</h1>

<p align="center">
  <strong>My 42 Paris journey, organized as a network of Git repositories:</strong><br>
  from the <strong>2017 foundations</strong> to the <strong>2023 Common Core</strong>, post–Common Core projects, personal tools and custom Git workflows.
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

`42_Paris` is a **navigation hub**, not a standalone application. It brings together my work at **42 Paris** through Git submodules, including submodules nested several levels deep. Each child repository retains its own history and Git configuration.

<table>
<tr>
<td align="center" width="33%">
  <a href="https://github.com/Mechard-Organization/42_Paris_2017/tree/main_sub"><img src=".assets/images/42_paris_banner_2017.png" alt="42 Paris 2017" width="100%"></a>
  <br><br><strong>🧱 42_Paris_2017</strong><br>
  <sub>2017 Piscine, early C projects and cursus archives.</sub>
</td>
<td align="center" width="33%">
  <a href="42_Paris_2023/"><img src=".assets/images/42_paris_banner_2023.png" alt="42 Paris 2023" width="100%"></a>
  <br><br><strong>🚀 42_Paris_2023</strong><br>
  <sub>2023 Piscine, Common Core, advanced projects and associations.</sub>
</td>
<td align="center" width="33%">
  <a href="https://github.com/Mechard-Organization/Others/tree/main_sub"><img src=".assets/images/42_paris_banner_others.png" alt="Others" width="100%"></a>
  <br><br><strong>🛠️ Others</strong><br>
  <sub>School resources, shell tools and personal experiments.</sub>
</td>
</tr>
</table>

- 🎓 **School:** 42 Paris
- 🏁 **Milestone:** 2023 Common Core completed on **26 February 2026**
- 🧩 **Architecture:** Git submodules, including recursive dependencies
- 🌍 **Languages:** English, French and Japanese
- 🔐 **Access:** this parent repository is public, but some child repositories are private; their contents require permission

---

<a id="structure"></a>
## 🧭 Repository structure

The tree below highlights the main navigation paths, not every file or project:

```text
42_Paris/
├── 42_Paris_2017/                         # Git submodule
│   ├── Piscine_C_2017/
│   └── Cursus_2017/
├── 42_Paris_2023/
│   ├── Association_2023/                 # Git submodule
│   │   ├── BDE/
│   │   └── Blackout/
│   ├── Piscine_C_2023/                   # Git submodule
│   └── Cursus_2023/                     # Git submodule
│       ├── Common_Core/                 # Git submodule
│       │   ├── Cpp/                     # Git submodule (cpp00 to cpp09)
│       │   └── ...                      # Other Common Core projects
│       ├── Post_Common_Core/            # Git submodule
│       │   ├── Realeased/
│       │   │   └── Internship_I_119/    # Git submodule
│       │   └── Unrealeased/
│       │       ├── Darkly/              # Git submodule
│       │       ├── libasm/              # Git submodule
│       │       └── snow-crash/          # Git submodule
│       └── Tools/
│           └── Complete_libft ✅/       # Git submodule
├── Others/                                # Git submodule
│   ├── École_42/                         # Git submodule
│   └── Perso/
│       ├── GC/
│       └── GS/
├── .assets/                               # README assets and guides
│   ├── docs/
│   ├── images/
│   ├── text/
│   └── tree/
├── .gitmodules
├── README.md
├── README.fr.md
└── README.ja.md
```

> Folder names such as `Realeased` and `Unrealeased` follow the **actual Git paths**, including their original spelling. Submodule entries are pinned to specific commits, not automatically to the tip of a branch.

Additional tree snapshots: [2017](.assets/tree/42_Paris_2017.md) · [2023](.assets/tree/42_Paris_2023.md) · [Others](.assets/tree/Others.md). These snapshots are documentation and may not reflect the very latest commit.

---

<a id="projects"></a>
## 🧱 42_Paris_2017

<p align="center"><img src=".assets/images/42_paris_banner_2017.png" alt="42 Paris 2017 banner" width="100%"></p>

An archive of my first steps at 42, including the **2017 Piscine** and early C/Unix coursework.

| Area | Content |
| :--- | :--- |
| [`Piscine_C_2017`](https://github.com/Mechard-Organization/42_Paris_2017/tree/main_sub/Piscine_C_2017) | Day exercises and rushes |
| [`Cursus_2017`](https://github.com/Mechard-Organization/42_Paris_2017/tree/main_sub/Cursus_2017) | Early projects such as `libft`, `get_next_line`, `ft_printf`, `fillit` and `fdf` |

## 🚀 42_Paris_2023

<p align="center"><img src=".assets/images/42_paris_banner_2023.png" alt="42 Paris 2023 banner" width="100%"></p>

The 2023 curriculum includes the Piscine, the **Common Core**, post–Common Core work and student associations.

| Area | Content | Repository |
| :--- | :--- | :--- |
| **Piscine C / Shell** | Shell exercises, C modules and rushes | [`Piscine_C_2023`](https://github.com/Mechard-Organization/Piscine_C_2023/tree/main_sub) |
| **Common Core** | C, C++, processes, graphics, networks and collaborative projects | [`Common_core`](https://github.com/Mechard-Organization/Common_core/tree/main) |
| **Post–Common Core** | Advanced projects and internship archive | [`Post_common_core`](https://github.com/Mechard-Organization/Post_common_core/tree/main) |
| **Tools** | Reusable development utilities | [`Cursus_2023/Tools`](42_Paris_2023/Cursus_2023/Tools/) |
| **Associations** | `BDE` and `Blackout` | [`Association_2023`](42_Paris_2023/Association_2023/) |

### Common Core project families

| Focus | Projects |
| :--- | :--- |
| **C fundamentals** | `libft_125`, `ft_printf_110`, `get_next_line_112` |
| **Algorithms & processes** | `push_swap_100`, `pipex_115`, `philo_100`, `minishell_101` |
| **Graphics** | `So_long_96`, `Cub3D_105` |
| **C++** | `Cpp` → `cpp00_80` through `cpp09_100` |
| **Systems & networking** | `Born2beroot_125`, `Netpractice_105`, `IRC_125`, `Inception_100` |
| **Web & collaboration** | `42_collaborative_resume_100`, `ft_transcendence_125` |

### Post–Common Core

| Directory | Projects |
| :--- | :--- |
| [`Realeased/`](42_Paris_2023/Cursus_2023/Post_Common_Core/Realeased/) | [`Internship_I_119`](42_Paris_2023/Cursus_2023/Post_Common_Core/Realeased/Internship_I_119/) |
| [`Unrealeased/`](42_Paris_2023/Cursus_2023/Post_Common_Core/Unrealeased/) | [`Darkly`](42_Paris_2023/Cursus_2023/Post_Common_Core/Unrealeased/Darkly/), [`libasm`](42_Paris_2023/Cursus_2023/Post_Common_Core/Unrealeased/libasm/), [`snow-crash`](42_Paris_2023/Cursus_2023/Post_Common_Core/Unrealeased/snow-crash/) |

Directory names and project folders describe the repository layout; they do **not** imply that each project has been completed or validated.

### Development tools

[`Tools/Complete_libft ✅`](42_Paris_2023/Cursus_2023/Tools/Complete_libft%20%E2%9C%85/) is a **real Git submodule**, linked to the private [`Complete_Libft-`](https://github.com/Mechard-Organization/Complete_Libft-) repository. It remains inside `Cursus_2023/Tools/` and has its own commit history.

## 🛠️ Others

<p align="center"><img src=".assets/images/42_paris_banner_others.png" alt="Others banner" width="100%"></p>

A workspace for personal tooling, automation, school-related resources and side projects.

| Directory | Purpose |
| :--- | :--- |
| `École_42/` | School-related resources (nested submodule) |
| `Perso/GC/` | Custom Git utilities and shell helpers |
| `Perso/GS/` | Additional personal tools and scripts |

---

<a id="git-workflow"></a>
## 🔀 Git workflow

<p align="center"><img src=".assets/images/42_paris_banner_git_workflow.png" alt="Git workflow banner" width="100%"></p>

### Clone the complete repository

```bash
git clone --recurse-submodules git@github.com:Mechard-Organization/42_Paris.git
cd 42_Paris
```

You need **SSH access to every private child repository** to complete a fully recursive clone. Otherwise, Git can clone the public parent while access to some submodules fails.

### Initialize or repair submodules

```bash
git submodule sync --recursive
git submodule update --init --recursive
git submodule status --recursive
```

### Update a submodule reference intentionally

```bash
# Example: follow the branch configured for the 2017 submodule
git submodule update --remote -- 42_Paris_2017
git add 42_Paris_2017
git commit -m "chore: update 42_Paris_2017 submodule"
git push origin main_42_Paris
```

A `git submodule update --init --recursive` checkout uses the **commits pinned by the parent**. It does not automatically fetch the latest branch tip. Review changes in children before committing an updated pointer.

### Personal Git automation

I also use a custom **Zsh Git wrapper** for recursive cloning, branch alignment, child-before-parent commits, publishing changes and readable logs. Its behavior is specific to my local configuration; the commands above are the portable Git workflow.

📘 [Custom Git workflow documentation](.assets/docs/GIT_WORKFLOW.md)

---

<a id="documentation"></a>
## 🗂️ Assets & documentation

<p align="center"><img src=".assets/images/42_paris_banner_repository_guide.png" alt="Repository guide banner" width="100%"></p>

The repository's README resources are grouped under `.assets/`.

| Resource | Location |
| :--- | :--- |
| Repository guide | [`.assets/docs/REPOSITORY_GUIDE.md`](.assets/docs/REPOSITORY_GUIDE.md) |
| Git workflow guide | [`.assets/docs/GIT_WORKFLOW.md`](.assets/docs/GIT_WORKFLOW.md) |
| Assets guide | [`.assets/docs/ASSETS.md`](.assets/docs/ASSETS.md) |
| Banners and visuals | [`.assets/images/`](.assets/images/) |
| Directory tree snapshots | [`.assets/tree/`](.assets/tree/) |
| Text exports | [`.assets/text/`](.assets/text/) |

---

## 💡 Purpose

This repository serves as a **technical archive**, a **navigation hub for nested repositories**, and a **living workspace for learning and experimentation**. The root README is an overview; the individual repositories remain the source of truth for their code and project-specific documentation.

<p align="center"><a href="#top">⬆️ Back to top</a></p>
