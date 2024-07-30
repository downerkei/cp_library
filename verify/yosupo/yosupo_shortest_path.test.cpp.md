---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/shortest_path/dijkstra.hpp
    title: graph/shortest_path/dijkstra.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/shortest_path
    links:
    - https://judge.yosupo.jp/problem/shortest_path
  bundledCode: "#line 1 \"verify/yosupo/yosupo_shortest_path.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/shortest_path\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#line 1 \"graph/shortest_path/dijkstra.hpp\"\nstruct Dijkstra{\n\
    \    static constexpr long long INF = 2e18;\n    vector<long long> dist;\n   \
    \ vector<int> pre;\n    vector<vector<pair<int, long long>>> G;\n\n    Dijkstra(int\
    \ N) : G(N), dist(N, INF), pre(N, -1) {}\n\n    void add_edge(int a, int b, long\
    \ long c) {\n        G[a].push_back({b, c});\n    }\n\n    vector<long long> solve(int\
    \ s) {\n        dist[s] = 0;\n        priority_queue<pair<long long, int>> pq;\n\
    \        pq.push({0, s});\n        while(pq.size()) {\n            auto [d, v]\
    \ = pq.top(); pq.pop();\n            if(dist[v] < -d) continue;\n            for(auto\
    \ [nv, c] : G[v]) {\n                if(dist[nv] <= dist[v] + c) continue;\n \
    \               dist[nv] = dist[v] + c;\n                pre[nv] = v;\n      \
    \          pq.push({-dist[nv], nv});\n            }\n        }\n        for(int\
    \ i = 0; i < (int)G.size(); i++) {\n            if(dist[i] == INF) dist[i] = -1;\n\
    \        }\n        return dist;\n    }\n\n    vector<int> calc_path(int t) {\n\
    \        vector<int> path;\n        for(; t != -1; t = pre[t]) path.push_back(t);\n\
    \        reverse(path.begin(), path.end());\n        return path;\n    }\n};\n\
    #line 7 \"verify/yosupo/yosupo_shortest_path.test.cpp\"\n\nint main() {\n    cin.tie(nullptr);\n\
    \    ios::sync_with_stdio(false);\n    int N, M, s, t;\n    cin >> N >> M >> s\
    \ >> t;\n    \n    Dijkstra dij(N);\n    for(int i = 0; i < M; i++) {\n      \
    \  int a, b, c;\n        cin >> a >> b >> c;\n        dij.add_edge(a, b, c);\n\
    \    }\n\n    auto dist = dij.solve(s);\n\n    if(dist[t] == -1) {\n        cout\
    \ << -1 << endl;\n        return 0;\n    }\n\n    auto path = dij.calc_path(t);\n\
    \n    cout << dist[t] << \" \" << path.size() - 1 << endl;\n    for(int i = 0;\
    \ i < (int)path.size() - 1; i++) {\n        cout << path[i] << \" \" << path[i\
    \ + 1] << endl;\n    }\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/shortest_path\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../graph/shortest_path/dijkstra.hpp\"\
    \n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n  \
    \  int N, M, s, t;\n    cin >> N >> M >> s >> t;\n    \n    Dijkstra dij(N);\n\
    \    for(int i = 0; i < M; i++) {\n        int a, b, c;\n        cin >> a >> b\
    \ >> c;\n        dij.add_edge(a, b, c);\n    }\n\n    auto dist = dij.solve(s);\n\
    \n    if(dist[t] == -1) {\n        cout << -1 << endl;\n        return 0;\n  \
    \  }\n\n    auto path = dij.calc_path(t);\n\n    cout << dist[t] << \" \" << path.size()\
    \ - 1 << endl;\n    for(int i = 0; i < (int)path.size() - 1; i++) {\n        cout\
    \ << path[i] << \" \" << path[i + 1] << endl;\n    }\n\n    return 0;\n}\n"
  dependsOn:
  - graph/shortest_path/dijkstra.hpp
  isVerificationFile: true
  path: verify/yosupo/yosupo_shortest_path.test.cpp
  requiredBy: []
  timestamp: '2024-07-31 03:16:02+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/yosupo_shortest_path.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/yosupo_shortest_path.test.cpp
- /verify/verify/yosupo/yosupo_shortest_path.test.cpp.html
title: verify/yosupo/yosupo_shortest_path.test.cpp
---
