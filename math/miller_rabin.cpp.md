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
  bundledCode: "#line 1 \"math/miller_rabin.cpp\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\n\nnamespace MillerRabin {\n    \n// \u30E2\u30F3\u30B4\u30E1\
    \u30EA\u4E57\u7B97modint\nstruct MontgomeryModInt64 {\n    using mint = MontgomeryModInt64;\n\
    \    using u64 = uint64_t;\n    using u128 = __uint128_t;\n\n    // static\u5909\
    \u6570\n    // R = 2 ^ 64\n    static inline u64 MOD;\n    static inline u64 INV_MOD;\
    \  // INV_MOD * MOD \u2261 1 (mod 2 ^ 64)\n    static inline u64 T128;     //\
    \ 2 ^ 128 (mod MOD)\n\n    u64 val;\n\n    // \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\
    \u30BF\n    // MOD\u3092\u8DB3\u3059\uFF1F\n    MontgomeryModInt64(): val(0) {}\n\
    \    MontgomeryModInt64(long long v): val(MR((u128(v) + MOD) * T128)) {}\n\n \
    \   // \u5024\u3092\u8FD4\u3059\n    u64 get() const {\n        u64 res = MR(val);\n\
    \        return res >= MOD ? res - MOD : res;\n    }\n\n    // static\u95A2\u6570\
    \n    static u64 get_mod() { return MOD; }\n    static void set_mod(u64 mod) {\n\
    \        MOD = mod;\n        T128 = -u128(mod) % mod;\n        INV_MOD = get_inv_mod();\n\
    \    }\n    // \u30CB\u30E5\u30FC\u30C8\u30F3\u6CD5\u3067\u9006\u5143\u3092\u6C42\
    \u3081\u308B\n    static u64 get_inv_mod() {\n        u64 res = MOD;\n       \
    \ for(int i = 0; i < 5; ++i) res *= 2 - MOD * res;\n        return res;\n    }\n\
    \    // \u30E2\u30F3\u30B4\u30E1\u30EA\u30EA\u30C0\u30AF\u30B7\u30E7\u30F3\n \
    \   static u64 MR(const u128& v) {\n        return (v + u128(u64(v) * u64(-INV_MOD))\
    \ * MOD) >> 64;\n    }\n\n    // \u7B97\u8853\u6F14\u7B97\u5B50\n    mint operator\
    \ - () const { return mint() - mint(*this); }\n\n    mint operator + (const mint&\
    \ r) const { return mint(*this) += r; }\n    mint operator - (const mint& r) const\
    \ { return mint(*this) -= r; }\n    mint operator * (const mint& r) const { return\
    \ mint(*this) *= r; }\n    mint operator / (const mint& r) const { return mint(*this)\
    \ /= r; }\n\n    mint& operator += (const mint& r) {\n        if((val += r.val)\
    \ >= 2 * MOD) val -= 2 * MOD;\n        return *this;\n    }\n    mint& operator\
    \ -= (const mint& r) {\n        if((val += 2 * MOD - r.val) >= 2 * MOD) val -=\
    \ 2 * MOD;\n        return *this;\n    }\n    mint& operator *= (const mint& r)\
    \ {\n        val = MR(u128(val) * r.val);\n        return *this;\n    }\n    mint&\
    \ operator /= (const mint& r) {\n        *this *= r.inv();\n        return *this;\n\
    \    }\n\n    mint inv() const { return pow(MOD - 2); }\n    mint pow(u128 n)\
    \ const {\n        mint res(1), mul(*this);\n        while(n > 0) {\n        \
    \    if(n & 1) res *= mul;\n            mul *= mul;\n            n >>= 1;\n  \
    \      }\n        return res;\n    }\n\n    // \u305D\u306E\u4ED6\u6F14\u7B97\u5B50\
    \n    bool operator == (const mint& r) const {\n        return (val >= MOD ? val\
    \ - MOD : val) == (r.val >= MOD ? r.val - MOD : r.val);\n    }\n    bool operator\
    \ != (const mint& r) const {\n        return (val >= MOD ? val - MOD : val) !=\
    \ (r.val >= MOD ? r.val - MOD : r.val);\n    }\n\n    // \u5165\u529B\n    friend\
    \ istream& operator >> (istream& is, mint& x) {\n        long long t;\n      \
    \  is >> t;\n        x = mint(t);\n        return is;\n    }\n    // \u51FA\u529B\
    \n    friend ostream& operator << (ostream& os, const mint& x) {\n        return\
    \ os << x.get();\n    }\n    friend mint modpow(const mint& r, long long n) {\n\
    \        return r.pow(n);\n    } \n    friend mint modinv(const mint& r) {\n \
    \       return r.inv();\n    }\n};\n\n\nusing mint = MontgomeryModInt64;\n// \u30DF\
    \u30E9\u30FC\u30E9\u30D3\u30F3\u7D20\u6570\u5224\u5B9A\u6CD5\u3067\u7D20\u6570\
    \u5224\u5B9A\u3092\u884C\u3046\n// isPrime(N): O(logN)\u3067\u7D20\u6570\u5224\
    \u5B9A\u3092\u884C\u3048\u308B\n\n// \u30DF\u30E9\u30FC\u30E9\u30D3\u30F3\u7D20\
    \u6570\u5224\u5B9A\u6CD5\u3092\u884C\u3046\n// \u5224\u5B9A\u3059\u308B\u6570\
    N\u3068\u57FA\u306E\u5217A\u3092\u5165\u529B\uFF0C\u7D20\u6570\u304B\u3069\u3046\
    \u304B\u5224\u5B9A\n\n// \u5947\u6570N\u306B\u5BFE\u3057\uFF0CN = 2 ^ s * d +\
    \ 1\u3068\u5206\u89E3\u3059\u308B\uFF0E\n// a ^ d \u2261 1 (mod N) \u3068 a ^\
    \ ((2 ^ r) * d) \u2261 -1 (mod N) \u306E\u3069\u3061\u3089\u3082\u6E80\u305F\u3055\
    \u306A\u3044a\u304C\u3042\u308B\u3068\u304D\uFF0C\n// N\u306F\u5408\u6210\u6570\
    \u3067\u3042\u308B.\nbool millerRabin(long long N, vector<long long> A) {\n  \
    \  mint::set_mod(N);\n    long long s = 0, d = N - 1;\n    while(d % 2 == 0) {\n\
    \        s++;\n        d >>= 1;\n    }\n\n    for(long long a : A) {\n       \
    \ // \u8B0E\uFF0C\u6CD5N\u3088\u308A\u57FAa\u304C\u5927\u304D\u3044\u3068\u610F\
    \u5473\u306A\u3044\uFF1F\n        if(N <= a) return true;\n        mint x = mint(a).pow(d);\n\
    \n        if(x == 1) continue;\n        long long t;\n        for(t = 0; t < s;\
    \ t++) {\n            if(x == N - 1) break;\n            x *= x;\n        }\n\n\
    \        // a ^ d \u2261 1 \u3067\u3082 a ^ ((2 ^ r) * d) \u2261 -1 \u3067\u3082\
    \u306A\u3044\u306A\u3089\u3070\u5408\u6210\u6570\n        if(t == s) return false;\n\
    \    }\n\n    // \u5168\u3066\u306E\u57FA\u3067\u5408\u6210\u6570\u3067\u306A\u3051\
    \u308C\u3070\u7D20\u6570\n    return true;\n}\n\nbool isPrime(long long N) {\n\
    \    if(N <= 1) return false;\n    if(N == 2) return true;\n    if(N % 2 == 0)\
    \ return false;\n\n    // 4759123141\u4EE5\u5185\u306A\u3089{2, 7, 61}\u3092\u8A66\
    \u305B\u3070\u5341\u5206\n    if(N < 4759123141LL) return millerRabin(N, {2, 7,\
    \ 61});\n\n    // 64bit\u4EE5\u5185\u306A\u3089{2, 325, 9375, 28178, 450775, 9780504,\
    \ 1795265022}\u3092\u8A66\u305B\u3070\u5341\u5206\n    return millerRabin(N, {2,\
    \ 325, 9375, 28178, 450775, 9780504, 1795265022});\n}\n} // namespace MillerRabin\n\
    \nint main() {\n    int Q;\n    cin >> Q;\n    \n    while(Q--) {\n        long\
    \ long N;\n        cin >> N;\n        if(MillerRabin::isPrime(N)) cout << \"Yes\\\
    n\";\n        else cout << \"No\\n\";\n    }\n\n    return 0;\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\n\nnamespace MillerRabin\
    \ {\n    \n// \u30E2\u30F3\u30B4\u30E1\u30EA\u4E57\u7B97modint\nstruct MontgomeryModInt64\
    \ {\n    using mint = MontgomeryModInt64;\n    using u64 = uint64_t;\n    using\
    \ u128 = __uint128_t;\n\n    // static\u5909\u6570\n    // R = 2 ^ 64\n    static\
    \ inline u64 MOD;\n    static inline u64 INV_MOD;  // INV_MOD * MOD \u2261 1 (mod\
    \ 2 ^ 64)\n    static inline u64 T128;     // 2 ^ 128 (mod MOD)\n\n    u64 val;\n\
    \n    // \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n    // MOD\u3092\u8DB3\u3059\
    \uFF1F\n    MontgomeryModInt64(): val(0) {}\n    MontgomeryModInt64(long long\
    \ v): val(MR((u128(v) + MOD) * T128)) {}\n\n    // \u5024\u3092\u8FD4\u3059\n\
    \    u64 get() const {\n        u64 res = MR(val);\n        return res >= MOD\
    \ ? res - MOD : res;\n    }\n\n    // static\u95A2\u6570\n    static u64 get_mod()\
    \ { return MOD; }\n    static void set_mod(u64 mod) {\n        MOD = mod;\n  \
    \      T128 = -u128(mod) % mod;\n        INV_MOD = get_inv_mod();\n    }\n   \
    \ // \u30CB\u30E5\u30FC\u30C8\u30F3\u6CD5\u3067\u9006\u5143\u3092\u6C42\u3081\u308B\
    \n    static u64 get_inv_mod() {\n        u64 res = MOD;\n        for(int i =\
    \ 0; i < 5; ++i) res *= 2 - MOD * res;\n        return res;\n    }\n    // \u30E2\
    \u30F3\u30B4\u30E1\u30EA\u30EA\u30C0\u30AF\u30B7\u30E7\u30F3\n    static u64 MR(const\
    \ u128& v) {\n        return (v + u128(u64(v) * u64(-INV_MOD)) * MOD) >> 64;\n\
    \    }\n\n    // \u7B97\u8853\u6F14\u7B97\u5B50\n    mint operator - () const\
    \ { return mint() - mint(*this); }\n\n    mint operator + (const mint& r) const\
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
    \      }\n        return res;\n    }\n\n    // \u305D\u306E\u4ED6\u6F14\u7B97\u5B50\
    \n    bool operator == (const mint& r) const {\n        return (val >= MOD ? val\
    \ - MOD : val) == (r.val >= MOD ? r.val - MOD : r.val);\n    }\n    bool operator\
    \ != (const mint& r) const {\n        return (val >= MOD ? val - MOD : val) !=\
    \ (r.val >= MOD ? r.val - MOD : r.val);\n    }\n\n    // \u5165\u529B\n    friend\
    \ istream& operator >> (istream& is, mint& x) {\n        long long t;\n      \
    \  is >> t;\n        x = mint(t);\n        return is;\n    }\n    // \u51FA\u529B\
    \n    friend ostream& operator << (ostream& os, const mint& x) {\n        return\
    \ os << x.get();\n    }\n    friend mint modpow(const mint& r, long long n) {\n\
    \        return r.pow(n);\n    } \n    friend mint modinv(const mint& r) {\n \
    \       return r.inv();\n    }\n};\n\n\nusing mint = MontgomeryModInt64;\n// \u30DF\
    \u30E9\u30FC\u30E9\u30D3\u30F3\u7D20\u6570\u5224\u5B9A\u6CD5\u3067\u7D20\u6570\
    \u5224\u5B9A\u3092\u884C\u3046\n// isPrime(N): O(logN)\u3067\u7D20\u6570\u5224\
    \u5B9A\u3092\u884C\u3048\u308B\n\n// \u30DF\u30E9\u30FC\u30E9\u30D3\u30F3\u7D20\
    \u6570\u5224\u5B9A\u6CD5\u3092\u884C\u3046\n// \u5224\u5B9A\u3059\u308B\u6570\
    N\u3068\u57FA\u306E\u5217A\u3092\u5165\u529B\uFF0C\u7D20\u6570\u304B\u3069\u3046\
    \u304B\u5224\u5B9A\n\n// \u5947\u6570N\u306B\u5BFE\u3057\uFF0CN = 2 ^ s * d +\
    \ 1\u3068\u5206\u89E3\u3059\u308B\uFF0E\n// a ^ d \u2261 1 (mod N) \u3068 a ^\
    \ ((2 ^ r) * d) \u2261 -1 (mod N) \u306E\u3069\u3061\u3089\u3082\u6E80\u305F\u3055\
    \u306A\u3044a\u304C\u3042\u308B\u3068\u304D\uFF0C\n// N\u306F\u5408\u6210\u6570\
    \u3067\u3042\u308B.\nbool millerRabin(long long N, vector<long long> A) {\n  \
    \  mint::set_mod(N);\n    long long s = 0, d = N - 1;\n    while(d % 2 == 0) {\n\
    \        s++;\n        d >>= 1;\n    }\n\n    for(long long a : A) {\n       \
    \ // \u8B0E\uFF0C\u6CD5N\u3088\u308A\u57FAa\u304C\u5927\u304D\u3044\u3068\u610F\
    \u5473\u306A\u3044\uFF1F\n        if(N <= a) return true;\n        mint x = mint(a).pow(d);\n\
    \n        if(x == 1) continue;\n        long long t;\n        for(t = 0; t < s;\
    \ t++) {\n            if(x == N - 1) break;\n            x *= x;\n        }\n\n\
    \        // a ^ d \u2261 1 \u3067\u3082 a ^ ((2 ^ r) * d) \u2261 -1 \u3067\u3082\
    \u306A\u3044\u306A\u3089\u3070\u5408\u6210\u6570\n        if(t == s) return false;\n\
    \    }\n\n    // \u5168\u3066\u306E\u57FA\u3067\u5408\u6210\u6570\u3067\u306A\u3051\
    \u308C\u3070\u7D20\u6570\n    return true;\n}\n\nbool isPrime(long long N) {\n\
    \    if(N <= 1) return false;\n    if(N == 2) return true;\n    if(N % 2 == 0)\
    \ return false;\n\n    // 4759123141\u4EE5\u5185\u306A\u3089{2, 7, 61}\u3092\u8A66\
    \u305B\u3070\u5341\u5206\n    if(N < 4759123141LL) return millerRabin(N, {2, 7,\
    \ 61});\n\n    // 64bit\u4EE5\u5185\u306A\u3089{2, 325, 9375, 28178, 450775, 9780504,\
    \ 1795265022}\u3092\u8A66\u305B\u3070\u5341\u5206\n    return millerRabin(N, {2,\
    \ 325, 9375, 28178, 450775, 9780504, 1795265022});\n}\n} // namespace MillerRabin\n\
    \nint main() {\n    int Q;\n    cin >> Q;\n    \n    while(Q--) {\n        long\
    \ long N;\n        cin >> N;\n        if(MillerRabin::isPrime(N)) cout << \"Yes\\\
    n\";\n        else cout << \"No\\n\";\n    }\n\n    return 0;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/miller_rabin.cpp
  requiredBy: []
  timestamp: '2024-06-21 02:11:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/miller_rabin.cpp
layout: document
redirect_from:
- /library/math/miller_rabin.cpp
- /library/math/miller_rabin.cpp.html
title: math/miller_rabin.cpp
---
