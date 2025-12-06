---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/crt.hpp
    title: "\u4E2D\u56FD\u5270\u4F59\u5B9A\u7406"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj/aoj_ntl_1_e.test.cpp
    title: verify/aoj/aoj_ntl_1_e.test.cpp
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
    }\n"
  code: "tuple<long long, long long, long long> ext_gcd(long long a, long long b)\
    \ {\n    if(b == 0) return {a, 1, 0};\n    auto [d, y, x] = ext_gcd(b, a % b);\n\
    \    y -= a / b * x;\n    return {d, x, y};\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/ext_gcd.hpp
  requiredBy:
  - math/crt.hpp
  timestamp: '2024-06-26 02:37:52+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj/aoj_ntl_1_e.test.cpp
  - verify/yukicoder/yukicoder_186.test.cpp
documentation_of: math/ext_gcd.hpp
layout: document
title: "\u62E1\u5F35\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u306E\u4E92\u9664\u6CD5"
---

## 概要

拡張ユークリッドの互除法

ax + by = gcd(a, b)となる(x, y)をひとつ計算し，d = gcd(a, b)を返す

この(x, y)は abs(x) + abs(y) が最小のものであり，かつx <= yである(らしい)．

## 計算

ax + by = dについて，

aをbで割って a = qb + rとする

方程式に代入すると，

(qb + r)x + by = d ⇔ b(qx + y) + rx = d

として，(a, b)の問題を(b, r)の問題に帰着する

bs + rt = dを満たす(s, t)が得られたとすると，

x = t, y = s - qtと元の解を構成できる

dx + 0y = dとなるのが終了条件であり，(x, y) = (1, 0)となる

## 逆元計算
aのm上での逆元を求めたい(a, mは互いに素)

ax + my = 1 ⇔ ax ≡ 1 mod m

x = a ^ -1