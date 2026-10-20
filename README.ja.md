<p align="center">
  🌐 <strong>言語：</strong>
  <a href="./README.md">🇬🇧 English</a> &nbsp;·&nbsp;
  <a href="./README.fr.md">🇫🇷 Français</a> &nbsp;·&nbsp;
  <strong>🇯🇵 日本語</strong>
</p>

<a id="top"></a>

<div align="center">

<a href="https://github.com/Mechard-Organization/42_Paris">
  <img src=".assets/images/42_Paris_title_banner.png" alt="42 Paris — プログラミング、プロジェクト、継続的な学習" width="820">
</a>

# 42 Paris · プロジェクトと学習の記録

**42 Parisでの2つの学習期間。その中で成長し続けるコード、実験、ツールのコレクション。**

**2017年のPiscine**から**2023年に始めたカリキュラム**まで、学習プロジェクト、技術的な実験、それらを管理するためのツールをまとめています。

**[リポジトリを探索](#explore)** · **[2023年のプロジェクト](#journey-2023)** · **[2017年のアーカイブ](#journey-2017)** · **[Gitワークフロー](#git-workflow)**

<sub>管理者：<strong>Maxime Echard</strong> · École 42 Paris</sub>

</div>

---

## はじめに

`42_Paris`は、**École 42 Paris**で取り組んだプロジェクトや学習資料を集めた中心的なワークスペースです。**2017年**の最初の学習期間、**2023年**に開始した新たなカリキュラム、そして並行して開発した個人プロジェクトやユーティリティが含まれています。

このリポジトリは、1つの巨大なアプリケーションではなく、**ネストされたGitサブモジュールでつながる複数のリポジトリ**で構成されています。それぞれのプロジェクトは、ソースコード、履歴、必要に応じてドキュメントを独立して保持しています。

> **節目：** **2026年2月26日に2023年カリキュラムのCommon Core（共通課程）を修了**しました。このリポジトリには過去の作品、実験、Common Core修了後のプロジェクトも含まれています。プロジェクトが存在することは、その評価・合格状況を保証するものではありません。

<a id="explore"></a>

## リポジトリを探索

<table>
<tr>
  <td align="center" width="33%">
    <a href="42_Paris_2017/"><img src=".assets/images/42_Paris_2017_title_banner.png" alt="2017年の学習記録を見る" width="250"></a>
    <br><strong><a href="42_Paris_2017/">42 Paris · 2017</a></strong>
    <br><sub>C Piscine、プログラミングの第一歩、初期の課題。</sub>
  </td>
  <td align="center" width="33%">
    <a href="42_Paris_2023/"><img src=".assets/images/42_Paris_2023_title_banner.png" alt="2023年の学習記録を見る" width="250"></a>
    <br><strong><a href="42_Paris_2023/">42 Paris · 2023</a></strong>
    <br><sub>Piscine、Common Core、その後の課題、学生生活。</sub>
  </td>
  <td align="center" width="33%">
    <a href="Others/"><img src=".assets/images/Others_title_banner.png" alt="個人プロジェクトとツールを見る" width="250"></a>
    <br><strong><a href="Others/">Others</a></strong>
    <br><sub>自主学習、実験、メモ、Gitユーティリティ。</sub>
  </td>
</tr>
</table>

### ディレクトリ構成

```text
42_Paris/
├── 42_Paris_2017/
│   ├── Piscine_C_2017/          # 2017年Piscineの演習と課題
│   └── Cursus_2017/            # 初期のプロジェクトと学習資料
├── 42_Paris_2023/
│   ├── Piscine_C_2023/          # CとShellのPiscine演習
│   ├── Cursus_2023/
│   │   └── Projects/
│   │       ├── Common_core/     # 共通課程とネストされたリポジトリ
│   │       ├── Post_CC/         # Common Core修了後の作品
│   │       └── Tools/           # 補助ツールとユーティリティ
│   └── Association_2023/       # 学生団体の資料
├── Others/
│   ├── École_42/                # 個人用の学校関連資料
│   └── Perso/GC/               # カスタムGitツール
└── .assets/
    ├── docs/                    # 補足ドキュメント
    ├── images/                  # READMEで使用する画像
    ├── text/                    # ディレクトリツリーのテキスト出力
    └── tree/                    # 詳細なディレクトリツリーの記録
```

この図はすべての演習やサブリポジトリを列挙したものではなく、**主要な入口**を示しています。詳細は[ディレクトリガイド](.assets/docs/REPOSITORY_GUIDE.md)とツリー一覧から確認できます：[2017](.assets/tree/42_Paris_2017.md) · [2023](.assets/tree/42_Paris_2023.md) · [Others](.assets/tree/Others.md)。

---

<a id="journey-2023"></a>

## 2023年からの学習

<p align="center"><a href="42_Paris_2023/"><img src=".assets/images/42_Paris_2023_title_banner.png" alt="42 Paris 2023セクション" width="600"></a></p>

2023年のセクションでは、学校のカリキュラムに戻ってからの学習を記録しています。**Piscine**、**Common Core**のプロジェクト、その後の活動、学生団体への参加などが含まれます。

| 分野 | 内容 | リンク |
| :--- | :--- | :--- |
| **C Piscine** | Shell演習、Cモジュール、Rush課題 | [Piscine_C_2023](42_Paris_2023/Piscine_C_2023/) |
| **Common Core** | プログラミングの基礎、アルゴリズム、システム、ネットワーク、チーム開発 | [Common_core](42_Paris_2023/Cursus_2023/Projects/Common_core/) |
| **Post–Common Core** | 共通課程修了後の追加・発展的なプロジェクト | [Post_CC](42_Paris_2023/Cursus_2023/Projects/Post_CC/) |
| **ツール** | 再利用可能なユーティリティや開発支援ツール | [Tools](42_Paris_2023/Cursus_2023/Projects/Tools/) |
| **学生団体** | BDEとBlackoutの関連資料 | [Association_2023](42_Paris_2023/Association_2023/) |

### Common Coreの主なプロジェクト

以下は提供されたリポジトリのスナップショットに存在するプロジェクトとフォルダです。名称は元のリポジトリ構成に従っています。

| 分野 | プロジェクト |
| :--- | :--- |
| **C言語の基礎・入出力** | [`libft_125`](42_Paris_2023/Cursus_2023/Projects/Common_core/libft_125/)、[`ft_printf_110`](42_Paris_2023/Cursus_2023/Projects/Common_core/ft_printf_110/)、[`get_next_line_112`](42_Paris_2023/Cursus_2023/Projects/Common_core/get_next_line_112/) |
| **アルゴリズム・プロセス管理** | [`push_swap_100`](42_Paris_2023/Cursus_2023/Projects/Common_core/push_swap_100/)、[`pipex_115`](42_Paris_2023/Cursus_2023/Projects/Common_core/pipex_115/)、[`philo_100`](42_Paris_2023/Cursus_2023/Projects/Common_core/philo_100/)、[`minishell_101`](42_Paris_2023/Cursus_2023/Projects/Common_core/minishell_101/) |
| **グラフィックス** | [`So_long_96`](42_Paris_2023/Cursus_2023/Projects/Common_core/So_long_96/)、[`Cub3D_105`](42_Paris_2023/Cursus_2023/Projects/Common_core/Cub3D_105/) |
| **C++** | [`Cpp`](42_Paris_2023/Cursus_2023/Projects/Common_core/Cpp/) — アーカイブに収録されている`cpp00_80`から`cpp09_100`までのモジュール |
| **システム・ネットワーク** | [`Born2beroot_125`](42_Paris_2023/Cursus_2023/Projects/Common_core/Born2beroot_125/)、[`Netpractice_100`](42_Paris_2023/Cursus_2023/Projects/Common_core/Netpractice_100/)、[`IRC_125`](42_Paris_2023/Cursus_2023/Projects/Common_core/IRC_125/)、[`Inception_100`](42_Paris_2023/Cursus_2023/Projects/Common_core/Inception_100/) |
| **共同開発・Web** | [`42_collaborative_resume_100`](42_Paris_2023/Cursus_2023/Projects/Common_core/42_collaborative_resume_100/)、[`ft_transcendence_125`](42_Paris_2023/Cursus_2023/Projects/Common_core/ft_transcendence_125/) |

フォルダ単位で確認するには、[2023年のナビゲーションガイド](.assets/docs/REPOSITORY_GUIDE.md#2023-curriculum)をご覧ください。

---

<a id="journey-2017"></a>

## 2017年の学習

<p align="center"><a href="42_Paris_2017/"><img src=".assets/images/42_Paris_2017_title_banner.png" alt="42 Paris 2017セクション" width="600"></a></p>

42での最初の期間を記録したアーカイブです。**C言語とUnixの基礎**、集中的なPiscine演習、カリキュラム初期のプロジェクトが中心です。学習の出発点を振り返るために保存しています。

| 分野 | 内容 |
| :--- | :--- |
| **[2017年 C Piscine](42_Paris_2017/Piscine_C_2017/)** | 日々の演習、C言語の練習、課題資料 |
| **[2017年 Cursus](42_Paris_2017/Cursus_2017/)** | `libft`、`get_next_line`、`ft_printf`、`fillit`、`fdf`、`fract_ol`、`docker-1`、`init`、`piscine_reloaded`などの初期の作品 |

2017年のセクションは主に**過去の学習記録**です。コードの慣習や依存関係は、その後のカリキュラムとは異なる場合があります。

---

## 個人プロジェクトとツール

<p align="center"><a href="Others/"><img src=".assets/images/Others_title_banner.png" alt="Others：個人プロジェクト、資料、ツール" width="600"></a></p>

[`Others/`](Others/)には、カリキュラムの必須課題とは別に取り組んだ学習資料、スクリプト、実験、実用的なユーティリティをまとめています。

| 場所 | 用途 |
| :--- | :--- |
| [`École_42/`](Others/%C3%89cole_42/) | 学校関連の追加資料、演習、参考資料 |
| [`Perso/GC/`](Others/Perso/GC/) | 個人用Gitヘルパーとシェル設定 |
| [`Perso/`](Others/Perso/) | その他の個人用ワークスペース |

**注記：** 個人プロジェクトのアーカイブのため、ドキュメントの充実度、メンテナンス状況、公開範囲はフォルダによって異なります。

---

<a id="git-workflow"></a>

## このリポジトリの使い方

### ネストされたサブモジュールをすべてクローンする

このリポジトリには**ネストされたGitサブモジュール**が含まれます。通常の`git clone`だけでは、すべての作業ツリーを取得できない場合があります。

**標準のGit** — Bash、Zshなどのシェルで利用できます。

```bash
git clone --recurse-submodules git@github.com:Mechard-Organization/42_Paris.git
cd 42_Paris
```

サブモジュールなしでクローン済みの場合：

```bash
git submodule update --init --recursive
```

**個人用Zsh設定** — このワークスペースのカスタムラッパーをインストールしている場合、次のコマンドで再帰的クローンとブランチの自動調整も実行できます。

```bash
git clone git@github.com:Mechard-Organization/42_Paris.git
```

これは**Git本体の標準機能ではありません**。Zshラッパーを使用しない場合は、上記の標準的な再帰クローンを実行してください。

### ブランチとコミット

個人用ラッパーは、ルートリポジトリを`main_42_Paris`に、サブモジュールを`main_sub`（存在しない場合は`main`）に合わせます。通常、Gitサブモジュールは**親リポジトリに記録されたコミット**をチェックアウトするため、ブランチの調整や新しいコミットによって、親に記録されるサブモジュール参照（*gitlink*）が更新されることがあります。

ラッパーが有効な場合の公開手順：

```bash
git add -A
git commit -m "変更内容を記述"
git push
```

ラッパーはネストされたリポジトリを巡回し、必要なコミットを**子から親の順番**で作成します。その後、公開待ちのローカルコミットがあるリポジトリだけをpushします。pushを試みるたびに、次回は新たな`add → commit`サイクルが必要です。

> **コミット前に内容を確認してください。** カスタム`git add -A`は、ネストされたディレクトリから実行した場合でも、このワークスペース内の**初期化済みの全リポジトリ**を対象にします。特に個人用ファイルがある場合は、関連するリポジトリで`git status`や`git diff --cached`を確認してください。認証情報や秘密情報をコミットしないでください。

コマンド一覧、安全上の注意、使用例、ログの場所は**[Gitワークフローとラッパーのガイド](.assets/docs/GIT_WORKFLOW.md)**に記載しています。

---

## ドキュメントとアセット

**このREADME群**で使用する補助リソースは、ルートの[`.assets/`](.assets/)にまとめています。**画像、補足のMarkdown・テキスト資料、既存のディレクトリツリー出力**が含まれます。外部の画像・バッジ配信サービスには依存していません。

| リソース | 場所 |
| :--- | :--- |
| リポジトリガイドとGitワークフロー | [`.assets/docs/`](.assets/docs/) |
| バナー、プロフィール画像、その他の画像 | [`.assets/images/`](.assets/images/) |
| 既存のテキスト形式のディレクトリツリー | [`.assets/text/`](.assets/text/) |
| 既存のMarkdown形式のツリー記録 | [`.assets/tree/`](.assets/tree/) |
| アセットの整理・管理について | [`.assets/docs/ASSETS.md`](.assets/docs/ASSETS.md) |

下位のフォルダには、それぞれ独自のREADME、ソースファイル、プロジェクト固有のリソースがあります。`.assets/`は**ルートREADMEを支える補助資料**を集約する場所であり、ソースコードの移動や独立したサブモジュールの変更は行いません。

---

<div align="center">

<img src=".assets/images/mechard_round.png" alt="Maxime Echardのプロフィール画像" width="96">

**Maxime Echard** · 42 Paris

*作って、失敗して、理解して、また作る。その繰り返しから学んでいく。*

[ページの先頭へ ↑](#top)

</div>
