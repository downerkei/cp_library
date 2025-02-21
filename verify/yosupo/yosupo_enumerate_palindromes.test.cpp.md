---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: string/manacher.hpp
    title: string/manacher.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/enumerate_palindromes
    links:
    - https://judge.yosupo.jp/problem/enumerate_palindromes
  bundledCode: "#line 1 \"verify/yosupo/yosupo_enumerate_palindromes.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_palindromes\"\n\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"string/manacher.hpp\"\
    \nvector<int> manacher(const string& s) {\n    int n = s.size();\n    vector<int>\
    \ ret(n);\n    int i = 0, j = 0;\n    while(i < n) {\n        while(i - j >= 0\
    \ && i + j < n && s[i - j] == s[i + j]) j++;\n        ret[i] = j;\n        int\
    \ k = 1;\n        while(i - k >= 0 && k + ret[i - k] < j) ret[i + k] = ret[i -\
    \ k], k++;\n        i += k; j -= k;\n    }\n    return ret;\n}\n#line 7 \"verify/yosupo/yosupo_enumerate_palindromes.test.cpp\"\
    \n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n  \
    \  string S;\n    cin >> S;\n\n    string T;\n    for(int i = 0; i < S.size();\
    \ i++) {\n        T += '$';\n        T += S[i];\n    }\n    T += '$';\n\n    auto\
    \ ans = manacher(T);\n    for(int i = 1; i < ans.size() - 1; i++) {\n        cout\
    \ << ans[i] - 1 << \" \";\n    }\n    cout << \"\\n\";\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_palindromes\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../string/manacher.hpp\"\
    \n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n  \
    \  string S;\n    cin >> S;\n\n    string T;\n    for(int i = 0; i < S.size();\
    \ i++) {\n        T += '$';\n        T += S[i];\n    }\n    T += '$';\n\n    auto\
    \ ans = manacher(T);\n    for(int i = 1; i < ans.size() - 1; i++) {\n        cout\
    \ << ans[i] - 1 << \" \";\n    }\n    cout << \"\\n\";\n\n    return 0;\n}"
  dependsOn:
  - string/manacher.hpp
  isVerificationFile: true
  path: verify/yosupo/yosupo_enumerate_palindromes.test.cpp
  requiredBy: []
  timestamp: '2025-02-21 22:29:18+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/yosupo_enumerate_palindromes.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/yosupo_enumerate_palindromes.test.cpp
- /verify/verify/yosupo/yosupo_enumerate_palindromes.test.cpp.html
title: verify/yosupo/yosupo_enumerate_palindromes.test.cpp
---
