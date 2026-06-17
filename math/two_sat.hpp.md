---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: graph/scc.hpp
    title: graph/scc.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/scc.hpp\"\nvector<vector<int>> calc_scc(const vector<vector<int>>&\
    \ G) {\n    int N = G.size();\n    vector<vector<int>> RG(N);\n    for(int i =\
    \ 0; i < N; i++) {\n        for(int j : G[i]) {\n            RG[j].push_back(i);\n\
    \        }\n    }\n\n    stack<int> st;\n    vector<bool> used(N, false);\n  \
    \  auto dfs = [&](auto dfs, int v) -> void {\n        used[v] = true;\n      \
    \  for(int nv : G[v]) {\n            if(used[nv]) continue;\n            dfs(dfs,\
    \ nv);\n        }\n        st.push(v);\n    };\n    for(int s = 0; s < N; s++)\
    \ {\n        if(used[s]) continue;\n        dfs(dfs, s);\n    }\n\n    vector<vector<int>>\
    \ scc;\n    used.assign(N, false);\n    while(st.size()) {\n        int s = st.top();\n\
    \        st.pop();\n        if(used[s]) continue;\n\n        vector<int> component;\n\
    \        auto dfs2 = [&](auto dfs2, int v) -> void {\n            used[v] = true;\n\
    \            component.push_back(v);\n            for(int nv : RG[v]) {\n    \
    \            if(used[nv]) continue;\n                dfs2(dfs2, nv);\n       \
    \     }\n        };\n        dfs2(dfs2, s);\n\n        scc.push_back(component);\n\
    \    }\n\n    return scc;\n}\n#line 2 \"math/two_sat.hpp\"\n\nstruct two_sat {\n\
    \    int n;\n    vector<bool> ans;\n    vector<vector<int>> G;\n    two_sat(int\
    \ n) : n(n), ans(n), G(2 * n) {}\n\n    void add_clause(int i, bool f, int j,\
    \ bool g) {\n        G[2 * i + (f ? 0 : 1)].push_back(2 * j + (g ? 1 : 0));\n\
    \        G[2 * j + (g ? 0 : 1)].push_back(2 * i + (f ? 1 : 0));\n    }\n\n   \
    \ bool satisfiable() {\n        auto scc = calc_scc(G);\n        vector<int> scc_id(2\
    \ * n);\n        for(int i = 0; i < (int)scc.size(); i++) {\n            for(int\
    \ v : scc[i]) {\n                scc_id[v] = i;\n            }\n        }\n\n\
    \        for(int i = 0; i < n; i++) {\n            if(scc_id[2 * i] == scc_id[2\
    \ * i + 1]) return false;\n            ans[i] = scc_id[2 * i] < scc_id[2 * i +\
    \ 1];\n        }\n        return true;\n    }\n\n    vector<bool> answer() {\n\
    \        return ans;\n    }\n};\n"
  code: "#include \"../graph/scc.hpp\"\n\nstruct two_sat {\n    int n;\n    vector<bool>\
    \ ans;\n    vector<vector<int>> G;\n    two_sat(int n) : n(n), ans(n), G(2 * n)\
    \ {}\n\n    void add_clause(int i, bool f, int j, bool g) {\n        G[2 * i +\
    \ (f ? 0 : 1)].push_back(2 * j + (g ? 1 : 0));\n        G[2 * j + (g ? 0 : 1)].push_back(2\
    \ * i + (f ? 1 : 0));\n    }\n\n    bool satisfiable() {\n        auto scc = calc_scc(G);\n\
    \        vector<int> scc_id(2 * n);\n        for(int i = 0; i < (int)scc.size();\
    \ i++) {\n            for(int v : scc[i]) {\n                scc_id[v] = i;\n\
    \            }\n        }\n\n        for(int i = 0; i < n; i++) {\n          \
    \  if(scc_id[2 * i] == scc_id[2 * i + 1]) return false;\n            ans[i] =\
    \ scc_id[2 * i] < scc_id[2 * i + 1];\n        }\n        return true;\n    }\n\
    \n    vector<bool> answer() {\n        return ans;\n    }\n};"
  dependsOn:
  - graph/scc.hpp
  isVerificationFile: false
  path: math/two_sat.hpp
  requiredBy: []
  timestamp: '2026-06-13 04:56:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/two_sat.hpp
layout: document
redirect_from:
- /library/math/two_sat.hpp
- /library/math/two_sat.hpp.html
title: math/two_sat.hpp
---
