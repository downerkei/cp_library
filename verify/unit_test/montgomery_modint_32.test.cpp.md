---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/montgomery_modint_32.hpp
    title: data_structure/montgomery_modint_32.hpp
  - icon: ':heavy_check_mark:'
    path: math/random_number_generator.hpp
    title: math/random_number_generator.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"verify/unit_test/montgomery_modint_32.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#line 1 \"data_structure/montgomery_modint_32.hpp\"\n\
    // mod\u5947\u6570\u306E\u5270\u4F59\u8A08\u7B97\u9AD8\u901F\nstruct MontgomeryModint32\
    \ {\n    using mint = MontgomeryModint32;\n    using u32 = uint32_t;\n    using\
    \ u64 = uint64_t;\n\n    u32 _v;\n\n    // static\u5909\u6570\n    // R = 2 ^\
    \ 32\n    static inline u32 MOD;\n    static inline u32 INV_MOD;  // INV_MOD *\
    \ MOD \u2261 1 (mod 2 ^ 32)\n    static inline u32 T64;     // 2 ^ 64 (mod MOD)\n\
    \n    // static\u95A2\u6570\n    static void set_mod(u32 mod) {\n        MOD =\
    \ mod;\n        T64 = -u64(mod) % mod;\n        INV_MOD = get_inv_mod();\n   \
    \ }\n    // \u30CB\u30E5\u30FC\u30C8\u30F3\u6CD5\u3067\u9006\u5143\u3092\u6C42\
    \u3081\u308B\n    static u32 get_inv_mod() {\n        u32 res = MOD;\n       \
    \ for(int i = 0; i < 4; ++i) res *= 2 - MOD * res;\n        return res;\n    }\n\
    \    // \u30E2\u30F3\u30B4\u30E1\u30EA\u30EA\u30C0\u30AF\u30B7\u30E7\u30F3\n \
    \   static u32 MR(const u64& v) {\n        return (v + u64(u32(v) * u32(-INV_MOD))\
    \ * MOD) >> 32;\n    }\n\n    mint inv() const { return pow(MOD - 2); }\n    mint\
    \ pow(u64 n) const {\n        mint res(1), mul(*this);\n        while(n) {\n \
    \           if(n & 1) res *= mul;\n            mul *= mul;\n            n >>=\
    \ 1;\n        }\n        return res;\n    }\n\n    u32 val() const {\n       \
    \ u32 res = MR(_v);\n        return res >= MOD ? res - MOD : res;\n    }\n\n \
    \   MontgomeryModint32(): _v(0) {}\n    MontgomeryModint32(long long v): _v(MR((u64(v)\
    \ + MOD) * T64)) {}\n\n    \n    mint operator + () const { return *this; }\n\
    \    mint operator - () const { return mint() - mint(*this); }\n\n    mint& operator\
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
    \       return *this;\n    }\n\n    bool operator == (const mint& r) const {\n\
    \        return (_v >= MOD ? _v - MOD : _v) == (r._v >= MOD ? r._v - MOD : r._v);\n\
    \    }\n    bool operator != (const mint& r) const {\n        return (_v >= MOD\
    \ ? _v - MOD : _v) != (r._v >= MOD ? r._v - MOD : r._v);\n    }\n\n    friend\
    \ istream& operator >> (istream& is, mint& x) {\n        long long t;\n      \
    \  is >> t;\n        x = mint(t);\n        return is;\n    }\n    friend ostream&\
    \ operator << (ostream& os, const mint& x) {\n        return os << x.val();\n\
    \    }\n};\n#line 1 \"math/random_number_generator.hpp\"\nstruct RandomNumberGenerator\
    \ {\n    mt19937 mt;\n\n    RandomNumberGenerator() : mt(random_device()()) {}\n\
    \n    // [a, b)\u306E\u7BC4\u56F2\n    long long operator()(long long a, long\
    \ long b) {\n        uniform_int_distribution<long long> dist(a, b - 1);\n   \
    \     return dist(mt);\n    }\n\n    // [0, b)\u306E\u7BC4\u56F2\n    long long\
    \ operator()(long long b) {\n        return (*this)(0, b);\n    }\n};\n#line 8\
    \ \"verify/unit_test/montgomery_modint_32.test.cpp\"\n\nusing mint = MontgomeryModint32;\n\
    RandomNumberGenerator rnd;\n\nvoid set_test() {\n    for(int i = 0; i < 1e6; i++)\
    \ {\n        int mod = rnd(1e9);\n        if(mod % 2 == 0) mod += 1;\n\n     \
    \   mint::set_mod(mod);\n\n        int v = rnd(mod + 1, 1e9);\n\n        assert(mint(v)\
    \ == v % mod);\n    }\n}\n\nvoid operator_test(int mod) {\n    mint::set_mod(mod);\n\
    \    for(int i = 0; i < 1e5; i++) {\n        int a = rnd(mod);\n        if(rnd(1e9)\
    \ % 10 == 0) a = 0;\n        if(rnd(1e9) % 10 == 0) a = mod - 1;\n        mint\
    \ A = a;\n        assert(A.val() == a);\n\n        int b = rnd(mod);\n       \
    \ if(rnd(1e9) % 10 == 0) b = 0;\n        if(rnd(1e9) % 10 == 0) b = mod - 1;\n\
    \        mint B = b;\n        assert(B.val() == b);\n\n        int c = (a + b)\
    \ % mod;\n        mint C = A + B;\n        assert(C.val() == c);\n\n        int\
    \ d = (a + mod - b) % mod;\n        mint D = A - B;\n        assert(D.val() ==\
    \ d);\n\n        int e = (1LL * a * b) % mod;\n        mint E = A * B;\n     \
    \   assert(E.val() == e);\n\n        mint F = rnd(1, mod);\n        mint G = F.inv();\n\
    \        if(F * G != 1) cerr << mod << endl;\n        assert(F * G == 1);\n  \
    \  }\n}\n\nvoid test() {\n    set_test();\n    operator_test(998244353);\n   \
    \ operator_test(1000000007);\n    operator_test(1);\n    operator_test(3);\n \
    \   operator_test(5);\n    operator_test(7);\n    operator_test(11);\n    operator_test(101);\n\
    \    \n    cerr << \"ok\" << endl;\n}\n\nint main() {\n    test();\n\n    int\
    \ a, b;\n    cin >> a >> b;\n    cout << a + b << endl;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#include \"../../data_structure/montgomery_modint_32.hpp\"\
    \n#include \"../../math/random_number_generator.hpp\"\n\nusing mint = MontgomeryModint32;\n\
    RandomNumberGenerator rnd;\n\nvoid set_test() {\n    for(int i = 0; i < 1e6; i++)\
    \ {\n        int mod = rnd(1e9);\n        if(mod % 2 == 0) mod += 1;\n\n     \
    \   mint::set_mod(mod);\n\n        int v = rnd(mod + 1, 1e9);\n\n        assert(mint(v)\
    \ == v % mod);\n    }\n}\n\nvoid operator_test(int mod) {\n    mint::set_mod(mod);\n\
    \    for(int i = 0; i < 1e5; i++) {\n        int a = rnd(mod);\n        if(rnd(1e9)\
    \ % 10 == 0) a = 0;\n        if(rnd(1e9) % 10 == 0) a = mod - 1;\n        mint\
    \ A = a;\n        assert(A.val() == a);\n\n        int b = rnd(mod);\n       \
    \ if(rnd(1e9) % 10 == 0) b = 0;\n        if(rnd(1e9) % 10 == 0) b = mod - 1;\n\
    \        mint B = b;\n        assert(B.val() == b);\n\n        int c = (a + b)\
    \ % mod;\n        mint C = A + B;\n        assert(C.val() == c);\n\n        int\
    \ d = (a + mod - b) % mod;\n        mint D = A - B;\n        assert(D.val() ==\
    \ d);\n\n        int e = (1LL * a * b) % mod;\n        mint E = A * B;\n     \
    \   assert(E.val() == e);\n\n        mint F = rnd(1, mod);\n        mint G = F.inv();\n\
    \        if(F * G != 1) cerr << mod << endl;\n        assert(F * G == 1);\n  \
    \  }\n}\n\nvoid test() {\n    set_test();\n    operator_test(998244353);\n   \
    \ operator_test(1000000007);\n    operator_test(1);\n    operator_test(3);\n \
    \   operator_test(5);\n    operator_test(7);\n    operator_test(11);\n    operator_test(101);\n\
    \    \n    cerr << \"ok\" << endl;\n}\n\nint main() {\n    test();\n\n    int\
    \ a, b;\n    cin >> a >> b;\n    cout << a + b << endl;\n}"
  dependsOn:
  - data_structure/montgomery_modint_32.hpp
  - math/random_number_generator.hpp
  isVerificationFile: true
  path: verify/unit_test/montgomery_modint_32.test.cpp
  requiredBy: []
  timestamp: '2024-06-25 02:44:34+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/unit_test/montgomery_modint_32.test.cpp
layout: document
redirect_from:
- /verify/verify/unit_test/montgomery_modint_32.test.cpp
- /verify/verify/unit_test/montgomery_modint_32.test.cpp.html
title: verify/unit_test/montgomery_modint_32.test.cpp
---
