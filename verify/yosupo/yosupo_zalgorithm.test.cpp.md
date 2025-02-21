---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: string/z_algorithm.hpp
    title: string/z_algorithm.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/zalgorithm
    links:
    - https://judge.yosupo.jp/problem/zalgorithm
  bundledCode: "#line 1 \"verify/yosupo/yosupo_zalgorithm.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/zalgorithm\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#line 1 \"string/z_algorithm.hpp\"\nvector<int> z_algorithm(const\
    \ string& s) {\n    int n = s.size();\n    vector<int> z(n);\n    z[0] = n;\n\
    \    int i = 1, j = 0;\n    while(i < n) {\n        while(i + j < n && s[j] ==\
    \ s[i + j]) j++;\n        z[i] = j;\n        if(j == 0) { i++; continue; } \n\
    \        int k = 1;\n        while(k < j && k + z[k] < j) { z[i + k] = z[k]; k++;\
    \ }\n        i += k; j -= k;\n    }\n    return z;\n}\n#line 7 \"verify/yosupo/yosupo_zalgorithm.test.cpp\"\
    \n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n  \
    \  string S;\n    cin >> S;\n    for(auto ans : z_algorithm(S)) {\n        cout\
    \ << ans << \" \";\n    }\n    cout << endl;\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../string/z_algorithm.hpp\"\
    \n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n  \
    \  string S;\n    cin >> S;\n    for(auto ans : z_algorithm(S)) {\n        cout\
    \ << ans << \" \";\n    }\n    cout << endl;\n\n    return 0;\n}"
  dependsOn:
  - string/z_algorithm.hpp
  isVerificationFile: true
  path: verify/yosupo/yosupo_zalgorithm.test.cpp
  requiredBy: []
  timestamp: '2025-02-21 22:14:14+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/yosupo_zalgorithm.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/yosupo_zalgorithm.test.cpp
- /verify/verify/yosupo/yosupo_zalgorithm.test.cpp.html
title: verify/yosupo/yosupo_zalgorithm.test.cpp
---
