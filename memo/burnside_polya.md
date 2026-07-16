# Burnside・Polya

## Burnside の補題

対称性で同一視したときの本質的に異なる塗り方の数．

群 $G$ が集合 $X$ に作用するとき，軌道の個数は，

$$
\frac{1}{|G|}\sum_{g\in G}|\mathrm{Fix}(g)|
$$

$\mathrm{Fix}(g)$ は，操作 $g$ で変わらない要素の個数．

競プロでは，

* 回転で同じ
* 反転で同じ
* ネックレス
* ブレスレット
* グリッドの対称性

で使う．

## ネックレス

$n$ 個の位置を $m$ 色で塗る．回転で同じものを同一視する．

回転 $r$ 個分ずらす操作で固定される塗り方は，

$$
m^{\gcd(n,r)}
$$

よって，

$$
\frac{1}{n}\sum_{r=0}^{n-1}m^{\gcd(n,r)}
$$

```cpp
long long necklace(int n, long long m) {
    long long ret = 0;
    for(int r = 0; r < n; r++) {
        ret = (ret + modpow(m, gcd(n, r))) % MOD;
    }
    return ret * inv(n) % MOD;
}
```

約数でまとめると，

$$
\frac{1}{n}\sum_{d\mid n}\varphi(d)m^{n/d}
$$

```cpp
long long necklace_fast(int n, long long m) {
    long long ret = 0;

    for(int d = 1; d * d <= n; d++) {
        if(n % d != 0) continue;

        ret = (ret + phi(d) * modpow(m, n / d)) % MOD;

        if(d * d != n) {
            int e = n / d;
            ret = (ret + phi(e) * modpow(m, n / e)) % MOD;
        }
    }

    return ret * inv(n) % MOD;
}
```

## ブレスレット

$n$ 個の位置を $m$ 色で塗る．回転と反転で同じものを同一視する．

回転分はネックレスと同じ．反転分を足して $2n$ で割る．

$n$ が奇数：

$$
\frac{1}{2n}
\left(
\sum_{r=0}^{n-1}m^{\gcd(n,r)}
+ n m^{(n+1)/2}
\right)
$$

$n$ が偶数：

$$
\frac{1}{2n}
\left(
\sum_{r=0}^{n-1}m^{\gcd(n,r)}
+ \frac{n}{2}m^{n/2+1}
+ \frac{n}{2}m^{n/2}
\right)
$$

## Polya

置換の cycle ごとに同じ色である必要がある．

操作 $g$ の cycle 数が $c(g)$ なら，$m$ 色で固定される塗り方は，

$$
m^{c(g)}
$$

したがって，

$$
\frac{1}{|G|}\sum_{g\in G}m^{c(g)}
$$

色ごとの個数制限があるときは，cycle index を使う．

## cycle index

置換 $g$ が長さ $1,2,\dots$ の cycle をそれぞれ $c_1,c_2,\dots$ 個持つとき，

$$
x_1^{c_1}x_2^{c_2}\cdots
$$

を対応させる．

群全体で平均を取ったものが cycle index．

$$
Z_G(x_1,x_2,\dots)
=\frac{1}{|G|}\sum_{g\in G}\prod_i x_i^{c_i(g)}
$$

$m$ 色で色数制限なしなら，全ての $x_i$ に $m$ を代入する．

## 色の個数制限つき

色 $1,2,\dots,m$ の重みを $a_1,a_2,\dots,a_m$ とする．

長さ $i$ の cycle は同じ色で塗られるので，

$$
x_i = a_1^i+a_2^i+\cdots+a_m^i
$$

を cycle index に代入する．

欲しい個数の係数を取る．

## 固定されるものを数えるコツ

操作で位置がいくつかの cycle に分かれる．

同じ cycle 内の位置は同じ色でなければならない．

つまり，

* cycle 数が自由度
* 色数制限なしなら $m^{\text{cycle数}}$
* 個数制限ありなら cycle 長を重みとして DP

## グリッドの反転

$H \times W$ グリッドを上下反転で同一視する．$m$ 色で塗る．

上下反転で固定される塗り方は，

$$
m^{\lceil H/2\rceil W}
$$

恒等操作で固定される塗り方は，

$$
m^{HW}
$$

したがって，

$$
\frac{m^{HW}+m^{\lceil H/2\rceil W}}{2}
$$

左右反転も同時に考えるなら，4操作それぞれの固定数を数えて平均する．

