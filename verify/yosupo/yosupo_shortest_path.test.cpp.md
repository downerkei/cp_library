---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/dijkstra.hpp
    title: graph/dijkstra.hpp
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
    using namespace std;\n\n#line 1 \"graph/dijkstra.hpp\"\nstruct Dijkstra{\n   \
    \ static constexpr long long INF = 2e18;\n    vector<long long> dis;\n    vector<int>\
    \ pre;\n    priority_queue<pair<long long, int>> pq;\n    vector<int> p;\n   \
    \ Dijkstra(vector<vector<pair<int, long long>>>& G, int s) : dis(G.size(), INF),\
    \ pre(G.size(), -1) {\n        dis[s] = 0;\n        pq.push({0, s});\n       \
    \ while(pq.size()) {\n            auto [d, v] = pq.top(); pq.pop();\n        \
    \    if(dis[v] < -d) continue;\n            for(auto [nv, c] : G[v]) {\n     \
    \           if(dis[nv] <= dis[v] + c) continue;\n                dis[nv] = dis[v]\
    \ + c;\n                pre[nv] = v;\n                pq.push({-dis[nv], nv});\n\
    \            }\n        }\n    }\n\n    long long dist(int t) { return (dis[t]\
    \ == INF) ? -1 : dis[t]; }\n    vector<int> path(int t) {\n        if(p.size())\
    \ return p;\n        for(; t != -1; t = pre[t]) p.push_back(t);\n        reverse(p.begin(),\
    \ p.end());\n        return p;\n    }\n};\n#line 7 \"verify/yosupo/yosupo_shortest_path.test.cpp\"\
    \n\nint main() {\n    int N, M, s, t;\n    cin >> N >> M >> s >> t;\n    vector<vector<pair<int,\
    \ long long>>> G(N);\n    for(int i = 0; i < M; i++) {\n        int a, b, c;\n\
    \        cin >> a >> b >> c;\n        G[a].push_back({b, c});\n    }\n\n    Dijkstra\
    \ dijkstra(G, s);\n\n    if(dijkstra.dist(t) == -1) {\n        cout << -1 << endl;\n\
    \        return 0;\n    }\n\n    auto path = dijkstra.path(t);\n\n    cout <<\
    \ dijkstra.dist(t) << \" \" << path.size() - 1 << endl;\n    for(int i = 0; i\
    \ < (int)path.size() - 1; i++) {\n        cout << path[i] << \" \" << path[i +\
    \ 1] << endl;\n    }\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/shortest_path\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../graph/dijkstra.hpp\"\
    \n\nint main() {\n    int N, M, s, t;\n    cin >> N >> M >> s >> t;\n    vector<vector<pair<int,\
    \ long long>>> G(N);\n    for(int i = 0; i < M; i++) {\n        int a, b, c;\n\
    \        cin >> a >> b >> c;\n        G[a].push_back({b, c});\n    }\n\n    Dijkstra\
    \ dijkstra(G, s);\n\n    if(dijkstra.dist(t) == -1) {\n        cout << -1 << endl;\n\
    \        return 0;\n    }\n\n    auto path = dijkstra.path(t);\n\n    cout <<\
    \ dijkstra.dist(t) << \" \" << path.size() - 1 << endl;\n    for(int i = 0; i\
    \ < (int)path.size() - 1; i++) {\n        cout << path[i] << \" \" << path[i +\
    \ 1] << endl;\n    }\n\n    return 0;\n}\n"
  dependsOn:
  - graph/dijkstra.hpp
  isVerificationFile: true
  path: verify/yosupo/yosupo_shortest_path.test.cpp
  requiredBy: []
  timestamp: '2024-07-12 04:38:45+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/yosupo_shortest_path.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/yosupo_shortest_path.test.cpp
- /verify/verify/yosupo/yosupo_shortest_path.test.cpp.html
title: verify/yosupo/yosupo_shortest_path.test.cpp
---
