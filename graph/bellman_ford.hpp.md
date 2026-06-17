---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj/aoj_grl_1_b.test.cpp
    title: verify/aoj/aoj_grl_1_b.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/bellman_ford.hpp\"\nstruct BellmanFord {\n    static\
    \ constexpr long long INF = 2e18;\n\n    struct Edge {\n        int from, to;\n\
    \        long long weight;\n    };\n\n    vector<long long> dist;\n    vector<int>\
    \ prev;\n    vector<bool> negative_inf;\n\n    vector<long long> shortest_path(const\
    \ vector<vector<pair<int, long long>>>& G, int s) {\n        vector<Edge> edges;\n\
    \        for(int v = 0; v < (int)G.size(); v++) {\n            for(auto [nv, weight]\
    \ : G[v]) edges.push_back({v, nv, weight});\n        }\n        return shortest_path(G.size(),\
    \ edges, s);\n    }\n\n    vector<long long> shortest_path(int N, const vector<Edge>&\
    \ edges, int s) {\n        dist.assign(N, INF);\n        prev.assign(N, -1);\n\
    \        negative_inf.assign(N, false);\n        dist[s] = 0;\n\n        for(int\
    \ i = 0; i < N - 1; i++) {\n            bool updated = false;\n            for(auto\
    \ [from, to, weight] : edges) {\n                if(dist[from] == INF) continue;\n\
    \                if(dist[to] <= dist[from] + weight) continue;\n             \
    \   dist[to] = dist[from] + weight;\n                prev[to] = from;\n      \
    \          updated = true;\n            }\n            if(!updated) break;\n \
    \       }\n\n        for(int i = 0; i < N; i++) {\n            for(auto [from,\
    \ to, weight] : edges) {\n                if(dist[from] == INF) continue;\n  \
    \              if(dist[to] > dist[from] + weight) {\n                    dist[to]\
    \ = dist[from] + weight;\n                    negative_inf[to] = true;\n     \
    \           }\n                if(negative_inf[from]) negative_inf[to] = true;\n\
    \            }\n        }\n\n        return dist;\n    }\n\n    bool has_reachable_negative_cycle()\
    \ const {\n        for(bool f : negative_inf) {\n            if(f) return true;\n\
    \        }\n        return false;\n    }\n\n    bool is_negative_inf(int v) const\
    \ { return negative_inf[v]; }\n\n    vector<int> restore_path(int t) {\n     \
    \   vector<int> path;\n        if(dist[t] == INF || negative_inf[t]) return path;\n\
    \        for(; t != -1; t = prev[t]) path.push_back(t);\n        reverse(path.begin(),\
    \ path.end());\n        return path;\n    }\n};\n"
  code: "struct BellmanFord {\n    static constexpr long long INF = 2e18;\n\n    struct\
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
    \        return path;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/bellman_ford.hpp
  requiredBy: []
  timestamp: '2026-06-17 22:16:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj/aoj_grl_1_b.test.cpp
documentation_of: graph/bellman_ford.hpp
layout: document
redirect_from:
- /library/graph/bellman_ford.hpp
- /library/graph/bellman_ford.hpp.html
title: graph/bellman_ford.hpp
---
