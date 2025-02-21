---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/yosupo_enumerate_palindromes.test.cpp
    title: verify/yosupo/yosupo_enumerate_palindromes.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"string/manacher.hpp\"\nvector<int> manacher(const string&\
    \ s) {\n    int n = s.size();\n    vector<int> ret(n);\n    int i = 0, j = 0;\n\
    \    while(i < n) {\n        while(i - j >= 0 && i + j < n && s[i - j] == s[i\
    \ + j]) j++;\n        ret[i] = j;\n        int k = 1;\n        while(i - k >=\
    \ 0 && k + ret[i - k] < j) ret[i + k] = ret[i - k], k++;\n        i += k; j -=\
    \ k;\n    }\n    return ret;\n}\n"
  code: "vector<int> manacher(const string& s) {\n    int n = s.size();\n    vector<int>\
    \ ret(n);\n    int i = 0, j = 0;\n    while(i < n) {\n        while(i - j >= 0\
    \ && i + j < n && s[i - j] == s[i + j]) j++;\n        ret[i] = j;\n        int\
    \ k = 1;\n        while(i - k >= 0 && k + ret[i - k] < j) ret[i + k] = ret[i -\
    \ k], k++;\n        i += k; j -= k;\n    }\n    return ret;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: string/manacher.hpp
  requiredBy: []
  timestamp: '2025-02-21 22:29:18+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/yosupo_enumerate_palindromes.test.cpp
documentation_of: string/manacher.hpp
layout: document
redirect_from:
- /library/string/manacher.hpp
- /library/string/manacher.hpp.html
title: string/manacher.hpp
---
