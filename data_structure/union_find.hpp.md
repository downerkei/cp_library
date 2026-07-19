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
  bundledCode: "#line 1 \"data_structure/union_find.hpp\"\nstruct UnionFind {\n  \
    \  vector<int> par, siz;\n\n    UnionFind(int n) : par(n, -1), siz(n, 1) {}\n\n\
    \    int root(int v) {\n        if(par[v] == -1) return v;\n        return par[v]\
    \ = root(par[v]);\n    }\n\n    bool same(int u, int v) {\n        return root(u)\
    \ == root(v);\n    }\n\n    bool unite(int u, int v) {\n        u = root(u);\n\
    \        v = root(v);\n        if(u == v) return false;\n        if(siz[u] < siz[v])\
    \ swap(u, v);\n        par[v] = u;\n        siz[u] += siz[v];\n        // write\
    \ something\n        return true;\n    }\n\n    int size(int v) {\n        return\
    \ siz[root(v)];\n    }\n};\n"
  code: "struct UnionFind {\n    vector<int> par, siz;\n\n    UnionFind(int n) : par(n,\
    \ -1), siz(n, 1) {}\n\n    int root(int v) {\n        if(par[v] == -1) return\
    \ v;\n        return par[v] = root(par[v]);\n    }\n\n    bool same(int u, int\
    \ v) {\n        return root(u) == root(v);\n    }\n\n    bool unite(int u, int\
    \ v) {\n        u = root(u);\n        v = root(v);\n        if(u == v) return\
    \ false;\n        if(siz[u] < siz[v]) swap(u, v);\n        par[v] = u;\n     \
    \   siz[u] += siz[v];\n        // write something\n        return true;\n    }\n\
    \n    int size(int v) {\n        return siz[root(v)];\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/union_find.hpp
  requiredBy: []
  timestamp: '2026-07-20 01:33:34+09:00'
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