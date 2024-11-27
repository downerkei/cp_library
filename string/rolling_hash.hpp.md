---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: string/enumerate_lcp.hpp
    title: string/enumerate_lcp.hpp
  - icon: ':heavy_check_mark:'
    path: string/enumerate_palindromes.hpp
    title: string/enumerate_palindromes.hpp
  - icon: ':heavy_check_mark:'
    path: string/suffix_array.hpp
    title: string/suffix_array.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/yosupo_enumerate_palindromes.test.cpp
    title: verify/yosupo/yosupo_enumerate_palindromes.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/yosupo_suffix_array.test.cpp
    title: verify/yosupo/yosupo_suffix_array.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/yosupo_zalgorithm.test.cpp
    title: verify/yosupo/yosupo_zalgorithm.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"string/rolling_hash.hpp\"\nstruct RollingHash{\n    using\
    \ u64 = uint64_t;\n\n    constexpr static u64 MASK30 = (1UL << 30) - 1;\n    constexpr\
    \ static u64 MASK31 = (1UL << 31) - 1;\n    constexpr static u64 MASK61 = (1UL\
    \ << 61) - 1;\n    constexpr static u64 MOD = (1UL << 61) - 1;\n    constexpr\
    \ static u64 POSITIVIZER = MOD * 4;\n\n    static inline u64 base;\n\n    int\
    \ N;\n    vector<u64> hashed, power;\n    \n    u64 mul(const u64& a, const u64&\
    \ b) const {\n        u64 au = a >> 31;\n        u64 ad = a & MASK31;\n      \
    \  u64 bu = b >> 31;\n        u64 bd = b & MASK31;\n        u64 mid = ad * bu\
    \ + au * bd;\n        u64 midu = mid >> 30;\n        u64 midd = mid & MASK30;\n\
    \        return au * bu * 2 + midu + (midd << 31) + ad * bd;\n    }\n\n    u64\
    \ calc_mod(const u64& x) const {\n        u64 xu = x >> 61;\n        u64 xd =\
    \ x & MASK61;\n        u64 ret = xu + xd;\n        if(ret >= MOD) ret -= MOD;\n\
    \        return ret;\n    }\n\n    void gen_base() {\n        random_device seed_gen;\n\
    \        mt19937_64 engine(seed_gen());\n        uniform_int_distribution<u64>\
    \ rand(0, MOD - 1);\n        base = rand(engine);\n    }\n\n    template<class\
    \ VType>\n    RollingHash(const VType& V) {\n        if(base == 0) gen_base();\n\
    \n        N = (int)V.size();\n        power.resize(N + 1, 0);\n        hashed.resize(N\
    \ + 1, 0);\n\n        power[0] = 1;\n        for(int i = 0; i < N; i++) {\n  \
    \          power[i + 1] = calc_mod(mul(power[i], base));\n            hashed[i\
    \ + 1] = calc_mod(mul(hashed[i], base) + (long long)V[i]);\n        }\n    }\n\
    \    \n    u64 get_hash(int l, int r) const {\n        return calc_mod(hashed[r]\
    \ + POSITIVIZER - mul(hashed[l], power[r - l]));\n    }\n};\n"
  code: "struct RollingHash{\n    using u64 = uint64_t;\n\n    constexpr static u64\
    \ MASK30 = (1UL << 30) - 1;\n    constexpr static u64 MASK31 = (1UL << 31) - 1;\n\
    \    constexpr static u64 MASK61 = (1UL << 61) - 1;\n    constexpr static u64\
    \ MOD = (1UL << 61) - 1;\n    constexpr static u64 POSITIVIZER = MOD * 4;\n\n\
    \    static inline u64 base;\n\n    int N;\n    vector<u64> hashed, power;\n \
    \   \n    u64 mul(const u64& a, const u64& b) const {\n        u64 au = a >> 31;\n\
    \        u64 ad = a & MASK31;\n        u64 bu = b >> 31;\n        u64 bd = b &\
    \ MASK31;\n        u64 mid = ad * bu + au * bd;\n        u64 midu = mid >> 30;\n\
    \        u64 midd = mid & MASK30;\n        return au * bu * 2 + midu + (midd <<\
    \ 31) + ad * bd;\n    }\n\n    u64 calc_mod(const u64& x) const {\n        u64\
    \ xu = x >> 61;\n        u64 xd = x & MASK61;\n        u64 ret = xu + xd;\n  \
    \      if(ret >= MOD) ret -= MOD;\n        return ret;\n    }\n\n    void gen_base()\
    \ {\n        random_device seed_gen;\n        mt19937_64 engine(seed_gen());\n\
    \        uniform_int_distribution<u64> rand(0, MOD - 1);\n        base = rand(engine);\n\
    \    }\n\n    template<class VType>\n    RollingHash(const VType& V) {\n     \
    \   if(base == 0) gen_base();\n\n        N = (int)V.size();\n        power.resize(N\
    \ + 1, 0);\n        hashed.resize(N + 1, 0);\n\n        power[0] = 1;\n      \
    \  for(int i = 0; i < N; i++) {\n            power[i + 1] = calc_mod(mul(power[i],\
    \ base));\n            hashed[i + 1] = calc_mod(mul(hashed[i], base) + (long long)V[i]);\n\
    \        }\n    }\n    \n    u64 get_hash(int l, int r) const {\n        return\
    \ calc_mod(hashed[r] + POSITIVIZER - mul(hashed[l], power[r - l]));\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: string/rolling_hash.hpp
  requiredBy:
  - string/suffix_array.hpp
  - string/enumerate_palindromes.hpp
  - string/enumerate_lcp.hpp
  timestamp: '2024-11-27 19:22:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/yosupo_enumerate_palindromes.test.cpp
  - verify/yosupo/yosupo_zalgorithm.test.cpp
  - verify/yosupo/yosupo_suffix_array.test.cpp
documentation_of: string/rolling_hash.hpp
layout: document
redirect_from:
- /library/string/rolling_hash.hpp
- /library/string/rolling_hash.hpp.html
title: string/rolling_hash.hpp
---
