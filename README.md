# lasta-sezemi-2014-readable-code-1
C言語

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
レシピID の指定の仕方は2種類あります。

```
./recipe ${レシピID}
```
```
./recipe
${レシピID}
```

* レシピ名は256byteまでです
