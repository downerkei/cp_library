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
  bundledCode: "#line 1 \"flow/primal_dual.hpp\"\ntemplate<typename Cap, typename\
    \ Cost> struct PrimalDual {\n    struct Edge {\n        int from, to, rev;\n \
    \       Cap cap;\n        Cost cost;\n        Edge(int f, int t, int r, Cap ca,\
    \ Cost co) : from(f), to(t), rev(r), cap(ca), cost(co) {}\n    };\n\n    int N;\n\
    \    const Cost COST_INF = numeric_limits<Cost>::max();\n    const Cap CAP_INF\
    \ = numeric_limits<Cap>::max();\n    vector<vector<Edge>> G;\n    vector<pair<int,\
    \ int>> pos;\n\n    PrimalDual(int N) : N(N), G(N) {}\n\n    void add_edge(int\
    \ from, int to, Cap cap, Cost cost) {\n        pos.push_back({from, G[from].size()});\n\
    \        int from_id = G[from].size();\n        int to_id = G[to].size();\n  \
    \      if(from == to) to_id++;\n        G[from].push_back(Edge(from, to, to_id,\
    \ cap, cost));\n        G[to].push_back(Edge(to, from, from_id, 0, -cost));\n\
    \    }\n\n    pair<Cap, Cost> max_flow(int s, int t) {\n        return max_flow(s,\
    \ t, CAP_INF);\n    }\n    pair<Cap, Cost> max_flow(int s, int t, Cap flow_limit)\
    \ {\n        return slope(s, t, flow_limit).back();\n    }\n    vector<pair<Cap,\
    \ Cost>> slope(int s, int t) {\n        return slope(s, t, CAP_INF);\n    }\n\n\
    \    // s -> t\u3078(flow_limit\u307E\u3067)\u6D41\u305B\u308B\u3060\u3051\u6D41\
    \u3057\uFF0C(\u6D41\u91CF\uFF0C\u6700\u5C0F\u30B3\u30B9\u30C8)\u306Evector\u3092\
    \u8FD4\u3059\n    vector<pair<Cap, Cost>> slope(int s, int t, Cap flow_limit)\
    \ {\n        vector<Cost> dual(N, 0), dist(N);\n        vector<int> pv(N), pe(N);\n\
    \        vector<bool> vis(N);\n\n        // dijkstra\n        auto dual_ref =\
    \ [&]() -> bool {\n            fill(dist.begin(), dist.end(), COST_INF);\n   \
    \         fill(pv.begin(), pv.end(), -1);\n            fill(pe.begin(), pe.end(),\
    \ -1);\n            fill(vis.begin(), vis.end(), false);\n\n            using\
    \ Pi = pair<Cost, int>;\n            priority_queue<Pi, vector<Pi>, greater<Pi>>\
    \ que;    // \u6700\u5C0F\u30D2\u30FC\u30D7  \n            dist[s] = 0;\n    \
    \        que.push({0, s});\n            while(que.size()) {\n                int\
    \ v = que.top().second; que.pop();\n                if(vis[v]) continue;\n   \
    \             vis[v] = true;\n                if(v == t) break;\n            \
    \    for(int i = 0; i < (int)G[v].size(); i++) {\n                    auto e =\
    \ G[v][i];\n\n                    if(vis[e.to] || e.cap == 0) continue;\n    \
    \                Cost cost = e.cost - dual[e.to] + dual[v];\n\n              \
    \      if(dist[e.to] <= cost + dist[v]) continue;\n                    dist[e.to]\
    \ = dist[v] + cost;\n                    pv[e.to] = v;\n                    pe[e.to]\
    \ = i;\n                    que.push({dist[e.to], e.to});\n                }\n\
    \            }\n\n            if(!vis[t]) return false;\n\n            for(int\
    \ v = 0; v < N; v++) {\n                if(!vis[v]) continue;\n              \
    \  dual[v] -= dist[t] - dist[v];\n            }\n            return true;\n  \
    \      };\n\n        Cap flow = 0;\n        Cost cost = 0, prev_cost_per_flow\
    \ = -1;\n        vector<pair<Cap, Cost>> ret;\n        ret.push_back({flow, cost});\n\
    \        while(flow < flow_limit) {\n            if(!dual_ref()) break;\n    \
    \        Cap c = flow_limit - flow;\n\n            // \u30C0\u30A4\u30AF\u30B9\
    \u30C8\u30E9\u3067\u6C42\u3081\u305F\u7D4C\u8DEF\u3092\u5FA9\u5143\u3057\u3066\
    max\u6D41\u3059\n            for(int v = t; v != s; v = pv[v]) {\n           \
    \     c = min(c, G[pv[v]][pe[v]].cap);\n            }\n\n            for(int v\
    \ = t; v != s; v = pv[v]) {\n                auto& e = G[pv[v]][pe[v]];\n    \
    \            e.cap -= c;\n                G[v][e.rev].cap += c;\n            }\n\
    \n            Cost d = -dual[s];\n            flow += c;\n            cost +=\
    \ c * d;\n            if(prev_cost_per_flow == d) {\n                ret.pop_back();\n\
    \            }\n            ret.push_back({flow, cost});\n            prev_cost_per_flow\
    \ = d;\n        }\n        return ret;\n    }\n};\n"
  code: "template<typename Cap, typename Cost> struct PrimalDual {\n    struct Edge\
    \ {\n        int from, to, rev;\n        Cap cap;\n        Cost cost;\n      \
    \  Edge(int f, int t, int r, Cap ca, Cost co) : from(f), to(t), rev(r), cap(ca),\
    \ cost(co) {}\n    };\n\n    int N;\n    const Cost COST_INF = numeric_limits<Cost>::max();\n\
    \    const Cap CAP_INF = numeric_limits<Cap>::max();\n    vector<vector<Edge>>\
    \ G;\n    vector<pair<int, int>> pos;\n\n    PrimalDual(int N) : N(N), G(N) {}\n\
    \n    void add_edge(int from, int to, Cap cap, Cost cost) {\n        pos.push_back({from,\
    \ G[from].size()});\n        int from_id = G[from].size();\n        int to_id\
    \ = G[to].size();\n        if(from == to) to_id++;\n        G[from].push_back(Edge(from,\
    \ to, to_id, cap, cost));\n        G[to].push_back(Edge(to, from, from_id, 0,\
    \ -cost));\n    }\n\n    pair<Cap, Cost> max_flow(int s, int t) {\n        return\
    \ max_flow(s, t, CAP_INF);\n    }\n    pair<Cap, Cost> max_flow(int s, int t,\
    \ Cap flow_limit) {\n        return slope(s, t, flow_limit).back();\n    }\n \
    \   vector<pair<Cap, Cost>> slope(int s, int t) {\n        return slope(s, t,\
    \ CAP_INF);\n    }\n\n    // s -> t\u3078(flow_limit\u307E\u3067)\u6D41\u305B\u308B\
    \u3060\u3051\u6D41\u3057\uFF0C(\u6D41\u91CF\uFF0C\u6700\u5C0F\u30B3\u30B9\u30C8\
    )\u306Evector\u3092\u8FD4\u3059\n    vector<pair<Cap, Cost>> slope(int s, int\
    \ t, Cap flow_limit) {\n        vector<Cost> dual(N, 0), dist(N);\n        vector<int>\
    \ pv(N), pe(N);\n        vector<bool> vis(N);\n\n        // dijkstra\n       \
    \ auto dual_ref = [&]() -> bool {\n            fill(dist.begin(), dist.end(),\
    \ COST_INF);\n            fill(pv.begin(), pv.end(), -1);\n            fill(pe.begin(),\
    \ pe.end(), -1);\n            fill(vis.begin(), vis.end(), false);\n\n       \
    \     using Pi = pair<Cost, int>;\n            priority_queue<Pi, vector<Pi>,\
    \ greater<Pi>> que;    // \u6700\u5C0F\u30D2\u30FC\u30D7  \n            dist[s]\
    \ = 0;\n            que.push({0, s});\n            while(que.size()) {\n     \
    \           int v = que.top().second; que.pop();\n                if(vis[v]) continue;\n\
    \                vis[v] = true;\n                if(v == t) break;\n         \
    \       for(int i = 0; i < (int)G[v].size(); i++) {\n                    auto\
    \ e = G[v][i];\n\n                    if(vis[e.to] || e.cap == 0) continue;\n\
    \                    Cost cost = e.cost - dual[e.to] + dual[v];\n\n          \
    \          if(dist[e.to] <= cost + dist[v]) continue;\n                    dist[e.to]\
    \ = dist[v] + cost;\n                    pv[e.to] = v;\n                    pe[e.to]\
    \ = i;\n                    que.push({dist[e.to], e.to});\n                }\n\
    \            }\n\n            if(!vis[t]) return false;\n\n            for(int\
    \ v = 0; v < N; v++) {\n                if(!vis[v]) continue;\n              \
    \  dual[v] -= dist[t] - dist[v];\n            }\n            return true;\n  \
    \      };\n\n        Cap flow = 0;\n        Cost cost = 0, prev_cost_per_flow\
    \ = -1;\n        vector<pair<Cap, Cost>> ret;\n        ret.push_back({flow, cost});\n\
    \        while(flow < flow_limit) {\n            if(!dual_ref()) break;\n    \
    \        Cap c = flow_limit - flow;\n\n            // \u30C0\u30A4\u30AF\u30B9\
    \u30C8\u30E9\u3067\u6C42\u3081\u305F\u7D4C\u8DEF\u3092\u5FA9\u5143\u3057\u3066\
    max\u6D41\u3059\n            for(int v = t; v != s; v = pv[v]) {\n           \
    \     c = min(c, G[pv[v]][pe[v]].cap);\n            }\n\n            for(int v\
    \ = t; v != s; v = pv[v]) {\n                auto& e = G[pv[v]][pe[v]];\n    \
    \            e.cap -= c;\n                G[v][e.rev].cap += c;\n            }\n\
    \n            Cost d = -dual[s];\n            flow += c;\n            cost +=\
    \ c * d;\n            if(prev_cost_per_flow == d) {\n                ret.pop_back();\n\
    \            }\n            ret.push_back({flow, cost});\n            prev_cost_per_flow\
    \ = d;\n        }\n        return ret;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: flow/primal_dual.hpp
  requiredBy: []
  timestamp: '2024-11-18 19:42:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: flow/primal_dual.hpp
layout: document
redirect_from:
- /library/flow/primal_dual.hpp
- /library/flow/primal_dual.hpp.html
title: flow/primal_dual.hpp
---
