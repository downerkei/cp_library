---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/montgomery_modint_64.hpp
    title: data_structure/montgomery_modint_64.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/primality_test
    links:
    - https://judge.yosupo.jp/problem/primality_test
  bundledCode: "#line 1 \"verify/yosupo/yosupo_primality_test.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/primality_test\"\n\n#include <bits/stdc++.h>\n\
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
    \ fast_factorize {\n\nusing mint = MontgomeryModint64;\nbool miller_rabin(long\
    \ long N, vector<long long> A) {\n    mint::set_mod(N);\n    long long s = 0,\
    \ d = N - 1;\n    while(!(d & 1)) {\n        s++;\n        d >>= 1;\n    }\n \
    \   for(long long a : A) {\n        if(N <= a) return true;\n        mint x =\
    \ mint(a).pow(d);\n        if(x == 1) continue;\n        long long t;\n      \
    \  for(t = 0; t < s; t++) {\n            if(x == N - 1) break;\n            x\
    \ *= x;\n        }\n        if(t == s) return false;\n    }\n    return true;\n\
    }\n\nbool is_prime(long long N) {\n    if(N <= 1) return false;\n    if(N == 2)\
    \ return true;\n    if(!(N & 1)) return false;\n\n    if(N < 4759123141LL) return\
    \ miller_rabin(N, {2, 7, 61});\n\n    return miller_rabin(N, {2, 325, 9375, 28178,\
    \ 450775, 9780504, 1795265022});\n}\n\n} // namespace fast_factorize\n#line 7\
    \ \"verify/yosupo/yosupo_primality_test.test.cpp\"\n\nint main() {\n    int Q;\n\
    \    cin >> Q;\n    while(Q--) {\n        long long N;\n        cin >> N;\n  \
    \      if(fast_factorize::is_prime(N)) cout << \"Yes\" << endl;\n        else\
    \ cout << \"No\" << endl;\n    }\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/primality_test\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../math/miller_rabin.hpp\"\
    \n\nint main() {\n    int Q;\n    cin >> Q;\n    while(Q--) {\n        long long\
    \ N;\n        cin >> N;\n        if(fast_factorize::is_prime(N)) cout << \"Yes\"\
    \ << endl;\n        else cout << \"No\" << endl;\n    }\n\n    return 0;\n}"
  dependsOn:
  - math/miller_rabin.hpp
  - data_structure/montgomery_modint_64.hpp
  isVerificationFile: true
  path: verify/yosupo/yosupo_primality_test.test.cpp
  requiredBy: []
  timestamp: '2024-06-25 11:57:36+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/yosupo_primality_test.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/yosupo_primality_test.test.cpp
- /verify/verify/yosupo/yosupo_primality_test.test.cpp.html
title: verify/yosupo/yosupo_primality_test.test.cpp
---
