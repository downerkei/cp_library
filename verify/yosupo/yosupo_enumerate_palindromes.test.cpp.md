---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: string/enumerate_palindromes.hpp
    title: string/enumerate_palindromes.hpp
  - icon: ':heavy_check_mark:'
    path: string/rolling_hash.hpp
    title: string/rolling_hash.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/enumerate_palindromes
    links:
    - https://judge.yosupo.jp/problem/enumerate_palindromes
  bundledCode: "#line 1 \"verify/yosupo/yosupo_enumerate_palindromes.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_palindromes\"\n\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"string/rolling_hash.hpp\"\
    \nstruct RollingHash{\n    using u64 = uint64_t;\n\n    constexpr static u64 MASK30\
    \ = (1UL << 30) - 1;\n    constexpr static u64 MASK31 = (1UL << 31) - 1;\n   \
    \ constexpr static u64 MASK61 = (1UL << 61) - 1;\n    constexpr static u64 MOD\
    \ = (1UL << 61) - 1;\n    constexpr static u64 POSITIVIZER = MOD * 4;\n\n    static\
    \ inline u64 base;\n\n    int N;\n    vector<u64> hashed, power;\n    \n    u64\
    \ mul(const u64& a, const u64& b) const {\n        u64 au = a >> 31;\n       \
    \ u64 ad = a & MASK31;\n        u64 bu = b >> 31;\n        u64 bd = b & MASK31;\n\
    \        u64 mid = ad * bu + au * bd;\n        u64 midu = mid >> 30;\n       \
    \ u64 midd = mid & MASK30;\n        return au * bu * 2 + midu + (midd << 31) +\
    \ ad * bd;\n    }\n\n    u64 calc_mod(const u64& x) const {\n        u64 xu =\
    \ x >> 61;\n        u64 xd = x & MASK61;\n        u64 ret = xu + xd;\n       \
    \ if(ret >= MOD) ret -= MOD;\n        return ret;\n    }\n\n    void gen_base()\
    \ {\n        random_device seed_gen;\n        mt19937_64 engine(seed_gen());\n\
    \        uniform_int_distribution<u64> rand(0, MOD - 1);\n        base = rand(engine);\n\
    \    }\n\n    template<class VType>\n    RollingHash(const VType& V) {\n     \
    \   if(base == 0) gen_base();\n\n        N = (int)V.size();\n        power.resize(N\
    \ + 1, 0);\n        hashed.resize(N + 1, 0);\n\n        power[0] = 1;\n      \
    \  for(int i = 0; i < N; i++) {\n            power[i + 1] = calc_mod(mul(power[i],\
    \ base));\n            hashed[i + 1] = calc_mod(mul(hashed[i], base) + (long long)V[i]);\n\
    \        }\n    }\n    \n    u64 get_hash(int l, int r) const {\n        return\
    \ calc_mod(hashed[r] + POSITIVIZER - mul(hashed[l], power[r - l]));\n    }\n};\n\
    #line 2 \"string/enumerate_palindromes.hpp\"\n\nint get_palindrome(int p, const\
    \ RollingHash& a, const RollingHash& b) {\n    int N = a.N;\n    int q = N - p\
    \ - 1;\n\n    int lb = 0, ub = min(N - p, p + 1);\n    while(ub - lb > 1) {\n\
    \        int mid = (ub + lb) / 2;\n        if(a.get_hash(p - mid, p + mid + 1)\
    \ == b.get_hash(q - mid, q + mid + 1)) lb = mid;\n        else ub = mid;\n   \
    \ }\n\n    return lb;\n}\n\nvector<int> enumerate_palindromes(string S) {\n  \
    \  int N = S.size();\n    string T = \"\";\n    for(int i = 0; i < N; i++) {\n\
    \        T += '$';\n        T += S[i];\n    }\n    T += '$';\n    RollingHash\
    \ a(T);\n    reverse(T.begin(), T.end());\n    RollingHash b(T);\n    vector<int>\
    \ ret;\n    for(int i = 1; i < (int)T.size() - 1; i++) {\n        ret.push_back(get_palindrome(i,\
    \ a, b));\n    }\n\n    return ret;\n}\n#line 7 \"verify/yosupo/yosupo_enumerate_palindromes.test.cpp\"\
    \n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n  \
    \  string S;\n    cin >> S;\n    for(auto ans : enumerate_palindromes(S)) {\n\
    \        cout << ans << \" \";\n    }\n    cout << \"\\n\";\n\n    return 0;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_palindromes\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../string/enumerate_palindromes.hpp\"\
    \n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n  \
    \  string S;\n    cin >> S;\n    for(auto ans : enumerate_palindromes(S)) {\n\
    \        cout << ans << \" \";\n    }\n    cout << \"\\n\";\n\n    return 0;\n\
    }"
  dependsOn:
  - string/enumerate_palindromes.hpp
  - string/rolling_hash.hpp
  isVerificationFile: true
  path: verify/yosupo/yosupo_enumerate_palindromes.test.cpp
  requiredBy: []
  timestamp: '2024-11-27 19:22:43+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/yosupo_enumerate_palindromes.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/yosupo_enumerate_palindromes.test.cpp
- /verify/verify/yosupo/yosupo_enumerate_palindromes.test.cpp.html
title: verify/yosupo/yosupo_enumerate_palindromes.test.cpp
---
