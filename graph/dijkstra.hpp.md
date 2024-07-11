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
    \ long long INF = 2e18;\n    vector<long long> dis;\n    vector<int> pre;\n  \
    \  priority_queue<pair<long long, int>> pq;\n    vector<int> p;\n    Dijkstra(vector<vector<pair<int,\
    \ long long>>>& G, int s) : dis(G.size(), INF), pre(G.size(), -1) {\n        dis[s]\
    \ = 0;\n        pq.push({0, s});\n        while(pq.size()) {\n            auto\
    \ [d, v] = pq.top(); pq.pop();\n            if(dis[v] < -d) continue;\n      \
    \      for(auto [nv, c] : G[v]) {\n                if(dis[nv] <= dis[v] + c) continue;\n\
    \                dis[nv] = dis[v] + c;\n                pre[nv] = v;\n       \
    \         pq.push({-dis[nv], nv});\n            }\n        }\n    }\n\n    long\
    \ long dist(int t) { return (dis[t] == INF) ? -1 : dis[t]; }\n    vector<int>\
    \ path(int t) {\n        if(p.size()) return p;\n        for(; t != -1; t = pre[t])\
    \ p.push_back(t);\n        reverse(p.begin(), p.end());\n        return p;\n \
    \   }\n};\n"
  code: "struct Dijkstra{\n    static constexpr long long INF = 2e18;\n    vector<long\
    \ long> dis;\n    vector<int> pre;\n    priority_queue<pair<long long, int>> pq;\n\
    \    vector<int> p;\n    Dijkstra(vector<vector<pair<int, long long>>>& G, int\
    \ s) : dis(G.size(), INF), pre(G.size(), -1) {\n        dis[s] = 0;\n        pq.push({0,\
    \ s});\n        while(pq.size()) {\n            auto [d, v] = pq.top(); pq.pop();\n\
    \            if(dis[v] < -d) continue;\n            for(auto [nv, c] : G[v]) {\n\
    \                if(dis[nv] <= dis[v] + c) continue;\n                dis[nv]\
    \ = dis[v] + c;\n                pre[nv] = v;\n                pq.push({-dis[nv],\
    \ nv});\n            }\n        }\n    }\n\n    long long dist(int t) { return\
    \ (dis[t] == INF) ? -1 : dis[t]; }\n    vector<int> path(int t) {\n        if(p.size())\
    \ return p;\n        for(; t != -1; t = pre[t]) p.push_back(t);\n        reverse(p.begin(),\
    \ p.end());\n        return p;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/dijkstra.hpp
  requiredBy: []
  timestamp: '2024-07-12 04:38:45+09:00'
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
