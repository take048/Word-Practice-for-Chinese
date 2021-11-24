# Word-Practice-for-Chinese


Word-Practice-for-Chineseは中国語の単語の学習をコンソール上で行えるアプリケーションです。


使用言語：C言語

# アプリケーションの実行方法
本アプリケーションはC言語で書かれているので、通常のやり方でコンパイルしていただき、生成された実行ファイルを実行させてください。

例：gccの場合
```
gcc numeron.c
./a.out
```
# データファイルの準備
学習を行うためには、本アプリケーションに使用するテキストファイルを用意する必要があります。
テキストファイルの構成は以下のようになります。
```
データの数(n)
日本語_中国語_拼音
日本語_中国語_拼音
...(以下同行)
```

具体的には以下のとおりです。

![データファイルの準備](screenshot/procedure1.png)
 
# 学習の開始

アプリケーションの実行後、以下の４つを選択します。
- ファイル名(拡張子なし)
- 問題形式 (1=日本語 2=中国語 3=拼音)
- 回答形式 (1=日本語 2=中国語 3=拼音)
- 出題形式(1=ランダムモード　2=連続モード)

ファイル名は拡張子、ディレクトリ指定なしです。

出題形式がランダムモードの時、出題される問題はランダムで選ばれ、アプリケーションを終了するときは強制終了(ctrl+c)を行います。

出題形式が連続モードの時、出題される問題はデータファイルの上から順に選ばれ、最後まで出題し終わるとアプリケーションは終了します。

---

仮にファイル名を「1」、問題形式を「1」、回答形式を「2」、出題形式を「2」の時以下のように表示されます。

![学習の開始](screenshot/procedure2.png)

初めに問題が表示されるので、頭で考える、紙に書くなどして回答してください。

問題が表示されている状態からエンターキーを押下すると回答が表示されます。

![学習の開始](screenshot/procedure3.png)

回答が表示されている状態でエンターキーを押下すると次の問題が表示されます。

![学習の開始](screenshot/procedure4.png)

以上を繰り返し学習を進めていきます。
異常を繰り返し学習を進めていきます。
