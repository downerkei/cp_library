---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"dp/longest_increasing_subsequence.cpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n// longest increasing subsequence\ntemplate<class T>\n\
    int longest_increasing_subsequence(const vector<T> &A) {\n    vector<T> lis;\n\
    \    for(const auto& p : A) {\n        // \u72ED\u7FA9\n        auto it = lower_bound(lis.begin(),\
    \ lis.end(), p);\n        if(lis.end() == it) lis.push_back(p);\n        else\
    \ *it = p;\n    }\n    return lis.size();\n}\n\nint main() {\n    int N;\n   \
    \ cin >> N;\n    vector<int> A(N);\n    for(int i = 0; i < N; i++) {\n       \
    \ cin >> A[i];\n    }\n    cout << longest_increasing_subsequence<int>(A) << endl;\n\
    \n    return 0;\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\n// longest increasing subsequence\n\
    template<class T>\nint longest_increasing_subsequence(const vector<T> &A) {\n\
    \    vector<T> lis;\n    for(const auto& p : A) {\n        // \u72ED\u7FA9\n \
    \       auto it = lower_bound(lis.begin(), lis.end(), p);\n        if(lis.end()\
    \ == it) lis.push_back(p);\n        else *it = p;\n    }\n    return lis.size();\n\
    }\n\nint main() {\n    int N;\n    cin >> N;\n    vector<int> A(N);\n    for(int\
    \ i = 0; i < N; i++) {\n        cin >> A[i];\n    }\n    cout << longest_increasing_subsequence<int>(A)\
    \ << endl;\n\n    return 0;\n}"
  dependsOn: []
  isVerificationFile: false
  path: dp/longest_increasing_subsequence.cpp
  requiredBy: []
  timestamp: '2024-06-21 01:14:17+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: dp/longest_increasing_subsequence.cpp
layout: document
redirect_from:
- /library/dp/longest_increasing_subsequence.cpp
- /library/dp/longest_increasing_subsequence.cpp.html
title: dp/longest_increasing_subsequence.cpp
---
