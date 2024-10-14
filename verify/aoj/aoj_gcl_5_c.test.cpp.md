---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tree/lowest_common_ancestor.hpp
    title: tree/lowest_common_ancestor.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C&lang=ja
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C&lang=ja
  bundledCode: "#line 1 \"verify/aoj/aoj_gcl_5_c.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C&lang=ja\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"tree/lowest_common_ancestor.hpp\"\
    \ntemplate<class T>\nstruct LowestCommonAncestor{\n    vector<vector<int>> parent;\n\
    \    vector<int> height;\n    vector<T> dist;\n    LowestCommonAncestor(const\
    \ vector<vector<pair<int, T>>>& G, int root=0) {\n        init(G, root);\n   \
    \ }\n\n    void init(const vector<vector<pair<int, T>>>& G, int root=0) {\n  \
    \      int N = G.size();\n        int M = 1; while((1 << M) < N) M++;\n      \
    \  parent.assign(M, vector<int>(N, -1));\n        height.assign(N, -1);\n    \
    \    dist.assign(N, -1);\n        dfs(G, root, -1, 0, 0);\n        for(int lv\
    \ = 1; lv < M; lv++) {\n            for(int i = 0; i < N; i++) {\n           \
    \     if(parent[lv - 1][i] == -1) parent[lv][i] = -1;\n                else parent[lv][i]\
    \ = parent[lv - 1][parent[lv - 1][i]];\n            }\n        }\n    }\n\n  \
    \  void dfs(const vector<vector<pair<int, T>>>& G, int v, int p, int h, T d) {\n\
    \        parent[0][v] = p;\n        height[v] = h;\n        dist[v] = d;\n   \
    \     for(auto [nv, c] : G[v]) {\n            if(nv == p) continue;\n        \
    \    dfs(G, nv, v, h + 1, d + c);\n        }\n    }\n\n    int lca(int u, int\
    \ v) {\n        if(height[u] < height[v]) swap(u, v);\n        int M = parent.size();\n\
    \        for(int lv = 0; lv < M; lv++) {\n            if(((height[u] - height[v])\
    \ >> lv) & 1) u = parent[lv][u];\n        }\n        if(u == v) return u;\n  \
    \      for(int lv = M - 1; lv >= 0; lv--) {\n            if(parent[lv][u] != parent[lv][v])\
    \ {\n                u = parent[lv][u];\n                v = parent[lv][v];\n\
    \            }\n        }\n        return parent[0][u];\n    }\n\n    T dist_bitween(int\
    \ u, int v) { return dist[u] + dist[v] - 2 * dist[lca(u, v)]; }\n\n    int path_len(int\
    \ u, int v) { return height[u] + height[v] - 2 * height[lca(u, v)]; }\n};\n#line\
    \ 7 \"verify/aoj/aoj_gcl_5_c.test.cpp\"\n\nint main() {\n    int N;\n    cin >>\
    \ N;\n\n    vector<vector<pair<int, int>>> G(N);\n\n    for(int i = 0; i < N;\
    \ i++) {\n        int k;\n        cin >> k;\n        for(int j = 0; j < k; j++)\
    \ {\n            int c;\n            cin >> c;\n            G[i].push_back({c,\
    \ 1});\n            G[c].push_back({i, 1});\n        }\n    }\n\n    LowestCommonAncestor<int>\
    \ lca(G, 0);\n\n    int Q;\n    cin >> Q;\n    while(Q--) {\n        int u, v;\n\
    \        cin >> u >> v;\n        cout << lca.lca(u, v) << endl;\n    }\n\n   \
    \ return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C&lang=ja\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../tree/lowest_common_ancestor.hpp\"\
    \n\nint main() {\n    int N;\n    cin >> N;\n\n    vector<vector<pair<int, int>>>\
    \ G(N);\n\n    for(int i = 0; i < N; i++) {\n        int k;\n        cin >> k;\n\
    \        for(int j = 0; j < k; j++) {\n            int c;\n            cin >>\
    \ c;\n            G[i].push_back({c, 1});\n            G[c].push_back({i, 1});\n\
    \        }\n    }\n\n    LowestCommonAncestor<int> lca(G, 0);\n\n    int Q;\n\
    \    cin >> Q;\n    while(Q--) {\n        int u, v;\n        cin >> u >> v;\n\
    \        cout << lca.lca(u, v) << endl;\n    }\n\n    return 0;\n}"
  dependsOn:
  - tree/lowest_common_ancestor.hpp
  isVerificationFile: true
  path: verify/aoj/aoj_gcl_5_c.test.cpp
  requiredBy: []
  timestamp: '2024-10-14 21:14:48+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aoj/aoj_gcl_5_c.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj/aoj_gcl_5_c.test.cpp
- /verify/verify/aoj/aoj_gcl_5_c.test.cpp.html
title: verify/aoj/aoj_gcl_5_c.test.cpp
---
