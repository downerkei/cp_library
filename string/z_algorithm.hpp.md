---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/yosupo_zalgorithm.test.cpp
    title: verify/yosupo/yosupo_zalgorithm.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"string/z_algorithm.hpp\"\nvector<int> z_algorithm(const\
    \ string& s) {\n    int n = s.size();\n    vector<int> z(n);\n    z[0] = n;\n\
    \    int i = 1, j = 0;\n    while(i < n) {\n        while(i + j < n && s[j] ==\
    \ s[i + j]) j++;\n        z[i] = j;\n        if(j == 0) { i++; continue; } \n\
    \        int k = 1;\n        while(k < j && k + z[k] < j) { z[i + k] = z[k]; k++;\
    \ }\n        i += k; j -= k;\n    }\n    return z;\n}\n"
  code: "vector<int> z_algorithm(const string& s) {\n    int n = s.size();\n    vector<int>\
    \ z(n);\n    z[0] = n;\n    int i = 1, j = 0;\n    while(i < n) {\n        while(i\
    \ + j < n && s[j] == s[i + j]) j++;\n        z[i] = j;\n        if(j == 0) { i++;\
    \ continue; } \n        int k = 1;\n        while(k < j && k + z[k] < j) { z[i\
    \ + k] = z[k]; k++; }\n        i += k; j -= k;\n    }\n    return z;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: string/z_algorithm.hpp
  requiredBy: []
  timestamp: '2025-02-21 22:14:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/yosupo_zalgorithm.test.cpp
documentation_of: string/z_algorithm.hpp
layout: document
redirect_from:
- /library/string/z_algorithm.hpp
- /library/string/z_algorithm.hpp.html
title: string/z_algorithm.hpp
---
