---
title: UnionFind
documentation_of: //data_structure/union_find.hpp
---

## 概要

素集合データ構造

集合を扱うためのデータ構造．無向グラフに対して，辺の追加(union)，2頂点が連結かの判定(find)が高速に行える．



## コンストラクタ

```cpp
UnionFind uf(int n)
```

* $n$ 頂点 $0$ 辺の無向グラフを作る．

### 制約

* $0 \leq n \leq 10 ^ 8$

### 計算時間

* $O(n)$



## unite

```cpp
bool uf.unite(int u, int v)
```

* 無向辺 $(u, v)$ を足す．既に $u, v$ が連結なら`false`，非連結なら`true`を返す．

### 制約

* $0 \leq u < n$
* $0 \leq v < n$

### 計算時間

* ならし $O(\alpha(n))$



## same

```cpp
bool uf.same(int u, int v)
```

* 頂点 $u, v$ が連結かどうか判定する．

### 制約

* $0 \leq u < n$
* $0 \leq v < n$

### 計算時間

* ならし $O(\alpha(n))$



## root

```cpp
int uf.root(int v)
```

* 頂点 $v$ の属する連結成分の代表元を返す．

### 制約

* $0 \leq v < n$

### 計算時間

* ならし $O(\alpha(n))$



## size

```cpp
int uf.size(int v)
```

* 頂点 $v$ の属する連結成分のサイズを返す．

### 制約

* $0 \leq v < n$

### 計算時間

* ならし $O(\alpha(n))$