---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/yosupo_longest_common_substring.test.cpp
    title: verify/yosupo/yosupo_longest_common_substring.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"string/lcp_array.hpp\"\nvector<int> lcp_array(const string&\
    \ S, const vector<int>& sa) {\n    int N = S.size();\n    vector<int> rank(N);\n\
    \    for(int i = 0; i < N; i++) {\n        rank[sa[i]] = i;\n    }\n    vector<int>\
    \ lcp(N - 1);\n    int h = 0;\n    for(int i = 0; i < N; i++) {\n        if(h\
    \ > 0) h--;\n        if(rank[i] == 0) continue;\n        int j = sa[rank[i] -\
    \ 1];\n        while(i + h < N && j + h < N && S[i + h] == S[j + h]) h++;\n  \
    \      lcp[rank[i] - 1] = h;\n    }\n    return lcp;\n}\n"
  code: "vector<int> lcp_array(const string& S, const vector<int>& sa) {\n    int\
    \ N = S.size();\n    vector<int> rank(N);\n    for(int i = 0; i < N; i++) {\n\
    \        rank[sa[i]] = i;\n    }\n    vector<int> lcp(N - 1);\n    int h = 0;\n\
    \    for(int i = 0; i < N; i++) {\n        if(h > 0) h--;\n        if(rank[i]\
    \ == 0) continue;\n        int j = sa[rank[i] - 1];\n        while(i + h < N &&\
    \ j + h < N && S[i + h] == S[j + h]) h++;\n        lcp[rank[i] - 1] = h;\n   \
    \ }\n    return lcp;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: string/lcp_array.hpp
  requiredBy: []
  timestamp: '2024-12-02 02:18:27+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/yosupo_longest_common_substring.test.cpp
documentation_of: string/lcp_array.hpp
layout: document
redirect_from:
- /library/string/lcp_array.hpp
- /library/string/lcp_array.hpp.html
title: string/lcp_array.hpp
---
