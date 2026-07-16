# 漸化式・数列の数え上げ

## 線形漸化式

$$
a_n=c_1a_{n-1}+c_2a_{n-2}+\cdots+c_ka_{n-k}
$$

$N$ が大きいときは，

* 行列累乗: $O(k^3\log N)$
* Kitamasa: $O(k^2\log N)$
* Bostan-Mori: $O(k\log k\log N)$

を考える．

## 行列累乗

Fibonacci 型なら companion matrix を作る．

$$
\begin{pmatrix}
a_n\\
a_{n-1}\\
\vdots\\
a_{n-k+1}
\end{pmatrix}
=
\begin{pmatrix}
c_1&c_2&\cdots&c_{k-1}&c_k\\
1&0&\cdots&0&0\\
0&1&\cdots&0&0\\
\vdots&\vdots&\ddots&\vdots&\vdots\\
0&0&\cdots&1&0
\end{pmatrix}
\begin{pmatrix}
a_{n-1}\\
a_{n-2}\\
\vdots\\
a_{n-k}
\end{pmatrix}
$$

## Kitamasa の考え方

特性多項式

$$
x^k-c_1x^{k-1}-c_2x^{k-2}-\cdots-c_k=0
$$

のもとで，

$$
x^N \bmod P(x)
$$

を求める．

その係数を初期値に掛けると $a_N$ になる．

## Bostan-Mori

母関数が

$$
\frac{P(x)}{Q(x)}
$$

で表されるとき，$[x^N]P(x)/Q(x)$ を高速に求める．

偶数番目・奇数番目の係数を取り出しながら $N$ を半分にする．

NTT があると強い．

## Berlekamp-Massey

最初の数列項から，最短の線形漸化式を推定する．

mod が素数のとき使いやすい．

典型：

* DP を $2k$ 項くらい愚直に出す
* Berlekamp-Massey で漸化式を得る
* Kitamasa で $N$ 項目を求める

## Fibonacci

$$
F_0=0,\quad F_1=1
$$

$$
F_n=F_{n-1}+F_{n-2}
$$

母関数：

$$
\sum_{n\geq 0}F_nx^n=\frac{x}{1-x-x^2}
$$

## Catalan

$$
C_{n+1}=\sum_{i=0}^{n}C_iC_{n-i}
$$

畳み込み型の漸化式．

母関数 $C(x)$ は，

$$
C(x)=1+xC(x)^2
$$

## 分割数

$p(n)$ は $n$ の分割数．

$$
\sum_{n\geq 0}p(n)x^n=\prod_{i=1}^{\infty}\frac{1}{1-x^i}
$$

Euler の五角数定理：

$$
\prod_{i=1}^{\infty}(1-x^i)
=\sum_{k=-\infty}^{\infty}(-1)^kx^{k(3k-1)/2}
$$

これにより，

$$
p(n)=\sum_{k\neq 0}(-1)^{k-1}p\left(n-\frac{k(3k-1)}{2}\right)
$$

範囲外は $0$，$p(0)=1$．

```cpp
vector<long long> partition_euler(int n) {
    vector<long long> p(n + 1);
    p[0] = 1;

    for(int i = 1; i <= n; i++) {
        for(long long k = 1; ; k++) {
            long long g1 = k * (3 * k - 1) / 2;
            long long g2 = k * (3 * k + 1) / 2;
            if(g1 > i) break;

            long long sign = (k & 1) ? 1 : -1;
            p[i] = (p[i] + sign * p[i - g1]) % MOD;
            if(g2 <= i) p[i] = (p[i] + sign * p[i - g2]) % MOD;
        }
        if(p[i] < 0) p[i] += MOD;
    }
    return p;
}
```

計算時間は $O(n\sqrt n)$．
