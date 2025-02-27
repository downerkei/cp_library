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
  bundledCode: "#line 1 \"string/lps_table.hpp\"\ntemplate<typename VType>\nvector<int>\
    \ lps_table(const VType& s) {\n    int n = s.size();\n    vector<int> lps(n +\
    \ 1);\n    lps[0] = -1;\n    int j = -1;\n    for(int i = 0; i < n; i++) {\n \
    \       while(j >= 0 && s[i] != s[j]) j = lps[j];\n        j++;\n        lps[i\
    \ + 1] = j;\n    }\n    return lps;\n}\n"
  code: "template<typename VType>\nvector<int> lps_table(const VType& s) {\n    int\
    \ n = s.size();\n    vector<int> lps(n + 1);\n    lps[0] = -1;\n    int j = -1;\n\
    \    for(int i = 0; i < n; i++) {\n        while(j >= 0 && s[i] != s[j]) j = lps[j];\n\
    \        j++;\n        lps[i + 1] = j;\n    }\n    return lps;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: string/lps_table.hpp
  requiredBy: []
  timestamp: '2025-02-27 15:42:04+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/lps_table.hpp
layout: document
redirect_from:
- /library/string/lps_table.hpp
- /library/string/lps_table.hpp.html
title: string/lps_table.hpp
---
