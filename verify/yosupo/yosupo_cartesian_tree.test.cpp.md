---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tree/cartesian_tree.hpp
    title: tree/cartesian_tree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/cartesian_tree
    links:
    - https://judge.yosupo.jp/problem/cartesian_tree
  bundledCode: "#line 1 \"verify/yosupo/yosupo_cartesian_tree.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/cartesian_tree\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#line 1 \"tree/cartesian_tree.hpp\"\ntemplate<typename\
    \ T=int>\nstruct CartesianTree {\n    int n;\n    int root;\n    vector<int> lc,\
    \ rc, p;\n\n    CartesianTree(const vector<T>& a) : n(a.size()), lc(n, -1), rc(n,\
    \ -1), p(n, -1) {\n        vector<int> st;\n        for(int i = 0; i < n; i++)\
    \ {\n            int last_pop = -1;\n            // Max-Cartesian Tree\u306A\u3089\
    \ a[top] < a[i]\n            while(!st.empty() && a[st.back()] > a[i]) {\n   \
    \             last_pop = st.back();\n                st.pop_back();\n        \
    \    }\n\n            if(last_pop != -1) {\n                lc[i] = last_pop;\n\
    \                p[last_pop] = i;\n            }\n\n            if(!st.empty())\
    \ {\n                rc[st.back()] = i;\n                p[i] = st.back();\n \
    \           }\n\n            st.push_back(i);\n        }\n        if(!st.empty())\
    \ root = st.front();\n        else root = -1;\n    }\n};\n#line 7 \"verify/yosupo/yosupo_cartesian_tree.test.cpp\"\
    \n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n  \
    \  \n    int N;\n    cin >> N;\n    vector<int> A(N);\n    for(int i = 0; i <\
    \ N; i++) {\n        cin >> A[i];\n    }\n\n    CartesianTree ct(A);\n\n    for(int\
    \ i = 0; i < N; i++) {\n        cout << (ct.p[i] != -1 ? ct.p[i] : i) << \" \"\
    ;\n    }\n    cout << \"\\n\";\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/cartesian_tree\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../tree/cartesian_tree.hpp\"\
    \n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n  \
    \  \n    int N;\n    cin >> N;\n    vector<int> A(N);\n    for(int i = 0; i <\
    \ N; i++) {\n        cin >> A[i];\n    }\n\n    CartesianTree ct(A);\n\n    for(int\
    \ i = 0; i < N; i++) {\n        cout << (ct.p[i] != -1 ? ct.p[i] : i) << \" \"\
    ;\n    }\n    cout << \"\\n\";\n\n    return 0;\n}"
  dependsOn:
  - tree/cartesian_tree.hpp
  isVerificationFile: true
  path: verify/yosupo/yosupo_cartesian_tree.test.cpp
  requiredBy: []
  timestamp: '2025-12-07 06:33:02+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/yosupo_cartesian_tree.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/yosupo_cartesian_tree.test.cpp
- /verify/verify/yosupo/yosupo_cartesian_tree.test.cpp.html
title: verify/yosupo/yosupo_cartesian_tree.test.cpp
---
