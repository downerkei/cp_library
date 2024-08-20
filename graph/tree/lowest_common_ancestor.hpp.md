---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj/aoj_gcl_5_c.test.cpp
    title: verify/aoj/aoj_gcl_5_c.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/yosupo_lca.test.cpp
    title: verify/yosupo/yosupo_lca.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/tree/lowest_common_ancestor.hpp\"\nstruct LowestCommonAncestor{\n\
    \    vector<vector<int>> parent;\n    vector<int> dist;\n    LowestCommonAncestor(const\
    \ vector<vector<int>>& G, int root=0) {\n        init(G, root);\n    }\n\n   \
    \ void init(const vector<vector<int>>& G, int root) {\n        int N = G.size();\n\
    \        int M = 1; while((1 << M) < N) M++;\n        parent.assign(M, vector<int>(N,\
    \ -1));\n        dist.assign(N, -1);\n        dfs(G, root, -1, 0);\n        for(int\
    \ lv = 1; lv < M; lv++) {\n            for(int i = 0; i < N; i++) {\n        \
    \        if(parent[lv - 1][i] == -1) parent[lv][i] = -1;\n                else\
    \ parent[lv][i] = parent[lv - 1][parent[lv - 1][i]];\n            }\n        }\n\
    \    }\n\n    void dfs(const vector<vector<int>>& G, int v, int p, int d) {\n\
    \        parent[0][v] = p;\n        dist[v] = d;\n        for(int nv : G[v]) {\n\
    \            if(nv == p) continue;\n            dfs(G, nv, v, d + 1);\n      \
    \  }\n    }\n\n    int lca(int u, int v) {\n        if(dist[u] < dist[v]) swap(u,\
    \ v);\n        int M = parent.size();\n        for(int lv = 0; lv < M; lv++) {\n\
    \            if(((dist[u] - dist[v]) >> lv) & 1) u = parent[lv][u];\n        }\n\
    \        if(u == v) return u;\n        for(int lv = M - 1; lv >= 0; lv--) {\n\
    \            if(parent[lv][u] != parent[lv][v]) {\n                u = parent[lv][u];\n\
    \                v = parent[lv][v];\n            }\n        }\n        return\
    \ parent[0][u];\n    }\n};\n"
  code: "struct LowestCommonAncestor{\n    vector<vector<int>> parent;\n    vector<int>\
    \ dist;\n    LowestCommonAncestor(const vector<vector<int>>& G, int root=0) {\n\
    \        init(G, root);\n    }\n\n    void init(const vector<vector<int>>& G,\
    \ int root) {\n        int N = G.size();\n        int M = 1; while((1 << M) <\
    \ N) M++;\n        parent.assign(M, vector<int>(N, -1));\n        dist.assign(N,\
    \ -1);\n        dfs(G, root, -1, 0);\n        for(int lv = 1; lv < M; lv++) {\n\
    \            for(int i = 0; i < N; i++) {\n                if(parent[lv - 1][i]\
    \ == -1) parent[lv][i] = -1;\n                else parent[lv][i] = parent[lv -\
    \ 1][parent[lv - 1][i]];\n            }\n        }\n    }\n\n    void dfs(const\
    \ vector<vector<int>>& G, int v, int p, int d) {\n        parent[0][v] = p;\n\
    \        dist[v] = d;\n        for(int nv : G[v]) {\n            if(nv == p) continue;\n\
    \            dfs(G, nv, v, d + 1);\n        }\n    }\n\n    int lca(int u, int\
    \ v) {\n        if(dist[u] < dist[v]) swap(u, v);\n        int M = parent.size();\n\
    \        for(int lv = 0; lv < M; lv++) {\n            if(((dist[u] - dist[v])\
    \ >> lv) & 1) u = parent[lv][u];\n        }\n        if(u == v) return u;\n  \
    \      for(int lv = M - 1; lv >= 0; lv--) {\n            if(parent[lv][u] != parent[lv][v])\
    \ {\n                u = parent[lv][u];\n                v = parent[lv][v];\n\
    \            }\n        }\n        return parent[0][u];\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/tree/lowest_common_ancestor.hpp
  requiredBy: []
  timestamp: '2024-08-18 01:12:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj/aoj_gcl_5_c.test.cpp
  - verify/yosupo/yosupo_lca.test.cpp
documentation_of: graph/tree/lowest_common_ancestor.hpp
layout: document
redirect_from:
- /library/graph/tree/lowest_common_ancestor.hpp
- /library/graph/tree/lowest_common_ancestor.hpp.html
title: graph/tree/lowest_common_ancestor.hpp
---
