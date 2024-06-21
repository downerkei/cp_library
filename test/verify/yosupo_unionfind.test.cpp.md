---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/union_find.hpp
    title: data_structure/union_find.hpp
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
  bundledCode: "#line 1 \"test/verify/yosupo_unionfind.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/unionfind\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#line 1 \"data_structure/union_find.hpp\"\nstruct UnionFind\
    \ {\n  public:\n    UnionFind(int n) : par(n, -1), rank(n, 0), siz(n, 1) {}\n\n\
    \    int root(int a) {\n        if(par[a] == -1) return a;\n        else return\
    \ par[a] = root(par[a]);\n    }\n\n    bool same(int a, int b) {\n        return\
    \ root(a) == root(b);\n    }\n\n    bool unite(int a, int b) {\n        int ra\
    \ = root(a), rb = root(b);\n        if(ra == rb) return false;\n        if(rank[ra]\
    \ < rank[rb]) swap(ra, rb);\n        par[rb] = ra;\n        if(rank[ra] == rank[rb])\
    \ rank[ra]++;\n        siz[ra] += siz[rb];\n        return true;\n    }\n\n  \
    \  int size(int a) {\n        return siz[root(a)];\n    }\n\n  private:\n    vector<int>\
    \ par, rank, siz;\n};\n#line 7 \"test/verify/yosupo_unionfind.test.cpp\"\n\nint\
    \ main() {\n    int N, Q;\n    cin >> N >> Q;\n\n    UnionFind uf(N);\n\n    for(int\
    \ i = 0; i < Q; i++) {\n        int t, u, v;\n        cin >> t >> u >> v;\n\n\
    \        if(t == 0) {\n            uf.unite(u, v);\n        }\n\n        if(t\
    \ == 1) {\n            cout << uf.same(u, v) << endl;\n        }\n    }\n\n  \
    \  return 0;\n}\n"
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
  path: test/verify/yosupo_unionfind.test.cpp
  requiredBy: []
  timestamp: '2024-06-21 23:11:34+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/verify/yosupo_unionfind.test.cpp
layout: document
redirect_from:
- /verify/test/verify/yosupo_unionfind.test.cpp
- /verify/test/verify/yosupo_unionfind.test.cpp.html
title: test/verify/yosupo_unionfind.test.cpp
---
