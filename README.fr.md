<p align="center">
  <a href="./README.md">🇬🇧 English</a> &nbsp;·&nbsp;
  <strong>🇫🇷 Français</strong> &nbsp;·&nbsp;
  <a href="./README.ja.md">🇯🇵 日本語</a>
</p>

<a id="top"></a>

<p align="center">
  <img src=".assets/images/42_paris_banner_main.png" alt="42 Paris — projets, archives et expérimentations" width="100%">
</p>

<h1 align="center">42 Paris · Projets, archives & expérimentations</h1>

<p align="center">
  <strong>Mon parcours à 42 Paris, organisé en un réseau de dépôts Git :</strong><br>
  des <strong>fondations de 2017</strong> au <strong>Common Core 2023</strong>, puis aux projets post–Common Core, aux outils personnels et à un workflow Git sur mesure.
</p>

<p align="center">
  <a href="#overview">Vue d’ensemble</a> ·
  <a href="#structure">Structure</a> ·
  <a href="#projects">Projets</a> ·
  <a href="#git-workflow">Workflow Git</a> ·
  <a href="#documentation">Documentation</a>
</p>

---

<a id="overview"></a>
## ✨ Vue d’ensemble

`42_Paris` est un **point d’entrée vers plusieurs dépôts**, et non une application unique. Il rassemble mon travail à **42 Paris** grâce à des sous-modules Git, parfois imbriqués sur plusieurs niveaux. Chaque dépôt enfant conserve son propre historique et sa propre configuration Git.

<table>
<tr>
<td align="center" width="33%">
  <a href="https://github.com/Mechard-Organization/42_Paris_2017/tree/main_sub"><img src=".assets/images/42_paris_banner_2017.png" alt="42 Paris 2017" width="100%"></a>
  <br><br><strong>🧱 42_Paris_2017</strong><br>
  <sub>Piscine 2017, premiers projets C et archives de cursus.</sub>
</td>
<td align="center" width="33%">
  <a href="42_Paris_2023/"><img src=".assets/images/42_paris_banner_2023.png" alt="42 Paris 2023" width="100%"></a>
  <br><br><strong>🚀 42_Paris_2023</strong><br>
  <sub>Piscine 2023, Common Core, projets avancés et associations.</sub>
</td>
<td align="center" width="33%">
  <a href="https://github.com/Mechard-Organization/Others/tree/main_sub"><img src=".assets/images/42_paris_banner_others.png" alt="Others" width="100%"></a>
  <br><br><strong>🛠️ Others</strong><br>
  <sub>Ressources scolaires, outils shell et expérimentations personnelles.</sub>
</td>
</tr>
</table>

- 🎓 **École :** 42 Paris
- 🏁 **Étape importante :** Common Core 2023 terminé le **26 février 2026**
- 🧩 **Architecture :** sous-modules Git, avec dépendances récursives
- 🌍 **Langues :** anglais, français et japonais
- 🔐 **Accès :** le dépôt parent est public, mais certains dépôts enfants sont privés ; leur contenu nécessite une autorisation

---

<a id="structure"></a>
## 🧭 Structure du dépôt

Cette arborescence présente les principaux chemins de navigation, sans détailler tous les fichiers et projets :

```text
42_Paris/
├── 42_Paris_2017/                       # Sous-module Git
│   ├── Piscine_C_2017/
│   └── Cursus_2017/
├── 42_Paris_2023/
│   ├── Association_2023/                # Sous-module Git
│   │   ├── BDE/
│   │   └── Blackout/
│   ├── Piscine_C_2023/                  # Sous-module Git
│   └── Cursus_2023/                     # Sous-module Git
│       ├── Common_Core/                 # Sous-module Git
│       │   ├── Cpp/                     # Sous-module Git (cpp00 à cpp09)
│       │   └── ...                      # Autres projets Common Core
│       ├── Post_Common_Core/            # Sous-module Git
│       │   ├── Realeased/
│       │   │   └── Internship_I_119/    # Sous-module Git
│       │   └── Unrealeased/
│       │       ├── Darkly/              # Sous-module Git
│       │       ├── libasm/              # Sous-module Git
│       │       └── snow-crash/          # Sous-module Git
│       └── Tools/
│           └── Complete_libft ✅/       # Sous-module Git
├── Others/                              # Sous-module Git
│   ├── École_42/                        # Sous-module Git
│   └── Perso/
│       └── Git_Custom/
├── .assets/                             # Visuels et guides des README
│   ├── docs/
│   ├── images/
│   ├── text/
│   └── tree/
├── .gitmodules
├── README.md
├── README.fr.md
└── README.ja.md
```

> Les noms `Realeased` et `Unrealeased` respectent **l'orthographe réelle des chemins Git**. Les sous-modules pointent vers des commits précis ; ils ne suivent pas automatiquement la dernière version d'une branche.

Arborescences détaillées : [2017](.assets/tree/42_Paris_2017.md) · [2023](.assets/tree/42_Paris_2023.md) · [Others](.assets/tree/Others.md). Ces instantanés sont documentaires et peuvent différer des derniers commits.

---

<a id="projects"></a>
## 🧱 42_Paris_2017

<p align="center"><img src=".assets/images/42_paris_banner_2017.png" alt="Bannière 42 Paris 2017" width="100%"></p>

Une archive de mes débuts à 42 : **Piscine 2017**, premiers projets en C et apprentissage d'Unix.

| Partie | Contenu |
| :--- | :--- |
| [`Piscine_C_2017`](https://github.com/Mechard-Organization/42_Paris_2017/tree/main_sub/Piscine_C_2017) | Exercices journaliers et rushes |
| [`Cursus_2017`](https://github.com/Mechard-Organization/42_Paris_2017/tree/main_sub/Cursus_2017) | Premiers projets comme `libft`, `get_next_line`, `ft_printf`, `fillit` et `fdf` |

## 🚀 42_Paris_2023

<p align="center"><img src=".assets/images/42_paris_banner_2023.png" alt="Bannière 42 Paris 2023" width="100%"></p>

Le cursus 2023 regroupe la Piscine, le **Common Core**, les projets post–Common Core et les associations étudiantes.

| Partie | Contenu | Dépôt |
| :--- | :--- | :--- |
| **Piscine C / Shell** | Exercices Shell, modules C et rushes | [`Piscine_C_2023`](https://github.com/Mechard-Organization/Piscine_C_2023/tree/main_sub) |
| **Common Core** | C, C++, processus, graphisme, réseau et projets collaboratifs | [`Common_core`](https://github.com/Mechard-Organization/Common_core/tree/main) |
| **Post–Common Core** | Projets avancés et archives de stage | [`Post_common_core`](https://github.com/Mechard-Organization/Post_common_core/tree/main) |
| **Tools** | Utilitaires de développement réutilisables | [`Cursus_2023/Tools`](42_Paris_2023/Cursus_2023/Tools/) |
| **Associations** | `BDE` et `Blackout` | [`Association_2023`](42_Paris_2023/Association_2023/) |

### Familles de projets du Common Core

| Domaine | Projets |
| :--- | :--- |
| **Fondations C** | `libft_125`, `ft_printf_110`, `get_next_line_112` |
| **Algorithmes & processus** | `push_swap_100`, `pipex_115`, `philo_100`, `minishell_101` |
| **Graphisme** | `So_long_96`, `Cub3D_105` |
| **C++** | `Cpp` → `cpp00_80` à `cpp09_100` |
| **Systèmes & réseau** | `Born2beroot_125`, `Netpractice_105`, `IRC_125`, `Inception_100` |
| **Web & collaboration** | `42_collaborative_resume_100`, `ft_transcendence_125` |

### Post–Common Core

| Dossier | Projets |
| :--- | :--- |
| [`Realeased/`](42_Paris_2023/Cursus_2023/Post_Common_Core/Realeased/) | `Internship_I_119` |
| [`Unrealeased/`](42_Paris_2023/Cursus_2023/Post_Common_Core/Unrealeased/) | `Darkly`, `libasm`, `snow-crash` |

Ces noms et dossiers décrivent l'organisation du dépôt ; ils **ne signifient pas** que tous les projets sont terminés ou validés.

### Outils de développement

[`Tools/Complete_libft ✅`](42_Paris_2023/Cursus_2023/Tools/Complete_libft%20%E2%9C%85/) est un **véritable sous-module Git**, relié au dépôt privé [`Complete_Libft-`](https://github.com/Mechard-Organization/Complete_Libft-). Il reste dans `Cursus_2023/Tools/` et possède son propre historique de commits.

## 🛠️ Others

<p align="center"><img src=".assets/images/42_paris_banner_others.png" alt="Bannière Others" width="100%"></p>

Un espace dédié aux outils personnels, à l'automatisation, aux ressources de l'école et aux projets annexes.

| Dossier | Rôle |
| :--- | :--- |
| `École_42/` | Ressources scolaires (sous-module imbriqué) |
| `Perso/Git_Custom/` | Utilitaires Git personnalisés et helpers shell |

---

<a id="git-workflow"></a>
## 🔀 Workflow Git

<p align="center"><img src=".assets/images/42_paris_banner_git_workflow.png" alt="Bannière workflow Git" width="100%"></p>

### Cloner l'ensemble des dépôts

```bash
git clone --recurse-submodules git@github.com:Mechard-Organization/42_Paris.git
cd 42_Paris
```

Le clonage intégral nécessite **un accès SSH à chaque dépôt enfant privé**. Sans les autorisations correspondantes, Git peut cloner le dépôt parent public, mais échouer sur certains sous-modules.

### Initialiser ou resynchroniser les sous-modules

```bash
git submodule sync --recursive
git submodule update --init --recursive
git submodule status --recursive
```

### Mettre à jour volontairement une référence de sous-module

```bash
# Exemple : suivre la branche configurée pour le sous-module 2017
git submodule update --remote -- 42_Paris_2017
git add 42_Paris_2017
git commit -m "chore: update 42_Paris_2017 submodule"
git push origin main_42_Paris
```

La commande `git submodule update --init --recursive` utilise les **commits enregistrés par le dépôt parent**, et non forcément les derniers commits des branches. Il faut vérifier les modifications des dépôts enfants avant d'enregistrer une nouvelle référence.

### Automatisation Git personnelle

J'utilise aussi un **wrapper Git en Zsh** pour le clonage récursif, l'alignement des branches, les commits des enfants avant les parents, la publication et les logs. Son fonctionnement dépend de ma configuration locale ; les commandes précédentes constituent la méthode Git standard.

📘 [Documentation du workflow Git personnalisé](.assets/docs/GIT_WORKFLOW.md)

---

<a id="documentation"></a>
## 🗂️ Assets & documentation

<p align="center"><img src=".assets/images/42_paris_banner_repository_guide.png" alt="Bannière du guide du dépôt" width="100%"></p>

Les ressources des README sont regroupées dans `.assets/`.

| Ressource | Emplacement |
| :--- | :--- |
| Guide du dépôt | [`.assets/docs/REPOSITORY_GUIDE.md`](.assets/docs/REPOSITORY_GUIDE.md) |
| Guide du workflow Git | [`.assets/docs/GIT_WORKFLOW.md`](.assets/docs/GIT_WORKFLOW.md) |
| Guide des ressources | [`.assets/docs/ASSETS.md`](.assets/docs/ASSETS.md) |
| Bannières et visuels | [`.assets/images/`](.assets/images/) |
| Instantanés d'arborescence | [`.assets/tree/`](.assets/tree/) |
| Exports texte | [`.assets/text/`](.assets/text/) |

---

## 💡 Objectif du dépôt

Ce dépôt est à la fois une **archive technique**, un **point d'entrée vers les dépôts imbriqués** et un **espace vivant d'apprentissage et d'expérimentation**. Le README principal présente une vue d'ensemble ; chaque dépôt enfant reste la référence pour son code et sa documentation propre.

<p align="center"><a href="#top">⬆️ Retour en haut</a></p>
