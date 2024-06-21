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
  bundledCode: "#line 1 \"verify/yosupo/yosupo_unionfind.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/unionfind\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#line 1 \"data_structure/union_find.hpp\"\nstruct UnionFind\
    \ {\n  public:\n    UnionFind(int n) : par(n, -1), rank(n, 0), siz(n, 1) {}\n\n\
    \    int Root(int a) {\n        if(par[a] == -1) return a;\n        else return\
    \ par[a] = Root(par[a]);\n    }\n\n    bool Same(int a, int b) {\n        return\
    \ Root(a) == Root(b);\n    }\n\n    bool Unite(int a, int b) {\n        int ra\
    \ = Root(a), rb = Root(b);\n        if(ra == rb) return false;\n        if(rank[ra]\
    \ < rank[rb]) swap(ra, rb);\n        par[rb] = ra;\n        if(rank[ra] == rank[rb])\
    \ rank[ra]++;\n        siz[ra] += siz[rb];\n        return true;\n    }\n\n  \
    \  int Size(int a) {\n        return siz[Root(a)];\n    }\n\n  private:\n    vector<int>\
    \ par, rank, siz;\n};\n#line 7 \"verify/yosupo/yosupo_unionfind.test.cpp\"\n\n\
    int main() {\n    int N, Q;\n    cin >> N >> Q;\n\n    UnionFind uf(N);\n\n  \
    \  for(int i = 0; i < Q; i++) {\n        int t, u, v;\n        cin >> t >> u >>\
    \ v;\n\n        if(t == 0) {\n            uf.Unite(u, v);\n        }\n\n     \
    \   if(t == 1) {\n            cout << uf.Same(u, v) << endl;\n        }\n    }\n\
    \n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../data_structure/union_find.hpp\"\
    \n\nint main() {\n    int N, Q;\n    cin >> N >> Q;\n\n    UnionFind uf(N);\n\n\
    \    for(int i = 0; i < Q; i++) {\n        int t, u, v;\n        cin >> t >> u\
    \ >> v;\n\n        if(t == 0) {\n            uf.Unite(u, v);\n        }\n\n  \
    \      if(t == 1) {\n            cout << uf.Same(u, v) << endl;\n        }\n \
    \   }\n\n    return 0;\n}"
  dependsOn:
  - data_structure/union_find.hpp
  isVerificationFile: true
  path: verify/yosupo/yosupo_unionfind.test.cpp
  requiredBy: []
  timestamp: '2024-06-22 04:42:05+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/yosupo_unionfind.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/yosupo_unionfind.test.cpp
- /verify/verify/yosupo/yosupo_unionfind.test.cpp.html
title: verify/yosupo/yosupo_unionfind.test.cpp
---
