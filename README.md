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

次に、githubにリモート環境からssh接続できるようにします。[ここ](https://qiita.com/shizuma/items/2b2f873a0034839e47ce)を参照してsshの設定を行ってください。

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
## ブランチを作成する

ローカルリポジトリの状態を確認
```
$ git status
On branch master
Your branch is up to date with 'origin/master'.

nothing to commit, working tree clean
``` 
「ファイルの変更が直接 Master に反映する」ということが書かれています。複数人で作業している場合、masterを直接変更すると競合してしまうので、変更作業を行うブランチを作成して、そこで変更を行いましょう。

まず、現在のブランチを確認します。
```
$ git branch 
* master
```
*マークがついてるブランチが現在いるブランチです。今はmasterブランチにいることがわかります。
では、新しいブランチを作成します。
```
$ git branch <ブランチ名>
```

```
$ git branch
* master
  <作成したブランチ>
```
作成したブランチに移動
```
$ git checkout <作成したブランチ>
```
現在のブランチを確認
```
$ git branch
master
* <作成したブランチ>
```

これで、新しく作成したブランチに移動することができました。

## ファイルの中身を変更する

では早速ファイルの中身を変更してみましょう。

このチュートリアルでは src/main.py を変更していきます。
```Python
# main.py

while True:
    print("数値を入力してください")
    input_num = int(input())

    if input_num == 0:
        print('プログラムを終了します')
        break
    # -- ここに処理を追加してみよう --
    else:
        print('該当するコマンドがありません')
```

ファイルを変更したら、その変更をローカルリポジトリに記録します。
まずは変更したファイルを下記のコマンドで指定します。
```
$ git add -p src/main.py
```

次に変更内容をローカルリポジトリに反映します。
```
$ git commit -m "<ここに変更した内容を書く>"
```
これで、ローカルリポジトリに変更を反映することができました。

1. ファイルの中身を変更
2. git addで変更を記録するファイルを指定
3. git commitでローカルリポジトリに反映

この操作を繰り返すことで自分の行った変更を記録していきます。

---
## リモートリポジトリに変更を反映、masterにマージする

では、最後に自分の行った変更をmasterに反映します。つまり、他の人が自分の変更したファイルを使えるようにします。

まず最初に下記コマンドでローカルリポジトリの内容をリモートリポジトリに送信します。
```
git push -u origin <作成したブランチ>
```
これで、リモートリポジトリの<作成したブランチ>に変更が反映されました。最後に、この変更をmasterに反映します。

まず[このページ(リモートリポジトリ)](https://github.com/mnemonic24/GithubTutorial)をブラウザから開きます。
<!-- [github rep home](https://user-images.githubusercontent.com/30532640/61031670-f2131880-a3fa-11e9-9709-4ae9556bc6dc.png) -->
すると、画像のようにCompare & pull requestというボタンが出現するのでクリックします。
<!-- [github pullrequest](https://user-images.githubusercontent.com/30532640/61031671-f2abaf00-a3fa-11e9-8d10-2de5a5fe351d.png) -->
すると、open pull requestというページに行くので、マージする準備をします。ここで Able to merge と表示されていれば、マージすることができます。Create pull requestからpull requestを作成します。次のページでmergeをクリックするとマージ完了です。マージが完了したらDelete branchをクリックして作成したブランチを削除しましょう。

---
## ローカルリポジトリを最新の状態にする。
上記の操作でリモートリポジトリのmasterを更新することができました。しかし、ローカルリポジトリのmasterは最初の状態のままです。最後にリモートリポジトリの内容をローカルリポジトリに反映します。
まず、現在のブランチをmasterに変更しましょう。
現在いるブランチを確認します。
```
$ git branch
  master
* <作成したブランチ>

$ git checkout master
Swittched to branch 'master'

$ git branch
* master
  <作成したブランチ>
```

この状態でsrc/main.pyの中身をみてみると、最初の状態(変更前)に戻っているはずです。

では、リモートリポジトリのmasterをローカルリポジトリに反映しましょう。
```
$ git pull origin master
```
これで再度src/main.pyを見てみると中身が変更されているはずです。ローカルも無事更新したので、不必要なブランチは削除しておきましょう。
```
$ git branch -D <作成したブランチ> 
```
以上がgithubを使ったバージョン管理の流れになります。

---
## 補足
### .gitignore
他人に見られたくないファイルは.gitignoreに記載してaddできないようにする必要があります。
```
# .gitignore

.DS_Store
```

### 使わない方がいいコマンド
```
# 全ファイルの追加
git add .
git add --all
```
共有してはいけないファイルを共有するリスクがあるため