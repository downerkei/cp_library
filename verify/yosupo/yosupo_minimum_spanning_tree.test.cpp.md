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
    PROBLEM: https://judge.yosupo.jp/problem/minimum_spanning_tree
    links:
    - https://judge.yosupo.jp/problem/minimum_spanning_tree
  bundledCode: "#line 1 \"verify/yosupo/yosupo_minimum_spanning_tree.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/minimum_spanning_tree\"\n\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"data_structure/union_find.hpp\"\
    \nstruct UnionFind {\n    vector<int> par, siz;\n\n    UnionFind(int n) : par(n,\
    \ -1), siz(n, 1) {}\n\n    int root(int v) {\n        if(par[v] == -1) return\
    \ v;\n        return par[v] = root(par[v]);\n    }\n\n    bool same(int u, int\
    \ v) {\n        return root(u) == root(v);\n    }\n\n    bool unite(int u, int\
    \ v) {\n        u = root(u);\n        v = root(v);\n        if(u == v) return\
    \ false;\n        if(siz[u] < siz[v]) swap(u, v);\n        par[v] = u;\n     \
    \   siz[u] += siz[v];\n        // write something\n        return true;\n    }\n\
    \n    int size(int v) {\n        return siz[root(v)];\n    }\n};\n#line 7 \"verify/yosupo/yosupo_minimum_spanning_tree.test.cpp\"\
    \n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n  \
    \  \n    int N, M; \n    cin >> N >> M;\n\n    vector<array<int, 4>> E(M);\n \
    \   for(int i = 0; i < M; i++) {\n        cin >> E[i][1] >> E[i][2] >> E[i][0];\n\
    \        E[i][3] = i;\n    }\n\n    ranges::sort(E);\n\n    long long cost = 0;\n\
    \    vector<int> ans;\n    UnionFind uf(N);\n    for(auto [c, a, b, i] : E) {\n\
    \        if(uf.unite(a, b)) {\n            cost += c;\n            ans.push_back(i);\n\
    \        } \n    }\n\n    cout << cost << \"\\n\";\n    for(int a : ans) {\n \
    \       cout << a << \" \";\n    }\n    cout << \"\\n\";\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/minimum_spanning_tree\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../data_structure/union_find.hpp\"\
    \n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n  \
    \  \n    int N, M; \n    cin >> N >> M;\n\n    vector<array<int, 4>> E(M);\n \
    \   for(int i = 0; i < M; i++) {\n        cin >> E[i][1] >> E[i][2] >> E[i][0];\n\
    \        E[i][3] = i;\n    }\n\n    ranges::sort(E);\n\n    long long cost = 0;\n\
    \    vector<int> ans;\n    UnionFind uf(N);\n    for(auto [c, a, b, i] : E) {\n\
    \        if(uf.unite(a, b)) {\n            cost += c;\n            ans.push_back(i);\n\
    \        } \n    }\n\n    cout << cost << \"\\n\";\n    for(int a : ans) {\n \
    \       cout << a << \" \";\n    }\n    cout << \"\\n\";\n\n    return 0;\n}"
  dependsOn:
  - data_structure/union_find.hpp
  isVerificationFile: true
  path: verify/yosupo/yosupo_minimum_spanning_tree.test.cpp
  requiredBy: []
  timestamp: '2026-07-20 04:42:07+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/yosupo_minimum_spanning_tree.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/yosupo_minimum_spanning_tree.test.cpp
- /verify/verify/yosupo/yosupo_minimum_spanning_tree.test.cpp.html
title: verify/yosupo/yosupo_minimum_spanning_tree.test.cpp
---
