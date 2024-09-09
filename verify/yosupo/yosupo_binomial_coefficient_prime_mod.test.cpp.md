---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/binomial_coefficient.hpp
    title: math/binomial_coefficient.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod
    links:
    - https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod
  bundledCode: "#line 1 \"verify/yosupo/yosupo_binomial_coefficient_prime_mod.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"math/binomial_coefficient.hpp\"\
    \nstruct BinomialCoefficient{\n    int MOD;\n    vector<long long> fact, fact_inv,\
    \ inv;\n\n    BinomialCoefficient(int n=1e5, int p=998244353) : MOD(p), fact(n\
    \ + 1), fact_inv(n + 1), inv(n + 1) {\n        fact[0] = fact[1] = 1;\n      \
    \  fact_inv[0] = fact_inv[1] = 1;\n        inv[1] = 1;\n\n        for(int i =\
    \ 2; i <= n; i++) {\n            fact[i] = fact[i-1] * i % MOD;\n            inv[i]\
    \ = MOD - inv[MOD%i] * (MOD / i) % MOD;\n            fact_inv[i] = fact_inv[i-1]\
    \ * inv[i] % MOD;\n        }\n    }\n\n    long long operator() (int n, int r)\
    \ {\n        if(n < 0 || n < r || r < 0) return 0;\n        assert(n < fact.size());\n\
    \        return fact[n] * fact_inv[n-r] % MOD * fact_inv[r] % MOD;\n    }\n};\n\
    \n// nCr\u3092\u8A08\u7B97\u3059\u308B\n// O(r)\u3067\u8A08\u7B97\uFF0C\u30AA\u30FC\
    \u30D0\u30FC\u30D5\u30ED\u30FC\u306B\u6CE8\u610F\n// 60C30 = 1e17\u304F\u3089\u3044\
    \nlong long comb(int n, int r) {\n    if(r < 0 || n < r) return 0;\n    long long\
    \ ret = 1;\n    for(long long i = 1; i <= r; i++) {\n        ret *= n--;\n   \
    \     ret /= i;\n    }\n\n    return ret;\n}\n#line 7 \"verify/yosupo/yosupo_binomial_coefficient_prime_mod.test.cpp\"\
    \n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n  \
    \  \n    int T, m;\n    cin >> T >> m;\n\n    vector<int> N(T), K(T);\n    int\
    \ mx = 0;\n    for(int i = 0; i < T; i++) {\n        cin >> N[i] >> K[i];\n  \
    \      mx = max(mx, N[i]);\n    }\n\n    BinomialCoefficient binom(mx, m);\n \
    \   for(int i = 0; i < T; i++) {\n        cout << binom(N[i], K[i]) << \"\\n\"\
    ;\n    }\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../math/binomial_coefficient.hpp\"\
    \n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n  \
    \  \n    int T, m;\n    cin >> T >> m;\n\n    vector<int> N(T), K(T);\n    int\
    \ mx = 0;\n    for(int i = 0; i < T; i++) {\n        cin >> N[i] >> K[i];\n  \
    \      mx = max(mx, N[i]);\n    }\n\n    BinomialCoefficient binom(mx, m);\n \
    \   for(int i = 0; i < T; i++) {\n        cout << binom(N[i], K[i]) << \"\\n\"\
    ;\n    }\n\n    return 0;\n}"
  dependsOn:
  - math/binomial_coefficient.hpp
  isVerificationFile: true
  path: verify/yosupo/yosupo_binomial_coefficient_prime_mod.test.cpp
  requiredBy: []
  timestamp: '2024-09-09 21:42:35+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/yosupo_binomial_coefficient_prime_mod.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/yosupo_binomial_coefficient_prime_mod.test.cpp
- /verify/verify/yosupo/yosupo_binomial_coefficient_prime_mod.test.cpp.html
title: verify/yosupo/yosupo_binomial_coefficient_prime_mod.test.cpp
---
