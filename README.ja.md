<p align="center">
  <a href="./README.md">🇬🇧 English</a> &nbsp;·&nbsp;
  <a href="./README.fr.md">🇫🇷 Français</a> &nbsp;·&nbsp;
  <strong>🇯🇵 日本語</strong>
</p>

<a id="top"></a>

<p align="center">
  <img src=".assets/images/42_paris_banner_main.png" alt="42 Paris — プロジェクト、アーカイブ、実験" width="100%">
</p>

<h1 align="center">42 Paris · プロジェクト、アーカイブ、実験集</h1>

<p align="center">
  <strong>42 Parisでの学習成果を、Gitリポジトリのネットワークとして整理しています。</strong><br>
  <strong>2017年の基礎学習</strong>から<strong>2023年のCommon Core</strong>、その後のプロジェクト、個人ツール、独自のGitワークフローまでをまとめた場所です。
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

`42_Paris` は単一のアプリケーションではなく、**複数のリポジトリを結ぶナビゲーションハブ**です。**42 Paris**で取り組んだ課題やツールを、複数階層にわたるGitサブモジュールで管理しています。各子リポジトリには独立した履歴とGit設定があります。

<table>
<tr>
<td align="center" width="33%">
  <a href="https://github.com/Mechard-Organization/42_Paris_2017/tree/main_sub"><img src=".assets/images/42_paris_banner_2017.png" alt="42 Paris 2017" width="100%"></a>
  <br><br><strong>🧱 42_Paris_2017</strong><br>
  <sub>2017年のPiscine、初期のC言語課題、カリキュラムの記録。</sub>
</td>
<td align="center" width="33%">
  <a href="42_Paris_2023/"><img src=".assets/images/42_paris_banner_2023.png" alt="42 Paris 2023" width="100%"></a>
  <br><br><strong>🚀 42_Paris_2023</strong><br>
  <sub>2023年のPiscine、Common Core、発展的な課題、学生団体。</sub>
</td>
<td align="center" width="33%">
  <a href="https://github.com/Mechard-Organization/Others/tree/main_sub"><img src=".assets/images/42_paris_banner_others.png" alt="Others" width="100%"></a>
  <br><br><strong>🛠️ Others</strong><br>
  <sub>学校関連の資料、シェルツール、個人プロジェクト。</sub>
</td>
</tr>
</table>

- 🎓 **学校：** 42 Paris
- 🏁 **節目：** 2023年のCommon Coreを**2026年2月26日**に修了
- 🧩 **構成：** 再帰的な依存関係を含むGitサブモジュール
- 🌍 **言語：** 英語・フランス語・日本語
- 🔐 **アクセス：** 親リポジトリは公開されていますが、一部の子リポジトリは非公開です。内容の閲覧には権限が必要です

---

<a id="structure"></a>
## 🧭 リポジトリの構成

以下は主要なディレクトリの概要です。すべてのファイルや課題を網羅するものではありません。

```text
42_Paris/
├── 42_Paris_2017/                         # Gitサブモジュール
│   ├── Piscine_C_2017/
│   └── Cursus_2017/
├── 42_Paris_2023/
│   ├── Association_2023/                 # Gitサブモジュール
│   │   ├── BDE/
│   │   └── Blackout/
│   ├── Piscine_C_2023/                   # Gitサブモジュール
│   └── Cursus_2023/                     # Gitサブモジュール
│       ├── Common_Core/                 # Gitサブモジュール
│       │   ├── Cpp/                     # Gitサブモジュール (cpp00〜cpp09)
│       │   └── ...                      # その他のCommon Core課題
│       ├── Post_Common_Core/            # Gitサブモジュール
│       │   ├── Realeased/
│       │   │   └── Internship_I_119/    # Gitサブモジュール
│       │   └── Unrealeased/
│       │       ├── Darkly/              # Gitサブモジュール
│       │       ├── libasm/              # Gitサブモジュール
│       │       └── snow-crash/          # Gitサブモジュール
│       └── Tools/
│           └── Complete_libft ✅/       # Gitサブモジュール
├── Others/                                # Gitサブモジュール
│   ├── École_42/                         # Gitサブモジュール
│   └── Perso/
│       ├── GC/
│       └── GS/
├── .assets/                               # README用の画像とガイド
│   ├── docs/
│   ├── images/
│   ├── text/
│   └── tree/
├── .gitmodules
├── README.md
├── README.fr.md
└── README.ja.md
```

> `Realeased` と `Unrealeased` は**実際のGitパスの表記**をそのまま使用しています。サブモジュールは特定のコミットを参照しており、ブランチの最新コミットに自動的に追従するわけではありません。

詳細なディレクトリ一覧：[2017](.assets/tree/42_Paris_2017.md) · [2023](.assets/tree/42_Paris_2023.md) · [Others](.assets/tree/Others.md)。これらは記録用のスナップショットであり、最新のコミットと異なる場合があります。

---

<a id="projects"></a>
## 🧱 42_Paris_2017

<p align="center"><img src=".assets/images/42_paris_banner_2017.png" alt="42 Paris 2017 バナー" width="100%"></p>

42での最初の学習を保存したアーカイブです。**2017年のPiscine**、初期のC言語課題、Unixの基礎を含みます。

| 分野 | 内容 |
| :--- | :--- |
| [`Piscine_C_2017`](https://github.com/Mechard-Organization/42_Paris_2017/tree/main_sub/Piscine_C_2017) | 日々の演習とrush |
| [`Cursus_2017`](https://github.com/Mechard-Organization/42_Paris_2017/tree/main_sub/Cursus_2017) | `libft`、`get_next_line`、`ft_printf`、`fillit`、`fdf`などの初期課題 |

## 🚀 42_Paris_2023

<p align="center"><img src=".assets/images/42_paris_banner_2023.png" alt="42 Paris 2023 バナー" width="100%"></p>

2023年のカリキュラムにはPiscine、**Common Core**、Post–Common Coreの課題、学生団体の活動が含まれます。

| 分野 | 内容 | リポジトリ |
| :--- | :--- | :--- |
| **Piscine C / Shell** | Shell演習、C言語モジュール、rush | [`Piscine_C_2023`](https://github.com/Mechard-Organization/Piscine_C_2023/tree/main_sub) |
| **Common Core** | C、C++、プロセス、グラフィックス、ネットワーク、共同開発 | [`Common_core`](https://github.com/Mechard-Organization/Common_core/tree/main) |
| **Post–Common Core** | 発展的な課題とインターンシップの記録 | [`Post_common_core`](https://github.com/Mechard-Organization/Post_common_core/tree/main) |
| **Tools** | 再利用可能な開発ツール | [`Cursus_2023/Tools`](42_Paris_2023/Cursus_2023/Tools/) |
| **学生団体** | `BDE` と `Blackout` | [`Association_2023`](42_Paris_2023/Association_2023/) |

### Common Coreの主な課題分野

| 分野 | プロジェクト |
| :--- | :--- |
| **C言語の基礎** | `libft_125`、`ft_printf_110`、`get_next_line_112` |
| **アルゴリズム・プロセス** | `push_swap_100`、`pipex_115`、`philo_100`、`minishell_101` |
| **グラフィックス** | `So_long_96`、`Cub3D_105` |
| **C++** | `Cpp` → `cpp00_80` から `cpp09_100` |
| **システム・ネットワーク** | `Born2beroot_125`、`Netpractice_105`、`IRC_125`、`Inception_100` |
| **Web・共同開発** | `42_collaborative_resume_100`、`ft_transcendence_125` |

### Post–Common Core

| ディレクトリ | プロジェクト |
| :--- | :--- |
| [`Realeased/`](42_Paris_2023/Cursus_2023/Post_Common_Core/Realeased/) | [`Internship_I_119`](42_Paris_2023/Cursus_2023/Post_Common_Core/Realeased/Internship_I_119/) |
| [`Unrealeased/`](42_Paris_2023/Cursus_2023/Post_Common_Core/Unrealeased/) | [`Darkly`](42_Paris_2023/Cursus_2023/Post_Common_Core/Unrealeased/Darkly/)、[`libasm`](42_Paris_2023/Cursus_2023/Post_Common_Core/Unrealeased/libasm/)、[`snow-crash`](42_Paris_2023/Cursus_2023/Post_Common_Core/Unrealeased/snow-crash/) |

これらのディレクトリ名はリポジトリの構成を示しています。**すべての課題の完了や評価合格を意味するものではありません。**

### 開発ツール

[`Tools/Complete_libft ✅`](42_Paris_2023/Cursus_2023/Tools/Complete_libft%20%E2%9C%85/) は、非公開リポジトリ[`Complete_Libft-`](https://github.com/Mechard-Organization/Complete_Libft-)を参照する**正式なGitサブモジュール**です。`Cursus_2023/Tools/` 配下に配置され、独立したコミット履歴を持ちます。

## 🛠️ Others

<p align="center"><img src=".assets/images/42_paris_banner_others.png" alt="Others バナー" width="100%"></p>

個人ツール、自動化、学校関連の資料、サイドプロジェクトをまとめた作業領域です。

| ディレクトリ | 用途 |
| :--- | :--- |
| `École_42/` | 学校関連の資料（ネストされたサブモジュール） |
| `Perso/GC/` | カスタムGitユーティリティ、シェル補助ツール |
| `Perso/GS/` | その他の個人ツールやスクリプト |

---

<a id="git-workflow"></a>
## 🔀 Gitワークフロー

<p align="center"><img src=".assets/images/42_paris_banner_git_workflow.png" alt="Gitワークフローのバナー" width="100%"></p>

### すべてのリポジトリをクローンする

```bash
git clone --recurse-submodules git@github.com:Mechard-Organization/42_Paris.git
cd 42_Paris
```

再帰的なクローンを完了するには、**非公開の子リポジトリすべてへのSSHアクセス権限**が必要です。権限がない場合、公開された親リポジトリは取得できても、一部のサブモジュールの取得に失敗します。

### サブモジュールの初期化・同期

```bash
git submodule sync --recursive
git submodule update --init --recursive
git submodule status --recursive
```

### サブモジュールの参照コミットを更新する

```bash
# 例：2017年のサブモジュールに設定されたブランチを参照する
git submodule update --remote -- 42_Paris_2017
git add 42_Paris_2017
git commit -m "chore: update 42_Paris_2017 submodule"
git push origin main_42_Paris
```

`git submodule update --init --recursive` は、**親リポジトリに記録されたコミット**をチェックアウトします。ブランチの最新コミットを自動的に使用するわけではありません。参照を更新してコミットする前に、子リポジトリの変更を確認してください。

### 個人用Git自動化

独自の**Zsh Gitラッパー**も使用しています。再帰クローン、ブランチの調整、子から親への順でのコミット、push、ログ出力などを補助します。このラッパーはローカル環境に依存するため、上記のコマンドが一般的なGitの手順です。

📘 [カスタムGitワークフローのドキュメント](.assets/docs/GIT_WORKFLOW.md)

---

<a id="documentation"></a>
## 🗂️ Assetsとドキュメント

<p align="center"><img src=".assets/images/42_paris_banner_repository_guide.png" alt="リポジトリガイドのバナー" width="100%"></p>

READMEで使う画像と補足資料は `.assets/` にまとめています。

| リソース | 場所 |
| :--- | :--- |
| リポジトリガイド | [`.assets/docs/REPOSITORY_GUIDE.md`](.assets/docs/REPOSITORY_GUIDE.md) |
| Gitワークフローガイド | [`.assets/docs/GIT_WORKFLOW.md`](.assets/docs/GIT_WORKFLOW.md) |
| アセットガイド | [`.assets/docs/ASSETS.md`](.assets/docs/ASSETS.md) |
| バナーと画像 | [`.assets/images/`](.assets/images/) |
| ディレクトリ構成の記録 | [`.assets/tree/`](.assets/tree/) |
| テキストエクスポート | [`.assets/text/`](.assets/text/) |

---

## 💡 このリポジトリの目的

このリポジトリは、**技術的な学習記録**、**ネストされたリポジトリへのナビゲーションハブ**、そして**学習と実験を続ける作業領域**として活用しています。ルートのREADMEは全体の概要を示し、各子リポジトリがコードと個別ドキュメントの参照元になります。

<p align="center"><a href="#top">⬆️ トップへ戻る</a></p>
