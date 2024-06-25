---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/montgomery_modint_64.hpp
    title: data_structure/montgomery_modint_64.hpp
  - icon: ':heavy_check_mark:'
    path: math/fast_factorize.hpp
    title: math/fast_factorize.hpp
  - icon: ':heavy_check_mark:'
    path: math/miller_rabin.hpp
    title: math/miller_rabin.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/factorize
    links:
    - https://judge.yosupo.jp/problem/factorize
  bundledCode: "#line 1 \"verify/yosupo/yosupo_factorize.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/factorize\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#line 1 \"data_structure/montgomery_modint_64.hpp\"\n\
    struct MontgomeryModint64 {\n    using mint = MontgomeryModint64;\n    using u64\
    \ = uint64_t;\n    using u128 = __uint128_t;\n\n    static inline u64 MOD;\n \
    \   static inline u64 INV_MOD;  // INV_MOD * MOD \u2261 1 (mod 2 ^ 64)\n    static\
    \ inline u64 T128;     // 2 ^ 128 (mod MOD)\n\n    u64 val;\n\n    MontgomeryModint64():\
    \ val(0) {}\n    MontgomeryModint64(long long v): val(MR((u128(v) + MOD) * T128))\
    \ {}\n\n    u64 get() const {\n        u64 res = MR(val);\n        return res\
    \ >= MOD ? res - MOD : res;\n    }\n\n    static u64 get_mod() { return MOD; }\n\
    \    static void set_mod(u64 mod) {\n        MOD = mod;\n        T128 = -u128(mod)\
    \ % mod;\n        INV_MOD = get_inv_mod();\n    }\n    // \u30CB\u30E5\u30FC\u30C8\
    \u30F3\u6CD5\u3067\u9006\u5143\u3092\u6C42\u3081\u308B\n    static u64 get_inv_mod()\
    \ {\n        u64 res = MOD;\n        for(int i = 0; i < 5; ++i) res *= 2 - MOD\
    \ * res;\n        return res;\n    }\n    static u64 MR(const u128& v) {\n   \
    \     return (v + u128(u64(v) * u64(-INV_MOD)) * MOD) >> 64;\n    }\n\n    mint\
    \ operator + () const { return mint(*this); }\n    mint operator - () const {\
    \ return mint() - mint(*this); }\n\n    mint operator + (const mint& r) const\
    \ { return mint(*this) += r; }\n    mint operator - (const mint& r) const { return\
    \ mint(*this) -= r; }\n    mint operator * (const mint& r) const { return mint(*this)\
    \ *= r; }\n    mint operator / (const mint& r) const { return mint(*this) /= r;\
    \ }\n\n    mint& operator += (const mint& r) {\n        if((val += r.val) >= 2\
    \ * MOD) val -= 2 * MOD;\n        return *this;\n    }\n    mint& operator -=\
    \ (const mint& r) {\n        if((val += 2 * MOD - r.val) >= 2 * MOD) val -= 2\
    \ * MOD;\n        return *this;\n    }\n    mint& operator *= (const mint& r)\
    \ {\n        val = MR(u128(val) * r.val);\n        return *this;\n    }\n    mint&\
    \ operator /= (const mint& r) {\n        *this *= r.inv();\n        return *this;\n\
    \    }\n\n    mint inv() const { return pow(MOD - 2); }\n    mint pow(u128 n)\
    \ const {\n        mint res(1), mul(*this);\n        while(n > 0) {\n        \
    \    if(n & 1) res *= mul;\n            mul *= mul;\n            n >>= 1;\n  \
    \      }\n        return res;\n    }\n\n    bool operator == (const mint& r) const\
    \ {\n        return (val >= MOD ? val - MOD : val) == (r.val >= MOD ? r.val -\
    \ MOD : r.val);\n    }\n    bool operator != (const mint& r) const {\n       \
    \ return (val >= MOD ? val - MOD : val) != (r.val >= MOD ? r.val - MOD : r.val);\n\
    \    }\n\n    friend istream& operator >> (istream& is, mint& x) {\n        long\
    \ long t;\n        is >> t;\n        x = mint(t);\n        return is;\n    }\n\
    \    friend ostream& operator << (ostream& os, const mint& x) {\n        return\
    \ os << x.get();\n    }\n    friend mint modpow(const mint& r, long long n) {\n\
    \        return r.pow(n);\n    } \n    friend mint modinv(const mint& r) {\n \
    \       return r.inv();\n    }\n};\n#line 2 \"math/miller_rabin.hpp\"\n\nnamespace\
    \ fast_factorize {\n    \nusing mint = MontgomeryModint64;\nbool miller_rabin(long\
    \ long N, vector<long long> A) {\n    mint::set_mod(N);\n    long long s = 0,\
    \ d = N - 1;\n    while(d % 2 == 0) {\n        s++;\n        d >>= 1;\n    }\n\
    \    for(long long a : A) {\n        if(N <= a) return true;\n        mint x =\
    \ mint(a).pow(d);\n        if(x == 1) continue;\n        long long t;\n      \
    \  for(t = 0; t < s; t++) {\n            if(x == N - 1) break;\n            x\
    \ *= x;\n        }\n        if(t == s) return false;\n    }\n    return true;\n\
    }\n\nbool is_prime(long long N) {\n    if(N <= 1) return false;\n    if(N == 2)\
    \ return true;\n    if(N % 2 == 0) return false;\n\n    if(N < 4759123141LL) return\
    \ miller_rabin(N, {2, 7, 61});\n\n    return miller_rabin(N, {2, 325, 9375, 28178,\
    \ 450775, 9780504, 1795265022});\n}\n} // namespace fast_factorize\n#line 2 \"\
    math/fast_factorize.hpp\"\n\nnamespace fast_factorize {\n\nlong long find_prime_factor(long\
    \ long N) {\n    if(!(N & 1)) return 2;\n\n    // GCD\u3092\u307E\u3068\u3081\u308B\
    \u6570\u306E\u4E0A\u9650\n    long long m = pow(N, 0.125) + 1;\n\n    for(int\
    \ c = 1; c < N; c++) {\n        // \u7591\u4F3C\u4E71\u6570\n        auto f =\
    \ [&](long long a) { return (__uint128_t(a) * a + c) % N; };\n        long long\
    \ y = 0;\n        long long g = 1, q = 1; // g : GCD\uFF0Cq : |x - y|\u7A4D\n\
    \        long long k = 0, r = 1; // k :  \n        long long ys;   // \u30D0\u30C3\
    \u30AF\u30C8\u30E9\u30C3\u30AF\u7528\u5909\u6570\n        long long x;\n\n   \
    \     while(g == 1) {\n            x = y;\n\n            // k < 3r / 4\u306E\u9593\
    \u306FGCD\u8A08\u7B97\u3092\u98DB\u3070\u3059\n            while(k < 3 * r / 4)\
    \ {\n                y = f(y);\n                k++;\n            }\n\n      \
    \      while(k < r && g == 1) {\n                // \u30D0\u30C3\u30AF\u30C8\u30E9\
    \u30C3\u30AF\u7528\u4FDD\u5B58\n                ys = y;\n                for(int\
    \ i = 0; i < min(m, r - k); i++) {\n                    y = f(y);\n          \
    \          q = __uint128_t(q) * abs(x - y) % N;\n                }\n         \
    \       g = gcd(q, N);\n                k += m;\n            }\n\n           \
    \ k = r;\n            r *= 2;\n        }\n\n        // \u307E\u3068\u3081\u305F\
    gcd\u304CN\u3068\u306A\u3063\u305F\u3089\n        if(g == N) {\n            g\
    \ = 1;\n            y = ys;\n            while(g == 1) {\n                y =\
    \ f(y);\n                g = gcd(abs(x - y), N);\n            }\n        }\n\n\
    \        // \u5931\u6557\u3057\u305F\u3089\u6B21\u306Ec\u3078\n        if(g ==\
    \ N) continue;\n        if(is_prime(g)) return g;\n        else if(is_prime(N\
    \ / g)) return N / g;\n        else return find_prime_factor(g);\n    }\n    return\
    \ -1;\n}\n\nvector<pair<long long, int>> factorize(long long N) {\n    vector<pair<long\
    \ long, int>> ret;\n    while(!is_prime(N) && N > 1) {\n        long long p =\
    \ find_prime_factor(N);\n        int e = 0;\n        while(N % p == 0) {\n   \
    \         e++;\n            N /= p;\n        }\n        ret.push_back({p, e});\n\
    \    }\n    if(N != 1) ret.push_back({N, 1});\n    sort(ret.begin(), ret.end());\n\
    \    return ret;\n}\n\n} // namespace fast_factorize\n#line 7 \"verify/yosupo/yosupo_factorize.test.cpp\"\
    \n\nint main() {\n    int Q;\n    cin >> Q;\n    while(Q--) {\n        long long\
    \ a;\n        cin >> a;\n        \n        auto ans = fast_factorize::factorize(a);\n\
    \n        int k = 0;\n        for(auto [p, e] : ans) {\n            k += e;\n\
    \        }\n        cout << k << \" \";\n        for(auto [p, e] : ans) {\n  \
    \          while(e--) {\n                cout << p << \" \";\n            }\n\
    \        }\n        cout << endl;\n    }\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/factorize\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../math/fast_factorize.hpp\"\
    \n\nint main() {\n    int Q;\n    cin >> Q;\n    while(Q--) {\n        long long\
    \ a;\n        cin >> a;\n        \n        auto ans = fast_factorize::factorize(a);\n\
    \n        int k = 0;\n        for(auto [p, e] : ans) {\n            k += e;\n\
    \        }\n        cout << k << \" \";\n        for(auto [p, e] : ans) {\n  \
    \          while(e--) {\n                cout << p << \" \";\n            }\n\
    \        }\n        cout << endl;\n    }\n\n    return 0;\n}"
  dependsOn:
  - math/fast_factorize.hpp
  - math/miller_rabin.hpp
  - data_structure/montgomery_modint_64.hpp
  isVerificationFile: true
  path: verify/yosupo/yosupo_factorize.test.cpp
  requiredBy: []
  timestamp: '2024-06-25 09:17:09+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/yosupo_factorize.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/yosupo_factorize.test.cpp
- /verify/verify/yosupo/yosupo_factorize.test.cpp.html
title: verify/yosupo/yosupo_factorize.test.cpp
---
