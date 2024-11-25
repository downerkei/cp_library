---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/yosupo_shortest_path.test.cpp
    title: verify/yosupo/yosupo_shortest_path.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/dijkstra.hpp\"\nstruct Dijkstra{\n    static constexpr\
    \ long long INF = 2e18;\n    vector<long long> dist;\n    vector<int> pre;\n\n\
    \    vector<long long> solve(const vector<vector<pair<int, long long>>>& G, int\
    \ s) {\n        dist.resize(G.size(), INF);\n        pre.resize(G.size(), -1);\n\
    \        dist[s] = 0;\n        priority_queue<pair<long long, int>> pq;\n    \
    \    pq.push({0, s});\n        while(pq.size()) {\n            auto [d, v] = pq.top();\
    \ pq.pop();\n            if(dist[v] < -d) continue;\n            for(auto [nv,\
    \ c] : G[v]) {\n                if(dist[nv] <= dist[v] + c) continue;\n      \
    \          dist[nv] = dist[v] + c;\n                pre[nv] = v;\n           \
    \     pq.push({-dist[nv], nv});\n            }\n        }\n        for(int i =\
    \ 0; i < (int)G.size(); i++) {\n            if(dist[i] == INF) dist[i] = -1;\n\
    \        }\n        return dist;\n    }\n\n    vector<int> calc_path(int t) {\n\
    \        vector<int> path;\n        for(; t != -1; t = pre[t]) path.push_back(t);\n\
    \        reverse(path.begin(), path.end());\n        return path;\n    }\n};\n"
  code: "struct Dijkstra{\n    static constexpr long long INF = 2e18;\n    vector<long\
    \ long> dist;\n    vector<int> pre;\n\n    vector<long long> solve(const vector<vector<pair<int,\
    \ long long>>>& G, int s) {\n        dist.resize(G.size(), INF);\n        pre.resize(G.size(),\
    \ -1);\n        dist[s] = 0;\n        priority_queue<pair<long long, int>> pq;\n\
    \        pq.push({0, s});\n        while(pq.size()) {\n            auto [d, v]\
    \ = pq.top(); pq.pop();\n            if(dist[v] < -d) continue;\n            for(auto\
    \ [nv, c] : G[v]) {\n                if(dist[nv] <= dist[v] + c) continue;\n \
    \               dist[nv] = dist[v] + c;\n                pre[nv] = v;\n      \
    \          pq.push({-dist[nv], nv});\n            }\n        }\n        for(int\
    \ i = 0; i < (int)G.size(); i++) {\n            if(dist[i] == INF) dist[i] = -1;\n\
    \        }\n        return dist;\n    }\n\n    vector<int> calc_path(int t) {\n\
    \        vector<int> path;\n        for(; t != -1; t = pre[t]) path.push_back(t);\n\
    \        reverse(path.begin(), path.end());\n        return path;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/dijkstra.hpp
  requiredBy: []
  timestamp: '2024-11-25 14:08:01+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/yosupo_shortest_path.test.cpp
documentation_of: graph/dijkstra.hpp
layout: document
redirect_from:
- /library/graph/dijkstra.hpp
- /library/graph/dijkstra.hpp.html
title: graph/dijkstra.hpp
---
