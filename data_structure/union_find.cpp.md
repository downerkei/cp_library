---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data_structure/union_find.cpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\nstruct UnionFind {\n  public:\n    UnionFind(int n) :\
    \ par(n, -1), rank(n, 0), siz(n, 1) {}\n\n    int root(int a) {\n        if(par[a]\
    \ == -1) return a;\n        else return par[a] = root(par[a]);\n    }\n\n    bool\
    \ same(int a, int b) {\n        return root(a) == root(b);\n    }\n\n    bool\
    \ unite(int a, int b) {\n        int ra = root(a), rb = root(b);\n        if(ra\
    \ == rb) return false;\n        if(rank[ra] < rank[rb]) swap(ra, rb);\n      \
    \  par[rb] = ra;\n        if(rank[ra] == rank[rb]) rank[ra]++;\n        siz[ra]\
    \ += siz[rb];\n        return true;\n    }\n\n    int size(int a) {\n        return\
    \ siz[root(a)];\n    }\n\n  private:\n    vector<int> par, rank, siz;\n};\n\n\
    int main() {\n    int N, Q;\n    cin >> N >> Q;\n\n    UnionFind uf(N);\n\n  \
    \  for(int i = 0; i < Q; i++) {\n        int t, u, v;\n        cin >> t >> u >>\
    \ v;\n\n        if(t == 0) {\n            uf.unite(u, v);\n        }\n\n     \
    \   if(t == 1) {\n            cout << uf.same(u, v) << endl;\n        }\n    }\n\
    \n    return 0;\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\nstruct UnionFind {\n  public:\n\
    \    UnionFind(int n) : par(n, -1), rank(n, 0), siz(n, 1) {}\n\n    int root(int\
    \ a) {\n        if(par[a] == -1) return a;\n        else return par[a] = root(par[a]);\n\
    \    }\n\n    bool same(int a, int b) {\n        return root(a) == root(b);\n\
    \    }\n\n    bool unite(int a, int b) {\n        int ra = root(a), rb = root(b);\n\
    \        if(ra == rb) return false;\n        if(rank[ra] < rank[rb]) swap(ra,\
    \ rb);\n        par[rb] = ra;\n        if(rank[ra] == rank[rb]) rank[ra]++;\n\
    \        siz[ra] += siz[rb];\n        return true;\n    }\n\n    int size(int\
    \ a) {\n        return siz[root(a)];\n    }\n\n  private:\n    vector<int> par,\
    \ rank, siz;\n};\n\nint main() {\n    int N, Q;\n    cin >> N >> Q;\n\n    UnionFind\
    \ uf(N);\n\n    for(int i = 0; i < Q; i++) {\n        int t, u, v;\n        cin\
    \ >> t >> u >> v;\n\n        if(t == 0) {\n            uf.unite(u, v);\n     \
    \   }\n\n        if(t == 1) {\n            cout << uf.same(u, v) << endl;\n  \
    \      }\n    }\n\n    return 0;\n}"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/union_find.cpp
  requiredBy: []
  timestamp: '2024-06-21 02:11:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/union_find.cpp
layout: document
redirect_from:
- /library/data_structure/union_find.cpp
- /library/data_structure/union_find.cpp.html
title: data_structure/union_find.cpp
---
