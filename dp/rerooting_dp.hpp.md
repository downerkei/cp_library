---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj/aoj_1595.test.cpp
    title: verify/aoj/aoj_1595.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"dp/rerooting_dp.hpp\"\ntemplate<class E, E (*merge)(E, E),\
    \ E (*e)(), E(*put_v)(E, int)>\nstruct RerootingDP{\n    int n;\n    vector<vector<int>>\
    \ G;\n    vector<E> dp1, dp2, ans;\n    RerootingDP(int n) : n(n), G(n), dp1(n,\
    \ e()), dp2(n, e()), ans(n, e()) {}\n\n    void add_edge(int u, int v) {\n   \
    \     G[u].push_back(v);\n        G[v].push_back(u);\n    }\n\n    void dfs1(int\
    \ v, int p=-1) {\n        for(int nv : G[v]) {\n            if(nv == p) continue;\n\
    \            dfs1(nv, v);\n            dp1[v] = merge(dp1[v], dp1[nv]);\n    \
    \    }\n        dp1[v] = put_v(dp1[v], v);\n    }\n\n    void dfs2(int v, int\
    \ p=-1) {\n        vector<E> lp(G[v].size(), e()), rp(G[v].size(), e());\n   \
    \     for(int i = 0; i < (int)G[v].size(); i++) {\n            int nv = G[v][i];\n\
    \            if(i - 1 >= 0) lp[i] = lp[i - 1];\n            if(nv == p) continue;\n\
    \            lp[i] = merge(lp[i], dp1[nv]);\n        }\n        for(int i = G[v].size()\
    \ - 1; i >= 0; i--) {\n            int nv = G[v][i];\n            if(i + 1 < (int)G[v].size())\
    \ rp[i] = rp[i + 1];\n            if(nv == p) continue;\n            rp[i] = merge(rp[i],\
    \ dp1[nv]);\n        }\n        for(int i = 0; i < (int)G[v].size(); i++) {\n\
    \            int nv = G[v][i];\n            if(nv == p) continue;\n          \
    \  dp2[nv] = dp2[v];\n            if(i - 1 >= 0) dp2[nv] = merge(dp2[nv], lp[i\
    \ - 1]);\n            if(i + 1 < (int)G[v].size()) dp2[nv] = merge(dp2[nv], rp[i\
    \ + 1]);\n            dp2[nv] = put_v(dp2[nv], nv);\n            dfs2(nv, v);\n\
    \        }\n    }\n\n    void dfs3(int v, int p=-1) {\n        for(int nv : G[v])\
    \ {\n            if(nv == p) continue;\n            ans[v] = merge(ans[v], dp1[nv]);\n\
    \            dfs3(nv, v);\n        }\n        ans[v] = merge(ans[v], dp2[v]);\n\
    \    }\n\n    vector<E> solve() {\n        dfs1(0);\n        dfs2(0);\n      \
    \  dfs3(0);\n        return ans;\n    }\n};\n"
  code: "template<class E, E (*merge)(E, E), E (*e)(), E(*put_v)(E, int)>\nstruct\
    \ RerootingDP{\n    int n;\n    vector<vector<int>> G;\n    vector<E> dp1, dp2,\
    \ ans;\n    RerootingDP(int n) : n(n), G(n), dp1(n, e()), dp2(n, e()), ans(n,\
    \ e()) {}\n\n    void add_edge(int u, int v) {\n        G[u].push_back(v);\n \
    \       G[v].push_back(u);\n    }\n\n    void dfs1(int v, int p=-1) {\n      \
    \  for(int nv : G[v]) {\n            if(nv == p) continue;\n            dfs1(nv,\
    \ v);\n            dp1[v] = merge(dp1[v], dp1[nv]);\n        }\n        dp1[v]\
    \ = put_v(dp1[v], v);\n    }\n\n    void dfs2(int v, int p=-1) {\n        vector<E>\
    \ lp(G[v].size(), e()), rp(G[v].size(), e());\n        for(int i = 0; i < (int)G[v].size();\
    \ i++) {\n            int nv = G[v][i];\n            if(i - 1 >= 0) lp[i] = lp[i\
    \ - 1];\n            if(nv == p) continue;\n            lp[i] = merge(lp[i], dp1[nv]);\n\
    \        }\n        for(int i = G[v].size() - 1; i >= 0; i--) {\n            int\
    \ nv = G[v][i];\n            if(i + 1 < (int)G[v].size()) rp[i] = rp[i + 1];\n\
    \            if(nv == p) continue;\n            rp[i] = merge(rp[i], dp1[nv]);\n\
    \        }\n        for(int i = 0; i < (int)G[v].size(); i++) {\n            int\
    \ nv = G[v][i];\n            if(nv == p) continue;\n            dp2[nv] = dp2[v];\n\
    \            if(i - 1 >= 0) dp2[nv] = merge(dp2[nv], lp[i - 1]);\n           \
    \ if(i + 1 < (int)G[v].size()) dp2[nv] = merge(dp2[nv], rp[i + 1]);\n        \
    \    dp2[nv] = put_v(dp2[nv], nv);\n            dfs2(nv, v);\n        }\n    }\n\
    \n    void dfs3(int v, int p=-1) {\n        for(int nv : G[v]) {\n           \
    \ if(nv == p) continue;\n            ans[v] = merge(ans[v], dp1[nv]);\n      \
    \      dfs3(nv, v);\n        }\n        ans[v] = merge(ans[v], dp2[v]);\n    }\n\
    \n    vector<E> solve() {\n        dfs1(0);\n        dfs2(0);\n        dfs3(0);\n\
    \        return ans;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: dp/rerooting_dp.hpp
  requiredBy: []
  timestamp: '2024-06-25 02:46:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj/aoj_1595.test.cpp
documentation_of: dp/rerooting_dp.hpp
layout: document
redirect_from:
- /library/dp/rerooting_dp.hpp
- /library/dp/rerooting_dp.hpp.html
title: dp/rerooting_dp.hpp
---
