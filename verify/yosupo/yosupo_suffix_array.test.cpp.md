---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: string/rolling_hash.hpp
    title: string/rolling_hash.hpp
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
    using namespace std;\n\n#line 2 \"string/suffix_array.hpp\"\nusing namespace std;\n\
    #line 1 \"string/rolling_hash.hpp\"\nstruct RollingHash{\n    using u64 = uint64_t;\n\
    \n    constexpr static u64 MASK30 = (1UL << 30) - 1;\n    constexpr static u64\
    \ MASK31 = (1UL << 31) - 1;\n    constexpr static u64 MASK61 = (1UL << 61) - 1;\n\
    \    constexpr static u64 MOD = (1UL << 61) - 1;\n    constexpr static u64 POSITIVIZER\
    \ = MOD * 4;\n\n    static inline u64 base;\n\n    int N;\n    vector<u64> hashed,\
    \ power;\n    \n    u64 mul(const u64& a, const u64& b) const {\n        u64 au\
    \ = a >> 31;\n        u64 ad = a & MASK31;\n        u64 bu = b >> 31;\n      \
    \  u64 bd = b & MASK31;\n        u64 mid = ad * bu + au * bd;\n        u64 midu\
    \ = mid >> 30;\n        u64 midd = mid & MASK30;\n        return au * bu * 2 +\
    \ midu + (midd << 31) + ad * bd;\n    }\n\n    u64 calc_mod(const u64& x) const\
    \ {\n        u64 xu = x >> 61;\n        u64 xd = x & MASK61;\n        u64 ret\
    \ = xu + xd;\n        if(ret >= MOD) ret -= MOD;\n        return ret;\n    }\n\
    \n    void gen_base() {\n        random_device seed_gen;\n        mt19937_64 engine(seed_gen());\n\
    \        uniform_int_distribution<u64> rand(0, MOD - 1);\n        base = rand(engine);\n\
    \    }\n\n    RollingHash(const string& S) { init<string>(S); }\n    RollingHash(const\
    \ vector<int>& V) { init<vector<int>>(V); }\n\n    template<class VType>\n   \
    \ void init(const VType& V) {\n        if(base == 0) gen_base();\n\n        N\
    \ = (int)V.size();\n        power.resize(N + 1, 0);\n        hashed.resize(N +\
    \ 1, 0);\n\n        power[0] = 1;\n        for(int i = 0; i < N; i++) {\n    \
    \        power[i + 1] = calc_mod(mul(power[i], base));\n            hashed[i +\
    \ 1] = calc_mod(mul(hashed[i], base) + (long long)V[i]);\n        }\n    }\n \
    \   \n    u64 get_hash(int l, int r) const {\n        return calc_mod(hashed[r]\
    \ + POSITIVIZER - mul(hashed[l], power[r - l]));\n    }\n};\n#line 4 \"string/suffix_array.hpp\"\
    \n\nint get_LCP(int p, const RollingHash& rh) {\n    int lb = 0, ub = rh.N - p\
    \ + 1;\n    while(ub - lb > 1) {\n        int mid = (ub + lb) / 2;\n        if(rh.get_hash(p,\
    \ p + mid) == rh.get_hash(0, mid)) lb = mid;\n        else ub = mid;\n    }\n\
    \    return lb;\n}\n\nvector<int> all_LCP(const RollingHash& rh) {\n    vector<int>\
    \ ret(rh.N);\n    for(int i = 0; i < rh.N; i++) {\n        ret[i] = get_LCP(i,\
    \ rh);\n    }\n    return ret;\n}\n\nbool comp(const int& i, const int& j, const\
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
    \ comp(i, j, rh); });\n    return ret;\n}\n#line 7 \"verify/yosupo/yosupo_suffix_array.test.cpp\"\
    \n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n  \
    \  string S;\n    cin >> S;\n    for(auto ans : calc_suffix_array(S)) {\n    \
    \    cout << ans << \" \";\n    }\n    cout << endl;\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/suffixarray\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../string/suffix_array.hpp\"\
    \n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n  \
    \  string S;\n    cin >> S;\n    for(auto ans : calc_suffix_array(S)) {\n    \
    \    cout << ans << \" \";\n    }\n    cout << endl;\n\n    return 0;\n}"
  dependsOn:
  - string/suffix_array.hpp
  - string/rolling_hash.hpp
  isVerificationFile: true
  path: verify/yosupo/yosupo_suffix_array.test.cpp
  requiredBy: []
  timestamp: '2024-11-20 09:44:16+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/yosupo_suffix_array.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/yosupo_suffix_array.test.cpp
- /verify/verify/yosupo/yosupo_suffix_array.test.cpp.html
title: verify/yosupo/yosupo_suffix_array.test.cpp
---
