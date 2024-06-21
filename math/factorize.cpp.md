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
  bundledCode: "#line 1 \"math/factorize.cpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nvector<pair<long long, int>> factorize(long long N) {\n    vector<pair<long\
    \ long, int>> ret;\n    for(long long p = 2; p * p <= N; p++) {\n        if(N\
    \ % p != 0) continue;\n        int e = 0;\n        while(N % p == 0) {\n     \
    \       N /= p;\n            e++;\n        }\n        ret.push_back({p, e});\n\
    \    }\n    if(N != 1) ret.push_back({N, 1});\n    return ret;\n}\n\nint main()\
    \ {\n    long long N;\n    cin >> N;\n    auto ans = factorize(N);\n    for(auto\
    \ [p, e] : ans) {\n        while(e--) {\n            cout << p << \" \";\n   \
    \     }\n    }\n    cout << endl;\n\n    return 0;\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\nvector<pair<long long,\
    \ int>> factorize(long long N) {\n    vector<pair<long long, int>> ret;\n    for(long\
    \ long p = 2; p * p <= N; p++) {\n        if(N % p != 0) continue;\n        int\
    \ e = 0;\n        while(N % p == 0) {\n            N /= p;\n            e++;\n\
    \        }\n        ret.push_back({p, e});\n    }\n    if(N != 1) ret.push_back({N,\
    \ 1});\n    return ret;\n}\n\nint main() {\n    long long N;\n    cin >> N;\n\
    \    auto ans = factorize(N);\n    for(auto [p, e] : ans) {\n        while(e--)\
    \ {\n            cout << p << \" \";\n        }\n    }\n    cout << endl;\n\n\
    \    return 0;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/factorize.cpp
  requiredBy: []
  timestamp: '2024-06-21 01:14:17+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/factorize.cpp
layout: document
redirect_from:
- /library/math/factorize.cpp
- /library/math/factorize.cpp.html
title: math/factorize.cpp
---
