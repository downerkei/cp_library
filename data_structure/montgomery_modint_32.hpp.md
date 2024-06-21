---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/unit_test/montgomery_modint_32.test.cpp
    title: verify/unit_test/montgomery_modint_32.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data_structure/montgomery_modint_32.hpp\"\n// mod\u5947\u6570\
    \u306E\u5270\u4F59\u8A08\u7B97\u9AD8\u901F\nstruct MontgomeryModint32 {\n    using\
    \ mint = MontgomeryModint32;\n    using u32 = uint32_t;\n    using u64 = uint64_t;\n\
    \n    u32 _v;\n\n    // static\u5909\u6570\n    // R = 2 ^ 32\n    static inline\
    \ u32 MOD;\n    static inline u32 INV_MOD;  // INV_MOD * MOD \u2261 1 (mod 2 ^\
    \ 32)\n    static inline u32 T64;     // 2 ^ 64 (mod MOD)\n\n    // static\u95A2\
    \u6570\n    static void SetMod(u32 mod) {\n        MOD = mod;\n        T64 = -u64(mod)\
    \ % mod;\n        INV_MOD = GetInvMod();\n    }\n    // \u30CB\u30E5\u30FC\u30C8\
    \u30F3\u6CD5\u3067\u9006\u5143\u3092\u6C42\u3081\u308B\n    static u32 GetInvMod()\
    \ {\n        u32 res = MOD;\n        for(int i = 0; i < 4; ++i) res *= 2 - MOD\
    \ * res;\n        return res;\n    }\n    // \u30E2\u30F3\u30B4\u30E1\u30EA\u30EA\
    \u30C0\u30AF\u30B7\u30E7\u30F3\n    static u32 MR(const u64& v) {\n        return\
    \ (v + u64(u32(v) * u32(-INV_MOD)) * MOD) >> 32;\n    }\n\n    mint Inv() const\
    \ { return Pow(MOD - 2); }\n    mint Pow(u64 n) const {\n        mint res(1),\
    \ mul(*this);\n        while(n) {\n            if(n & 1) res *= mul;\n       \
    \     mul *= mul;\n            n >>= 1;\n        }\n        return res;\n    }\n\
    \n    u32 Val() const {\n        u32 res = MR(_v);\n        return res >= MOD\
    \ ? res - MOD : res;\n    }\n\n    MontgomeryModint32(): _v(0) {}\n    MontgomeryModint32(long\
    \ long v): _v(MR((u64(v) + MOD) * T64)) {}\n\n    \n    mint operator + () const\
    \ { return *this; }\n    mint operator - () const { return mint() - mint(*this);\
    \ }\n\n    mint& operator ++ () { return *this += 1; }\n    mint& operator --\
    \ () { return *this -= 1; }\n    mint operator ++ (int) { mint res = *this; ++*this;\
    \ return res; }\n    mint operator -- (int) { mint res = *this; --*this; return\
    \ res; }\n\n    mint operator + (const mint& r) const { return mint(*this) +=\
    \ r; }\n    mint operator - (const mint& r) const { return mint(*this) -= r; }\n\
    \    mint operator * (const mint& r) const { return mint(*this) *= r; }\n    mint\
    \ operator / (const mint& r) const { return mint(*this) /= r; }\n\n    mint& operator\
    \ += (const mint& r) {\n        if((_v += r._v) >= 2 * MOD) _v -= 2 * MOD;\n \
    \       return *this;\n    }\n    mint& operator -= (const mint& r) {\n      \
    \  if((_v += 2 * MOD - r._v) >= 2 * MOD) _v -= 2 * MOD;\n        return *this;\n\
    \    }\n    mint& operator *= (const mint& r) {\n        _v = MR(u64(_v) * r._v);\n\
    \        return *this;\n    }\n    mint& operator /= (const mint& r) {\n     \
    \   *this *= r.Inv();\n        return *this;\n    }\n\n    bool operator == (const\
    \ mint& r) const {\n        return (_v >= MOD ? _v - MOD : _v) == (r._v >= MOD\
    \ ? r._v - MOD : r._v);\n    }\n    bool operator != (const mint& r) const {\n\
    \        return (_v >= MOD ? _v - MOD : _v) != (r._v >= MOD ? r._v - MOD : r._v);\n\
    \    }\n\n    friend istream& operator >> (istream& is, mint& x) {\n        long\
    \ long t;\n        is >> t;\n        x = mint(t);\n        return is;\n    }\n\
    \    friend ostream& operator << (ostream& os, const mint& x) {\n        return\
    \ os << x.Val();\n    }\n};\n"
  code: "// mod\u5947\u6570\u306E\u5270\u4F59\u8A08\u7B97\u9AD8\u901F\nstruct MontgomeryModint32\
    \ {\n    using mint = MontgomeryModint32;\n    using u32 = uint32_t;\n    using\
    \ u64 = uint64_t;\n\n    u32 _v;\n\n    // static\u5909\u6570\n    // R = 2 ^\
    \ 32\n    static inline u32 MOD;\n    static inline u32 INV_MOD;  // INV_MOD *\
    \ MOD \u2261 1 (mod 2 ^ 32)\n    static inline u32 T64;     // 2 ^ 64 (mod MOD)\n\
    \n    // static\u95A2\u6570\n    static void SetMod(u32 mod) {\n        MOD =\
    \ mod;\n        T64 = -u64(mod) % mod;\n        INV_MOD = GetInvMod();\n    }\n\
    \    // \u30CB\u30E5\u30FC\u30C8\u30F3\u6CD5\u3067\u9006\u5143\u3092\u6C42\u3081\
    \u308B\n    static u32 GetInvMod() {\n        u32 res = MOD;\n        for(int\
    \ i = 0; i < 4; ++i) res *= 2 - MOD * res;\n        return res;\n    }\n    //\
    \ \u30E2\u30F3\u30B4\u30E1\u30EA\u30EA\u30C0\u30AF\u30B7\u30E7\u30F3\n    static\
    \ u32 MR(const u64& v) {\n        return (v + u64(u32(v) * u32(-INV_MOD)) * MOD)\
    \ >> 32;\n    }\n\n    mint Inv() const { return Pow(MOD - 2); }\n    mint Pow(u64\
    \ n) const {\n        mint res(1), mul(*this);\n        while(n) {\n         \
    \   if(n & 1) res *= mul;\n            mul *= mul;\n            n >>= 1;\n   \
    \     }\n        return res;\n    }\n\n    u32 Val() const {\n        u32 res\
    \ = MR(_v);\n        return res >= MOD ? res - MOD : res;\n    }\n\n    MontgomeryModint32():\
    \ _v(0) {}\n    MontgomeryModint32(long long v): _v(MR((u64(v) + MOD) * T64))\
    \ {}\n\n    \n    mint operator + () const { return *this; }\n    mint operator\
    \ - () const { return mint() - mint(*this); }\n\n    mint& operator ++ () { return\
    \ *this += 1; }\n    mint& operator -- () { return *this -= 1; }\n    mint operator\
    \ ++ (int) { mint res = *this; ++*this; return res; }\n    mint operator -- (int)\
    \ { mint res = *this; --*this; return res; }\n\n    mint operator + (const mint&\
    \ r) const { return mint(*this) += r; }\n    mint operator - (const mint& r) const\
    \ { return mint(*this) -= r; }\n    mint operator * (const mint& r) const { return\
    \ mint(*this) *= r; }\n    mint operator / (const mint& r) const { return mint(*this)\
    \ /= r; }\n\n    mint& operator += (const mint& r) {\n        if((_v += r._v)\
    \ >= 2 * MOD) _v -= 2 * MOD;\n        return *this;\n    }\n    mint& operator\
    \ -= (const mint& r) {\n        if((_v += 2 * MOD - r._v) >= 2 * MOD) _v -= 2\
    \ * MOD;\n        return *this;\n    }\n    mint& operator *= (const mint& r)\
    \ {\n        _v = MR(u64(_v) * r._v);\n        return *this;\n    }\n    mint&\
    \ operator /= (const mint& r) {\n        *this *= r.Inv();\n        return *this;\n\
    \    }\n\n    bool operator == (const mint& r) const {\n        return (_v >=\
    \ MOD ? _v - MOD : _v) == (r._v >= MOD ? r._v - MOD : r._v);\n    }\n    bool\
    \ operator != (const mint& r) const {\n        return (_v >= MOD ? _v - MOD :\
    \ _v) != (r._v >= MOD ? r._v - MOD : r._v);\n    }\n\n    friend istream& operator\
    \ >> (istream& is, mint& x) {\n        long long t;\n        is >> t;\n      \
    \  x = mint(t);\n        return is;\n    }\n    friend ostream& operator << (ostream&\
    \ os, const mint& x) {\n        return os << x.Val();\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/montgomery_modint_32.hpp
  requiredBy: []
  timestamp: '2024-06-22 04:42:05+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/unit_test/montgomery_modint_32.test.cpp
documentation_of: data_structure/montgomery_modint_32.hpp
layout: document
redirect_from:
- /library/data_structure/montgomery_modint_32.hpp
- /library/data_structure/montgomery_modint_32.hpp.html
title: data_structure/montgomery_modint_32.hpp
---
