<p align="center">
  <a href="./README.md">🇬🇧 English</a> &nbsp;·&nbsp;
  <strong>🇫🇷 Français</strong> &nbsp;·&nbsp;
  <a href="./README.ja.md">🇯🇵 日本語</a>
</p>

<a id="top"></a>

<p align="center">
  <img src=".assets/images/42_paris_banner_main.png" alt="42 Paris banner" width="100%">
</p>

<h1 align="center">42 Paris · Projets, archives & expérimentations</h1>

<p align="center">
  <strong>Un hub propre et lisible de tout mon parcours à 42 Paris :</strong><br>
  des <strong>fondations de 2017</strong> au <strong>Common Core 2023</strong>, avec des outils perso, des expérimentations et un workflow Git sur mesure.
</p>

<p align="center">
  <a href="#-vue-densemble">Vue d’ensemble</a> ·
  <a href="#-explorer-le-dépôt">Explorer</a> ·
  <a href="#-workflow-git">Workflow Git</a> ·
  <a href="#-assets--documentation">Assets & docs</a>
</p>

---

## ✨ Vue d’ensemble

> `42_Paris` n’est pas une seule application. C’est un **hub de dépôts et de sous-modules imbriqués** qui rassemble mon travail à **42 Paris** : projets, archives de cursus, expérimentations et outils.

<table>
<tr>
<td align="center" width="33%">
  <a href="https://github.com/Mechard-Organization/42_Paris_2017/tree/main_sub"><img src=".assets/images/42_paris_banner_2017.png" alt="42 Paris 2017" width="100%"></a>
  <br><br>
  <strong>🧱 42_Paris_2017</strong><br>
  <sub>Cursus historique, Piscine et premières bases en programmation.</sub>
</td>
<td align="center" width="33%">
  <a href="42_Paris_2023/"><img src=".assets/images/42_paris_banner_2023.png" alt="42 Paris 2023" width="100%"></a>
  <br><br>
  <strong>🚀 42_Paris_2023</strong><br>
  <sub>Cursus moderne, Common Core et projets plus avancés.</sub>
</td>
<td align="center" width="33%">
  <a href="https://github.com/Mechard-Organization/Others/tree/main_sub"><img src=".assets/images/42_paris_banner_others.png" alt="Others" width="100%"></a>
  <br><br>
  <strong>🛠️ Others</strong><br>
  <sub>Outils perso, automatisation, notes et projets annexes.</sub>
</td>
</tr>
</table>

### Informations clés

- 🎓 **École :** 42 Paris  
- 📚 **Contenu :** archives de cursus, projets Common Core, outils personnels et expérimentations  
- 🧩 **Structure :** dépôts Git imbriqués / sous-modules  
- 🏁 **Étape importante :** Common Core 2023 terminé le **26 février 2026**  
- 🌍 **Documentation :** disponible en **anglais, français et japonais**

---

## 🧭 Explorer le dépôt

### Structure globale

```text
42_Paris/
├── 42_Paris_2017/
│   ├── Piscine_C_2017/
│   └── Cursus_2017/
├── 42_Paris_2023/
│   ├── Association_2023/
│   │   ├── BDE/
│   │   └── Blackout/
│   ├── Piscine_C_2023/
│   └── Cursus_2023/
│       ├── Common_Core/                    # 16 project folders
│       │   ├── Cpp/                        # cpp00_80 … cpp09_100
│       │   └── ...                         # C, graphics, systems, web
│       ├── Post_Common_Core/
│       │   ├── Realeased/
│       │   └── Unrealeased/
│       │       ├── Darkly/
│       │       ├── libasm/
│       │       └── snow-crash/
│       └── Tools/
│           └── Complete_libft ✅/
├── Others/
│   ├── École_42/
│   └── Perso/GC/
└── .assets/
    ├── docs/
    ├── images/
    ├── text/
    └── tree/
```

Pour les arborescences détaillées :
- [`42_Paris_2017`](.assets/tree/42_Paris_2017.md)
- [`42_Paris_2023`](.assets/tree/42_Paris_2023.md)
- [`Others`](.assets/tree/Others.md)

---

## 🧱 42_Paris_2017

<p align="center"><img src=".assets/images/42_paris_banner_2017.png" alt="42 Paris 2017 banner" width="100%"></p>

La section **2017** conserve le début de mon parcours à 42 : la Piscine, les premiers projets en C, les bases Unix et les premiers réflexes de développement.

| Partie | Description |
| :--- | :--- |
| **Piscine C** | exercices quotidiens, rushes et premières mises en pratique |
| **Programmation C** | projets classiques de démarrage et fondations algorithmiques |
| **Valeur d’archive** | permet de retracer l’évolution du niveau et de la méthodologie |

---

## 🚀 42_Paris_2023

<p align="center"><img src=".assets/images/42_paris_banner_2023.png" alt="42 Paris 2023 banner" width="100%"></p>

La section **2023** correspond à une phase plus moderne de mon parcours : reprise du cursus, progression structurée dans le Common Core et projets techniques plus ambitieux.

| Partie | Description | Lien |
| :--- | :--- | :--- |
| **Piscine C / Shell** | retour dans la pédagogie 42 | [ouvrir](42_Paris_2023/Piscine_C_2023/) |
| **Common Core** | prog système, algo, graphisme, réseau, travail en équipe | [ouvrir](42_Paris_2023/Cursus_2023/Common_Core/) |
| **Post_Common_Core** | projets additionnels après le Common Core | [ouvrir](42_Paris_2023/Cursus_2023/Post_Common_Core/) |
| **Tools** | utilitaires et supports réutilisables | [ouvrir](42_Paris_2023/Cursus_2023/Tools/) |
| **Associations** | vie étudiante et matériel associatif | [ouvrir](42_Paris_2023/Association_2023/) |

### Familles de projets

- **Fondations C** : `libft_125`, `ft_printf_110`, `get_next_line_112`
- **Algo & processus** : `push_swap_100`, `pipex_115`, `philo_100`, `minishell_101`
- **Graphisme** : `So_long_96`, `Cub3D_105`
- **C++** : `Cpp`, `cpp00_80` → `cpp09_100`
- **Systèmes & infra** : `Born2beroot_125`, `Netpractice_100`, `IRC_125`, `Inception_100`
- **Web & collaboration** : `42_collaborative_resume_100`, `ft_transcendence_125`

### Post–Common Core : nouvelle organisation

Le travail post–Common Core se trouve directement sous [`Cursus_2023/Post_Common_Core/`](42_Paris_2023/Cursus_2023/Post_Common_Core/), et non plus sous l'ancien chemin `Projects/Post_CC/`.

| Dossier | Contenu |
| :--- | :--- |
| [`Realeased/`](42_Paris_2023/Cursus_2023/Post_Common_Core/Realeased/) | Contient un fichier `tmp` dans cette archive (orthographe d'origine conservée) |
| [`Unrealeased/`](42_Paris_2023/Cursus_2023/Post_Common_Core/Unrealeased/) | [`Darkly`](42_Paris_2023/Cursus_2023/Post_Common_Core/Unrealeased/Darkly/), [`libasm`](42_Paris_2023/Cursus_2023/Post_Common_Core/Unrealeased/libasm/) et [`snow-crash`](42_Paris_2023/Cursus_2023/Post_Common_Core/Unrealeased/snow-crash/) |

Cette liste décrit les **dossiers présents dans l'archive fournie**, sans présumer de la validation des projets. Les noms `Realeased` et `Unrealeased` respectent exactement l'arborescence actuelle.


---

## 🛠️ Others

<p align="center"><img src=".assets/images/42_paris_banner_others.png" alt="Others banner" width="100%"></p>

`Others/` est le **terrain d’expérimentation** du dépôt : outils perso, helpers shell, automatisations Git, notes d’apprentissage et side projects.

| Dossier | Rôle |
| :--- | :--- |
| `École_42/` | ressources personnelles liées à l’école |
| `Perso/GC/` | commandes Git custom, outils shell et helpers |
| autres sous-dossiers | projets perso et expérimentations |

---

## 🔀 Workflow Git

<p align="center"><img src=".assets/images/42_paris_banner_git_workflow.png" alt="Git workflow banner" width="100%"></p>

Comme ce dépôt repose sur des **sous-modules imbriqués**, le workflow Git est central.

### Clonage récursif standard

```bash
git clone --recurse-submodules git@github.com:Mechard-Organization/42_Paris.git
cd 42_Paris
```

### Si le dépôt est déjà cloné sans sous-modules

```bash
git submodule update --init --recursive
```

### Workflow personnalisé (avec mon wrapper Zsh)

```bash
git clone git@github.com:Mechard-Organization/42_Paris.git
git add -A
git commit -m "Ton message"
git push
```

Le wrapper personnalisé peut :
- cloner récursivement les sous-modules et sous-sous-modules
- aligner les branches (`main_42_Paris`, `main_sub`, `main`)
- préparer les dépôts imbriqués
- commit des enfants vers les parents
- push uniquement les dépôts réellement modifiés
- conserver des logs lisibles

📘 Tous les détails sont dans [`.assets/docs/GIT_WORKFLOW.md`](.assets/docs/GIT_WORKFLOW.md).

---

## 🗂️ Assets & documentation

<p align="center"><img src=".assets/images/42_paris_banner_repository_guide.png" alt="Repository guide banner" width="100%"></p>

Toutes les ressources liées aux README sont centralisées dans `.assets/`.

| Ressource | Emplacement |
| :--- | :--- |
| Guide du dépôt | [`.assets/docs/REPOSITORY_GUIDE.md`](.assets/docs/REPOSITORY_GUIDE.md) |
| Guide du workflow Git | [`.assets/docs/GIT_WORKFLOW.md`](.assets/docs/GIT_WORKFLOW.md) |
| Documentation des assets | [`.assets/docs/ASSETS.md`](.assets/docs/ASSETS.md) |
| Images du README | [`.assets/images/`](.assets/images/) |
| snapshots d’arborescence | [`.assets/tree/`](.assets/tree/) |
| exports texte | [`.assets/text/`](.assets/text/) |

---

## 💡 Pourquoi ce dépôt est intéressant

Ce dépôt est à la fois :
- une **archive technique** du parcours 42,
- un **point d’entrée** pour naviguer dans des dépôts imbriqués,
- un **workspace vivant** pour l’outillage et l’expérimentation.

---

<p align="center"><a href="#top">⬆️ Retour en haut</a></p>
