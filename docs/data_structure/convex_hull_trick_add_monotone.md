---
title: 傾き単調CHT
documentation_of: //data_structure/convex_hull_trick_add_monotone.hpp
---

## 概要

直線 $ax + b$ の追加クエリとある点 $x$ での最小値クエリ．

追加クエリの傾き $a$ が単調減少の場合のみ．

$a$ が単調増加で最大値クエリの場合は $a$ と $b$ をそれぞれ符号反転して，傾き単調減少な最小値クエリとする．

## コンストラクタ

```cpp
ConvexHullTrickAddMonotone<T> cht;
```

* デフォルトコンストラクタ．初期状態で直線はない．

### 制約

* $T$ は整数型．直線 $ax + b$ における $a, b, x$ の型．


## add

```cpp
void cht.add(T a, T b);
```

* 直線 $ax + b$ を追加する．

### 制約

* $a$ は追加順で単調減少である必要がある．

### 計算時間

* 償却 $O(1)$


## get_min

```cpp
T cht.get_min(T x);
```

* $ax + b$ の最小値を求める．

### 制約

* $x$ が単調増加である必要がある．

* $x$ が単調減少の場合，`lines` 末尾の2つを比較し，最小となるまで `lines.pop_back()` を繰り返す．

* $x$ が単調でない場合，`lines` 上で二分探索．

### 計算時間

* $x$ が単調の場合，償却 $O(1)$

* $x$ が単調でない場合，直線の数を $n$ として $O(\log n)$