<p align="center">
  <a href="./README.md">🇬🇧 English</a> &nbsp;·&nbsp;
  <strong>🇫🇷 Français</strong> &nbsp;·&nbsp;
  <a href="./README.ja.md">🇯🇵 日本語</a>
</p>

<a id="top"></a>

<p align="center">
  <img src="../.assets/images/42_paris_banner_2023.png" alt="42 Paris 2023 — Piscine, Common Core et vie étudiante" width="100%">
</p>

<h1 align="center">42 Paris · Piscine, cursus & associations 2023</h1>

<p align="center">
  <strong>Le chapitre 2023 de mon parcours à 42 Paris :</strong><br>
  de la <strong>Piscine</strong> au <strong>Common Core</strong>, puis aux projets post–Common Core, aux outils de développement et à la vie associative.
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

`42_Paris_2023/` est la **section consacrée à 2023** dans le [dépôt principal `42_Paris`](../README.fr.md). Elle rassemble la Piscine, le cursus et les associations étudiantes au moyen de **trois sous-modules Git directs**. Le cursus contient lui-même d'autres sous-modules imbriqués, chacun avec son propre historique.

<table>
<tr>
<td align="center" width="33%">
  <a href="#piscine"><strong>🏊 Piscine_C_2023</strong></a><br><br>
  <sub>Exercices Shell, modules C et rushes : les premières bases du parcours 2023.</sub>
</td>
<td align="center" width="33%">
  <a href="#cursus"><strong>🚀 Cursus_2023</strong></a><br><br>
  <sub>Projets Common Core, travaux post–Common Core et outils réutilisables.</sub>
</td>
<td align="center" width="33%">
  <a href="#associations"><strong>🤝 Association_2023</strong></a><br><br>
  <sub>Initiatives étudiantes, BDE et ressources de l'association Blackout.</sub>
</td>
</tr>
</table>

- 🎓 **École :** 42 Paris
- 🏁 **Étape importante :** Common Core 2023 terminé le **26 février 2026**
- 🧩 **Architecture :** trois sous-modules directs, puis des sous-modules récursifs sous `Cursus_2023`
- 🌍 **Langues :** français, anglais et japonais
- 🔐 **Accès :** le dépôt principal est public, mais plusieurs dépôts enfants sont privés ; leur contenu nécessite une autorisation

---

<a id="structure"></a>
## 🧭 Structure des dossiers

Cette arborescence sert de **repère de navigation** : elle ne répertorie pas tous les fichiers. Les noms correspondent aux chemins Git actuels.

```text
42_Paris_2023/
├── Association_2023/                    # Sous-module Git
│   ├── BDE/
│   └── Blackout/
├── Piscine_C_2023/                      # Sous-module Git
│   ├── Shell_00/
│   ├── Shell_01/
│   ├── C_00/ ... C_09/
│   ├── C_11/
│   └── Rush/
├── Cursus_2023/                         # Sous-module Git
│   ├── Common_Core/                     # Sous-module Git (16 projets)
│   │   ├── Cpp/                         # Sous-module Git (cpp00 à cpp09)
│   │   └── ...                          # Autres projets Common Core
│   ├── Post_Common_Core/               # Sous-module Git
│   │   ├── Realeased/
│   │   │   └── Internship_I_119/        # Sous-module Git
│   │   └── Unrealeased/
│   │       ├── Darkly/                  # Sous-module Git
│   │       ├── libasm/                  # Sous-module Git
│   │       └── snow-crash/              # Sous-module Git
│   └── Tools/
│       ├── Complete_libft ✅/           # Sous-module Git
│       └── Makefile_standard
├── README.md
├── README.fr.md
└── README.ja.md
```

> `42_Paris_2023/` est un dossier du dépôt parent, **pas un dépôt Git indépendant**. Ses trois dossiers enfants directs sont des sous-modules. Git enregistre un **commit précis** pour chacun : la présence d'une branche dans `.gitmodules` n'actualise pas automatiquement cette référence.

> Les noms `Realeased` et `Unrealeased` sont conservés volontairement, conformément aux vrais chemins. La Piscine contient `C_11`, mais pas de dossier `C_10`.

---

<a id="projects"></a>
## 🧪 Projets & activités

<a id="piscine"></a>
### 🏊 Piscine C / Shell — 2023

La Piscine 2023 regroupe les premiers exercices en **Shell et en C**, ainsi que les défis collectifs (rushes). Elle est conservée dans un dépôt distinct dont l'accès peut nécessiter une autorisation.

| Partie | Contenu | Accès |
| :--- | :--- | :--- |
| **Shell** | `Shell_00`, `Shell_01` | [`Piscine_C_2023`](https://github.com/Mechard-Organization/Piscine_C_2023/tree/main_sub) |
| **Modules C** | `C_00` à `C_09` et `C_11` | [Modules C](https://github.com/Mechard-Organization/Piscine_C_2023/tree/main_sub) |
| **Rushes** | Projets collectifs et chronométrés dans `Rush/` | [Dossier Rush](https://github.com/Mechard-Organization/Piscine_C_2023/tree/main_sub/Rush) |

<a id="cursus"></a>
### 🚀 Cursus 2023

[`Cursus_2023`](https://github.com/Mechard-Organization/Cursus_2023/tree/main_sub) est le dépôt central du cursus. Il distingue **Common_Core**, **Post_Common_Core** et **Tools**, avec plusieurs sous-modules Git imbriqués.

<a id="common-core"></a>
#### 🧱 Common Core

Le **Common Core** couvre le C, le C++, les algorithmes, les systèmes Unix, le graphisme, le réseau et le développement collaboratif. Le dépôt [`Common_core`](https://github.com/Mechard-Organization/Common_core/tree/main) contient **16 sous-modules de projets** :

| Domaine | Dossiers des projets |
| :--- | :--- |
| **Fondations C** | `libft_125`, `ft_printf_110`, `get_next_line_112` |
| **Algorithmes, processus & shells** | `push_swap_100`, `pipex_115`, `philo_100`, `minishell_101` |
| **Graphisme** | `So_long_96`, `Cub3D_105` |
| **C++** | `Cpp` → `cpp00_80` à `cpp09_100` (imbriqués dans `Cpp`) |
| **Systèmes & réseau** | `Born2beroot_125`, `Netpractice_105`, `IRC_125`, `Inception_100` |
| **Web & collaboration** | `42_collaborative_resume_100`, `ft_transcendence_125` |

**Étape personnelle :** le Common Core 2023 a été terminé le **26 février 2026**. Les scores apparaissant dans les noms de certains dossiers sont conservés comme éléments de la nomenclature du dépôt.

<a id="post-common-core"></a>
#### 🔭 Post–Common Core

Le dépôt privé [`Post_common_core`](https://github.com/Mechard-Organization/Post_common_core/tree/main) regroupe les travaux au-delà du Common Core et les éléments relatifs au stage.

| Dossier | Sous-modules Git |
| :--- | :--- |
| [`Realeased/`](https://github.com/Mechard-Organization/Post_common_core/tree/main/Realeased) | `Internship_I_119` |
| [`Unrealeased/`](https://github.com/Mechard-Organization/Post_common_core/tree/main/Unrealeased) | `Darkly`, `libasm`, `snow-crash` |

Ces dossiers décrivent l'organisation du dépôt ; **ils ne signifient pas que tous les projets ont été validés ou publiés**.

#### 🛠️ Outils de développement

Le dossier `Tools/` contient actuellement :

- **[`Complete_libft ✅`](https://github.com/Mechard-Organization/Complete_Libft-/tree/main)** — un véritable sous-module Git, hébergé dans un dépôt privé avec son propre historique de commits.
- **`Makefile_standard`** — un fichier suivi par Git, placé aux côtés des outils dans [`Cursus_2023`](https://github.com/Mechard-Organization/Cursus_2023/tree/main_sub/Tools).

<a id="associations"></a>
### 🤝 Associations étudiantes

[`Association_2023`](https://github.com/Mechard-Organization/Associations/tree/main_sub) rassemble les ressources de la vie étudiante dans un dépôt privé.

| Partie | Contenu |
| :--- | :--- |
| **`BDE/`** | Ressources du bureau des étudiants |
| **`Blackout/`** | Ressources associatives organisées autour du bureau, de la communication et des visuels |

---

<a id="git-workflow"></a>
## 🔀 Workflow Git

<p align="center"><img src="../.assets/images/42_paris_banner_git_workflow.png" alt="Workflow des sous-modules Git — 42 Paris" width="100%"></p>

### Cloner toute l'arborescence

Puisque `42_Paris_2023/` appartient au dépôt principal, il faut cloner ce dernier **récursivement** :

```bash
git clone --recurse-submodules git@github.com:Mechard-Organization/42_Paris.git
cd 42_Paris/42_Paris_2023
```

Un accès SSH est nécessaire pour les dépôts enfants privés. Sans cet accès, le dépôt parent public peut être cloné, mais certains sous-modules ne pourront pas être récupérés.

### Synchroniser un clone existant

Depuis la **racine de `42_Paris`** :

```bash
git submodule sync --recursive
git submodule update --init --recursive
git submodule status --recursive
```

### Mettre à jour les références des sous-modules

Le dépôt parent pointe vers des **commits**, et non vers des branches mises à jour en direct. Pour avancer un sous-module direct sur le dernier commit de sa branche configurée, depuis la racine de `42_Paris` :

```bash
git submodule update --remote -- 42_Paris_2023/Cursus_2023
git add 42_Paris_2023/Cursus_2023
git commit -m "chore: update Cursus_2023 submodule"
```

Lorsqu'un sous-module **imbriqué** change, il faut d'abord enregistrer son nouveau commit dans son dépôt parent immédiat, puis remonter progressivement jusqu'à `42_Paris`.

📘 [Guide du workflow Git personnalisé](../.assets/docs/GIT_WORKFLOW.md)

---

<a id="documentation"></a>
## 🗂️ Documentation & navigation

<p align="center"><img src="../.assets/images/42_paris_banner_repository_guide.png" alt="Documentation du dépôt 42 Paris" width="100%"></p>

Les ressources visuelles et les guides communs sont centralisés dans `.assets/`, à la racine du dépôt principal.

| Ressource | Lien |
| :--- | :--- |
| Présentation du dépôt principal | [42_Paris](../README.fr.md) |
| Version anglaise de cette page | [README.md](./README.md) |
| Version japonaise de cette page | [README.ja.md](./README.ja.md) |
| Guide du dépôt | [REPOSITORY_GUIDE.md](../.assets/docs/REPOSITORY_GUIDE.md) |
| Guide du workflow Git | [GIT_WORKFLOW.md](../.assets/docs/GIT_WORKFLOW.md) |
| Images et ressources visuelles | [`.assets/images/`](../.assets/images/) |

---

## 💡 Objectif

Cette section est une **carte lisible de mon parcours 2023 à 42 Paris**, de la Piscine au Common Core et au-delà. Les détails techniques, les historiques de projets et les informations de validation restent dans les dépôts enfants concernés.

<p align="center"><a href="#top">⬆️ Retour en haut</a></p>
