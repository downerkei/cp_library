---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/warshall_floyd.hpp
    title: graph/warshall_floyd.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/GRL_1_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/GRL_1_C
  bundledCode: "#line 1 \"verify/aoj/aoj_grl_1_c.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_1_C\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"graph/warshall_floyd.hpp\"\
    \nstruct WarshallFloyd {\n    static constexpr long long INF = 2e18;\n\n    struct\
    \ Edge {\n        int from, to;\n        long long weight;\n    };\n\n    vector<vector<long\
    \ long>> dist;\n\n    vector<vector<long long>> shortest_path(int N, const vector<Edge>&\
    \ edges) {\n        dist.assign(N, vector<long long>(N, INF));\n        for(int\
    \ i = 0; i < N; i++) dist[i][i] = 0;\n        for(auto [from, to, weight] : edges)\
    \ {\n            dist[from][to] = min(dist[from][to], weight);\n        }\n  \
    \      return shortest_path(dist);\n    }\n\n    vector<vector<long long>> shortest_path(vector<vector<long\
    \ long>> d) {\n        dist = d;\n        int N = dist.size();\n        for(int\
    \ k = 0; k < N; k++) {\n            for(int i = 0; i < N; i++) {\n           \
    \     if(dist[i][k] == INF) continue;\n                for(int j = 0; j < N; j++)\
    \ {\n                    if(dist[k][j] == INF) continue;\n                   \
    \ dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);\n                }\n\
    \            }\n        }\n        return dist;\n    }\n\n    bool has_negative_cycle()\
    \ const {\n        for(int i = 0; i < (int)dist.size(); i++) {\n            if(dist[i][i]\
    \ < 0) return true;\n        }\n        return false;\n    }\n};\n#line 7 \"verify/aoj/aoj_grl_1_c.test.cpp\"\
    \n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\n\
    \    int V, E;\n    cin >> V >> E;\n\n    vector<WarshallFloyd::Edge> edges;\n\
    \    for(int i = 0; i < E; i++) {\n        int s, t;\n        long long d;\n \
    \       cin >> s >> t >> d;\n        edges.push_back({s, t, d});\n    }\n\n  \
    \  WarshallFloyd wf;\n    auto dist = wf.shortest_path(V, edges);\n\n    if(wf.has_negative_cycle())\
    \ {\n        cout << \"NEGATIVE CYCLE\" << '\\n';\n        return 0;\n    }\n\n\
    \    for(int i = 0; i < V; i++) {\n        for(int j = 0; j < V; j++) {\n    \
    \        if(j) cout << ' ';\n            if(dist[i][j] == WarshallFloyd::INF)\
    \ cout << \"INF\";\n            else cout << dist[i][j];\n        }\n        cout\
    \ << '\\n';\n    }\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_1_C\"\n\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../graph/warshall_floyd.hpp\"\
    \n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\n\
    \    int V, E;\n    cin >> V >> E;\n\n    vector<WarshallFloyd::Edge> edges;\n\
    \    for(int i = 0; i < E; i++) {\n        int s, t;\n        long long d;\n \
    \       cin >> s >> t >> d;\n        edges.push_back({s, t, d});\n    }\n\n  \
    \  WarshallFloyd wf;\n    auto dist = wf.shortest_path(V, edges);\n\n    if(wf.has_negative_cycle())\
    \ {\n        cout << \"NEGATIVE CYCLE\" << '\\n';\n        return 0;\n    }\n\n\
    \    for(int i = 0; i < V; i++) {\n        for(int j = 0; j < V; j++) {\n    \
    \        if(j) cout << ' ';\n            if(dist[i][j] == WarshallFloyd::INF)\
    \ cout << \"INF\";\n            else cout << dist[i][j];\n        }\n        cout\
    \ << '\\n';\n    }\n\n    return 0;\n}\n"
  dependsOn:
  - graph/warshall_floyd.hpp
  isVerificationFile: true
  path: verify/aoj/aoj_grl_1_c.test.cpp
  requiredBy: []
  timestamp: '2026-06-17 23:47:48+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aoj/aoj_grl_1_c.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj/aoj_grl_1_c.test.cpp
- /verify/verify/aoj/aoj_grl_1_c.test.cpp.html
title: verify/aoj/aoj_grl_1_c.test.cpp
---
