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
  bundledCode: "#line 1 \"matrix/left_rotate.hpp\"\ntemplate<class T=int>\nvector<vector<T>>\
    \ left_rotate(const vector<vector<T>>& A) {\n    int N = A.size();\n    vector<vector<T>>\
    \ ret(N, vector<T>(N));\n    for(int i = 0; i < N; i++) {\n        for(int j =\
    \ 0; j < N; j++) {\n            ret[N - j - 1][i] = A[i][j];\n        }\n    }\n\
    \    return ret;\n}\n"
  code: "template<class T=int>\nvector<vector<T>> left_rotate(const vector<vector<T>>&\
    \ A) {\n    int N = A.size();\n    vector<vector<T>> ret(N, vector<T>(N));\n \
    \   for(int i = 0; i < N; i++) {\n        for(int j = 0; j < N; j++) {\n     \
    \       ret[N - j - 1][i] = A[i][j];\n        }\n    }\n    return ret;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: matrix/left_rotate.hpp
  requiredBy: []
  timestamp: '2024-10-14 14:37:27+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: matrix/left_rotate.hpp
layout: document
redirect_from:
- /library/matrix/left_rotate.hpp
- /library/matrix/left_rotate.hpp.html
title: matrix/left_rotate.hpp
---
