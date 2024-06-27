---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/yosupo_binomial_coefficient_prime_mod.test.cpp
    title: verify/yosupo/yosupo_binomial_coefficient_prime_mod.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/binomial_coefficient.hpp\"\nstruct BinomialCoefficient{\n\
    \    int MOD;\n    vector<long long> fact, fact_inv, inv;\n\n    BinomialCoefficient(int\
    \ n=1e5, int p=998244353) : MOD(p), fact(n + 1), fact_inv(n + 1), inv(n + 1) {\n\
    \        fact[0] = fact[1] = 1;\n        fact_inv[0] = fact_inv[1] = 1;\n    \
    \    inv[1] = 1;\n\n        for(int i = 2; i <= n; i++) {\n            fact[i]\
    \ = fact[i-1] * i % MOD;\n            inv[i] = MOD - inv[MOD%i] * (MOD / i) %\
    \ MOD;\n            fact_inv[i] = fact_inv[i-1] * inv[i] % MOD;\n        }\n \
    \   }\n\n    long long comb(int n, int r) {\n        if(n < 0 || n < r || r <\
    \ 0) return 0;\n        return fact[n] * fact_inv[n-r] % MOD * fact_inv[r] % MOD;\n\
    \    }\n};\n\n// nCr\u3092\u8A08\u7B97\u3059\u308B\n// O(r)\u3067\u8A08\u7B97\uFF0C\
    \u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\u306B\u6CE8\u610F\n// 60C30 = 1e17\u304F\
    \u3089\u3044\nlong long comb(int n, int r) {\n    if(r < 0 || n < r) return 0;\n\
    \    long long ret = 1;\n    for(long long i = 1; i <= r; i++) {\n        ret\
    \ *= n--;\n        ret /= i;\n    }\n\n    return ret;\n}\n"
  code: "struct BinomialCoefficient{\n    int MOD;\n    vector<long long> fact, fact_inv,\
    \ inv;\n\n    BinomialCoefficient(int n=1e5, int p=998244353) : MOD(p), fact(n\
    \ + 1), fact_inv(n + 1), inv(n + 1) {\n        fact[0] = fact[1] = 1;\n      \
    \  fact_inv[0] = fact_inv[1] = 1;\n        inv[1] = 1;\n\n        for(int i =\
    \ 2; i <= n; i++) {\n            fact[i] = fact[i-1] * i % MOD;\n            inv[i]\
    \ = MOD - inv[MOD%i] * (MOD / i) % MOD;\n            fact_inv[i] = fact_inv[i-1]\
    \ * inv[i] % MOD;\n        }\n    }\n\n    long long comb(int n, int r) {\n  \
    \      if(n < 0 || n < r || r < 0) return 0;\n        return fact[n] * fact_inv[n-r]\
    \ % MOD * fact_inv[r] % MOD;\n    }\n};\n\n// nCr\u3092\u8A08\u7B97\u3059\u308B\
    \n// O(r)\u3067\u8A08\u7B97\uFF0C\u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\u306B\
    \u6CE8\u610F\n// 60C30 = 1e17\u304F\u3089\u3044\nlong long comb(int n, int r)\
    \ {\n    if(r < 0 || n < r) return 0;\n    long long ret = 1;\n    for(long long\
    \ i = 1; i <= r; i++) {\n        ret *= n--;\n        ret /= i;\n    }\n\n   \
    \ return ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/binomial_coefficient.hpp
  requiredBy: []
  timestamp: '2024-06-27 19:55:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/yosupo_binomial_coefficient_prime_mod.test.cpp
documentation_of: math/binomial_coefficient.hpp
layout: document
redirect_from:
- /library/math/binomial_coefficient.hpp
- /library/math/binomial_coefficient.hpp.html
title: math/binomial_coefficient.hpp
---
