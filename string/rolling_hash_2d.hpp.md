---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"string/rolling_hash_2d.hpp\"\nstruct RollingHash2D {\n \
    \   using u64 = uint64_t;\n\n    constexpr static u64 MOD = 998244353;\n    constexpr\
    \ static u64 BASE1 = 132678926;\n    constexpr static u64 BASE2 = 234987414;\n\
    \n    int H, W;\n    vector<vector<u64>> hashed, power;\n\n    template<class\
    \ VType>\n    RollingHash2D(const vector<VType>& V) {\n        H = (int)V.size();\n\
    \        W = (int)V[0].size();\n        power.assign(H + 1, vector<u64>(W + 1,\
    \ 0));\n        hashed.assign(H + 1, vector<u64>(W + 1, 0));\n        power[0][0]\
    \ = 1;\n\n        // mapping\n        for(int i = 0; i < H; i++) {\n         \
    \   for(int j = 0; j < W; j++) {\n                hashed[i + 1][j + 1] = V[i][j];\n\
    \            }\n        }\n\n        // BASE1\n        for(int i = 0; i <= H;\
    \ i++) {\n            for(int j = 0; j < W; j++) {\n                power[i][j\
    \ + 1] = power[i][j] * BASE1 % MOD;\n                hashed[i][j + 1] += hashed[i][j]\
    \ * BASE1;\n                hashed[i][j + 1] %= MOD;\n            }\n        }\n\
    \n        // BASE2\n        for(int i = 0; i < H; i++) {\n            for(int\
    \ j = 0; j <= W; j++) {\n                power[i + 1][j] = power[i][j] * BASE2\
    \ % MOD;\n                hashed[i + 1][j] += hashed[i][j] * BASE2;\n        \
    \        hashed[i + 1][j] %= MOD;\n            }\n        }\n    }\n\n    u64\
    \ get_hash(int l1, int r1, int l2, int r2) {\n        long long v1 = hashed[r1][r2];\n\
    \        long long v2 = (hashed[l1][r2] * power[r1 - l1][0]) % MOD;\n        long\
    \ long v3 = (hashed[r1][l2] * power[0][r2 - l2]) % MOD;\n        long long v4\
    \ = (hashed[l1][l2] * power[r1 - l1][r2 - l2]) % MOD;\n\n        return (2 * MOD\
    \ + v1 - v2 - v3 + v4) % MOD;\n    }\n};\n"
  code: "struct RollingHash2D {\n    using u64 = uint64_t;\n\n    constexpr static\
    \ u64 MOD = 998244353;\n    constexpr static u64 BASE1 = 132678926;\n    constexpr\
    \ static u64 BASE2 = 234987414;\n\n    int H, W;\n    vector<vector<u64>> hashed,\
    \ power;\n\n    template<class VType>\n    RollingHash2D(const vector<VType>&\
    \ V) {\n        H = (int)V.size();\n        W = (int)V[0].size();\n        power.assign(H\
    \ + 1, vector<u64>(W + 1, 0));\n        hashed.assign(H + 1, vector<u64>(W + 1,\
    \ 0));\n        power[0][0] = 1;\n\n        // mapping\n        for(int i = 0;\
    \ i < H; i++) {\n            for(int j = 0; j < W; j++) {\n                hashed[i\
    \ + 1][j + 1] = V[i][j];\n            }\n        }\n\n        // BASE1\n     \
    \   for(int i = 0; i <= H; i++) {\n            for(int j = 0; j < W; j++) {\n\
    \                power[i][j + 1] = power[i][j] * BASE1 % MOD;\n              \
    \  hashed[i][j + 1] += hashed[i][j] * BASE1;\n                hashed[i][j + 1]\
    \ %= MOD;\n            }\n        }\n\n        // BASE2\n        for(int i = 0;\
    \ i < H; i++) {\n            for(int j = 0; j <= W; j++) {\n                power[i\
    \ + 1][j] = power[i][j] * BASE2 % MOD;\n                hashed[i + 1][j] += hashed[i][j]\
    \ * BASE2;\n                hashed[i + 1][j] %= MOD;\n            }\n        }\n\
    \    }\n\n    u64 get_hash(int l1, int r1, int l2, int r2) {\n        long long\
    \ v1 = hashed[r1][r2];\n        long long v2 = (hashed[l1][r2] * power[r1 - l1][0])\
    \ % MOD;\n        long long v3 = (hashed[r1][l2] * power[0][r2 - l2]) % MOD;\n\
    \        long long v4 = (hashed[l1][l2] * power[r1 - l1][r2 - l2]) % MOD;\n\n\
    \        return (2 * MOD + v1 - v2 - v3 + v4) % MOD;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: string/rolling_hash_2d.hpp
  requiredBy: []
  timestamp: '2026-06-13 04:56:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/rolling_hash_2d.hpp
layout: document
redirect_from:
- /library/string/rolling_hash_2d.hpp
- /library/string/rolling_hash_2d.hpp.html
title: string/rolling_hash_2d.hpp
---
