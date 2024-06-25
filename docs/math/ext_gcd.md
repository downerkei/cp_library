---
documentation_of: //math/ext_gcd.hpp
---

## 概要

拡張ユークリッドの互除法

ax + by = gcd(a, b)となる(x, y)をひとつ計算し，d = gcd(a, b)を返す

この(x, y)は|x| + |y|が最小のものであり，かつx <= yである(らしい)．

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