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
  bundledCode: "#line 1 \"other/matching/gale_shapley.cpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n// gale-shapley\u30A2\u30EB\u30B4\u30EA\u30BA\u30E0\n\
    // \u5B89\u5B9A\u30DE\u30C3\u30C1\u30F3\u30B0\n\n// \u5165\u529B\uFF1A\u5404\u4EBA\
    \u597D\u307F\u306E\u9806\u4F4D\u306E\u4E8C\u6B21\u5143\u914D\u5217x2\n// A[i][j]:\
    \ i\u756A\u76EE\u306E\u4EBA\u304Cj\u756A\u76EE\u306B\u597D\u304D\u306A\u4EBA\n\
    // \u51FA\u529B\uFF1A\u30DE\u30C3\u30C1\u30F3\u30B0(pair)\u306Evector\nvector<pair<int,\
    \ int>> gale_shapley(const vector<vector<int>>& A, const vector<vector<int>>&\
    \ B) {\n    int N = A.size();\n    int M = B.size();\n\n    // B_rank[i][j]: i\u756A\
    \u76EE\u306E\u4EBA\u304B\u3089\u898B\u3066j\u306F\u4F55\u756A\u76EE\u304B\n  \
    \  // B\u304B\u3089\u898B\u305FA\u306E\u4EBA\u306E\u30E9\u30F3\u30AF\n    vector<vector<int>>\
    \ B_rank(M, vector<int>(N));\n    for(int i = 0; i < M; i++) {\n        for(int\
    \ j = 0; j < N; j++) {\n            B_rank[i][B[i][j]] = j;\n        }\n    }\n\
    \n    // A\u306E\u4EBA\u304C\u5165\u308B\u30AD\u30E5\u30FC\n    queue<int> q;\n\
    \    for(int i = 0; i < N; i++) {\n        q.push(i);\n    }\n\n    // A\u304C\
    \u632F\u3089\u308C\u3066\u3044\u306A\u3044\u4E2D\u3067\u518D\u4E0A\u4F4D\u306E\
    \u9806\u4F4D\u3092\u7BA1\u7406\n    vector<int> A_best_rank(N, 0);\n\n    // B\u304C\
    \u30AD\u30FC\u30D7\u3057\u3066\u3044\u308B\u4EBA\u306E\u512A\u5148\u9806\u4F4D\
    \n    vector<int> B_keep_rank(M, N);\n\n    // \u8AB0\u306B\u3082\u30AD\u30FC\u30D7\
    \u3055\u308C\u3066\u306A\u3044A\u304C\u3044\u308C\u3070\u4ECA\u307E\u3067\u632F\
    \u3089\u308C\u3066\u3044\u306A\u3044\u4E2D\u3067\u518D\u4E0A\u4F4D\u306B\u58F0\
    \u3092\u304B\u3051\u308B\n    while(q.size()) {\n        int a = q.front(); q.pop();\n\
    \        if(A_best_rank[a] < M) {\n            int a_rank = A_best_rank[a];\n\
    \            int b = A[a][a_rank];\n\n            // B_keep_rank vs b\u304B\u3089\
    \u898B\u305Fa\u306E\u30E9\u30F3\u30AF\n            // \u53D7\u7406\u30D1\u30BF\
    \u30FC\u30F3\n            if(B_keep_rank[b] > B_rank[b][a]) {\n              \
    \  int dumpted_rank = B_keep_rank[b];\n                // \u76F8\u624B\u304C\u3044\
    \u308C\u3070\u632F\u308B\n                if(dumpted_rank != N) {\n          \
    \          int dumpted = B[b][dumpted_rank];\n                    q.push(dumpted);\n\
    \                    A_best_rank[dumpted]++;\n                }\n\n          \
    \      // \u30DA\u30A2\u66F4\u65B0\n                B_keep_rank[b] = B_rank[b][a];\n\
    \            }\n\n            // \u62D2\u5426\u30D1\u30BF\u30FC\u30F3\n      \
    \      else {\n                // a\u304C\u632F\u3089\u308C\u308B\n          \
    \      q.push(a);\n                A_best_rank[a]++;\n            }\n        }\n\
    \    }\n\n    for(int i = 0; i < M; i++) {\n        cout << i << \" \" << B_keep_rank[i]\
    \ << endl;\n    }\n\n    // \u8FD4\u308A\u5024\u69CB\u7BC9\n    vector<pair<int,\
    \ int>> ret;\n    for(int i = 0; i < M; i++) {\n        int a_rank = B_keep_rank[i];\n\
    \        if(a_rank == N) continue;\n        int a = B[i][a_rank];\n        ret.push_back({a,\
    \ i});\n    }\n\n    return ret;\n}\n\nint main() {\n    int N, M;\n    cin >>\
    \ N >> M;\n\n    vector<vector<int>> A(N, vector<int>(M)), B(M, vector<int>(N));\n\
    \n    for(int i = 0; i < N; i++) {\n        for(int j = 0; j < M; j++) {\n   \
    \         cin >> A[i][j];\n        }\n    }\n\n    for(int i = 0; i < M; i++)\
    \ {\n        for(int j = 0; j < N; j++) {\n            cin >> B[i][j];\n     \
    \   }\n    }\n\n    auto ans = gale_shapley(A, B);\n\n\n    cout << ans.size()\
    \ << endl;\n    for(auto [a, b] : ans) {\n        cout << a << \" \" << b << endl;\n\
    \    }\n    \n\n    return 0;\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\n// gale-shapley\u30A2\u30EB\
    \u30B4\u30EA\u30BA\u30E0\n// \u5B89\u5B9A\u30DE\u30C3\u30C1\u30F3\u30B0\n\n//\
    \ \u5165\u529B\uFF1A\u5404\u4EBA\u597D\u307F\u306E\u9806\u4F4D\u306E\u4E8C\u6B21\
    \u5143\u914D\u5217x2\n// A[i][j]: i\u756A\u76EE\u306E\u4EBA\u304Cj\u756A\u76EE\
    \u306B\u597D\u304D\u306A\u4EBA\n// \u51FA\u529B\uFF1A\u30DE\u30C3\u30C1\u30F3\u30B0\
    (pair)\u306Evector\nvector<pair<int, int>> gale_shapley(const vector<vector<int>>&\
    \ A, const vector<vector<int>>& B) {\n    int N = A.size();\n    int M = B.size();\n\
    \n    // B_rank[i][j]: i\u756A\u76EE\u306E\u4EBA\u304B\u3089\u898B\u3066j\u306F\
    \u4F55\u756A\u76EE\u304B\n    // B\u304B\u3089\u898B\u305FA\u306E\u4EBA\u306E\u30E9\
    \u30F3\u30AF\n    vector<vector<int>> B_rank(M, vector<int>(N));\n    for(int\
    \ i = 0; i < M; i++) {\n        for(int j = 0; j < N; j++) {\n            B_rank[i][B[i][j]]\
    \ = j;\n        }\n    }\n\n    // A\u306E\u4EBA\u304C\u5165\u308B\u30AD\u30E5\
    \u30FC\n    queue<int> q;\n    for(int i = 0; i < N; i++) {\n        q.push(i);\n\
    \    }\n\n    // A\u304C\u632F\u3089\u308C\u3066\u3044\u306A\u3044\u4E2D\u3067\
    \u518D\u4E0A\u4F4D\u306E\u9806\u4F4D\u3092\u7BA1\u7406\n    vector<int> A_best_rank(N,\
    \ 0);\n\n    // B\u304C\u30AD\u30FC\u30D7\u3057\u3066\u3044\u308B\u4EBA\u306E\u512A\
    \u5148\u9806\u4F4D\n    vector<int> B_keep_rank(M, N);\n\n    // \u8AB0\u306B\u3082\
    \u30AD\u30FC\u30D7\u3055\u308C\u3066\u306A\u3044A\u304C\u3044\u308C\u3070\u4ECA\
    \u307E\u3067\u632F\u3089\u308C\u3066\u3044\u306A\u3044\u4E2D\u3067\u518D\u4E0A\
    \u4F4D\u306B\u58F0\u3092\u304B\u3051\u308B\n    while(q.size()) {\n        int\
    \ a = q.front(); q.pop();\n        if(A_best_rank[a] < M) {\n            int a_rank\
    \ = A_best_rank[a];\n            int b = A[a][a_rank];\n\n            // B_keep_rank\
    \ vs b\u304B\u3089\u898B\u305Fa\u306E\u30E9\u30F3\u30AF\n            // \u53D7\
    \u7406\u30D1\u30BF\u30FC\u30F3\n            if(B_keep_rank[b] > B_rank[b][a])\
    \ {\n                int dumpted_rank = B_keep_rank[b];\n                // \u76F8\
    \u624B\u304C\u3044\u308C\u3070\u632F\u308B\n                if(dumpted_rank !=\
    \ N) {\n                    int dumpted = B[b][dumpted_rank];\n              \
    \      q.push(dumpted);\n                    A_best_rank[dumpted]++;\n       \
    \         }\n\n                // \u30DA\u30A2\u66F4\u65B0\n                B_keep_rank[b]\
    \ = B_rank[b][a];\n            }\n\n            // \u62D2\u5426\u30D1\u30BF\u30FC\
    \u30F3\n            else {\n                // a\u304C\u632F\u3089\u308C\u308B\
    \n                q.push(a);\n                A_best_rank[a]++;\n            }\n\
    \        }\n    }\n\n    for(int i = 0; i < M; i++) {\n        cout << i << \"\
    \ \" << B_keep_rank[i] << endl;\n    }\n\n    // \u8FD4\u308A\u5024\u69CB\u7BC9\
    \n    vector<pair<int, int>> ret;\n    for(int i = 0; i < M; i++) {\n        int\
    \ a_rank = B_keep_rank[i];\n        if(a_rank == N) continue;\n        int a =\
    \ B[i][a_rank];\n        ret.push_back({a, i});\n    }\n\n    return ret;\n}\n\
    \nint main() {\n    int N, M;\n    cin >> N >> M;\n\n    vector<vector<int>> A(N,\
    \ vector<int>(M)), B(M, vector<int>(N));\n\n    for(int i = 0; i < N; i++) {\n\
    \        for(int j = 0; j < M; j++) {\n            cin >> A[i][j];\n        }\n\
    \    }\n\n    for(int i = 0; i < M; i++) {\n        for(int j = 0; j < N; j++)\
    \ {\n            cin >> B[i][j];\n        }\n    }\n\n    auto ans = gale_shapley(A,\
    \ B);\n\n\n    cout << ans.size() << endl;\n    for(auto [a, b] : ans) {\n   \
    \     cout << a << \" \" << b << endl;\n    }\n    \n\n    return 0;\n}"
  dependsOn: []
  isVerificationFile: false
  path: other/matching/gale_shapley.cpp
  requiredBy: []
  timestamp: '2024-06-21 02:11:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: other/matching/gale_shapley.cpp
layout: document
redirect_from:
- /library/other/matching/gale_shapley.cpp
- /library/other/matching/gale_shapley.cpp.html
title: other/matching/gale_shapley.cpp
---
