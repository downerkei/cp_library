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
    \   }\n\n    long long operator() (int n, int r) {\n        if(n < 0 || n < r\
    \ || r < 0) return 0;\n        assert(n < fact.size());\n        return fact[n]\
    \ * fact_inv[n-r] % MOD * fact_inv[r] % MOD;\n    }\n};\n"
  code: "struct BinomialCoefficient{\n    int MOD;\n    vector<long long> fact, fact_inv,\
    \ inv;\n\n    BinomialCoefficient(int n=1e5, int p=998244353) : MOD(p), fact(n\
    \ + 1), fact_inv(n + 1), inv(n + 1) {\n        fact[0] = fact[1] = 1;\n      \
    \  fact_inv[0] = fact_inv[1] = 1;\n        inv[1] = 1;\n\n        for(int i =\
    \ 2; i <= n; i++) {\n            fact[i] = fact[i-1] * i % MOD;\n            inv[i]\
    \ = MOD - inv[MOD%i] * (MOD / i) % MOD;\n            fact_inv[i] = fact_inv[i-1]\
    \ * inv[i] % MOD;\n        }\n    }\n\n    long long operator() (int n, int r)\
    \ {\n        if(n < 0 || n < r || r < 0) return 0;\n        assert(n < fact.size());\n\
    \        return fact[n] * fact_inv[n-r] % MOD * fact_inv[r] % MOD;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: math/binomial_coefficient.hpp
  requiredBy: []
  timestamp: '2024-11-18 13:42:40+09:00'
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
