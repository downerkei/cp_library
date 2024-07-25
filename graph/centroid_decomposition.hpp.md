---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yukicoder/yukicoder_1002.test.cpp
    title: verify/yukicoder/yukicoder_1002.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/centroid_decomposition.hpp\"\nstruct CentroidDecomposition{\n\
    \    vector<vector<int>> G, T;\n    vector<int> sub, ord;\n    vector<int> used;\n\
    \    int r;\n \n    CentroidDecomposition(vector<vector<int>>& G) : G(G), T(G.size()),\
    \ sub(G.size()), used(G.size()) {\n        build_dfs();\n    } \n \n    int calc_sub(int\
    \ v, int p=-1) {\n        sub[v] = 1;\n        for(int nv : G[v]) {\n        \
    \    if(used[nv] || p == nv) continue;\n            sub[v] += calc_sub(nv, v);\n\
    \        }\n        return sub[v];\n    }\n \n    int find_centroid(int v, int\
    \ mid, int p=-1) {\n        for(int nv : G[v]) {\n            if(used[nv] || p\
    \ == nv) continue;\n            if(sub[nv] > mid) return find_centroid(nv, mid,\
    \ v);\n        }\n        return v;\n    }\n \n    void build_dfs(int v=0, int\
    \ p=-1) {\n        int sz = calc_sub(v);\n        int centroid = find_centroid(v,\
    \ sz / 2);\n        used[centroid] = true;\n        ord.push_back(centroid);\n\
    \ \n        if(p == -1) r = centroid;\n        else {\n            T[p].push_back(centroid);\n\
    \            T[centroid].push_back(p);\n        }\n \n        for(int nv : G[centroid])\
    \ {\n            if(used[nv]) continue;\n            build_dfs(nv, centroid);\n\
    \        }\n    }\n};\n"
  code: "struct CentroidDecomposition{\n    vector<vector<int>> G, T;\n    vector<int>\
    \ sub, ord;\n    vector<int> used;\n    int r;\n \n    CentroidDecomposition(vector<vector<int>>&\
    \ G) : G(G), T(G.size()), sub(G.size()), used(G.size()) {\n        build_dfs();\n\
    \    } \n \n    int calc_sub(int v, int p=-1) {\n        sub[v] = 1;\n       \
    \ for(int nv : G[v]) {\n            if(used[nv] || p == nv) continue;\n      \
    \      sub[v] += calc_sub(nv, v);\n        }\n        return sub[v];\n    }\n\
    \ \n    int find_centroid(int v, int mid, int p=-1) {\n        for(int nv : G[v])\
    \ {\n            if(used[nv] || p == nv) continue;\n            if(sub[nv] > mid)\
    \ return find_centroid(nv, mid, v);\n        }\n        return v;\n    }\n \n\
    \    void build_dfs(int v=0, int p=-1) {\n        int sz = calc_sub(v);\n    \
    \    int centroid = find_centroid(v, sz / 2);\n        used[centroid] = true;\n\
    \        ord.push_back(centroid);\n \n        if(p == -1) r = centroid;\n    \
    \    else {\n            T[p].push_back(centroid);\n            T[centroid].push_back(p);\n\
    \        }\n \n        for(int nv : G[centroid]) {\n            if(used[nv]) continue;\n\
    \            build_dfs(nv, centroid);\n        }\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/centroid_decomposition.hpp
  requiredBy: []
  timestamp: '2024-07-26 01:37:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yukicoder/yukicoder_1002.test.cpp
documentation_of: graph/centroid_decomposition.hpp
layout: document
redirect_from:
- /library/graph/centroid_decomposition.hpp
- /library/graph/centroid_decomposition.hpp.html
title: graph/centroid_decomposition.hpp
---
