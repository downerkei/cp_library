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
    PROBLEM: https://judge.yosupo.jp/problem/bipartitematching
    links:
    - https://judge.yosupo.jp/problem/bipartitematching
  bundledCode: "#line 1 \"verify/yosupo/yosupo_bipartitematching.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/bipartitematching\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#line 1 \"flow/dinic.hpp\"\ntemplate<typename flow_t=int>\n\
    struct Dinic{\n    struct Edge{\n        int from, to, rev;\n        flow_t cap;\n\
    \        bool is_rev;\n        Edge(int f, int t, int r, flow_t c, bool b) : from(f),\
    \ to(t), rev(r), cap(c), is_rev(b) {}\n    };\n\n    vector<vector<Edge>> G;\n\
    \    vector<int> dist;\n    vector<int> iter;\n    const flow_t INF = numeric_limits<flow_t>::max();\n\
    \n    Dinic(int N) : G(N), dist(N), iter(N) {}\n\n    void add_edge(int from,\
    \ int to, flow_t cap) {\n        int fromrev = G[from].size();\n        int torev\
    \ = G[to].size();\n        G[from].push_back(Edge(from, to, torev, cap, 0));\n\
    \        G[to].push_back(Edge(to, from, fromrev, 0, 1));\n    }\n\n    void bfs(int\
    \ s) {\n        fill(dist.begin(), dist.end(), -1);\n        dist[s] = 0;\n  \
    \      queue<int> q;\n        q.push(s);\n        while(q.size()) {\n        \
    \    int v = q.front(); q.pop();\n            for(const Edge& e: G[v]) {\n   \
    \             if(e.cap == 0 || dist[e.to] >= 0) continue;\n                dist[e.to]\
    \ = dist[v] + 1;\n                q.push(e.to);\n            }\n        }\n  \
    \  }\n\n    flow_t dfs(int v, int t, flow_t f) {\n        if(v == t) return f;\n\
    \        if(f == 0) return 0;\n\n        for(int& i = iter[v]; i < (int)G[v].size();\
    \ i++) {\n            Edge& e = G[v][i];\n            if(e.cap == 0 || dist[v]\
    \ >= dist[e.to]) continue;\n            flow_t flow = dfs(e.to, t, min(f, e.cap));\n\
    \            if(flow == 0) continue;\n\n            e.cap -= flow;\n         \
    \   G[e.to][e.rev].cap += flow;\n\n            return flow;\n        }\n     \
    \   return 0;\n    }\n\n    flow_t max_flow(int s, int t) {\n        flow_t ret\
    \ = 0;\n\n        while(true) {\n            bfs(s);\n            if(dist[t] <\
    \ 0) return ret;\n\n            fill(iter.begin(), iter.end(), 0);\n         \
    \   while(true) {\n                flow_t flow = dfs(s, t, INF);\n           \
    \     if(flow == 0) break;\n                ret += flow;\n            }\n    \
    \    }\n\n        return 0;\n    }\n\n    vector<Edge> edges() {\n        vector<Edge>\
    \ ret;\n        for(const auto& v : G) {\n            for(const auto& e : v) {\n\
    \                if(e.is_rev) continue;\n                ret.push_back(e);\n \
    \           }\n        }\n        return ret;\n    }\n\n    void debug() {\n \
    \       for(const auto& v : G) {\n            for(const auto& e : v) {\n     \
    \           if(e.is_rev) continue;\n                cerr << e.from << \" -> \"\
    \ << e.to << \" (flow : \" << G[e.to][e.rev].cap << \" / \"\n                \
    \    << e.cap + G[e.to][e.rev].cap << \")\" << endl;\n            }\n        }\n\
    \    }\n};\n#line 7 \"verify/yosupo/yosupo_bipartitematching.test.cpp\"\n\nint\
    \ main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\n    int\
    \ L, R, M;\n    cin >> L >> R >> M;\n\n    Dinic<int> dinic(L + R + 2);\n\n  \
    \  for(int i = 0; i < M; i++) {\n        int a, b;\n        cin >> a >> b;\n \
    \       dinic.add_edge(a, L + b, 1);\n    }\n\n    for(int i = 0; i < L; i++)\
    \ {\n        dinic.add_edge(L + R, i, 1);\n    }\n\n    for(int i = 0; i < R;\
    \ i++) {\n        dinic.add_edge(L + i, L + R + 1, 1);\n    }\n\n    cout << dinic.max_flow(L\
    \ + R, L + R + 1) << endl;\n\n    const auto& edges = dinic.edges();\n\n    for(const\
    \ auto& e : edges) {\n        if(e.cap) continue;\n        if(e.from == L + R\
    \ || e.to == L + R + 1) continue;\n        cout << e.from << ' ' << e.to - L <<\
    \ endl;\n    }\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/bipartitematching\"\n\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../flow/dinic.hpp\"\
    \n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\n\
    \    int L, R, M;\n    cin >> L >> R >> M;\n\n    Dinic<int> dinic(L + R + 2);\n\
    \n    for(int i = 0; i < M; i++) {\n        int a, b;\n        cin >> a >> b;\n\
    \        dinic.add_edge(a, L + b, 1);\n    }\n\n    for(int i = 0; i < L; i++)\
    \ {\n        dinic.add_edge(L + R, i, 1);\n    }\n\n    for(int i = 0; i < R;\
    \ i++) {\n        dinic.add_edge(L + i, L + R + 1, 1);\n    }\n\n    cout << dinic.max_flow(L\
    \ + R, L + R + 1) << endl;\n\n    const auto& edges = dinic.edges();\n\n    for(const\
    \ auto& e : edges) {\n        if(e.cap) continue;\n        if(e.from == L + R\
    \ || e.to == L + R + 1) continue;\n        cout << e.from << ' ' << e.to - L <<\
    \ endl;\n    }\n\n    return 0;\n}"
  dependsOn:
  - flow/dinic.hpp
  isVerificationFile: true
  path: verify/yosupo/yosupo_bipartitematching.test.cpp
  requiredBy: []
  timestamp: '2024-11-21 06:58:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/yosupo_bipartitematching.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/yosupo_bipartitematching.test.cpp
- /verify/verify/yosupo/yosupo_bipartitematching.test.cpp.html
title: verify/yosupo/yosupo_bipartitematching.test.cpp
---
