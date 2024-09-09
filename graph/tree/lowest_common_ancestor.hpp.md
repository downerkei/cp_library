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
  - icon: ':heavy_check_mark:'
    path: verify/yukicoder/yukicoder_1094.test.cpp
    title: verify/yukicoder/yukicoder_1094.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yukicoder/yukicoder_386.test.cpp
    title: verify/yukicoder/yukicoder_386.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/tree/lowest_common_ancestor.hpp\"\ntemplate<class\
    \ T>\nstruct LowestCommonAncestor{\n    vector<vector<int>> parent;\n    vector<int>\
    \ height;\n    vector<T> dist;\n    LowestCommonAncestor(const vector<vector<pair<int,\
    \ T>>>& G, int root=0) {\n        init(G, root);\n    }\n\n    void init(const\
    \ vector<vector<pair<int, T>>>& G, int root=0) {\n        int N = G.size();\n\
    \        int M = 1; while((1 << M) < N) M++;\n        parent.assign(M, vector<int>(N,\
    \ -1));\n        height.assign(N, -1);\n        dist.assign(N, -1);\n        dfs(G,\
    \ root, -1, 0, 0);\n        for(int lv = 1; lv < M; lv++) {\n            for(int\
    \ i = 0; i < N; i++) {\n                if(parent[lv - 1][i] == -1) parent[lv][i]\
    \ = -1;\n                else parent[lv][i] = parent[lv - 1][parent[lv - 1][i]];\n\
    \            }\n        }\n    }\n\n    void dfs(const vector<vector<pair<int,\
    \ T>>>& G, int v, int p, int h, T d) {\n        parent[0][v] = p;\n        height[v]\
    \ = h;\n        dist[v] = d;\n        for(auto [nv, c] : G[v]) {\n           \
    \ if(nv == p) continue;\n            dfs(G, nv, v, h + 1, d + c);\n        }\n\
    \    }\n\n    int lca(int u, int v) {\n        if(height[u] < height[v]) swap(u,\
    \ v);\n        int M = parent.size();\n        for(int lv = 0; lv < M; lv++) {\n\
    \            if(((height[u] - height[v]) >> lv) & 1) u = parent[lv][u];\n    \
    \    }\n        if(u == v) return u;\n        for(int lv = M - 1; lv >= 0; lv--)\
    \ {\n            if(parent[lv][u] != parent[lv][v]) {\n                u = parent[lv][u];\n\
    \                v = parent[lv][v];\n            }\n        }\n        return\
    \ parent[0][u];\n    }\n\n    T dist_bitween(int u, int v) { return dist[u] +\
    \ dist[v] - 2 * dist[lca(u, v)]; }\n\n    int path_len(int u, int v) { return\
    \ height[u] + height[v] - 2 * height[lca(u, v)]; }\n};\n"
  code: "template<class T>\nstruct LowestCommonAncestor{\n    vector<vector<int>>\
    \ parent;\n    vector<int> height;\n    vector<T> dist;\n    LowestCommonAncestor(const\
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
    \ u, int v) { return height[u] + height[v] - 2 * height[lca(u, v)]; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/tree/lowest_common_ancestor.hpp
  requiredBy: []
  timestamp: '2024-08-22 20:57:48+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yukicoder/yukicoder_1094.test.cpp
  - verify/yukicoder/yukicoder_386.test.cpp
  - verify/yosupo/yosupo_lca.test.cpp
  - verify/aoj/aoj_gcl_5_c.test.cpp
documentation_of: graph/tree/lowest_common_ancestor.hpp
layout: document
redirect_from:
- /library/graph/tree/lowest_common_ancestor.hpp
- /library/graph/tree/lowest_common_ancestor.hpp.html
title: graph/tree/lowest_common_ancestor.hpp
---
