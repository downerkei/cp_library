---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj/aoj_grl_1_c.test.cpp
    title: verify/aoj/aoj_grl_1_c.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/warshall_floyd.hpp\"\nstruct WarshallFloyd {\n   \
    \ static constexpr long long INF = 2e18;\n\n    struct Edge {\n        int from,\
    \ to;\n        long long weight;\n    };\n\n    vector<vector<long long>> dist;\n\
    \n    vector<vector<long long>> shortest_path(int N, const vector<Edge>& edges)\
    \ {\n        dist.assign(N, vector<long long>(N, INF));\n        for(int i = 0;\
    \ i < N; i++) dist[i][i] = 0;\n        for(auto [from, to, weight] : edges) {\n\
    \            dist[from][to] = min(dist[from][to], weight);\n        }\n      \
    \  return shortest_path(dist);\n    }\n\n    vector<vector<long long>> shortest_path(vector<vector<long\
    \ long>> d) {\n        dist = d;\n        int N = dist.size();\n        for(int\
    \ k = 0; k < N; k++) {\n            for(int i = 0; i < N; i++) {\n           \
    \     if(dist[i][k] == INF) continue;\n                for(int j = 0; j < N; j++)\
    \ {\n                    if(dist[k][j] == INF) continue;\n                   \
    \ dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);\n                }\n\
    \            }\n        }\n        return dist;\n    }\n\n    bool has_negative_cycle()\
    \ const {\n        for(int i = 0; i < (int)dist.size(); i++) {\n            if(dist[i][i]\
    \ < 0) return true;\n        }\n        return false;\n    }\n};\n"
  code: "struct WarshallFloyd {\n    static constexpr long long INF = 2e18;\n\n  \
    \  struct Edge {\n        int from, to;\n        long long weight;\n    };\n\n\
    \    vector<vector<long long>> dist;\n\n    vector<vector<long long>> shortest_path(int\
    \ N, const vector<Edge>& edges) {\n        dist.assign(N, vector<long long>(N,\
    \ INF));\n        for(int i = 0; i < N; i++) dist[i][i] = 0;\n        for(auto\
    \ [from, to, weight] : edges) {\n            dist[from][to] = min(dist[from][to],\
    \ weight);\n        }\n        return shortest_path(dist);\n    }\n\n    vector<vector<long\
    \ long>> shortest_path(vector<vector<long long>> d) {\n        dist = d;\n   \
    \     int N = dist.size();\n        for(int k = 0; k < N; k++) {\n           \
    \ for(int i = 0; i < N; i++) {\n                if(dist[i][k] == INF) continue;\n\
    \                for(int j = 0; j < N; j++) {\n                    if(dist[k][j]\
    \ == INF) continue;\n                    dist[i][j] = min(dist[i][j], dist[i][k]\
    \ + dist[k][j]);\n                }\n            }\n        }\n        return\
    \ dist;\n    }\n\n    bool has_negative_cycle() const {\n        for(int i = 0;\
    \ i < (int)dist.size(); i++) {\n            if(dist[i][i] < 0) return true;\n\
    \        }\n        return false;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/warshall_floyd.hpp
  requiredBy: []
  timestamp: '2026-06-17 23:47:48+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj/aoj_grl_1_c.test.cpp
documentation_of: graph/warshall_floyd.hpp
layout: document
redirect_from:
- /library/graph/warshall_floyd.hpp
- /library/graph/warshall_floyd.hpp.html
title: graph/warshall_floyd.hpp
---
