# lasta-sezemi-2014-readable-code-1
D言語

## 実行手順
`./recipe`

## spec4: レシピの追加方法
`recipe-data.txt` に、1行ごとにレシピ名を記述してください

### 例
```
オムライス
親子丼
杏仁豆腐
```

## spec6: レシピIDの指定方法
レシピID の指定の仕方
レシピID はrecipe-data.txtを先頭から読み込む順番に，1-originでインクリメントされる

```
./recipe ${レシピID}
```

* レシピ名は256byteまでです

### spec8: ユーザー名の指定方法

```
./recipe ${レシピID}
input user name: hoge
```
