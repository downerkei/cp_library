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
  bundledCode: "#line 1 \"flow/ford_fulkerson.hpp\"\ntemplate<typename flow_t>\nstruct\
    \ FordFulkerson{\n    struct Edge{\n        int from, to, rev;\n        flow_t\
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
    \     return ret;\n    }\n\n    void debug() {\n        for(const auto& v : G)\
    \ {\n            for(const auto& e : v) {\n                if(e.is_rev) continue;\n\
    \                cout << e.from << \" -> \" << e.to << \" (flow : \" << G[e.to][e.rev].cap\
    \ << \" / \"\n                    << e.cap + G[e.to][e.rev].cap << \")\" << endl;\n\
    \            }\n        }\n    }\n};\n"
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
    \           }\n        }\n        return ret;\n    }\n\n    void debug() {\n \
    \       for(const auto& v : G) {\n            for(const auto& e : v) {\n     \
    \           if(e.is_rev) continue;\n                cout << e.from << \" -> \"\
    \ << e.to << \" (flow : \" << G[e.to][e.rev].cap << \" / \"\n                \
    \    << e.cap + G[e.to][e.rev].cap << \")\" << endl;\n            }\n        }\n\
    \    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: flow/ford_fulkerson.hpp
  requiredBy: []
  timestamp: '2024-10-14 15:35:37+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: flow/ford_fulkerson.hpp
layout: document
redirect_from:
- /library/flow/ford_fulkerson.hpp
- /library/flow/ford_fulkerson.hpp.html
title: flow/ford_fulkerson.hpp
---
