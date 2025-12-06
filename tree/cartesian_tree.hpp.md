---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/yosupo_cartesian_tree.test.cpp
    title: verify/yosupo/yosupo_cartesian_tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tree/cartesian_tree.hpp\"\ntemplate<typename T=int>\nstruct\
    \ CartesianTree {\n    int n;\n    int root;\n    vector<int> lc, rc, p;\n\n \
    \   CartesianTree(const vector<T>& a) : n(a.size()), lc(n, -1), rc(n, -1), p(n,\
    \ -1) {\n        vector<int> st;\n        for(int i = 0; i < n; i++) {\n     \
    \       int last_pop = -1;\n            // Max-Cartesian Tree\u306A\u3089 a[top]\
    \ < a[i]\n            while(!st.empty() && a[st.back()] > a[i]) {\n          \
    \      last_pop = st.back();\n                st.pop_back();\n            }\n\n\
    \            if(last_pop != -1) {\n                lc[i] = last_pop;\n       \
    \         p[last_pop] = i;\n            }\n\n            if(!st.empty()) {\n \
    \               rc[st.back()] = i;\n                p[i] = st.back();\n      \
    \      }\n\n            st.push_back(i);\n        }\n        if(!st.empty()) root\
    \ = st.front();\n        else root = -1;\n    }\n};\n"
  code: "template<typename T=int>\nstruct CartesianTree {\n    int n;\n    int root;\n\
    \    vector<int> lc, rc, p;\n\n    CartesianTree(const vector<T>& a) : n(a.size()),\
    \ lc(n, -1), rc(n, -1), p(n, -1) {\n        vector<int> st;\n        for(int i\
    \ = 0; i < n; i++) {\n            int last_pop = -1;\n            // Max-Cartesian\
    \ Tree\u306A\u3089 a[top] < a[i]\n            while(!st.empty() && a[st.back()]\
    \ > a[i]) {\n                last_pop = st.back();\n                st.pop_back();\n\
    \            }\n\n            if(last_pop != -1) {\n                lc[i] = last_pop;\n\
    \                p[last_pop] = i;\n            }\n\n            if(!st.empty())\
    \ {\n                rc[st.back()] = i;\n                p[i] = st.back();\n \
    \           }\n\n            st.push_back(i);\n        }\n        if(!st.empty())\
    \ root = st.front();\n        else root = -1;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: tree/cartesian_tree.hpp
  requiredBy: []
  timestamp: '2025-12-07 06:33:02+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/yosupo_cartesian_tree.test.cpp
documentation_of: tree/cartesian_tree.hpp
layout: document
redirect_from:
- /library/tree/cartesian_tree.hpp
- /library/tree/cartesian_tree.hpp.html
title: tree/cartesian_tree.hpp
---
