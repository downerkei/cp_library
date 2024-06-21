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
  bundledCode: "#line 1 \"string/rollong_hash.cpp\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\nstruct RollingHash{\n    using u64 = uint64_t;\n\n    // \u5B9A\
    \u6570\n    constexpr static u64 MASK30 = (1UL << 30) - 1;\n    constexpr static\
    \ u64 MASK31 = (1UL << 31) - 1;\n    constexpr static u64 MASK61 = (1UL << 61)\
    \ - 1;\n    constexpr static u64 MOD = (1UL << 61) - 1;\n    constexpr static\
    \ u64 POSITIVIZER = MOD * 4;\n\n    // static\u5909\u6570\n    static inline u64\
    \ base;\n\n    // \u30E1\u30F3\u30D0\u5909\u6570\n    int N;\n    vector<u64>\
    \ hashed, power;\n    \n    // 30bit, 31bit\u3067\u533A\u5207\u308B\u639B\u3051\
    \u7B97\n    u64 mul(const u64& a, const u64& b) {\n        u64 au = a >> 31;\n\
    \        u64 ad = a & MASK31;\n        u64 bu = b >> 31;\n        u64 bd = b &\
    \ MASK31;\n        u64 mid = ad * bu + au * bd;\n        u64 midu = mid >> 30;\n\
    \        u64 midd = mid & MASK30;\n        return au * bu * 2 + midu + (midd <<\
    \ 31) + ad * bd;\n    }\n\n    // mod\u3092\u53D6\u308B\n    u64 calc_mod(const\
    \ u64& x) {\n        u64 xu = x >> 61;\n        u64 xd = x & MASK61;\n       \
    \ u64 ret = xu + xd;\n        if(ret >= MOD) ret -= MOD;\n        return ret;\n\
    \    }\n\n    // base\u3092[0, MOD)\u304B\u3089\u4E71\u629E\n    void gen_base()\
    \ {\n        random_device seed_gen;\n        mt19937_64 engine(seed_gen());\n\
    \        uniform_int_distribution<u64> rand(0, MOD - 1);\n        base = rand(engine);\n\
    \    }\n\n    // \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF(\u6587\u5B57\u5217\
    )\n    RollingHash(const string& S) {\n        // base\u521D\u671F\u5316\n   \
    \     if(base == 0) gen_base();\n\n        // \u5909\u6570\u521D\u671F\u5316\n\
    \        N = (int)S.size();\n        power.resize(N + 1, 0);\n        hashed.resize(N\
    \ + 1, 0);\n\n        // power, hashed\u8A08\u7B97\n        power[0] = 1;\n  \
    \      for(int i = 0; i < N; i++) {\n            power[i + 1] = calc_mod(mul(power[i],\
    \ base));\n            hashed[i + 1] = calc_mod(mul(hashed[i], base) + S[i]);\n\
    \        }\n    }\n    // \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF(\u6570\u5217\
    )\n    RollingHash(const vector<int>& V) {\n        // base\u521D\u671F\u5316\n\
    \        if(base == 0) gen_base();\n\n        // \u5909\u6570\u521D\u671F\u5316\
    \n        N = (int)V.size();\n        power.resize(N + 1, 0);\n        hashed.resize(N\
    \ + 1, 0);\n\n        // power, hashed\u8A08\u7B97\n        power[0] = 1;\n  \
    \      for(int i = 0; i < N; i++) {\n            power[i + 1] = mul(power[i],\
    \ base);\n            hashed[i + 1] = calc_mod(mul(hashed[i], base) + V[i]);\n\
    \        }\n    }\n    \n    // [l, r)\u306E\u30CF\u30C3\u30B7\u30E5\u3092\u8A08\
    \u7B97\n    u64 get_hash(int l, int r) {\n        return calc_mod(hashed[r] +\
    \ POSITIVIZER - mul(hashed[l], power[r - l]));\n    }\n\n    // p\u59CB\u70B9\u306E\
    LCP\u8A08\u7B97\n    int get_LCP(int p) {\n        int lb = -1, ub = N - p + 1;\n\
    \        while(ub - lb > 1) {\n            int mid = (ub + lb) / 2;\n        \
    \    if(get_hash(p, p + mid) == get_hash(0, mid)) lb = mid;\n            else\
    \ ub = mid;\n        }\n        return lb;\n    }\n\n    // \u5168\u3066\u306E\
    LCP\u3092\u8FD4\u3059\n    vector<int> all_LCP() {\n        vector<int> ret(N);\n\
    \        for(int i = 0; i < N; i++) {\n            ret[i] = get_LCP(i);\n    \
    \    }\n        return ret;\n    }\n\n    // \u6BD4\u8F03\u95A2\u6570\uFF0CO(logN)\u3067\
    i\u3068j\u306E\u63A5\u5C3E\u8F9E\u3092\u6BD4\u8F03\uFF0Csubstr(i) < substr(j)\u3092\
    \u8FD4\u3059\n    bool comp(const int& i, const int& j) {\n        if(get_hash(i,\
    \ i + 1) != get_hash(j, j + 1)) return get_hash(i, i + 1) < get_hash(j, j + 1);\n\
    \n        // \u6307\u6570\u63A2\u7D22\u3067\u4E0A\u754C\u3092\u6C7A\u3081\u308B\
    \n        int lb = 0, ub = 1, ma = N - max(i, j) + 1;\n        while(get_hash(i,\
    \ i + ub) == get_hash(j, j + ub)) {\n            ub *= 5;\n            if(ub >=\
    \ ma) {\n                ub = ma;\n                break;\n            }\n   \
    \     }\n\n        // \u4E8C\u5206\u63A2\u7D22\u3067\u6700\u5927\u5171\u901A\u63A5\
    \u982D\u8F9E\u9577\u3092\u5F97\u308B\n        while(ub - lb > 1) {\n         \
    \   int mid = (ub + lb) / 2;\n            if(get_hash(i, i + mid) == get_hash(j,\
    \ j + mid)) lb = mid;\n            else ub = mid;\n        }\n        if(i + lb\
    \ == N) return true;\n        if(j + lb == N) return false;\n        return get_hash(i\
    \ + lb, i + lb + 1) < get_hash(j + lb, j + lb + 1);\n    }\n\n    // SA\u3092\u8FD4\
    \u3059\uFF0CO(Nlog^2N)\n    vector<int> suffix_array() {\n        vector<int>\
    \ ret(N);\n        iota(ret.begin(), ret.end(), 0);\n        sort(ret.begin(),\
    \ ret.end(), [this](const int& i, const int& j) { return comp(i, j); });\n   \
    \     return ret;\n    }\n};\n\n// b\u306Fa\u306E\u53CD\u8EE2\u5217\uFF0Cp\u4E2D\
    \u5FC3(odd = false\u306A\u3089p\u3068p + 1\u4E2D\u5FC3)\u306E\u56DE\u6587\u306E\
    \u9577\u3055\u3092\u8FD4\u3059\nint get_palindrome(int p, bool odd, RollingHash&\
    \ a, RollingHash& b) {\n    int N = a.N;\n    int q = N - p - 1;\n\n    // \u5947\
    \u6570\n    if(odd) {\n        int lb = -1, ub = min(N - p, p + 1);\n        while(ub\
    \ - lb > 1) {\n            int mid = (ub + lb) / 2;\n            if(a.get_hash(p\
    \ - mid, p + mid + 1) == b.get_hash(q - mid, q + mid + 1)) lb = mid;\n       \
    \     else ub = mid;\n        }\n        return lb * 2 + 1;\n    }\n    // \u5076\
    \u6570\n    else {\n        int lb = -1, ub = min(N - p - 1, p + 1);\n       \
    \ while(ub - lb > 1) {\n            int mid = (lb + ub) / 2;\n            if(a.get_hash(p\
    \ - mid, p + mid + 2) == b.get_hash(q - mid - 1, q + mid + 1)) lb = mid;\n   \
    \         else ub = mid;\n        }\n        return lb * 2 + 2;\n    }\n}\n\n\
    // \u6587\u5B57\u5217S\u306E\u5404\u4E2D\u5FC3\u306E\u6700\u5927\u56DE\u6587\u9577\
    \u3092\u8FD4\u3059\nvector<int> enumerate_palindromes(string S) {\n    RollingHash\
    \ a(S);\n    reverse(S.begin(), S.end());\n    RollingHash b(S);\n\n    vector<int>\
    \ ret;\n    for(int i = 0; i < a.N; i++) {\n        ret.push_back(get_palindrome(i,\
    \ true, a, b));\n        if(i == a.N - 1) break;\n        ret.push_back(get_palindrome(i,\
    \ false, a, b));\n    }\n\n    return ret;\n}\n\nint main() {\n    string S;\n\
    \    cin >> S;\n\n    RollingHash rh(S);\n\n    vector<int> SA = rh.suffix_array();\n\
    \n    for(int i : SA) {\n        cout << i << \" \";\n    }\n    cout << endl;\n\
    \n    return 0;\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\nstruct RollingHash{\n \
    \   using u64 = uint64_t;\n\n    // \u5B9A\u6570\n    constexpr static u64 MASK30\
    \ = (1UL << 30) - 1;\n    constexpr static u64 MASK31 = (1UL << 31) - 1;\n   \
    \ constexpr static u64 MASK61 = (1UL << 61) - 1;\n    constexpr static u64 MOD\
    \ = (1UL << 61) - 1;\n    constexpr static u64 POSITIVIZER = MOD * 4;\n\n    //\
    \ static\u5909\u6570\n    static inline u64 base;\n\n    // \u30E1\u30F3\u30D0\
    \u5909\u6570\n    int N;\n    vector<u64> hashed, power;\n    \n    // 30bit,\
    \ 31bit\u3067\u533A\u5207\u308B\u639B\u3051\u7B97\n    u64 mul(const u64& a, const\
    \ u64& b) {\n        u64 au = a >> 31;\n        u64 ad = a & MASK31;\n       \
    \ u64 bu = b >> 31;\n        u64 bd = b & MASK31;\n        u64 mid = ad * bu +\
    \ au * bd;\n        u64 midu = mid >> 30;\n        u64 midd = mid & MASK30;\n\
    \        return au * bu * 2 + midu + (midd << 31) + ad * bd;\n    }\n\n    //\
    \ mod\u3092\u53D6\u308B\n    u64 calc_mod(const u64& x) {\n        u64 xu = x\
    \ >> 61;\n        u64 xd = x & MASK61;\n        u64 ret = xu + xd;\n        if(ret\
    \ >= MOD) ret -= MOD;\n        return ret;\n    }\n\n    // base\u3092[0, MOD)\u304B\
    \u3089\u4E71\u629E\n    void gen_base() {\n        random_device seed_gen;\n \
    \       mt19937_64 engine(seed_gen());\n        uniform_int_distribution<u64>\
    \ rand(0, MOD - 1);\n        base = rand(engine);\n    }\n\n    // \u30B3\u30F3\
    \u30B9\u30C8\u30E9\u30AF\u30BF(\u6587\u5B57\u5217)\n    RollingHash(const string&\
    \ S) {\n        // base\u521D\u671F\u5316\n        if(base == 0) gen_base();\n\
    \n        // \u5909\u6570\u521D\u671F\u5316\n        N = (int)S.size();\n    \
    \    power.resize(N + 1, 0);\n        hashed.resize(N + 1, 0);\n\n        // power,\
    \ hashed\u8A08\u7B97\n        power[0] = 1;\n        for(int i = 0; i < N; i++)\
    \ {\n            power[i + 1] = calc_mod(mul(power[i], base));\n            hashed[i\
    \ + 1] = calc_mod(mul(hashed[i], base) + S[i]);\n        }\n    }\n    // \u30B3\
    \u30F3\u30B9\u30C8\u30E9\u30AF\u30BF(\u6570\u5217)\n    RollingHash(const vector<int>&\
    \ V) {\n        // base\u521D\u671F\u5316\n        if(base == 0) gen_base();\n\
    \n        // \u5909\u6570\u521D\u671F\u5316\n        N = (int)V.size();\n    \
    \    power.resize(N + 1, 0);\n        hashed.resize(N + 1, 0);\n\n        // power,\
    \ hashed\u8A08\u7B97\n        power[0] = 1;\n        for(int i = 0; i < N; i++)\
    \ {\n            power[i + 1] = mul(power[i], base);\n            hashed[i + 1]\
    \ = calc_mod(mul(hashed[i], base) + V[i]);\n        }\n    }\n    \n    // [l,\
    \ r)\u306E\u30CF\u30C3\u30B7\u30E5\u3092\u8A08\u7B97\n    u64 get_hash(int l,\
    \ int r) {\n        return calc_mod(hashed[r] + POSITIVIZER - mul(hashed[l], power[r\
    \ - l]));\n    }\n\n    // p\u59CB\u70B9\u306ELCP\u8A08\u7B97\n    int get_LCP(int\
    \ p) {\n        int lb = -1, ub = N - p + 1;\n        while(ub - lb > 1) {\n \
    \           int mid = (ub + lb) / 2;\n            if(get_hash(p, p + mid) == get_hash(0,\
    \ mid)) lb = mid;\n            else ub = mid;\n        }\n        return lb;\n\
    \    }\n\n    // \u5168\u3066\u306ELCP\u3092\u8FD4\u3059\n    vector<int> all_LCP()\
    \ {\n        vector<int> ret(N);\n        for(int i = 0; i < N; i++) {\n     \
    \       ret[i] = get_LCP(i);\n        }\n        return ret;\n    }\n\n    //\
    \ \u6BD4\u8F03\u95A2\u6570\uFF0CO(logN)\u3067i\u3068j\u306E\u63A5\u5C3E\u8F9E\u3092\
    \u6BD4\u8F03\uFF0Csubstr(i) < substr(j)\u3092\u8FD4\u3059\n    bool comp(const\
    \ int& i, const int& j) {\n        if(get_hash(i, i + 1) != get_hash(j, j + 1))\
    \ return get_hash(i, i + 1) < get_hash(j, j + 1);\n\n        // \u6307\u6570\u63A2\
    \u7D22\u3067\u4E0A\u754C\u3092\u6C7A\u3081\u308B\n        int lb = 0, ub = 1,\
    \ ma = N - max(i, j) + 1;\n        while(get_hash(i, i + ub) == get_hash(j, j\
    \ + ub)) {\n            ub *= 5;\n            if(ub >= ma) {\n               \
    \ ub = ma;\n                break;\n            }\n        }\n\n        // \u4E8C\
    \u5206\u63A2\u7D22\u3067\u6700\u5927\u5171\u901A\u63A5\u982D\u8F9E\u9577\u3092\
    \u5F97\u308B\n        while(ub - lb > 1) {\n            int mid = (ub + lb) /\
    \ 2;\n            if(get_hash(i, i + mid) == get_hash(j, j + mid)) lb = mid;\n\
    \            else ub = mid;\n        }\n        if(i + lb == N) return true;\n\
    \        if(j + lb == N) return false;\n        return get_hash(i + lb, i + lb\
    \ + 1) < get_hash(j + lb, j + lb + 1);\n    }\n\n    // SA\u3092\u8FD4\u3059\uFF0C\
    O(Nlog^2N)\n    vector<int> suffix_array() {\n        vector<int> ret(N);\n  \
    \      iota(ret.begin(), ret.end(), 0);\n        sort(ret.begin(), ret.end(),\
    \ [this](const int& i, const int& j) { return comp(i, j); });\n        return\
    \ ret;\n    }\n};\n\n// b\u306Fa\u306E\u53CD\u8EE2\u5217\uFF0Cp\u4E2D\u5FC3(odd\
    \ = false\u306A\u3089p\u3068p + 1\u4E2D\u5FC3)\u306E\u56DE\u6587\u306E\u9577\u3055\
    \u3092\u8FD4\u3059\nint get_palindrome(int p, bool odd, RollingHash& a, RollingHash&\
    \ b) {\n    int N = a.N;\n    int q = N - p - 1;\n\n    // \u5947\u6570\n    if(odd)\
    \ {\n        int lb = -1, ub = min(N - p, p + 1);\n        while(ub - lb > 1)\
    \ {\n            int mid = (ub + lb) / 2;\n            if(a.get_hash(p - mid,\
    \ p + mid + 1) == b.get_hash(q - mid, q + mid + 1)) lb = mid;\n            else\
    \ ub = mid;\n        }\n        return lb * 2 + 1;\n    }\n    // \u5076\u6570\
    \n    else {\n        int lb = -1, ub = min(N - p - 1, p + 1);\n        while(ub\
    \ - lb > 1) {\n            int mid = (lb + ub) / 2;\n            if(a.get_hash(p\
    \ - mid, p + mid + 2) == b.get_hash(q - mid - 1, q + mid + 1)) lb = mid;\n   \
    \         else ub = mid;\n        }\n        return lb * 2 + 2;\n    }\n}\n\n\
    // \u6587\u5B57\u5217S\u306E\u5404\u4E2D\u5FC3\u306E\u6700\u5927\u56DE\u6587\u9577\
    \u3092\u8FD4\u3059\nvector<int> enumerate_palindromes(string S) {\n    RollingHash\
    \ a(S);\n    reverse(S.begin(), S.end());\n    RollingHash b(S);\n\n    vector<int>\
    \ ret;\n    for(int i = 0; i < a.N; i++) {\n        ret.push_back(get_palindrome(i,\
    \ true, a, b));\n        if(i == a.N - 1) break;\n        ret.push_back(get_palindrome(i,\
    \ false, a, b));\n    }\n\n    return ret;\n}\n\nint main() {\n    string S;\n\
    \    cin >> S;\n\n    RollingHash rh(S);\n\n    vector<int> SA = rh.suffix_array();\n\
    \n    for(int i : SA) {\n        cout << i << \" \";\n    }\n    cout << endl;\n\
    \n    return 0;\n}"
  dependsOn: []
  isVerificationFile: false
  path: string/rollong_hash.cpp
  requiredBy: []
  timestamp: '2024-06-21 02:24:08+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/rollong_hash.cpp
layout: document
redirect_from:
- /library/string/rollong_hash.cpp
- /library/string/rollong_hash.cpp.html
title: string/rollong_hash.cpp
---