---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: dp/longest_increasing_subsequence.hpp
    title: dp/longest_increasing_subsequence.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_D
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_D
  bundledCode: "#line 1 \"verify/aoj/aoj_dpl_1_d.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_D\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"dp/longest_increasing_subsequence.hpp\"\
    \ntemplate<class T>\nint longest_increasing_subsequence(const vector<T> &A) {\n\
    \    vector<T> lis;\n    for(const auto& p : A) {\n        // \u72ED\u7FA9\n \
    \       auto it = lower_bound(lis.begin(), lis.end(), p);\n        if(lis.end()\
    \ == it) lis.push_back(p);\n        else *it = p;\n    }\n    return lis.size();\n\
    }\n#line 7 \"verify/aoj/aoj_dpl_1_d.test.cpp\"\n\nint main() {\n    int n;\n \
    \   cin >> n;\n    vector<int> A(n);\n    for(int i = 0; i < n; i++) {\n     \
    \   cin >> A[i];\n    }\n    cout << longest_increasing_subsequence<int>(A) <<\
    \ endl;\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_D\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../dp/longest_increasing_subsequence.hpp\"\
    \n\nint main() {\n    int n;\n    cin >> n;\n    vector<int> A(n);\n    for(int\
    \ i = 0; i < n; i++) {\n        cin >> A[i];\n    }\n    cout << longest_increasing_subsequence<int>(A)\
    \ << endl;\n\n    return 0;\n}"
  dependsOn:
  - dp/longest_increasing_subsequence.hpp
  isVerificationFile: true
  path: verify/aoj/aoj_dpl_1_d.test.cpp
  requiredBy: []
  timestamp: '2024-06-25 09:33:29+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aoj/aoj_dpl_1_d.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj/aoj_dpl_1_d.test.cpp
- /verify/verify/aoj/aoj_dpl_1_d.test.cpp.html
title: verify/aoj/aoj_dpl_1_d.test.cpp
---
