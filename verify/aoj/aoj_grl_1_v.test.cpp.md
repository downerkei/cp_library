---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/bellman_ford.hpp
    title: graph/bellman_ford.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/GRL_1_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/GRL_1_B
  bundledCode: "#line 1 \"verify/aoj/aoj_grl_1_v.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_1_B\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"graph/bellman_ford.hpp\"\
    \nstruct BellmanFord {\n    static constexpr long long INF = 2e18;\n\n    struct\
    \ Edge {\n        int from, to;\n        long long weight;\n    };\n\n    vector<long\
    \ long> dist;\n    vector<int> prev;\n    vector<bool> negative_inf;\n\n    vector<long\
    \ long> shortest_path(const vector<vector<pair<int, long long>>>& G, int s) {\n\
    \        vector<Edge> edges;\n        for(int v = 0; v < (int)G.size(); v++) {\n\
    \            for(auto [nv, weight] : G[v]) edges.push_back({v, nv, weight});\n\
    \        }\n        return shortest_path(G.size(), edges, s);\n    }\n\n    vector<long\
    \ long> shortest_path(int N, const vector<Edge>& edges, int s) {\n        dist.assign(N,\
    \ INF);\n        prev.assign(N, -1);\n        negative_inf.assign(N, false);\n\
    \        dist[s] = 0;\n\n        for(int i = 0; i < N - 1; i++) {\n          \
    \  bool updated = false;\n            for(auto [from, to, weight] : edges) {\n\
    \                if(dist[from] == INF) continue;\n                if(dist[to]\
    \ <= dist[from] + weight) continue;\n                dist[to] = dist[from] + weight;\n\
    \                prev[to] = from;\n                updated = true;\n         \
    \   }\n            if(!updated) break;\n        }\n\n        for(int i = 0; i\
    \ < N; i++) {\n            for(auto [from, to, weight] : edges) {\n          \
    \      if(dist[from] == INF) continue;\n                if(dist[to] > dist[from]\
    \ + weight) {\n                    dist[to] = dist[from] + weight;\n         \
    \           negative_inf[to] = true;\n                }\n                if(negative_inf[from])\
    \ negative_inf[to] = true;\n            }\n        }\n\n        return dist;\n\
    \    }\n\n    bool has_reachable_negative_cycle() const {\n        for(bool f\
    \ : negative_inf) {\n            if(f) return true;\n        }\n        return\
    \ false;\n    }\n\n    bool is_negative_inf(int v) const { return negative_inf[v];\
    \ }\n\n    vector<int> restore_path(int t) {\n        vector<int> path;\n    \
    \    if(dist[t] == INF || negative_inf[t]) return path;\n        for(; t != -1;\
    \ t = prev[t]) path.push_back(t);\n        reverse(path.begin(), path.end());\n\
    \        return path;\n    }\n};\n#line 7 \"verify/aoj/aoj_grl_1_v.test.cpp\"\n\
    \nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\n  \
    \  int V, E, r;\n    cin >> V >> E >> r;\n\n    vector<BellmanFord::Edge> edges;\n\
    \    for(int i = 0; i < E; i++) {\n        int s, t;\n        long long d;\n \
    \       cin >> s >> t >> d;\n        edges.push_back({s, t, d});\n    }\n\n  \
    \  BellmanFord bf;\n    auto dist = bf.shortest_path(V, edges, r);\n\n    if(bf.has_reachable_negative_cycle())\
    \ {\n        cout << \"NEGATIVE CYCLE\" << '\\n';\n        return 0;\n    }\n\n\
    \    for(int i = 0; i < V; i++) {\n        if(dist[i] == BellmanFord::INF) cout\
    \ << \"INF\" << '\\n';\n        else cout << dist[i] << '\\n';\n    }\n\n    return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_1_B\"\n\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../graph/bellman_ford.hpp\"\
    \n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\n\
    \    int V, E, r;\n    cin >> V >> E >> r;\n\n    vector<BellmanFord::Edge> edges;\n\
    \    for(int i = 0; i < E; i++) {\n        int s, t;\n        long long d;\n \
    \       cin >> s >> t >> d;\n        edges.push_back({s, t, d});\n    }\n\n  \
    \  BellmanFord bf;\n    auto dist = bf.shortest_path(V, edges, r);\n\n    if(bf.has_reachable_negative_cycle())\
    \ {\n        cout << \"NEGATIVE CYCLE\" << '\\n';\n        return 0;\n    }\n\n\
    \    for(int i = 0; i < V; i++) {\n        if(dist[i] == BellmanFord::INF) cout\
    \ << \"INF\" << '\\n';\n        else cout << dist[i] << '\\n';\n    }\n\n    return\
    \ 0;\n}\n"
  dependsOn:
  - graph/bellman_ford.hpp
  isVerificationFile: true
  path: verify/aoj/aoj_grl_1_v.test.cpp
  requiredBy: []
  timestamp: '2026-06-17 22:16:12+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aoj/aoj_grl_1_v.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj/aoj_grl_1_v.test.cpp
- /verify/verify/aoj/aoj_grl_1_v.test.cpp.html
title: verify/aoj/aoj_grl_1_v.test.cpp
---
