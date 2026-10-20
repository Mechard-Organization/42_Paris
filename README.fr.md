<p align="center">
  🌐 <strong>Langues :</strong>
  <a href="./README.md">🇬🇧 English</a> &nbsp;·&nbsp;
  <strong>🇫🇷 Français</strong> &nbsp;·&nbsp;
  <a href="./README.ja.md">🇯🇵 日本語</a>
</p>

<a id="top"></a>

<div align="center">

<a href="https://github.com/Mechard-Organization/42_Paris">
  <img src=".assets/images/42_Paris_title_banner.png" alt="42 Paris — programmation, projets et apprentissage continu" width="820">
</a>

# 42 Paris · Projets et archives d'apprentissage

**Deux chapitres à 42 Paris. Une collection de code, d'expérimentations et d'outils en constante évolution.**

De la **Piscine de 2017** au **cursus de 2023**, ce dépôt rassemble mes projets de formation, mes expérimentations techniques et les outils que j'utilise pour les maintenir.

**[Explorer le dépôt](#explore)** · **[Projets de 2023](#journey-2023)** · **[Archives de 2017](#journey-2017)** · **[Workflow Git](#git-workflow)**

<sub>Maintenu par <strong>Maxime Echard</strong> · École 42 Paris</sub>

</div>

---

## Bienvenue

`42_Paris` est mon espace de travail central pour les projets et ressources d'apprentissage issus de **l'École 42 Paris**. Il réunit mon premier parcours en **2017**, un nouveau cursus commencé en **2023**, ainsi que les projets personnels et utilitaires développés en parallèle.

Il s'agit d'une **collection de dépôts Git reliés par des sous-modules imbriqués**, et non d'une application monolithique. Chaque projet conserve son propre code source, son historique et, le cas échéant, sa documentation.

> **Étape importante :** j'ai terminé le **tronc commun du cursus 2023 le 26 février 2026**. Le dépôt contient également des travaux historiques, des expérimentations et des projets postérieurs au tronc commun ; la présence d'un projet ne signifie donc pas nécessairement qu'il a été validé.

<a id="explore"></a>

## Explorer le dépôt

<table>
<tr>
  <td align="center" width="33%">
    <a href="42_Paris_2017/"><img src=".assets/images/42_Paris_2017_title_banner.png" alt="Découvrir mon parcours en 2017" width="250"></a>
    <br><strong><a href="42_Paris_2017/">42 Paris · 2017</a></strong>
    <br><sub>Piscine C, premiers pas et premiers projets du cursus.</sub>
  </td>
  <td align="center" width="33%">
    <a href="42_Paris_2023/"><img src=".assets/images/42_Paris_2023_title_banner.png" alt="Découvrir mon parcours en 2023" width="250"></a>
    <br><strong><a href="42_Paris_2023/">42 Paris · 2023</a></strong>
    <br><sub>Piscine, tronc commun, projets ultérieurs et vie étudiante.</sub>
  </td>
  <td align="center" width="33%">
    <a href="Others/"><img src=".assets/images/Others_title_banner.png" alt="Explorer les projets personnels et outils" width="250"></a>
    <br><strong><a href="Others/">Others</a></strong>
    <br><sub>Apprentissage personnel, expérimentations, notes et outils Git.</sub>
  </td>
</tr>
</table>

### Structure du dépôt

```text
42_Paris/
├── 42_Paris_2017/
│   ├── Piscine_C_2017/          # Exercices et sujets de la Piscine 2017
│   └── Cursus_2017/            # Premiers projets et ressources d'apprentissage
├── 42_Paris_2023/
│   ├── Piscine_C_2023/          # Exercices de Piscine en C et en Shell
│   ├── Cursus_2023/
│   │   └── Projects/
│   │       ├── Common_core/     # Tronc commun et dépôts imbriqués
│   │       ├── Post_CC/         # Travaux postérieurs au tronc commun
│   │       └── Tools/           # Utilitaires et outils complémentaires
│   └── Association_2023/       # Vie associative étudiante
├── Others/
│   ├── École_42/                # Ressources personnelles pour l'école
│   └── Perso/GC/               # Outils Git personnalisés
└── .assets/
    ├── docs/                    # Documentation complémentaire
    ├── images/                  # Images utilisées par les README
    ├── text/                    # Exports textuels des arborescences
    └── tree/                    # Instantanés détaillés des arborescences
```

Cette carte présente volontairement les **principaux points d'entrée**, plutôt que chaque exercice et sous-dépôt. Consulte le [guide détaillé des dossiers](.assets/docs/REPOSITORY_GUIDE.md) ou les arborescences existantes : [2017](.assets/tree/42_Paris_2017.md) · [2023](.assets/tree/42_Paris_2023.md) · [Others](.assets/tree/Others.md).

---

<a id="journey-2023"></a>

## Le parcours de 2023

<p align="center"><a href="42_Paris_2023/"><img src=".assets/images/42_Paris_2023_title_banner.png" alt="Section 42 Paris 2023" width="600"></a></p>

La section 2023 retrace mon retour dans le cursus de l'école : la **Piscine**, les projets du **tronc commun**, les travaux ultérieurs et ma participation à des activités étudiantes.

| Domaine | Contenu | Explorer |
| :--- | :--- | :--- |
| **Piscine C** | Exercices Shell, modules C et projets rush | [Piscine_C_2023](42_Paris_2023/Piscine_C_2023/) |
| **Tronc commun** | Fondamentaux de programmation, algorithmes, systèmes, réseau et projets d'équipe | [Common_core](42_Paris_2023/Cursus_2023/Projects/Common_core/) |
| **Post–tronc commun** | Projets complémentaires et avancés | [Post_CC](42_Paris_2023/Cursus_2023/Projects/Post_CC/) |
| **Outils** | Utilitaires et composants réutilisables | [Tools](42_Paris_2023/Cursus_2023/Projects/Tools/) |
| **Associations** | Ressources du BDE et de Blackout | [Association_2023](42_Paris_2023/Association_2023/) |

### Sélection de projets du tronc commun

Les projets et dossiers ci-dessous sont présents dans l'archive fournie. Leurs noms respectent l'organisation d'origine des dépôts.

| Domaine | Projets |
| :--- | :--- |
| **Fondamentaux du C et entrées/sorties** | [`libft_125`](42_Paris_2023/Cursus_2023/Projects/Common_core/libft_125/), [`ft_printf_110`](42_Paris_2023/Cursus_2023/Projects/Common_core/ft_printf_110/), [`get_next_line_112`](42_Paris_2023/Cursus_2023/Projects/Common_core/get_next_line_112/) |
| **Algorithmes et gestion des processus** | [`push_swap_100`](42_Paris_2023/Cursus_2023/Projects/Common_core/push_swap_100/), [`pipex_115`](42_Paris_2023/Cursus_2023/Projects/Common_core/pipex_115/), [`philo_100`](42_Paris_2023/Cursus_2023/Projects/Common_core/philo_100/), [`minishell_101`](42_Paris_2023/Cursus_2023/Projects/Common_core/minishell_101/) |
| **Graphisme** | [`So_long_96`](42_Paris_2023/Cursus_2023/Projects/Common_core/So_long_96/), [`Cub3D_105`](42_Paris_2023/Cursus_2023/Projects/Common_core/Cub3D_105/) |
| **C++** | [`Cpp`](42_Paris_2023/Cursus_2023/Projects/Common_core/Cpp/) — modules de `cpp00_80` à `cpp09_100`, selon les éléments présents dans l'archive |
| **Systèmes et réseau** | [`Born2beroot_125`](42_Paris_2023/Cursus_2023/Projects/Common_core/Born2beroot_125/), [`Netpractice_100`](42_Paris_2023/Cursus_2023/Projects/Common_core/Netpractice_100/), [`IRC_125`](42_Paris_2023/Cursus_2023/Projects/Common_core/IRC_125/), [`Inception_100`](42_Paris_2023/Cursus_2023/Projects/Common_core/Inception_100/) |
| **Collaboration et web** | [`42_collaborative_resume_100`](42_Paris_2023/Cursus_2023/Projects/Common_core/42_collaborative_resume_100/), [`ft_transcendence_125`](42_Paris_2023/Cursus_2023/Projects/Common_core/ft_transcendence_125/) |

Pour parcourir tous les dossiers, consulte le [guide de navigation 2023](.assets/docs/REPOSITORY_GUIDE.md#2023-curriculum).

---

<a id="journey-2017"></a>

## Le parcours de 2017

<p align="center"><a href="42_Paris_2017/"><img src=".assets/images/42_Paris_2017_title_banner.png" alt="Section 42 Paris 2017" width="600"></a></p>

Mon premier chapitre à 42 : une archive de mes débuts en **programmation C et fondamentaux Unix**, avec les exercices intensifs de la Piscine et mes premiers projets du cursus. Ces ressources témoignent du début de mon parcours.

| Domaine | Contenu |
| :--- | :--- |
| **[Piscine C 2017](42_Paris_2017/Piscine_C_2017/)** | Exercices quotidiens, pratique du C et sujets |
| **[Cursus 2017](42_Paris_2017/Cursus_2017/)** | `libft`, `get_next_line`, `ft_printf`, `fillit`, `fdf`, `fract_ol`, `docker-1`, `init`, `piscine_reloaded` et autres premiers travaux |

La section 2017 constitue avant tout une **archive historique**. Son contenu, ses conventions et ses dépendances peuvent différer de ceux du cursus plus récent.

---

## Projets personnels et outils

<p align="center"><a href="Others/"><img src=".assets/images/Others_title_banner.png" alt="Others : projets personnels, ressources et outils" width="600"></a></p>

Le dossier [`Others/`](Others/) regroupe mes travaux en dehors des exigences formelles du cursus : ressources complémentaires, scripts, expérimentations et utilitaires pratiques.

| Emplacement | Fonction |
| :--- | :--- |
| [`École_42/`](Others/%C3%89cole_42/) | Ressources scolaires complémentaires, exercices et documentation de référence |
| [`Perso/GC/`](Others/Perso/GC/) | Outils Git personnels et configuration du shell |
| [`Perso/`](Others/Perso/) | Autres éléments de mon espace de travail personnel |

**Remarque :** il s'agit d'archives de projets personnels ; leur documentation, leur maintenance et leur visibilité peuvent varier d'un dossier à l'autre.

---

<a id="git-workflow"></a>

## Travailler avec ce dépôt

### Cloner tous les sous-modules imbriqués

Le dépôt contient des **sous-modules Git imbriqués**. Un simple `git clone` ne récupère pas nécessairement leur contenu.

**Git standard** — fonctionne avec Bash, Zsh et d'autres shells :

```bash
git clone --recurse-submodules git@github.com:Mechard-Organization/42_Paris.git
cd 42_Paris
```

Le dépôt est déjà cloné, mais sans ses sous-modules ?

```bash
git submodule update --init --recursive
```

**Configuration Zsh personnelle** — lorsque mon wrapper personnalisé est installé, la commande exacte ci-dessous active aussi le clonage récursif et l'alignement automatique des branches :

```bash
git clone git@github.com:Mechard-Organization/42_Paris.git
```

Ce comportement spécial **ne fait pas partie de Git**. Sans le wrapper Zsh, utilise la commande standard de clonage récursif ci-dessus.

### Branches et commits

Mon wrapper aligne la racine sur `main_42_Paris`, puis utilise `main_sub` dans les sous-modules lorsqu'elle existe, sinon `main`. Comme Git extrait normalement les sous-modules aux **commits enregistrés**, cet alignement et les commits suivants peuvent modifier les pointeurs des sous-modules dans les dépôts parents (*gitlinks*).

Lorsque le wrapper est activé, le workflow de publication est le suivant :

```bash
git add -A
git commit -m "Décrire les modifications"
git push
```

Le wrapper parcourt les dépôts imbriqués, crée les commits nécessaires **des enfants vers les parents**, puis pousse uniquement les dépôts ayant des commits locaux à publier. Après chaque tentative de push, un nouveau cycle `add → commit` est obligatoire.

> **Vérifie avant de committer.** Avec le wrapper, `git add -A` agit sur **tous les dépôts initialisés** de cet espace de travail, même lorsqu'il est lancé depuis un dossier imbriqué. Vérifie `git status` ou `git diff --cached` dans les dépôts concernés, surtout si tu travailles avec des fichiers personnels. Ne versionne pas de mots de passe ni d'autres secrets.

Pour les commandes détaillées, les précautions de sécurité, les exemples et l'emplacement des logs, consulte le **[guide Git et wrapper](.assets/docs/GIT_WORKFLOW.md)**.

---

## Documentation et ressources

Toutes les ressources utilisées par **ces README** sont regroupées dans [`.assets/`](.assets/) à la racine : **images, documents Markdown/textuels complémentaires et exports des arborescences**. Les README ne dépendent d'aucun service externe d'images ou de badges.

| Ressource | Emplacement |
| :--- | :--- |
| Guide du dépôt et workflow Git | [`.assets/docs/`](.assets/docs/) |
| Bannières, illustration de profil et autres images | [`.assets/images/`](.assets/images/) |
| Arborescences textuelles existantes | [`.assets/text/`](.assets/text/) |
| Instantanés Markdown des arborescences | [`.assets/tree/`](.assets/tree/) |
| Organisation et maintenance des ressources | [`.assets/docs/ASSETS.md`](.assets/docs/ASSETS.md) |

Les dossiers imbriqués conservent leurs propres README, fichiers source et ressources spécifiques. `.assets/` centralise le **contenu complémentaire des README racine** ; elle ne déplace pas le code source et ne modifie pas les sous-modules indépendants.

---

<div align="center">

<img src=".assets/images/mechard_round.png" alt="Illustration du profil de Maxime Echard" width="96">

**Maxime Echard** · 42 Paris

*Apprendre en construisant, en se trompant, en comprenant et en recommençant.*

[Retour en haut ↑](#top)

</div>
