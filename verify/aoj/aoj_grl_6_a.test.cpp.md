---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/flow/ford_fulkerson.hpp
    title: graph/flow/ford_fulkerson.hpp
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
  bundledCode: "#line 1 \"verify/aoj/aoj_grl_6_a.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A&lang=jp\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"graph/flow/ford_fulkerson.hpp\"\
    \ntemplate<typename flow_t>\nstruct FordFulkerson{\n    struct Edge{\n       \
    \ int from, to, rev;\n        flow_t cap;\n        bool is_rev;\n        Edge(int\
    \ f, int t, int r, flow_t c, bool b) : from(f), to(t), rev(r), cap(c), is_rev(b)\
    \ {}\n    };\n\n    vector<vector<Edge>> G;\n    vector<bool> used;\n    const\
    \ flow_t INF = numeric_limits<flow_t>::max();\n\n    FordFulkerson(int N) : G(N),\
    \ used(N, false) {}\n\n    void add_edge(int from, int to, flow_t cap) {\n   \
    \     int fromrev = G[from].size();\n        int torev = G[to].size();\n     \
    \   G[from].push_back(Edge(from, to, torev, cap, 0));\n        G[to].push_back(Edge(to,\
    \ from, fromrev, 0, 1));\n    }\n\n    flow_t dfs(int v, int t, flow_t f) {\n\
    \        if(v == t) return f;\n        used[v] = true;\n\n        for(Edge& e\
    \ : G[v]) {\n            if(used[e.to]) continue;\n            if(e.cap == 0)\
    \ continue;\n            flow_t flow = dfs(e.to, t, min(f, e.cap));\n        \
    \    if(flow == 0) continue;\n\n            e.cap -= flow;\n            G[e.to][e.rev].cap\
    \ += flow;\n\n            return flow;\n        }\n\n        return 0;\n    }\n\
    \n    flow_t max_flow(int s, int t) {\n        flow_t ret = 0;\n        while(true)\
    \ {\n            used.assign(G.size(), false);\n            flow_t flow = dfs(s,\
    \ t, INF);\n            if(flow == 0) break;\n            ret += flow;\n     \
    \   }\n        return ret;\n    }\n\n    vector<Edge> edges() {\n        vector<Edge>\
    \ ret;\n        for(const auto& v : G) {\n            for(const auto& e : v) {\n\
    \                if(e.is_rev) continue;\n                ret.push_back(e);\n \
    \           }\n        }\n        return ret;\n    }\n};\n#line 7 \"verify/aoj/aoj_grl_6_a.test.cpp\"\
    \n\nint main() {\n    int V, E;\n    cin >> V >> E;\n    FordFulkerson<int> ff(V);\n\
    \n    for(int i = 0; i < E; i++) {\n        int u, v, c;\n        cin >> u >>\
    \ v >> c;\n        ff.add_edge(u, v, c);\n    }\n\n    cout << ff.max_flow(0,\
    \ V - 1) << endl;\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A&lang=jp\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../graph/flow/ford_fulkerson.hpp\"\
    \n\nint main() {\n    int V, E;\n    cin >> V >> E;\n    FordFulkerson<int> ff(V);\n\
    \n    for(int i = 0; i < E; i++) {\n        int u, v, c;\n        cin >> u >>\
    \ v >> c;\n        ff.add_edge(u, v, c);\n    }\n\n    cout << ff.max_flow(0,\
    \ V - 1) << endl;\n\n    return 0;\n}\n"
  dependsOn:
  - graph/flow/ford_fulkerson.hpp
  isVerificationFile: true
  path: verify/aoj/aoj_grl_6_a.test.cpp
  requiredBy: []
  timestamp: '2024-07-31 23:33:19+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aoj/aoj_grl_6_a.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj/aoj_grl_6_a.test.cpp
- /verify/verify/aoj/aoj_grl_6_a.test.cpp.html
title: verify/aoj/aoj_grl_6_a.test.cpp
---
