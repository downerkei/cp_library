---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yukicoder/yukicoder_1002.test.cpp
    title: verify/yukicoder/yukicoder_1002.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/tree/centroid_decomposition.hpp\"\nstruct CentroidDecomposition{\n\
    \    vector<vector<int>> T;\n    vector<int> sub, ord;\n    vector<int> used;\n\
    \    int r;\n \n    CentroidDecomposition(vector<vector<int>>& G) : T(G.size()),\
    \ sub(G.size()), used(G.size()) {\n        build_dfs(G);\n    } \n \n    int calc_sub(vector<vector<int>>&\
    \ G, int v, int p=-1) {\n        sub[v] = 1;\n        for(int nv : G[v]) {\n \
    \           if(used[nv] || p == nv) continue;\n            sub[v] += calc_sub(G,\
    \ nv, v);\n        }\n        return sub[v];\n    }\n \n    int find_centroid(vector<vector<int>>&\
    \ G, int v, int mid, int p=-1) {\n        for(int nv : G[v]) {\n            if(used[nv]\
    \ || p == nv) continue;\n            if(sub[nv] > mid) return find_centroid(G,\
    \ nv, mid, v);\n        }\n        return v;\n    }\n \n    void build_dfs(vector<vector<int>>&\
    \ G, int v=0, int p=-1) {\n        int sz = calc_sub(G, v);\n        int centroid\
    \ = find_centroid(G, v, sz / 2);\n        used[centroid] = true;\n        ord.push_back(centroid);\n\
    \ \n        if(p == -1) r = centroid;\n        else {\n            T[p].push_back(centroid);\n\
    \            T[centroid].push_back(p);\n        }\n \n        for(int nv : G[centroid])\
    \ {\n            if(used[nv]) continue;\n            build_dfs(G, nv, centroid);\n\
    \        }\n    }\n\n    const vector<vector<int>>& get_tree() { return T; }\n\
    \n    int get_root() { return r; }\n\n    const vector<int>& get_order() { return\
    \ ord; }\n};\n"
  code: "struct CentroidDecomposition{\n    vector<vector<int>> T;\n    vector<int>\
    \ sub, ord;\n    vector<int> used;\n    int r;\n \n    CentroidDecomposition(vector<vector<int>>&\
    \ G) : T(G.size()), sub(G.size()), used(G.size()) {\n        build_dfs(G);\n \
    \   } \n \n    int calc_sub(vector<vector<int>>& G, int v, int p=-1) {\n     \
    \   sub[v] = 1;\n        for(int nv : G[v]) {\n            if(used[nv] || p ==\
    \ nv) continue;\n            sub[v] += calc_sub(G, nv, v);\n        }\n      \
    \  return sub[v];\n    }\n \n    int find_centroid(vector<vector<int>>& G, int\
    \ v, int mid, int p=-1) {\n        for(int nv : G[v]) {\n            if(used[nv]\
    \ || p == nv) continue;\n            if(sub[nv] > mid) return find_centroid(G,\
    \ nv, mid, v);\n        }\n        return v;\n    }\n \n    void build_dfs(vector<vector<int>>&\
    \ G, int v=0, int p=-1) {\n        int sz = calc_sub(G, v);\n        int centroid\
    \ = find_centroid(G, v, sz / 2);\n        used[centroid] = true;\n        ord.push_back(centroid);\n\
    \ \n        if(p == -1) r = centroid;\n        else {\n            T[p].push_back(centroid);\n\
    \            T[centroid].push_back(p);\n        }\n \n        for(int nv : G[centroid])\
    \ {\n            if(used[nv]) continue;\n            build_dfs(G, nv, centroid);\n\
    \        }\n    }\n\n    const vector<vector<int>>& get_tree() { return T; }\n\
    \n    int get_root() { return r; }\n\n    const vector<int>& get_order() { return\
    \ ord; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/tree/centroid_decomposition.hpp
  requiredBy: []
  timestamp: '2024-08-21 01:14:30+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yukicoder/yukicoder_1002.test.cpp
documentation_of: graph/tree/centroid_decomposition.hpp
layout: document
title: "\u91CD\u5FC3\u5206\u89E3"
---

## 概要

### 重心分解

木において，ある頂点を取り除くといくつかの木に分裂する．分裂後の木のサイズがすべて元のサイズの半分以下の場合，その頂点を木の重心という．

重心を取り除いた部分木についても再帰的に分解を行い，最終的にサイズが1になるまで続ける．

## コンストラクタ

```cpp
CentroidDecomposition cd(vector<vector<int>> G);
```

* 連結リスト`G`を入力として，木の重心とその分裂後の木の重心同士を再帰的に結んだ根付き木`T`を連結リストで構築．また，`T`をdfs行きがけ順で探索したものを`ord`，`T`の根を`r`に格納する．

## get_tree

```cpp
vector<vector<int>> get_tree();
```

* 重心同士を結んで木とした根付き木`T`をconst参照で返す．

## get_root

```cpp
int get_root();
```

* `T`の根ノード`r`を返す．元の木`G`の重心でもある．

## get_order

```cpp
vector<int> get_order();
```

* `T`をdfs行きがけ順である`ord`をconst参照で返す．