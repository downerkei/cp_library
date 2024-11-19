---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: flow/dinic.hpp
    title: flow/dinic.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A&lang=jp
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A&lang=jp
  bundledCode: "#line 1 \"verify/aoj/aoj_grl_6_a_dinic.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A&lang=jp\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"flow/dinic.hpp\"\
    \ntemplate<typename flow_t>\nstruct Dinic{\n    struct Edge{\n        int from,\
    \ to, rev;\n        flow_t cap;\n        bool is_rev;\n        Edge(int f, int\
    \ t, int r, flow_t c, bool b) : from(f), to(t), rev(r), cap(c), is_rev(b) {}\n\
    \    };\n\n    vector<vector<Edge>> G;\n    vector<int> dist;\n    vector<int>\
    \ iter;\n    const flow_t INF = numeric_limits<flow_t>::max();\n\n    Dinic(int\
    \ N) : G(N), dist(N), iter(N) {}\n\n    void add_edge(int from, int to, flow_t\
    \ cap) {\n        int fromrev = G[from].size();\n        int torev = G[to].size();\n\
    \        G[from].push_back(Edge(from, to, torev, cap, 0));\n        G[to].push_back(Edge(to,\
    \ from, fromrev, 0, 1));\n    }\n\n    void bfs(int s) {\n        fill(dist.begin(),\
    \ dist.end(), -1);\n        dist[s] = 0;\n        queue<int> q;\n        q.push(s);\n\
    \        while(q.size()) {\n            int v = q.front(); q.pop();\n        \
    \    for(const Edge& e: G[v]) {\n                if(e.cap == 0 || dist[e.to] >=\
    \ 0) continue;\n                dist[e.to] = dist[v] + 1;\n                q.push(e.to);\n\
    \            }\n        }\n    }\n\n    flow_t dfs(int v, int t, flow_t f) {\n\
    \        if(v == t) return f;\n        if(f == 0) return 0;\n\n        for(int&\
    \ i = iter[v]; i < (int)G[v].size(); i++) {\n            Edge& e = G[v][i];\n\
    \            if(e.cap == 0 || dist[v] >= dist[e.to]) continue;\n            flow_t\
    \ flow = dfs(e.to, t, min(f, e.cap));\n            if(flow == 0) continue;\n\n\
    \            e.cap -= flow;\n            G[e.to][e.rev].cap += flow;\n\n     \
    \       return flow;\n        }\n        return 0;\n    }\n\n    flow_t max_flow(int\
    \ s, int t) {\n        flow_t ret = 0;\n\n        while(true) {\n            bfs(s);\n\
    \            if(dist[t] < 0) return ret;\n\n            fill(iter.begin(), iter.end(),\
    \ 0);\n            while(true) {\n                flow_t flow = dfs(s, t, INF);\n\
    \                if(flow == 0) break;\n                ret += flow;\n        \
    \    }\n        }\n\n        return 0;\n    }\n\n    vector<Edge> edges() {\n\
    \        vector<Edge> ret;\n        for(const auto& v : G) {\n            for(const\
    \ auto& e : v) {\n                if(e.is_rev) continue;\n                ret.push_back(e);\n\
    \            }\n        }\n        return ret;\n    }\n\n    void debug() {\n\
    \        for(const auto& v : G) {\n            for(const auto& e : v) {\n    \
    \            if(e.is_rev) continue;\n                cerr << e.from << \" -> \"\
    \ << e.to << \" (flow : \" << G[e.to][e.rev].cap << \" / \"\n                \
    \    << e.cap + G[e.to][e.rev].cap << \")\" << endl;\n            }\n        }\n\
    \    }\n};\n#line 7 \"verify/aoj/aoj_grl_6_a_dinic.test.cpp\"\n\nint main() {\n\
    \    int V, E;\n    cin >> V >> E;\n\n    Dinic<int> dinic(V);\n\n    for(int\
    \ i = 0; i < E; i++) {\n        int u, v, c;\n        cin >> u >> v >> c;\n  \
    \      dinic.add_edge(u, v, c);\n    }\n\n    cout << dinic.max_flow(0, V - 1)\
    \ << endl;\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A&lang=jp\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../flow/dinic.hpp\"\
    \n\nint main() {\n    int V, E;\n    cin >> V >> E;\n\n    Dinic<int> dinic(V);\n\
    \n    for(int i = 0; i < E; i++) {\n        int u, v, c;\n        cin >> u >>\
    \ v >> c;\n        dinic.add_edge(u, v, c);\n    }\n\n    cout << dinic.max_flow(0,\
    \ V - 1) << endl;\n\n    return 0;\n}"
  dependsOn:
  - flow/dinic.hpp
  isVerificationFile: true
  path: verify/aoj/aoj_grl_6_a_dinic.test.cpp
  requiredBy: []
  timestamp: '2024-11-16 05:43:50+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aoj/aoj_grl_6_a_dinic.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj/aoj_grl_6_a_dinic.test.cpp
- /verify/verify/aoj/aoj_grl_6_a_dinic.test.cpp.html
title: verify/aoj/aoj_grl_6_a_dinic.test.cpp
---