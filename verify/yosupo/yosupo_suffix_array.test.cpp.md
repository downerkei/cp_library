---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: string/suffix_array.hpp
    title: string/suffix_array.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/suffixarray
    links:
    - https://judge.yosupo.jp/problem/suffixarray
  bundledCode: "#line 1 \"verify/yosupo/yosupo_suffix_array.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/suffixarray\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#line 1 \"string/suffix_array.hpp\"\nvector<int> suffix_array(const\
    \ string& S) {\n    int N = S.size();\n    vector<int> rank(N), sa(N);\n\n   \
    \ for(int i = 0; i < N; i++) {\n        sa[i] = i;\n        rank[i] = S[i];\n\
    \    }\n\n    for(int k = 1; k < N; k *= 2) {\n        auto get_rank = [&](int\
    \ i) -> int { return (i < N) ? rank[i] : 0; };\n\n        auto radix_sort = [&](int\
    \ k) -> void {\n            const int CHAR_SIZE = 130;\n            vector<int>\
    \ backet(max(N + 1, CHAR_SIZE), 0), nsa(N);\n            for(int i = 0; i < N;\
    \ i++) {\n                backet[get_rank(i + k)]++;\n            }\n        \
    \    for(int i = 1; i < backet.size(); i++) {\n                backet[i] += backet[i\
    \ - 1];\n            }\n            for(int i = N; i--;) {\n                int&\
    \ x = backet[get_rank(sa[i] + k)];\n                nsa[--x] = sa[i];\n      \
    \      }\n            swap(sa, nsa);\n        };\n        radix_sort(k);\n   \
    \     radix_sort(0);\n\n        vector<int> nrank(N);\n        nrank[sa[0]] =\
    \ 1;\n        for(int i = 1; i < N; i++) {\n            bool is_different = (get_rank(sa[i\
    \ - 1]) != get_rank(sa[i]) || get_rank(sa[i - 1] + k) != get_rank(sa[i] + k));\n\
    \            nrank[sa[i]] = nrank[sa[i - 1]] + is_different;\n        }\n    \
    \    swap(rank, nrank);\n    }\n\n    return sa;\n}\n#line 7 \"verify/yosupo/yosupo_suffix_array.test.cpp\"\
    \n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n  \
    \  string S;\n    cin >> S;\n    for(auto ans : suffix_array(S)) {\n        cout\
    \ << ans << \" \";\n    }\n    cout << endl;\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/suffixarray\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../string/suffix_array.hpp\"\
    \n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n  \
    \  string S;\n    cin >> S;\n    for(auto ans : suffix_array(S)) {\n        cout\
    \ << ans << \" \";\n    }\n    cout << endl;\n\n    return 0;\n}"
  dependsOn:
  - string/suffix_array.hpp
  isVerificationFile: true
  path: verify/yosupo/yosupo_suffix_array.test.cpp
  requiredBy: []
  timestamp: '2024-12-01 17:46:49+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/yosupo_suffix_array.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/yosupo_suffix_array.test.cpp
- /verify/verify/yosupo/yosupo_suffix_array.test.cpp.html
title: verify/yosupo/yosupo_suffix_array.test.cpp
---
