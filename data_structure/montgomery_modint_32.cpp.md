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
  bundledCode: "#line 1 \"data_structure/montgomery_modint_32.cpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\nstruct MontgomeryModint32 {\n    using mint = MontgomeryModint32;\n\
    \    using u32 = uint32_t;\n    using u64 = uint64_t;\n\n    // static\u5909\u6570\
    \n    // R = 2 ^ 32\n    static inline u32 MOD;\n    static inline u32 INV_MOD;\
    \  // INV_MOD * MOD \u2261 1 (mod 2 ^ 32)\n    static inline u32 T64;     // 2\
    \ ^ 64 (mod MOD)\n\n    // static\u95A2\u6570\n    static void set_mod(u32 mod)\
    \ {\n        MOD = mod;\n        T64 = -u64(mod) % mod;\n        INV_MOD = get_inv_mod();\n\
    \    }\n    // \u30CB\u30E5\u30FC\u30C8\u30F3\u6CD5\u3067\u9006\u5143\u3092\u6C42\
    \u3081\u308B\n    static u32 get_inv_mod() {\n        u32 res = MOD;\n       \
    \ for(int i = 0; i < 4; ++i) res *= 2 - MOD * res;\n        return res;\n    }\n\
    \    // \u30E2\u30F3\u30B4\u30E1\u30EA\u30EA\u30C0\u30AF\u30B7\u30E7\u30F3\n \
    \   static u32 MR(const u64& v) {\n        return (v + u64(u32(v) * u32(-INV_MOD))\
    \ * MOD) >> 32;\n    }\n\n    u32 _v;\n\n    MontgomeryModint32(): _v(0) {}\n\
    \    MontgomeryModint32(long long v): _v(MR((u64(v) + MOD) * T64)) {}\n\n    u32\
    \ val() const {\n        u32 res = MR(_v);\n        return res >= MOD ? res -\
    \ MOD : res;\n    }\n    \n    mint operator + () const { return *this; }\n  \
    \  mint operator - () const { return mint() - mint(*this); }\n\n    mint& operator\
    \ ++ () { return *this += 1; }\n    mint& operator -- () { return *this -= 1;\
    \ }\n    mint operator ++ (int) { mint res = *this; ++*this; return res; }\n \
    \   mint operator -- (int) { mint res = *this; --*this; return res; }\n\n    mint\
    \ operator + (const mint& r) const { return mint(*this) += r; }\n    mint operator\
    \ - (const mint& r) const { return mint(*this) -= r; }\n    mint operator * (const\
    \ mint& r) const { return mint(*this) *= r; }\n    mint operator / (const mint&\
    \ r) const { return mint(*this) /= r; }\n\n    mint& operator += (const mint&\
    \ r) {\n        if((_v += r._v) >= 2 * MOD) _v -= 2 * MOD;\n        return *this;\n\
    \    }\n    mint& operator -= (const mint& r) {\n        if((_v += 2 * MOD - r._v)\
    \ >= 2 * MOD) _v -= 2 * MOD;\n        return *this;\n    }\n    mint& operator\
    \ *= (const mint& r) {\n        _v = MR(u64(_v) * r._v);\n        return *this;\n\
    \    }\n    mint& operator /= (const mint& r) {\n        *this *= r.inv();\n \
    \       return *this;\n    }\n\n    mint inv() const { return pow(MOD - 2); }\n\
    \    mint pow(u64 n) const {\n        mint res(1), mul(*this);\n        while(n)\
    \ {\n            if(n & 1) res *= mul;\n            mul *= mul;\n            n\
    \ >>= 1;\n        }\n        return res;\n    }\n\n    bool operator == (const\
    \ mint& r) const {\n        return (_v >= MOD ? _v - MOD : _v) == (r._v >= MOD\
    \ ? r._v - MOD : r._v);\n    }\n    bool operator != (const mint& r) const {\n\
    \        return (_v >= MOD ? _v - MOD : _v) != (r._v >= MOD ? r._v - MOD : r._v);\n\
    \    }\n\n    friend istream& operator >> (istream& is, mint& x) {\n        long\
    \ long t;\n        is >> t;\n        x = mint(t);\n        return is;\n    }\n\
    \    friend ostream& operator << (ostream& os, const mint& x) {\n        return\
    \ os << x.val();\n    }\n};\n\nusing mint = MontgomeryModint32;\n\nint main()\
    \ {\n    mint::set_mod(11);\n\n    for(int i = 0; i < 20; i++) {\n        cout\
    \ << mint(i) << endl;\n    }\n    \n\n    return 0;\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\nstruct MontgomeryModint32\
    \ {\n    using mint = MontgomeryModint32;\n    using u32 = uint32_t;\n    using\
    \ u64 = uint64_t;\n\n    // static\u5909\u6570\n    // R = 2 ^ 32\n    static\
    \ inline u32 MOD;\n    static inline u32 INV_MOD;  // INV_MOD * MOD \u2261 1 (mod\
    \ 2 ^ 32)\n    static inline u32 T64;     // 2 ^ 64 (mod MOD)\n\n    // static\u95A2\
    \u6570\n    static void set_mod(u32 mod) {\n        MOD = mod;\n        T64 =\
    \ -u64(mod) % mod;\n        INV_MOD = get_inv_mod();\n    }\n    // \u30CB\u30E5\
    \u30FC\u30C8\u30F3\u6CD5\u3067\u9006\u5143\u3092\u6C42\u3081\u308B\n    static\
    \ u32 get_inv_mod() {\n        u32 res = MOD;\n        for(int i = 0; i < 4; ++i)\
    \ res *= 2 - MOD * res;\n        return res;\n    }\n    // \u30E2\u30F3\u30B4\
    \u30E1\u30EA\u30EA\u30C0\u30AF\u30B7\u30E7\u30F3\n    static u32 MR(const u64&\
    \ v) {\n        return (v + u64(u32(v) * u32(-INV_MOD)) * MOD) >> 32;\n    }\n\
    \n    u32 _v;\n\n    MontgomeryModint32(): _v(0) {}\n    MontgomeryModint32(long\
    \ long v): _v(MR((u64(v) + MOD) * T64)) {}\n\n    u32 val() const {\n        u32\
    \ res = MR(_v);\n        return res >= MOD ? res - MOD : res;\n    }\n    \n \
    \   mint operator + () const { return *this; }\n    mint operator - () const {\
    \ return mint() - mint(*this); }\n\n    mint& operator ++ () { return *this +=\
    \ 1; }\n    mint& operator -- () { return *this -= 1; }\n    mint operator ++\
    \ (int) { mint res = *this; ++*this; return res; }\n    mint operator -- (int)\
    \ { mint res = *this; --*this; return res; }\n\n    mint operator + (const mint&\
    \ r) const { return mint(*this) += r; }\n    mint operator - (const mint& r) const\
    \ { return mint(*this) -= r; }\n    mint operator * (const mint& r) const { return\
    \ mint(*this) *= r; }\n    mint operator / (const mint& r) const { return mint(*this)\
    \ /= r; }\n\n    mint& operator += (const mint& r) {\n        if((_v += r._v)\
    \ >= 2 * MOD) _v -= 2 * MOD;\n        return *this;\n    }\n    mint& operator\
    \ -= (const mint& r) {\n        if((_v += 2 * MOD - r._v) >= 2 * MOD) _v -= 2\
    \ * MOD;\n        return *this;\n    }\n    mint& operator *= (const mint& r)\
    \ {\n        _v = MR(u64(_v) * r._v);\n        return *this;\n    }\n    mint&\
    \ operator /= (const mint& r) {\n        *this *= r.inv();\n        return *this;\n\
    \    }\n\n    mint inv() const { return pow(MOD - 2); }\n    mint pow(u64 n) const\
    \ {\n        mint res(1), mul(*this);\n        while(n) {\n            if(n &\
    \ 1) res *= mul;\n            mul *= mul;\n            n >>= 1;\n        }\n \
    \       return res;\n    }\n\n    bool operator == (const mint& r) const {\n \
    \       return (_v >= MOD ? _v - MOD : _v) == (r._v >= MOD ? r._v - MOD : r._v);\n\
    \    }\n    bool operator != (const mint& r) const {\n        return (_v >= MOD\
    \ ? _v - MOD : _v) != (r._v >= MOD ? r._v - MOD : r._v);\n    }\n\n    friend\
    \ istream& operator >> (istream& is, mint& x) {\n        long long t;\n      \
    \  is >> t;\n        x = mint(t);\n        return is;\n    }\n    friend ostream&\
    \ operator << (ostream& os, const mint& x) {\n        return os << x.val();\n\
    \    }\n};\n\nusing mint = MontgomeryModint32;\n\nint main() {\n    mint::set_mod(11);\n\
    \n    for(int i = 0; i < 20; i++) {\n        cout << mint(i) << endl;\n    }\n\
    \    \n\n    return 0;\n}"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/montgomery_modint_32.cpp
  requiredBy: []
  timestamp: '2024-06-21 02:11:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/montgomery_modint_32.cpp
layout: document
redirect_from:
- /library/data_structure/montgomery_modint_32.cpp
- /library/data_structure/montgomery_modint_32.cpp.html
title: data_structure/montgomery_modint_32.cpp
---
