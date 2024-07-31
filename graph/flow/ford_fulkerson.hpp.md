---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj/aoj_grl_6_a.test.cpp
    title: verify/aoj/aoj_grl_6_a.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/flow/ford_fulkerson.hpp\"\ntemplate<typename flow_t>\n\
    struct FordFulkerson{\n    struct Edge{\n        int from, to, rev;\n        flow_t\
    \ cap;\n        bool is_rev;\n        Edge(int f, int t, int r, flow_t c, bool\
    \ b) : from(f), to(t), rev(r), cap(c), is_rev(b) {}\n    };\n\n    vector<vector<Edge>>\
    \ G;\n    vector<bool> used;\n    const flow_t INF = numeric_limits<flow_t>::max();\n\
    \n    FordFulkerson(int N) : G(N), used(N, false) {}\n\n    void add_edge(int\
    \ from, int to, flow_t cap) {\n        int fromrev = G[from].size();\n       \
    \ int torev = G[to].size();\n        G[from].push_back(Edge(from, to, torev, cap,\
    \ 0));\n        G[to].push_back(Edge(to, from, fromrev, 0, 1));\n    }\n\n   \
    \ flow_t dfs(int v, int t, flow_t f) {\n        if(v == t) return f;\n       \
    \ used[v] = true;\n\n        for(Edge& e : G[v]) {\n            if(used[e.to])\
    \ continue;\n            if(e.cap == 0) continue;\n            flow_t flow = dfs(e.to,\
    \ t, min(f, e.cap));\n            if(flow == 0) continue;\n\n            e.cap\
    \ -= flow;\n            G[e.to][e.rev].cap += flow;\n\n            return flow;\n\
    \        }\n\n        return 0;\n    }\n\n    flow_t max_flow(int s, int t) {\n\
    \        flow_t ret = 0;\n        while(true) {\n            used.assign(G.size(),\
    \ false);\n            flow_t flow = dfs(s, t, INF);\n            if(flow == 0)\
    \ break;\n            ret += flow;\n        }\n        return ret;\n    }\n\n\
    \    vector<Edge> edges() {\n        vector<Edge> ret;\n        for(const auto&\
    \ v : G) {\n            for(const auto& e : v) {\n                if(e.is_rev)\
    \ continue;\n                ret.push_back(e);\n            }\n        }\n   \
    \     return ret;\n    }\n};\n"
  code: "template<typename flow_t>\nstruct FordFulkerson{\n    struct Edge{\n    \
    \    int from, to, rev;\n        flow_t cap;\n        bool is_rev;\n        Edge(int\
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
    \           }\n        }\n        return ret;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/flow/ford_fulkerson.hpp
  requiredBy: []
  timestamp: '2024-07-31 23:32:31+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj/aoj_grl_6_a.test.cpp
documentation_of: graph/flow/ford_fulkerson.hpp
layout: document
redirect_from:
- /library/graph/flow/ford_fulkerson.hpp
- /library/graph/flow/ford_fulkerson.hpp.html
title: graph/flow/ford_fulkerson.hpp
---
