---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj/aoj_dpl_1_d.test.cpp
    title: verify/aoj/aoj_dpl_1_d.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"dp/longest_increasing_subsequence.hpp\"\ntemplate<class\
    \ T>\nint longest_increasing_subsequence(const vector<T> &A) {\n    vector<T>\
    \ lis;\n    for(const auto& p : A) {\n        // \u72ED\u7FA9\n        auto it\
    \ = lower_bound(lis.begin(), lis.end(), p);\n        if(lis.end() == it) lis.push_back(p);\n\
    \        else *it = p;\n    }\n    return lis.size();\n}\n"
  code: "template<class T>\nint longest_increasing_subsequence(const vector<T> &A)\
    \ {\n    vector<T> lis;\n    for(const auto& p : A) {\n        // \u72ED\u7FA9\
    \n        auto it = lower_bound(lis.begin(), lis.end(), p);\n        if(lis.end()\
    \ == it) lis.push_back(p);\n        else *it = p;\n    }\n    return lis.size();\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: dp/longest_increasing_subsequence.hpp
  requiredBy: []
  timestamp: '2024-06-25 03:00:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj/aoj_dpl_1_d.test.cpp
documentation_of: dp/longest_increasing_subsequence.hpp
layout: document
redirect_from:
- /library/dp/longest_increasing_subsequence.hpp
- /library/dp/longest_increasing_subsequence.hpp.html
title: dp/longest_increasing_subsequence.hpp
---
