<p align="center">
  <a href="./README.md">🇬🇧 English</a> &nbsp;·&nbsp;
  <a href="./README.fr.md">🇫🇷 Français</a> &nbsp;·&nbsp;
  <strong>🇯🇵 日本語</strong>
</p>

<a id="top"></a>

<p align="center">
  <img src="../.assets/images/42_paris_banner_2023.png" alt="42 Paris 2023 — Piscine、Common Core、学生生活" width="100%">
</p>

<h1 align="center">42 Paris · 2023年のPiscine、カリキュラム、学生団体</h1>

<p align="center">
  <strong>42 Parisでの学びのうち、2023年から始まった歩みをまとめています。</strong><br>
  <strong>Piscine</strong>から<strong>Common Core</strong>、その後の発展的な課題、開発ツール、学生団体での活動までを紹介します。
</p>

<p align="center">
  <a href="#overview">概要</a> ·
  <a href="#structure">構成</a> ·
  <a href="#projects">プロジェクト</a> ·
  <a href="#git-workflow">Gitワークフロー</a> ·
  <a href="#documentation">ドキュメント</a>
</p>

---

<a id="overview"></a>
## ✨ 概要

`42_Paris_2023/` は、[親リポジトリ `42_Paris`](../README.ja.md) の中にある**2023年の活動をまとめたディレクトリ**です。Piscine、カリキュラム、学生団体の記録を**3つの直接サブモジュール**で管理しています。カリキュラムの内部にはさらにサブモジュールがあり、それぞれが独立したGit履歴を持ちます。

<table>
<tr>
<td align="center" width="33%">
  <a href="#piscine"><strong>🏊 Piscine_C_2023</strong></a><br><br>
  <sub>Shell演習、C言語の課題、rushを通じた2023年の基礎学習。</sub>
</td>
<td align="center" width="33%">
  <a href="#cursus"><strong>🚀 Cursus_2023</strong></a><br><br>
  <sub>Common Core、修了後のプロジェクト、再利用可能な開発ツール。</sub>
</td>
<td align="center" width="33%">
  <a href="#associations"><strong>🤝 Association_2023</strong></a><br><br>
  <sub>学生の取り組み、BDE、Blackoutの活動資料。</sub>
</td>
</tr>
</table>

- 🎓 **学校：** 42 Paris
- 🏁 **節目：** 2023年のCommon Coreを**2026年2月26日**に修了
- 🧩 **構成：** 3つの直接サブモジュールと、`Cursus_2023` 内の再帰的なサブモジュール
- 🌍 **言語：** 英語・フランス語・日本語
- 🔐 **アクセス：** 親リポジトリは公開されていますが、一部の子リポジトリは非公開で、閲覧権限が必要です

---

<a id="structure"></a>
## 🧭 ディレクトリ構成

次のツリーは**主な構成を把握するための概要**です。すべてのファイルを列挙したものではありません。ディレクトリ名は現在のGitパスに合わせています。

```text
42_Paris_2023/
├── Association_2023/                    # Gitサブモジュール
│   ├── BDE/
│   └── Blackout/
├── Piscine_C_2023/                      # Gitサブモジュール
│   ├── Shell_00/
│   ├── Shell_01/
│   ├── C_00/ ... C_09/
│   ├── C_11/
│   └── Rush/
├── Cursus_2023/                         # Gitサブモジュール
│   ├── Common_Core/                     # Gitサブモジュール（16プロジェクト）
│   │   ├── Cpp/                         # Gitサブモジュール（cpp00〜cpp09）
│   │   └── ...                          # その他のCommon Core課題
│   ├── Post_Common_Core/               # Gitサブモジュール
│   │   ├── Realeased/
│   │   │   └── Internship_I_119/        # Gitサブモジュール
│   │   └── Unrealeased/
│   │       ├── Darkly/                  # Gitサブモジュール
│   │       ├── libasm/                  # Gitサブモジュール
│   │       └── snow-crash/              # Gitサブモジュール
│   └── Tools/
│       ├── Complete_libft ✅/           # Gitサブモジュール
│       └── Makefile_standard
├── README.md
├── README.fr.md
└── README.ja.md
```

> `42_Paris_2023/` は親リポジトリ内のディレクトリであり、**独立したGitリポジトリではありません**。直下の3つのディレクトリがサブモジュールです。Gitが記録するのはそれぞれの**特定のコミット**であり、`.gitmodules` でブランチを指定しても参照先が自動的に更新されるわけではありません。

> `Realeased` と `Unrealeased` は、実際のパスに合わせて意図的にそのまま表記しています。Piscineには `C_11` がありますが、`C_10` ディレクトリはありません。

---

<a id="projects"></a>
## 🧪 プロジェクトと活動

<a id="piscine"></a>
### 🏊 Piscine C / Shell — 2023

2023年のPiscineには、**ShellとC言語の基礎演習**、共同課題（rush）が含まれます。内容は別のリポジトリに保存されており、閲覧に権限が必要な場合があります。

| 分野 | 内容 | リンク |
| :--- | :--- | :--- |
| **Shell** | `Shell_00`、`Shell_01` | [`Piscine_C_2023`](https://github.com/Mechard-Organization/Piscine_C_2023/tree/main_sub) |
| **C言語の課題** | `C_00`〜`C_09` と `C_11` | [C言語の各課題](https://github.com/Mechard-Organization/Piscine_C_2023/tree/main_sub) |
| **Rush** | `Rush/` 内の制限時間付き共同課題 | [Rushディレクトリ](https://github.com/Mechard-Organization/Piscine_C_2023/tree/main_sub/Rush) |

<a id="cursus"></a>
### 🚀 Cursus 2023

[`Cursus_2023`](https://github.com/Mechard-Organization/Cursus_2023/tree/main_sub) はカリキュラムの中心となるリポジトリです。**Common_Core**、**Post_Common_Core**、**Tools** の3つの領域で構成され、内部にはネストされたGitサブモジュールがあります。

<a id="common-core"></a>
#### 🧱 Common Core

**Common Core**では、C、C++、アルゴリズム、Unixシステム、グラフィックス、ネットワーク、共同開発を学びます。[`Common_core`](https://github.com/Mechard-Organization/Common_core/tree/main) には**16個のプロジェクト用サブモジュール**があります。

| 分野 | プロジェクトのディレクトリ |
| :--- | :--- |
| **C言語の基礎** | `libft_125`、`ft_printf_110`、`get_next_line_112` |
| **アルゴリズム・プロセス・シェル** | `push_swap_100`、`pipex_115`、`philo_100`、`minishell_101` |
| **グラフィックス** | `So_long_96`、`Cub3D_105` |
| **C++** | `Cpp` → `cpp00_80`〜`cpp09_100`（`Cpp` 内にネスト） |
| **システム・ネットワーク** | `Born2beroot_125`、`Netpractice_105`、`IRC_125`、`Inception_100` |
| **Web・共同開発** | `42_collaborative_resume_100`、`ft_transcendence_125` |

**個人的な節目：** 2023年のCommon Coreは**2026年2月26日**に修了しました。フォルダ名に含まれるスコアは、リポジトリの命名規則の一部として残しています。

<a id="post-common-core"></a>
#### 🔭 Post–Common Core

非公開の [`Post_common_core`](https://github.com/Mechard-Organization/Post_common_core/tree/main) には、Common Core修了後の課題とインターンシップ関連の資料がまとめられています。

| ディレクトリ | Gitサブモジュール |
| :--- | :--- |
| [`Realeased/`](https://github.com/Mechard-Organization/Post_common_core/tree/main/Realeased) | `Internship_I_119` |
| [`Unrealeased/`](https://github.com/Mechard-Organization/Post_common_core/tree/main/Unrealeased) | `Darkly`、`libasm`、`snow-crash` |

これらはリポジトリの**配置を示す名前**であり、すべてのプロジェクトが評価済み、または一般公開されているという意味ではありません。

#### 🛠️ 開発ツール

現在の `Tools/` には、次の項目があります。

- **[`Complete_libft ✅`](https://github.com/Mechard-Organization/Complete_Libft-/tree/main)** — 独立したコミット履歴を持つ、非公開リポジトリの正式なGitサブモジュール。
- **`Makefile_standard`** — [`Cursus_2023`](https://github.com/Mechard-Organization/Cursus_2023/tree/main_sub/Tools) の `Tools/` 内で管理されるファイル。

<a id="associations"></a>
### 🤝 学生団体

[`Association_2023`](https://github.com/Mechard-Organization/Associations/tree/main_sub) には、非公開リポジトリとして学生生活に関する資料が保存されています。

| 分野 | 内容 |
| :--- | :--- |
| **`BDE/`** | 学生会に関する資料 |
| **`Blackout/`** | 運営、広報、画像素材などに分類された団体資料 |

---

<a id="git-workflow"></a>
## 🔀 Gitワークフロー

<p align="center"><img src="../.assets/images/42_paris_banner_git_workflow.png" alt="Gitサブモジュールの運用 — 42 Paris" width="100%"></p>

### 全体を再帰的にクローンする

`42_Paris_2023/` は親リポジトリの一部なので、親リポジトリを**再帰的に**クローンします。

```bash
git clone --recurse-submodules git@github.com:Mechard-Organization/42_Paris.git
cd 42_Paris/42_Paris_2023
```

非公開の子リポジトリを取得するにはSSHアクセス権が必要です。権限がない場合、公開されている親リポジトリはクローンできますが、一部のサブモジュールの取得に失敗します。

### 既存のクローンを同期する

**`42_Paris` のルートディレクトリ**で実行します。

```bash
git submodule sync --recursive
git submodule update --init --recursive
git submodule status --recursive
```

### サブモジュールの参照先を更新する

親リポジトリが記録しているのは、リアルタイムで追従するブランチではなく、**特定のコミット**です。直接サブモジュールを設定済みブランチの最新コミットに進める場合は、`42_Paris` のルートで実行します。

```bash
git submodule update --remote -- 42_Paris_2023/Cursus_2023
git add 42_Paris_2023/Cursus_2023
git commit -m "chore: update Cursus_2023 submodule"
```

**ネストされた**サブモジュールを変更したときは、まず直近の親リポジトリに新しい参照をコミットし、その上位の親へ順に反映して、最後に `42_Paris` まで更新します。

📘 [カスタムGitワークフローのガイド](../.assets/docs/GIT_WORKFLOW.md)

---

<a id="documentation"></a>
## 🗂️ ドキュメントとナビゲーション

<p align="center"><img src="../.assets/images/42_paris_banner_repository_guide.png" alt="42 Parisのリポジトリガイド" width="100%"></p>

画像や共通ガイドは、親リポジトリの `.assets/` ディレクトリで一元管理しています。

| リソース | リンク |
| :--- | :--- |
| 親リポジトリの概要 | [42_Paris](../README.ja.md) |
| このページの英語版 | [README.md](./README.md) |
| このページのフランス語版 | [README.fr.md](./README.fr.md) |
| リポジトリガイド | [REPOSITORY_GUIDE.md](../.assets/docs/REPOSITORY_GUIDE.md) |
| Gitワークフローガイド | [GIT_WORKFLOW.md](../.assets/docs/GIT_WORKFLOW.md) |
| 画像・ビジュアル素材 | [`.assets/images/`](../.assets/images/) |

---

## 💡 このディレクトリの目的

このページは、PiscineからCommon Core、そしてその先へと続く**42 Parisでの2023年からの学習記録を探すための案内図**です。詳細な技術情報、コミット履歴、評価に関する情報は、それぞれの子リポジトリを参照してください。

<p align="center"><a href="#top">⬆️ トップへ戻る</a></p>
