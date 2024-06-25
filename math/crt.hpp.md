---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/ext_gcd.hpp
    title: "\u62E1\u5F35\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u306E\u4E92\u9664\u6CD5"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yukicoder/yukicoder_186.test.cpp
    title: verify/yukicoder/yukicoder_186.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/ext_gcd.hpp\"\ntuple<long long, long long, long long>\
    \ ext_gcd(long long a, long long b) {\n    if(b == 0) return {a, 1, 0};\n    auto\
    \ [d, y, x] = ext_gcd(b, a % b);\n    y -= a / b * x;\n    return {d, x, y};\n\
    }\n#line 2 \"math/crt.hpp\"\n\ninline long long safe_mod(long long a, long long\
    \ m) {\n    return (a % m + m) % m;\n}\n\npair<long long, long long> crt(const\
    \ vector<long long>& b, const vector<long long>& m) {\n    assert(b.size() ==\
    \ m.size());\n    long long r = 0, M = 1;\n    for(int i = 0; i < (int)b.size();\
    \ i++) {\n        auto [d, p, q] = ext_gcd(M, m[i]);\n        if((b[i] - r) %\
    \ d != 0) return {0, -1};\n        long long tmp = (b[i] - r) / d * p % (m[i]\
    \ / d);\n        r += M * tmp;\n        M *= m[i] / d;\n    }\n    r = safe_mod(r,\
    \ M);\n    return {r, M};\n}\n"
  code: "#include \"ext_gcd.hpp\"\n\ninline long long safe_mod(long long a, long long\
    \ m) {\n    return (a % m + m) % m;\n}\n\npair<long long, long long> crt(const\
    \ vector<long long>& b, const vector<long long>& m) {\n    assert(b.size() ==\
    \ m.size());\n    long long r = 0, M = 1;\n    for(int i = 0; i < (int)b.size();\
    \ i++) {\n        auto [d, p, q] = ext_gcd(M, m[i]);\n        if((b[i] - r) %\
    \ d != 0) return {0, -1};\n        long long tmp = (b[i] - r) / d * p % (m[i]\
    \ / d);\n        r += M * tmp;\n        M *= m[i] / d;\n    }\n    r = safe_mod(r,\
    \ M);\n    return {r, M};\n}"
  dependsOn:
  - math/ext_gcd.hpp
  isVerificationFile: false
  path: math/crt.hpp
  requiredBy: []
  timestamp: '2024-06-26 03:18:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yukicoder/yukicoder_186.test.cpp
documentation_of: math/crt.hpp
layout: document
title: "\u4E2D\u56FD\u5270\u4F59\u5B9A\u7406"
---

## 概要

中国剰余定理

x ≡ b1 mod m1, x ≡ b2 mod m2をみたすxがx ≡ r mod mと書けるとき，

(r, m)を返す，解がなければ(0, -1)を返す

## 使い方

x ≡ bi (mod mi) を満たすlong long型のvector b, mを入力．

long long型のr, mを返す．

## 制約

x ≡ b1 mod m1, x ≡ b2 mod m2をみたすx ≡ r mod mが存在するには，

b1 ≡ b2 mod gcd(m1, m2)が必要

## 計算

d = gcd(m1, m2)とおくと，m1p + m2q = dを満たす(p, q)が構成できる

b1 ≡ b2 mod dより，b2 - b1はdで割り切れる．

s = (b2 - b1) / dとおくと，sm1p + sm2q = b2 - b1となる．

式変形し，b1 + sm1p = b2 - sm2qとし，左辺をxとおくと，

x ≡ b1 mod m1, x ≡ b2 mod m2を満たす．