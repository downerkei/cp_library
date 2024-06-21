---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/verify/yosupo_unionfind.test.cpp
    title: test/verify/yosupo_unionfind.test.cpp
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
  timestamp: '2024-06-21 23:11:34+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/verify/yosupo_unionfind.test.cpp
documentation_of: data_structure/union_find.hpp
layout: document
redirect_from:
- /library/data_structure/union_find.hpp
- /library/data_structure/union_find.hpp.html
title: data_structure/union_find.hpp
---
