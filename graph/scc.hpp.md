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
    \    }\n\n    return scc;\n}\n"
  code: "vector<vector<int>> calc_scc(const vector<vector<int>>& G) {\n    int N =\
    \ G.size();\n    vector<vector<int>> RG(N);\n    for(int i = 0; i < N; i++) {\n\
    \        for(int j : G[i]) {\n            RG[j].push_back(i);\n        }\n   \
    \ }\n\n    stack<int> st;\n    vector<bool> used(N, false);\n    auto dfs = [&](auto\
    \ dfs, int v) -> void {\n        used[v] = true;\n        for(int nv : G[v]) {\n\
    \            if(used[nv]) continue;\n            dfs(dfs, nv);\n        }\n  \
    \      st.push(v);\n    };\n    for(int s = 0; s < N; s++) {\n        if(used[s])\
    \ continue;\n        dfs(dfs, s);\n    }\n\n    vector<vector<int>> scc;\n   \
    \ used.assign(N, false);\n    while(st.size()) {\n        int s = st.top();\n\
    \        st.pop();\n        if(used[s]) continue;\n\n        vector<int> component;\n\
    \        auto dfs2 = [&](auto dfs2, int v) -> void {\n            used[v] = true;\n\
    \            component.push_back(v);\n            for(int nv : RG[v]) {\n    \
    \            if(used[nv]) continue;\n                dfs2(dfs2, nv);\n       \
    \     }\n        };\n        dfs2(dfs2, s);\n\n        scc.push_back(component);\n\
    \    }\n\n    return scc;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/scc.hpp
  requiredBy: []
  timestamp: '2025-06-27 05:13:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/scc.hpp
layout: document
redirect_from:
- /library/graph/scc.hpp
- /library/graph/scc.hpp.html
title: graph/scc.hpp
---
