---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/tree/lowest_common_ancestor.hpp
    title: graph/tree/lowest_common_ancestor.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/lca
    links:
    - https://judge.yosupo.jp/problem/lca
  bundledCode: "#line 1 \"verify/yosupo/yosupo_lca.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/lca\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n#line 1 \"graph/tree/lowest_common_ancestor.hpp\"\nstruct LowestCommonAncestor{\n\
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
    \ parent[0][u];\n    }\n};\n#line 7 \"verify/yosupo/yosupo_lca.test.cpp\"\n\n\
    int main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n    int\
    \ N, Q;\n    cin >> N >> Q;\n    vector<vector<int>> G(N);\n    for(int i = 1;\
    \ i < N; i++) {\n        int p;\n        cin >> p;\n        G[i].push_back(p);\n\
    \        G[p].push_back(i);\n    }\n\n    LowestCommonAncestor lca(G);\n\n   \
    \ while(Q--) {\n        int u, v;\n        cin >> u >> v;\n\n        cout << lca.lca(u,\
    \ v) << \"\\n\";\n    }\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#include \"../../graph/tree/lowest_common_ancestor.hpp\"\
    \n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n  \
    \  int N, Q;\n    cin >> N >> Q;\n    vector<vector<int>> G(N);\n    for(int i\
    \ = 1; i < N; i++) {\n        int p;\n        cin >> p;\n        G[i].push_back(p);\n\
    \        G[p].push_back(i);\n    }\n\n    LowestCommonAncestor lca(G);\n\n   \
    \ while(Q--) {\n        int u, v;\n        cin >> u >> v;\n\n        cout << lca.lca(u,\
    \ v) << \"\\n\";\n    }\n\n    return 0;\n}"
  dependsOn:
  - graph/tree/lowest_common_ancestor.hpp
  isVerificationFile: true
  path: verify/yosupo/yosupo_lca.test.cpp
  requiredBy: []
  timestamp: '2024-08-21 00:20:25+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/yosupo_lca.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/yosupo_lca.test.cpp
- /verify/verify/yosupo/yosupo_lca.test.cpp.html
title: verify/yosupo/yosupo_lca.test.cpp
---