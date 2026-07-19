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
  bundledCode: "#line 1 \"misc/mo.hpp\"\nvoid mo() {\n    int B = W / sqrt(Q);\n\n\
    \    vector<int> ord(Q);\n    iota(ord.begin(), ord.end(), 0);\n\n    sort(ord.begin(),\
    \ ord.end(), [&](int i, int j) {\n        // \u30D6\u30ED\u30C3\u30AF\u304C\u9055\
    \u3046\u306A\u3089\uFF0C\u5C0F\u3055\u3044\u65B9\u304B\u3089\n        if(L[i]\
    \ / B != L[j] / B) {\n            return L[i] / B < L[j] / B;\n        }\n\n \
    \       // \u30D6\u30ED\u30C3\u30AF\u304C\u540C\u3058\u306A\u3089\uFF0C\u4EA4\u4E92\
    \u306B\u4E26\u3079\u308B\n        if((L[i] / B) % 2) {\n            return R[i]\
    \ > R[j];\n        }\n        return R[i] < R[j];\n    });\n\n    int cur_l =\
    \ 0;\n    int cur_r = 0;\n\n    for(int i : ord) {\n        while(cur_l > L[i])\
    \ add_l(--cur_l);\n        while(cur_l < L[i]) rem_l(cur_l++);\n        while(cur_r\
    \ > R[i]) rem_r(--cur_r);\n        while(cur_r < R[i]) add_r(cur_r++);\n\n   \
    \     ans[i] = calc();\n    }\n}\n"
  code: "void mo() {\n    int B = W / sqrt(Q);\n\n    vector<int> ord(Q);\n    iota(ord.begin(),\
    \ ord.end(), 0);\n\n    sort(ord.begin(), ord.end(), [&](int i, int j) {\n   \
    \     // \u30D6\u30ED\u30C3\u30AF\u304C\u9055\u3046\u306A\u3089\uFF0C\u5C0F\u3055\
    \u3044\u65B9\u304B\u3089\n        if(L[i] / B != L[j] / B) {\n            return\
    \ L[i] / B < L[j] / B;\n        }\n\n        // \u30D6\u30ED\u30C3\u30AF\u304C\
    \u540C\u3058\u306A\u3089\uFF0C\u4EA4\u4E92\u306B\u4E26\u3079\u308B\n        if((L[i]\
    \ / B) % 2) {\n            return R[i] > R[j];\n        }\n        return R[i]\
    \ < R[j];\n    });\n\n    int cur_l = 0;\n    int cur_r = 0;\n\n    for(int i\
    \ : ord) {\n        while(cur_l > L[i]) add_l(--cur_l);\n        while(cur_l <\
    \ L[i]) rem_l(cur_l++);\n        while(cur_r > R[i]) rem_r(--cur_r);\n       \
    \ while(cur_r < R[i]) add_r(cur_r++);\n\n        ans[i] = calc();\n    }\n}"
  dependsOn: []
  isVerificationFile: false
  path: misc/mo.hpp
  requiredBy: []
  timestamp: '2026-07-20 03:22:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/mo.hpp
layout: document
redirect_from:
- /library/misc/mo.hpp
- /library/misc/mo.hpp.html
title: misc/mo.hpp
---
