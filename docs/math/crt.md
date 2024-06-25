---
title: 中国剰余定理
documentation_of: //math/crt.hpp
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