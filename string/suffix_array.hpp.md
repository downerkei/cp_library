---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: string/rolling_hash.hpp
    title: string/rolling_hash.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/yosupo/yosupo_suffix_array.test.cpp
    title: verify/yosupo/yosupo_suffix_array.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"string/rolling_hash.hpp\"\nstruct RollingHash{\n    using\
    \ u64 = uint64_t;\n\n    constexpr static u64 MASK30 = (1UL << 30) - 1;\n    constexpr\
    \ static u64 MASK31 = (1UL << 31) - 1;\n    constexpr static u64 MASK61 = (1UL\
    \ << 61) - 1;\n    constexpr static u64 MOD = (1UL << 61) - 1;\n    constexpr\
    \ static u64 POSITIVIZER = MOD * 4;\n\n    static inline u64 base;\n\n    int\
    \ N;\n    vector<u64> hashed, power;\n    \n    constexpr u64 mul(const u64& a,\
    \ const u64& b) const {\n        u64 au = a >> 31;\n        u64 ad = a & MASK31;\n\
    \        u64 bu = b >> 31;\n        u64 bd = b & MASK31;\n        u64 mid = ad\
    \ * bu + au * bd;\n        u64 midu = mid >> 30;\n        u64 midd = mid & MASK30;\n\
    \        return au * bu * 2 + midu + (midd << 31) + ad * bd;\n    }\n\n    constexpr\
    \ u64 calc_mod(const u64& x) const {\n        u64 xu = x >> 61;\n        u64 xd\
    \ = x & MASK61;\n        u64 ret = xu + xd;\n        if(ret >= MOD) ret -= MOD;\n\
    \        return ret;\n    }\n\n    void gen_base() {\n        random_device seed_gen;\n\
    \        mt19937_64 engine(seed_gen());\n        uniform_int_distribution<u64>\
    \ rand(0, MOD - 1);\n        base = rand(engine);\n    }\n\n    template<class\
    \ VType>\n    constexpr RollingHash(const VType& V) {\n        if(base == 0) gen_base();\n\
    \n        N = (int)V.size();\n        power.resize(N + 1, 0);\n        hashed.resize(N\
    \ + 1, 0);\n\n        power[0] = 1;\n        for(int i = 0; i < N; i++) {\n  \
    \          power[i + 1] = calc_mod(mul(power[i], base));\n            hashed[i\
    \ + 1] = calc_mod(mul(hashed[i], base) + (long long)V[i]);\n        }\n    }\n\
    \    \n    constexpr u64 get_hash(int l, int r) const {\n        return calc_mod(hashed[r]\
    \ + POSITIVIZER - mul(hashed[l], power[r - l]));\n    }\n};\n#line 2 \"string/suffix_array.hpp\"\
    \n\nbool comp(const int& i, const int& j, const RollingHash& rh) {\n    if(rh.get_hash(i,\
    \ i + 1) != rh.get_hash(j, j + 1)) return rh.get_hash(i, i + 1) < rh.get_hash(j,\
    \ j + 1);\n\n    int lb = 0, ub = 1, mx = rh.N - max(i, j) + 1;\n    while(rh.get_hash(i,\
    \ i + ub) == rh.get_hash(j, j + ub)) {\n        ub *= 5;\n        if(ub >= mx)\
    \ continue;\n        ub = mx;\n        break;\n    }\n\n    while(ub - lb > 1)\
    \ {\n        int mid = (ub + lb) / 2;\n        if(rh.get_hash(i, i + mid) == rh.get_hash(j,\
    \ j + mid)) lb = mid;\n        else ub = mid;\n    }\n\n    if(i + lb == rh.N)\
    \ return true;\n    if(j + lb == rh.N) return false;\n    return rh.get_hash(i\
    \ + lb, i + lb + 1) < rh.get_hash(j + lb, j + lb + 1);\n}\n\nvector<int> calc_suffix_array(const\
    \ string& S) {\n    RollingHash rh(S);\n    vector<int> ret(rh.N);\n    iota(ret.begin(),\
    \ ret.end(), 0);\n    sort(ret.begin(), ret.end(), [&rh](const int& i, const int&\
    \ j) { return comp(i, j, rh); });\n    return ret;\n}\n"
  code: "#include \"rolling_hash.hpp\"\n\nbool comp(const int& i, const int& j, const\
    \ RollingHash& rh) {\n    if(rh.get_hash(i, i + 1) != rh.get_hash(j, j + 1)) return\
    \ rh.get_hash(i, i + 1) < rh.get_hash(j, j + 1);\n\n    int lb = 0, ub = 1, mx\
    \ = rh.N - max(i, j) + 1;\n    while(rh.get_hash(i, i + ub) == rh.get_hash(j,\
    \ j + ub)) {\n        ub *= 5;\n        if(ub >= mx) continue;\n        ub = mx;\n\
    \        break;\n    }\n\n    while(ub - lb > 1) {\n        int mid = (ub + lb)\
    \ / 2;\n        if(rh.get_hash(i, i + mid) == rh.get_hash(j, j + mid)) lb = mid;\n\
    \        else ub = mid;\n    }\n\n    if(i + lb == rh.N) return true;\n    if(j\
    \ + lb == rh.N) return false;\n    return rh.get_hash(i + lb, i + lb + 1) < rh.get_hash(j\
    \ + lb, j + lb + 1);\n}\n\nvector<int> calc_suffix_array(const string& S) {\n\
    \    RollingHash rh(S);\n    vector<int> ret(rh.N);\n    iota(ret.begin(), ret.end(),\
    \ 0);\n    sort(ret.begin(), ret.end(), [&rh](const int& i, const int& j) { return\
    \ comp(i, j, rh); });\n    return ret;\n}\n"
  dependsOn:
  - string/rolling_hash.hpp
  isVerificationFile: false
  path: string/suffix_array.hpp
  requiredBy: []
  timestamp: '2024-12-01 03:17:31+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/yosupo/yosupo_suffix_array.test.cpp
documentation_of: string/suffix_array.hpp
layout: document
redirect_from:
- /library/string/suffix_array.hpp
- /library/string/suffix_array.hpp.html
title: string/suffix_array.hpp
---
