---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/fast_factorize.hpp
    title: math/fast_factorize.hpp
  - icon: ':heavy_check_mark:'
    path: math/miller_rabin.hpp
    title: math/miller_rabin.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/yosupo_factorize.test.cpp
    title: verify/yosupo/yosupo_factorize.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/yosupo_primality_test.test.cpp
    title: verify/yosupo/yosupo_primality_test.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data_structure/montgomery_modint_64.hpp\"\nstruct MontgomeryModint64\
    \ {\n    using mint = MontgomeryModint64;\n    using u64 = uint64_t;\n    using\
    \ u128 = __uint128_t;\n\n    static inline u64 MOD;\n    static inline u64 INV_MOD;\
    \  // INV_MOD * MOD \u2261 1 (mod 2 ^ 64)\n    static inline u64 T128;     //\
    \ 2 ^ 128 (mod MOD)\n\n    u64 val;\n\n    MontgomeryModint64(): val(0) {}\n \
    \   MontgomeryModint64(long long v): val(MR((u128(v) + MOD) * T128)) {}\n\n  \
    \  u64 get() const {\n        u64 res = MR(val);\n        return res >= MOD ?\
    \ res - MOD : res;\n    }\n\n    static u64 get_mod() { return MOD; }\n    static\
    \ void set_mod(u64 mod) {\n        MOD = mod;\n        T128 = -u128(mod) % mod;\n\
    \        INV_MOD = get_inv_mod();\n    }\n    // \u30CB\u30E5\u30FC\u30C8\u30F3\
    \u6CD5\u3067\u9006\u5143\u3092\u6C42\u3081\u308B\n    static u64 get_inv_mod()\
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
    \       return r.inv();\n    }\n};\n"
  code: "struct MontgomeryModint64 {\n    using mint = MontgomeryModint64;\n    using\
    \ u64 = uint64_t;\n    using u128 = __uint128_t;\n\n    static inline u64 MOD;\n\
    \    static inline u64 INV_MOD;  // INV_MOD * MOD \u2261 1 (mod 2 ^ 64)\n    static\
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
    \       return r.inv();\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/montgomery_modint_64.hpp
  requiredBy:
  - math/fast_factorize.hpp
  - math/miller_rabin.hpp
  timestamp: '2024-06-25 08:47:59+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/yosupo_factorize.test.cpp
  - verify/yosupo/yosupo_primality_test.test.cpp
documentation_of: data_structure/montgomery_modint_64.hpp
layout: document
redirect_from:
- /library/data_structure/montgomery_modint_64.hpp
- /library/data_structure/montgomery_modint_64.hpp.html
title: data_structure/montgomery_modint_64.hpp
---
