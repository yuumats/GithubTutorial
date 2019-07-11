# Github Tutorial

## はじめに

これはGithubのチュートリアル資料です。
このチュートリアルはGithubのアカウントが作成してあることが前提です。まだアカウントを作成していない場合は[このサイト](https://qiita.com/okumurakengo/items/848f7177765cf25fcde0)を参考にアカウントを作成してください。

---
## gitの環境構築
まずはローカルPCでgitを使える状態にします。

gitがインストールされているか確認
```
$ git version
git version <gitのバージョン>
```
gitのバージョンが表示されればすでにgitがインストールされています。
gitがインストールされていなければ[ここ](https://git-scm.com/downloads)からインストールしましょう。
インストールが完了したらgitの設定をします。下記のコマンドでgitの自分のユーザを登録しましょう。
```
$ git config --global user.name "<自分のユーザ名>"
```

```
$ git config --global user.email "<自分のメールアドレス>"
```

これでgitが使える状態になりました。

---
## ローカルで作業できるようにする

リモートリポジトリをクローン(ダウンロード)する。
```
$ git clone git@github.com:mnemonic24/GithubTutorial.git
```

もし指定した場所にクローンしたい場合は、下記のコマンドでクローン先のディレクトリを指定してください。
```
$ git clone git@github.com:mnemonic24/GithubTutorial.git <クローン先のディレクトリ>
```

クローンしたらちゃんとリポジトリがあるか確認し、リポジトリ(ディレクトリ)に移動しましょう。
```
$ ls
GithubTutorial

$ cd GithubTutorial
$ ls
README.md               src
```
これでリポジトリの準備ができました。

---
## ファイルの変更を反映してみよう

ローカルリポジトリの状態を確認
```
git status
``` 

ローカルブランチの状態を確認
```
git branch 
```

自分のブランチを作成
```
git branch ブランチの名前
```

作成したブランチに移動
```
git checkout ブランチの名前
```



```
git add src/main.py
```

```
git commit -m "ここに変更した内容を書く"
```

```
git push -u origin 
```