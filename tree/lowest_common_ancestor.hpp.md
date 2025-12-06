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
  bundledCode: "#line 1 \"tree/lowest_common_ancestor.hpp\"\ntemplate<class T=int>\n\
    struct LowestCommonAncestor{\n    int mx_level;\n    vector<vector<int>> parent;\n\
    \    vector<int> depth;\n    vector<T> dist;\n    LowestCommonAncestor(const vector<vector<pair<int,\
    \ T>>>& G, int root=0) {\n        init(G, root);\n    }\n\n    LowestCommonAncestor(const\
    \ vector<vector<int>>& G, int root=0) {\n        init(G, root);\n    }\n\n   \
    \ template<class GType>\n    void init(const GType& G, int root) {\n        int\
    \ N = G.size();\n        mx_level = 1; while((1 << mx_level) < N) mx_level++;\n\
    \        parent.assign(mx_level, vector<int>(N, -1));\n        depth.assign(N,\
    \ -1);\n        dist.assign(N, -1);\n        dfs(G, root, -1, 0, 0);\n       \
    \ for(int lv = 1; lv < mx_level; lv++) {\n            for(int i = 0; i < N; i++)\
    \ {\n                if(parent[lv - 1][i] == -1) parent[lv][i] = -1;\n       \
    \         else parent[lv][i] = parent[lv - 1][parent[lv - 1][i]];\n          \
    \  }\n        }\n    }\n\n    template<class GType>\n    void dfs(const GType&\
    \ G, int v, int p, int dep, T dis) {\n        parent[0][v] = p;\n        depth[v]\
    \ = dep;\n        dist[v] = dis;\n        if constexpr (is_same_v<GType, vector<vector<pair<int,\
    \ T>>>>) {\n            for(auto [nv, c] : G[v]) {\n                if(nv == p)\
    \ continue;\n                dfs(G, nv, v, dep + 1, dis + c);\n            }\n\
    \        }\n        else if constexpr (is_same_v<GType, vector<vector<int>>>)\
    \ {\n            for(int nv : G[v]) {\n                if(nv == p) continue;\n\
    \                dfs(G, nv, v, dep + 1, dis + T(1));\n            }\n        }\n\
    \    }\n\n    int lca(int u, int v) {\n        if(depth[u] < depth[v]) swap(u,\
    \ v);\n        for(int lv = 0; lv < mx_level; lv++) {\n            if(((depth[u]\
    \ - depth[v]) >> lv) & 1) u = parent[lv][u];\n        }\n        if(u == v) return\
    \ u;\n        for(int lv = mx_level - 1; lv >= 0; lv--) {\n            if(parent[lv][u]\
    \ != parent[lv][v]) {\n                u = parent[lv][u];\n                v =\
    \ parent[lv][v];\n            }\n        }\n        return parent[0][u];\n   \
    \ }\n\n    T dist_bitween(int u, int v) { return dist[u] + dist[v] - 2 * dist[lca(u,\
    \ v)]; }\n\n    int path_len(int u, int v) { return depth[u] + depth[v] - 2 *\
    \ depth[lca(u, v)]; }\n};\n"
  code: "template<class T=int>\nstruct LowestCommonAncestor{\n    int mx_level;\n\
    \    vector<vector<int>> parent;\n    vector<int> depth;\n    vector<T> dist;\n\
    \    LowestCommonAncestor(const vector<vector<pair<int, T>>>& G, int root=0) {\n\
    \        init(G, root);\n    }\n\n    LowestCommonAncestor(const vector<vector<int>>&\
    \ G, int root=0) {\n        init(G, root);\n    }\n\n    template<class GType>\n\
    \    void init(const GType& G, int root) {\n        int N = G.size();\n      \
    \  mx_level = 1; while((1 << mx_level) < N) mx_level++;\n        parent.assign(mx_level,\
    \ vector<int>(N, -1));\n        depth.assign(N, -1);\n        dist.assign(N, -1);\n\
    \        dfs(G, root, -1, 0, 0);\n        for(int lv = 1; lv < mx_level; lv++)\
    \ {\n            for(int i = 0; i < N; i++) {\n                if(parent[lv -\
    \ 1][i] == -1) parent[lv][i] = -1;\n                else parent[lv][i] = parent[lv\
    \ - 1][parent[lv - 1][i]];\n            }\n        }\n    }\n\n    template<class\
    \ GType>\n    void dfs(const GType& G, int v, int p, int dep, T dis) {\n     \
    \   parent[0][v] = p;\n        depth[v] = dep;\n        dist[v] = dis;\n     \
    \   if constexpr (is_same_v<GType, vector<vector<pair<int, T>>>>) {\n        \
    \    for(auto [nv, c] : G[v]) {\n                if(nv == p) continue;\n     \
    \           dfs(G, nv, v, dep + 1, dis + c);\n            }\n        }\n     \
    \   else if constexpr (is_same_v<GType, vector<vector<int>>>) {\n            for(int\
    \ nv : G[v]) {\n                if(nv == p) continue;\n                dfs(G,\
    \ nv, v, dep + 1, dis + T(1));\n            }\n        }\n    }\n\n    int lca(int\
    \ u, int v) {\n        if(depth[u] < depth[v]) swap(u, v);\n        for(int lv\
    \ = 0; lv < mx_level; lv++) {\n            if(((depth[u] - depth[v]) >> lv) &\
    \ 1) u = parent[lv][u];\n        }\n        if(u == v) return u;\n        for(int\
    \ lv = mx_level - 1; lv >= 0; lv--) {\n            if(parent[lv][u] != parent[lv][v])\
    \ {\n                u = parent[lv][u];\n                v = parent[lv][v];\n\
    \            }\n        }\n        return parent[0][u];\n    }\n\n    T dist_bitween(int\
    \ u, int v) { return dist[u] + dist[v] - 2 * dist[lca(u, v)]; }\n\n    int path_len(int\
    \ u, int v) { return depth[u] + depth[v] - 2 * depth[lca(u, v)]; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: tree/lowest_common_ancestor.hpp
  requiredBy: []
  timestamp: '2024-11-20 05:35:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj/aoj_gcl_5_c.test.cpp
  - verify/yukicoder/yukicoder_386.test.cpp
  - verify/yukicoder/yukicoder_1094.test.cpp
  - verify/yosupo/yosupo_lca.test.cpp
documentation_of: tree/lowest_common_ancestor.hpp
layout: document
redirect_from:
- /library/tree/lowest_common_ancestor.hpp
- /library/tree/lowest_common_ancestor.hpp.html
title: tree/lowest_common_ancestor.hpp
---
