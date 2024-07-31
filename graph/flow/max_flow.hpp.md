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
  bundledCode: "#line 1 \"graph/flow/max_flow.hpp\"\ntemplate<typename flow_t>\nstruct\
    \ FordFulkerson{\n    struct Edge{\n        int from, to, rev;\n        flow_t\
    \ cap;\n        Edge(int f, int t, int r, flow_t c) : from(f), to(t), rev(r),\
    \ cap(c) {}\n    };\n\n    vector<vector<Edge>> G;\n    vector<bool> used;\n \
    \   const flow_t INF = numeric_limits<flow_t>::max();\n\n    FordFulkerson(int\
    \ N) : G(N), used(N, false) {}\n\n    void add_edge(int from, int to, flow_t cap)\
    \ {\n        int fromrev = G[from].size();\n        int torev = G[to].size();\n\
    \        G[from].push_back(Edge(from, to, torev, cap));\n        G[to].push_back(Edge(to,\
    \ from, fromrev, 0));\n    }\n\n    flow_t dfs(int v, int t, flow_t f) {\n   \
    \     if(v == t) return f;\n        used[v] = true;\n\n        for(Edge& e : G[v])\
    \ {\n            if(used[e.to]) continue;\n            if(e.cap == 0) continue;\n\
    \            flow_t flow = dfs(e.to, t, min(f, e.cap));\n            if(flow ==\
    \ 0) continue;\n\n            e.cap -= flow;\n            G[e.to][e.rev].cap +=\
    \ flow;\n\n            return flow;\n        }\n\n        return 0;\n    }\n\n\
    \    flow_t max_flow(int s, int t) {\n        flow_t ret = 0;\n        while(true)\
    \ {\n            used.assign(G.size(), false);\n            flow_t flow = dfs(s,\
    \ t, INF);\n            if(flow == 0) break;\n            ret += flow;\n     \
    \   }\n        return ret;\n    }\n};\n"
  code: "template<typename flow_t>\nstruct FordFulkerson{\n    struct Edge{\n    \
    \    int from, to, rev;\n        flow_t cap;\n        Edge(int f, int t, int r,\
    \ flow_t c) : from(f), to(t), rev(r), cap(c) {}\n    };\n\n    vector<vector<Edge>>\
    \ G;\n    vector<bool> used;\n    const flow_t INF = numeric_limits<flow_t>::max();\n\
    \n    FordFulkerson(int N) : G(N), used(N, false) {}\n\n    void add_edge(int\
    \ from, int to, flow_t cap) {\n        int fromrev = G[from].size();\n       \
    \ int torev = G[to].size();\n        G[from].push_back(Edge(from, to, torev, cap));\n\
    \        G[to].push_back(Edge(to, from, fromrev, 0));\n    }\n\n    flow_t dfs(int\
    \ v, int t, flow_t f) {\n        if(v == t) return f;\n        used[v] = true;\n\
    \n        for(Edge& e : G[v]) {\n            if(used[e.to]) continue;\n      \
    \      if(e.cap == 0) continue;\n            flow_t flow = dfs(e.to, t, min(f,\
    \ e.cap));\n            if(flow == 0) continue;\n\n            e.cap -= flow;\n\
    \            G[e.to][e.rev].cap += flow;\n\n            return flow;\n       \
    \ }\n\n        return 0;\n    }\n\n    flow_t max_flow(int s, int t) {\n     \
    \   flow_t ret = 0;\n        while(true) {\n            used.assign(G.size(),\
    \ false);\n            flow_t flow = dfs(s, t, INF);\n            if(flow == 0)\
    \ break;\n            ret += flow;\n        }\n        return ret;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/flow/max_flow.hpp
  requiredBy: []
  timestamp: '2024-07-31 22:42:48+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj/aoj_grl_6_a.test.cpp
documentation_of: graph/flow/max_flow.hpp
layout: document
redirect_from:
- /library/graph/flow/max_flow.hpp
- /library/graph/flow/max_flow.hpp.html
title: graph/flow/max_flow.hpp
---
