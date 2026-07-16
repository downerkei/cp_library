# FPS・母関数

## 形式的冪級数

数列 $a_0,a_1,a_2,\dots$ を，

$$
A(x)=\sum_{n\geq 0}a_nx^n
$$

として扱う．

$[x^n]A(x)$ は $A(x)$ の $x^n$ の係数を表す．

## 足し算

$$
A(x)+B(x)
$$

係数ごとに足す．

$$
[x^n](A+B)=a_n+b_n
$$

## 掛け算

$$
C(x)=A(x)B(x)
$$

なら，

$$
c_n=\sum_{i=0}^{n}a_i b_{n-i}
$$

畳み込みになる．

NTT が使えるなら $O(n \log n)$．

## 逆元

$$
B(x)=\frac{1}{A(x)}
$$

は，

$$
A(x)B(x)=1
$$

を満たす FPS．$a_0 \neq 0$ が必要．

## 微分・積分

$$
A'(x)=\sum_{n\geq 1} n a_n x^{n-1}
$$

$$
\int A(x)dx=\sum_{n\geq 0}\frac{a_n}{n+1}x^{n+1}
$$

mod では逆元を使う．

## log

$$
\log A(x)=\int \frac{A'(x)}{A(x)}dx
$$

$a_0=1$ が必要．

組合せ的には，集合の cycle 分解や指数型母関数でよく出る．

## exp

$$
B(x)=\exp A(x)
$$

なら，

$$
\log B(x)=A(x)
$$

$a_0=0$ が必要．

## pow

$$
A(x)^k = \exp(k\log A(x))
$$

$a_0=1$ のとき使いやすい．

$a_0=0$ のときは，最初の非ゼロ項をくくり出す．

$$
A(x)=x^t c B(x),\quad B(0)=1
$$

なら，

$$
A(x)^k=x^{tk}c^kB(x)^k
$$

## 普通母関数

順序がある構造に強い．

### 選ばない・選ぶ

値 $w$ のものを高々1回選ぶ：

$$
1+x^w
$$

値 $w$ のものを何回でも選ぶ：

$$
1+x^w+x^{2w}+\cdots=\frac{1}{1-x^w}
$$

値 $w$ のものを $0$ 回以上 $m$ 回以下選ぶ：

$$
1+x^w+\cdots+x^{mw}
=\frac{1-x^{(m+1)w}}{1-x^w}
$$

複数種類あるときは掛ける．

## 指数型母関数

ラベル付き構造に強い．

$$
A(x)=\sum_{n\geq 0}a_n\frac{x^n}{n!}
$$

積はラベル集合の分割を表す．

$$
C(x)=A(x)B(x)
$$

なら，

$$
c_n=\sum_{i=0}^{n}\binom{n}{i}a_i b_{n-i}
$$

## よく出る母関数

### 全て 1

$$
1+x+x^2+\cdots=\frac{1}{1-x}
$$

### 二項係数

$$
(1+x)^n=\sum_{k=0}^{n}\binom{n}{k}x^k
$$

### 重複組合せ

$$
\frac{1}{(1-x)^n}
=\sum_{k\geq 0}\binom{n+k-1}{k}x^k
$$

### Fibonacci

$$
F_0=0,\quad F_1=1,\quad F_n=F_{n-1}+F_{n-2}
$$

なら，

$$
\sum_{n\geq 0}F_nx^n=\frac{x}{1-x-x^2}
$$

### Catalan

$$
C(x)=\sum_{n\geq 0}C_nx^n
$$

$$
C(x)=1+xC(x)^2
$$

したがって，

$$
C(x)=\frac{1-\sqrt{1-4x}}{2x}
$$

## 線形漸化式と母関数

$$
a_n=c_1a_{n-1}+c_2a_{n-2}+\cdots+c_ka_{n-k}
$$

なら，母関数は分母が

$$
1-c_1x-c_2x^2-\cdots-c_kx^k
$$

の有理関数になる．

$N$ 番目だけ欲しいときは Kitamasa，Bostan-Mori，行列累乗を考える．

## 分割数

$n$ を正整数の和で表す方法の個数．順序は区別しない．

$$
\prod_{i=1}^{\infty}\frac{1}{1-x^i}
$$

値 $i$ を何回でも使える，と見る．

```cpp
vector<long long> partition_number(int n) {
    vector<long long> dp(n + 1);
    dp[0] = 1;

    for(int x = 1; x <= n; x++) {
        for(int s = x; s <= n; s++) {
            dp[s] = (dp[s] + dp[s - x]) % MOD;
        }
    }
    return dp;
}
```

計算時間は $O(n^2)$．

## 係数を取りたいとき

式変形で

$$
[x^n]\frac{1}{(1-x)^k}
$$

まで落とせると，

$$
[x^n]\frac{1}{(1-x)^k}=\binom{n+k-1}{k-1}
$$

が使える．

また，

$$
[x^n]x^aA(x)=[x^{n-a}]A(x)
$$

なので，$x^a$ は添字シフト．

