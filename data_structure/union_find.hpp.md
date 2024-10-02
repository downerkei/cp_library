---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/yosupo_unionfind.test.cpp
    title: verify/yosupo/yosupo_unionfind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data_structure/union_find.hpp\"\nstruct UnionFind {\n  public:\n\
    \    UnionFind(int n) : par(n, -1), rank(n, 0), siz(n, 1) {}\n\n    int root(int\
    \ a) {\n        if(par[a] == -1) return a;\n        else return par[a] = root(par[a]);\n\
    \    }\n\n    bool same(int a, int b) {\n        return root(a) == root(b);\n\
    \    }\n\n    bool unite(int a, int b) {\n        int ra = root(a), rb = root(b);\n\
    \        if(ra == rb) return false;\n        if(rank[ra] < rank[rb]) swap(ra,\
    \ rb);\n        par[rb] = ra;\n        if(rank[ra] == rank[rb]) rank[ra]++;\n\
    \        siz[ra] += siz[rb];\n        return true;\n    }\n\n    int size(int\
    \ a) {\n        return siz[root(a)];\n    }\n\n  private:\n    vector<int> par,\
    \ rank, siz;\n};\n"
  code: "struct UnionFind {\n  public:\n    UnionFind(int n) : par(n, -1), rank(n,\
    \ 0), siz(n, 1) {}\n\n    int root(int a) {\n        if(par[a] == -1) return a;\n\
    \        else return par[a] = root(par[a]);\n    }\n\n    bool same(int a, int\
    \ b) {\n        return root(a) == root(b);\n    }\n\n    bool unite(int a, int\
    \ b) {\n        int ra = root(a), rb = root(b);\n        if(ra == rb) return false;\n\
    \        if(rank[ra] < rank[rb]) swap(ra, rb);\n        par[rb] = ra;\n      \
    \  if(rank[ra] == rank[rb]) rank[ra]++;\n        siz[ra] += siz[rb];\n       \
    \ return true;\n    }\n\n    int size(int a) {\n        return siz[root(a)];\n\
    \    }\n\n  private:\n    vector<int> par, rank, siz;\n};"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/union_find.hpp
  requiredBy: []
  timestamp: '2024-07-31 03:07:18+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/yosupo_unionfind.test.cpp
documentation_of: data_structure/union_find.hpp
layout: document
title: UnionFind
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
bool uf.unite(int a, int b)
```

* 無向辺 $(a, b)$ を足す．既に $a, b$ が連結なら`false`，非連結なら`true`を返す．

### 制約

* $0 \leq a < n$
* $0 \leq b < n$

### 計算時間

* ならし $O(\alpha(n))$



## same

```cpp
bool uf.same(int a, int b)
```

* 頂点 $a, b$ が連結かどうか判定する．

### 制約

* $0 \leq a < n$
* $0 \leq b < n$

### 計算時間

* ならし $O(\alpha(n))$



## root

```cpp
int uf.root(int a)
```

* 頂点 $a$ の属する連結成分の代表元を返す．

### 制約

* $0 \leq a < n$

### 計算時間

* ならし $O(\alpha(n))$



## size

```cpp
int uf.size(int a)
```

* 頂点 $a$ の属する連結成分のサイズを返す．

### 制約

* $0 \leq a < n$

### 計算時間

* ならし $O(\alpha(n))$