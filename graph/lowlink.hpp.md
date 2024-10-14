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
  bundledCode: "#line 1 \"graph/lowlink.hpp\"\nstruct Lowlink {\n    int N;\n    vector<int>\
    \ ord, low;\n    vector<pair<int, int>> bridges;\n\n    Lowlink(const vector<vector<int>>&\
    \ G) : N(G.size()), ord(N, -1), low(N, -1) { build(G); }\n\n    void build(const\
    \ vector<vector<int>>& G) {\n        int cnt = 0;\n\n        auto dfs = [&](auto\
    \ f, int v, int p) -> void {\n            ord[v] = cnt++;\n            low[v]\
    \ = ord[v];\n            for(int nv : G[v]) {\n                if(nv == p) continue;\n\
    \                // \u6728\u8FBA\n                if(ord[nv] == -1) {\n      \
    \              f(f, nv, v);\n                    low[v] = min(low[v], low[nv]);\n\
    \                    if(ord[v] < low[nv]) bridges.push_back({min(v, nv), max(v,\
    \ nv)});\n                } \n\n                // \u5F8C\u9000\u8FBA\n      \
    \          else low[v] = min(low[v], ord[nv]);\n            }\n        };\n\n\
    \        for(int i = 0; i < N; i++) {\n            if(ord[i] != -1) continue;\n\
    \            dfs(dfs, i, -1);\n        }\n    }\n\n    const vector<pair<int,\
    \ int>>& get_bridges() { return bridges; }\n    const vector<int>& get_ord() {\
    \ return ord; }\n    const vector<int>& get_low() { return low; }\n};\n"
  code: "struct Lowlink {\n    int N;\n    vector<int> ord, low;\n    vector<pair<int,\
    \ int>> bridges;\n\n    Lowlink(const vector<vector<int>>& G) : N(G.size()), ord(N,\
    \ -1), low(N, -1) { build(G); }\n\n    void build(const vector<vector<int>>& G)\
    \ {\n        int cnt = 0;\n\n        auto dfs = [&](auto f, int v, int p) -> void\
    \ {\n            ord[v] = cnt++;\n            low[v] = ord[v];\n            for(int\
    \ nv : G[v]) {\n                if(nv == p) continue;\n                // \u6728\
    \u8FBA\n                if(ord[nv] == -1) {\n                    f(f, nv, v);\n\
    \                    low[v] = min(low[v], low[nv]);\n                    if(ord[v]\
    \ < low[nv]) bridges.push_back({min(v, nv), max(v, nv)});\n                } \n\
    \n                // \u5F8C\u9000\u8FBA\n                else low[v] = min(low[v],\
    \ ord[nv]);\n            }\n        };\n\n        for(int i = 0; i < N; i++) {\n\
    \            if(ord[i] != -1) continue;\n            dfs(dfs, i, -1);\n      \
    \  }\n    }\n\n    const vector<pair<int, int>>& get_bridges() { return bridges;\
    \ }\n    const vector<int>& get_ord() { return ord; }\n    const vector<int>&\
    \ get_low() { return low; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/lowlink.hpp
  requiredBy: []
  timestamp: '2024-10-14 17:48:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/lowlink.hpp
layout: document
redirect_from:
- /library/graph/lowlink.hpp
- /library/graph/lowlink.hpp.html
title: graph/lowlink.hpp
---
