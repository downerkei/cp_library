---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: string/rollong_hash.hpp
    title: string/rollong_hash.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/suffixarray
    links:
    - https://judge.yosupo.jp/problem/suffixarray
  bundledCode: "#line 1 \"verify/yosupo/yosupo_suffix_array.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/suffixarray\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#line 1 \"string/rollong_hash.hpp\"\nstruct RollingHash{\n\
    \    using u64 = uint64_t;\n\n    constexpr static u64 MASK30 = (1UL << 30) -\
    \ 1;\n    constexpr static u64 MASK31 = (1UL << 31) - 1;\n    constexpr static\
    \ u64 MASK61 = (1UL << 61) - 1;\n    constexpr static u64 MOD = (1UL << 61) -\
    \ 1;\n    constexpr static u64 POSITIVIZER = MOD * 4;\n\n    static inline u64\
    \ base;\n\n    int N;\n    vector<u64> hashed, power;\n    \n    u64 mul(const\
    \ u64& a, const u64& b) {\n        u64 au = a >> 31;\n        u64 ad = a & MASK31;\n\
    \        u64 bu = b >> 31;\n        u64 bd = b & MASK31;\n        u64 mid = ad\
    \ * bu + au * bd;\n        u64 midu = mid >> 30;\n        u64 midd = mid & MASK30;\n\
    \        return au * bu * 2 + midu + (midd << 31) + ad * bd;\n    }\n\n    u64\
    \ calc_mod(const u64& x) {\n        u64 xu = x >> 61;\n        u64 xd = x & MASK61;\n\
    \        u64 ret = xu + xd;\n        if(ret >= MOD) ret -= MOD;\n        return\
    \ ret;\n    }\n\n    void gen_base() {\n        random_device seed_gen;\n    \
    \    mt19937_64 engine(seed_gen());\n        uniform_int_distribution<u64> rand(0,\
    \ MOD - 1);\n        base = rand(engine);\n    }\n\n    RollingHash(const string&\
    \ S) { init(S); }\n    RollingHash(const vector<int>& V) { init(V); }\n\n    template<class\
    \ VType>\n    void init(const VType& V) {\n        if(base == 0) gen_base();\n\
    \n        N = (int)V.size();\n        power.resize(N + 1, 0);\n        hashed.resize(N\
    \ + 1, 0);\n\n        power[0] = 1;\n        for(int i = 0; i < N; i++) {\n  \
    \          power[i + 1] = mul(power[i], base);\n            hashed[i + 1] = calc_mod(mul(hashed[i],\
    \ base) + V[i]);\n        }\n    }\n    \n    u64 get_hash(int l, int r) {\n \
    \       return calc_mod(hashed[r] + POSITIVIZER - mul(hashed[l], power[r - l]));\n\
    \    }\n\n    // p\u59CB\u70B9\u306ELCP\u8A08\u7B97\uFF0CO(logN)\n    int get_LCP(int\
    \ p) {\n        int lb = -1, ub = N - p + 1;\n        while(ub - lb > 1) {\n \
    \           int mid = (ub + lb) / 2;\n            if(get_hash(p, p + mid) == get_hash(0,\
    \ mid)) lb = mid;\n            else ub = mid;\n        }\n        return lb;\n\
    \    }\n\n    // \u5168\u3066\u306ELCP\u3092\u8FD4\u3059\uFF0CO(NlogN)\n    vector<int>\
    \ all_LCP() {\n        vector<int> ret(N);\n        for(int i = 0; i < N; i++)\
    \ {\n            ret[i] = get_LCP(i);\n        }\n        return ret;\n    }\n\
    \n    // \u6BD4\u8F03\u95A2\u6570\uFF0CO(logN)\u3067i\u3068j\u306E\u63A5\u5C3E\
    \u8F9E\u3092\u6BD4\u8F03\uFF0Csubstr(i) < substr(j)\u3092\u8FD4\u3059\n    bool\
    \ comp(const int& i, const int& j) {\n        if(get_hash(i, i + 1) != get_hash(j,\
    \ j + 1)) return get_hash(i, i + 1) < get_hash(j, j + 1);\n\n        // \u6307\
    \u6570\u63A2\u7D22\u3067\u4E0A\u754C\u3092\u6C7A\u3081\u308B\n        int lb =\
    \ 0, ub = 1, ma = N - max(i, j) + 1;\n        while(get_hash(i, i + ub) == get_hash(j,\
    \ j + ub)) {\n            ub *= 5;\n            if(ub >= ma) {\n             \
    \   ub = ma;\n                break;\n            }\n        }\n\n        // \u4E8C\
    \u5206\u63A2\u7D22\u3067\u6700\u5927\u5171\u901A\u63A5\u982D\u8F9E\u9577\u3092\
    \u5F97\u308B\n        while(ub - lb > 1) {\n            int mid = (ub + lb) /\
    \ 2;\n            if(get_hash(i, i + mid) == get_hash(j, j + mid)) lb = mid;\n\
    \            else ub = mid;\n        }\n        if(i + lb == N) return true;\n\
    \        if(j + lb == N) return false;\n        return get_hash(i + lb, i + lb\
    \ + 1) < get_hash(j + lb, j + lb + 1);\n    }\n\n    // SA\u3092\u8FD4\u3059\uFF0C\
    O(Nlog^2N)\n    vector<int> suffix_array() {\n        vector<int> ret(N);\n  \
    \      iota(ret.begin(), ret.end(), 0);\n        sort(ret.begin(), ret.end(),\
    \ [this](const int& i, const int& j) { return comp(i, j); });\n        return\
    \ ret;\n    }\n};\n\n// i\u3092\u4E2D\u5FC3\u3068\u3057\u305F\u56DE\u6587\u306E\
    \u9577\u3055\u3092\u8FD4\u3059\nint get_palindrome(int p, RollingHash& a, RollingHash&\
    \ b) {\n    int N = a.N;\n    int q = N - p - 1;\n\n    // \u521D\u671F\u5024\n\
    \    int lb = 0, ub = min(N - p, p + 1);\n    while(ub - lb > 1) {\n        int\
    \ mid = (ub + lb) / 2;\n        if(a.get_hash(p - mid, p + mid + 1) == b.get_hash(q\
    \ - mid, q + mid + 1)) lb = mid;\n        else ub = mid;\n    }\n\n    return\
    \ lb;\n}\n\n// \u6587\u5B57\u5217S\u306E\u5404\u4E2D\u5FC3\u306E\u6700\u5927\u56DE\
    \u6587\u9577\u3092\u8FD4\u3059\nvector<int> enumerate_palindromes(string S) {\n\
    \    int N = S.size();\n    string T = \"\";\n    for(int i = 0; i < N; i++) {\n\
    \        T += '$';\n        T += S[i];\n    }\n    T += '$';\n    RollingHash\
    \ a(T);\n    reverse(T.begin(), T.end());\n    RollingHash b(T);\n\n    vector<int>\
    \ ret;\n    for(int i = 1; i < a.N - 1; i++) {\n        ret.push_back(get_palindrome(i,\
    \ a, b));\n    }\n\n    return ret;\n}\n#line 7 \"verify/yosupo/yosupo_suffix_array.test.cpp\"\
    \n\nint main() {\n    string S;\n    cin >> S;\n    RollingHash rh(S);\n    for(auto\
    \ ans : rh.suffix_array()) {\n        cout << ans << \" \";\n    }\n    cout <<\
    \ endl;\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/suffixarray\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../string/rollong_hash.hpp\"\
    \n\nint main() {\n    string S;\n    cin >> S;\n    RollingHash rh(S);\n    for(auto\
    \ ans : rh.suffix_array()) {\n        cout << ans << \" \";\n    }\n    cout <<\
    \ endl;\n\n    return 0;\n}"
  dependsOn:
  - string/rollong_hash.hpp
  isVerificationFile: true
  path: verify/yosupo/yosupo_suffix_array.test.cpp
  requiredBy: []
  timestamp: '2024-11-20 06:43:26+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/yosupo/yosupo_suffix_array.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/yosupo_suffix_array.test.cpp
- /verify/verify/yosupo/yosupo_suffix_array.test.cpp.html
title: verify/yosupo/yosupo_suffix_array.test.cpp
---