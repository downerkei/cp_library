---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/union_find.hpp
    title: UnionFind
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"verify/yosupo/yosupo_unionfind.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/unionfind\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#line 1 \"data_structure/union_find.hpp\"\nstruct UnionFind\
    \ {\n    vector<int> par, siz;\n\n    UnionFind(int n) : par(n, -1), siz(n, 1)\
    \ {}\n\n    int root(int v) {\n        if(par[v] == -1) return v;\n        return\
    \ par[v] = root(par[v]);\n    }\n\n    bool same(int u, int v) {\n        return\
    \ root(u) == root(v);\n    }\n\n    bool unite(int u, int v) {\n        u = root(u);\n\
    \        v = root(v);\n        if(u == v) return false;\n        if(siz[u] < siz[v])\
    \ swap(u, v);\n        par[v] = u;\n        siz[u] += siz[v];\n        // write\
    \ something\n        return true;\n    }\n\n    int size(int v) {\n        return\
    \ siz[root(v)];\n    }\n};\n#line 7 \"verify/yosupo/yosupo_unionfind.test.cpp\"\
    \n\nint main() {\n    int N, Q;\n    cin >> N >> Q;\n\n    UnionFind uf(N);\n\n\
    \    for(int i = 0; i < Q; i++) {\n        int t, u, v;\n        cin >> t >> u\
    \ >> v;\n\n        if(t == 0) {\n            uf.unite(u, v);\n        }\n\n  \
    \      if(t == 1) {\n            cout << uf.same(u, v) << endl;\n        }\n \
    \   }\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../data_structure/union_find.hpp\"\
    \n\nint main() {\n    int N, Q;\n    cin >> N >> Q;\n\n    UnionFind uf(N);\n\n\
    \    for(int i = 0; i < Q; i++) {\n        int t, u, v;\n        cin >> t >> u\
    \ >> v;\n\n        if(t == 0) {\n            uf.unite(u, v);\n        }\n\n  \
    \      if(t == 1) {\n            cout << uf.same(u, v) << endl;\n        }\n \
    \   }\n\n    return 0;\n}"
  dependsOn:
  - data_structure/union_find.hpp
  isVerificationFile: true
  path: verify/yosupo/yosupo_unionfind.test.cpp
  requiredBy: []
  timestamp: '2026-07-20 01:33:34+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/yosupo_unionfind.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/yosupo_unionfind.test.cpp
- /verify/verify/yosupo/yosupo_unionfind.test.cpp.html
title: verify/yosupo/yosupo_unionfind.test.cpp
---
