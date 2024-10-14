---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/dijkstra.hpp\"\nstruct Dijkstra{\n    static constexpr\
    \ long long INF = 2e18;\n    vector<long long> dist;\n    vector<int> pre;\n \
    \   vector<vector<pair<int, long long>>> G;\n\n    Dijkstra(int N) : G(N), dist(N,\
    \ INF), pre(N, -1) {}\n\n    void add_edge(int a, int b, long long c) {\n    \
    \    G[a].push_back({b, c});\n    }\n\n    vector<long long> solve(int s) {\n\
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
    \ long> dist;\n    vector<int> pre;\n    vector<vector<pair<int, long long>>>\
    \ G;\n\n    Dijkstra(int N) : G(N), dist(N, INF), pre(N, -1) {}\n\n    void add_edge(int\
    \ a, int b, long long c) {\n        G[a].push_back({b, c});\n    }\n\n    vector<long\
    \ long> solve(int s) {\n        dist[s] = 0;\n        priority_queue<pair<long\
    \ long, int>> pq;\n        pq.push({0, s});\n        while(pq.size()) {\n    \
    \        auto [d, v] = pq.top(); pq.pop();\n            if(dist[v] < -d) continue;\n\
    \            for(auto [nv, c] : G[v]) {\n                if(dist[nv] <= dist[v]\
    \ + c) continue;\n                dist[nv] = dist[v] + c;\n                pre[nv]\
    \ = v;\n                pq.push({-dist[nv], nv});\n            }\n        }\n\
    \        for(int i = 0; i < (int)G.size(); i++) {\n            if(dist[i] == INF)\
    \ dist[i] = -1;\n        }\n        return dist;\n    }\n\n    vector<int> calc_path(int\
    \ t) {\n        vector<int> path;\n        for(; t != -1; t = pre[t]) path.push_back(t);\n\
    \        reverse(path.begin(), path.end());\n        return path;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/dijkstra.hpp
  requiredBy: []
  timestamp: '2024-10-14 15:35:37+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/dijkstra.hpp
layout: document
redirect_from:
- /library/graph/dijkstra.hpp
- /library/graph/dijkstra.hpp.html
title: graph/dijkstra.hpp
---
