# 組合せ

## 基本

順列：

$$
{}_nP_k = n(n-1)\cdots(n-k+1) = \frac{n!}{(n-k)!}
$$

組合せ：

$$
\binom{n}{k} = \frac{n!}{k!(n-k)!}
$$

重複組合せ：

$$
{}_nH_k = \binom{n+k-1}{k}
$$

## 二項係数

$$
\binom{n}{k} = \binom{n}{n-k}
$$

$$
\binom{n}{k} = \binom{n-1}{k-1} + \binom{n-1}{k}
$$

$$
\binom{n}{k} = \frac{n}{k}\binom{n-1}{k-1}
$$

$$
\sum_{i=0}^{n}\binom{n}{i} = 2^n
$$

$$
\sum_{i=0}^{n}(-1)^i\binom{n}{i} = 0
$$

## ホッケースティック

$$
\sum_{i=k}^{n}\binom{i}{k} = \binom{n+1}{k+1}
$$

区間和：

$$
\sum_{i=L}^{R-1}\binom{i}{k} = \binom{R}{k+1} - \binom{L}{k+1}
$$

## Vandermonde

$$
\sum_{i=0}^{k}\binom{a}{i}\binom{b}{k-i} = \binom{a+b}{k}
$$

$a$ 個のものと $b$ 個のものから合計 $k$ 個選ぶ，と見る．

## 多項係数

$n$ 個を，サイズ $a_1, a_2, \dots, a_m$ のグループに分ける方法．

$$
\binom{n}{a_1,a_2,\dots,a_m}
= \frac{n!}{a_1!a_2!\cdots a_m!}
$$

ただし，

$$
a_1 + a_2 + \dots + a_m = n
$$

## 重複組合せ

$n$ 種類から重複を許して $k$ 個選ぶ方法．

$$
x_1+x_2+\dots+x_n=k,\quad x_i \geq 0
$$

の非負整数解の個数と同じ．

$$
\binom{n+k-1}{k}
$$

各 $x_i \geq 1$ なら，

$$
x_1+x_2+\dots+x_n=k
$$

の正整数解の個数なので，

$$
\binom{k-1}{n-1}
$$

## 上限つき重複組合せ

$$
x_1+x_2+\dots+x_n=k,\quad 0 \leq x_i \leq m
$$

の解の個数．包除原理で，

$$
\sum_{j=0}^{n}(-1)^j\binom{n}{j}\binom{k-j(m+1)+n-1}{n-1}
$$

二項係数の範囲外は $0$ とする．

## mod で二項係数

$MOD$ が素数で，$n < MOD$ なら階乗と逆元で前計算する．

```cpp
const long long MOD = 998244353;

long long modpow(long long a, long long n) {
    long long ret = 1;
    while(n) {
        if(n & 1) ret = ret * a % MOD;
        a = a * a % MOD;
        n >>= 1;
    }
    return ret;
}

long long inv(long long a) {
    return modpow(a, MOD - 2);
}

vector<long long> fact, ifact;

void init_comb(int n) {
    fact.assign(n + 1, 1);
    ifact.assign(n + 1, 1);

    for(int i = 1; i <= n; i++) fact[i] = fact[i - 1] * i % MOD;

    ifact[n] = inv(fact[n]);
    for(int i = n; i >= 1; i--) ifact[i - 1] = ifact[i] * i % MOD;
}

long long C(long long n, long long k) {
    if(k < 0 || k > n) return 0;
    return fact[n] * ifact[k] % MOD * ifact[n - k] % MOD;
}
```

前計算 $O(n)$，クエリ $O(1)$．

## Lucas

$MOD$ が素数で，$n$ が大きいときに使う．

$$
\binom{n}{k} \equiv
\prod_i \binom{n_i}{k_i}
\pmod{MOD}
$$

$n_i, k_i$ は $MOD$ 進表記の各桁．

```cpp
long long lucas(long long n, long long k) {
    if(k < 0 || k > n) return 0;

    long long ret = 1;
    while(n > 0 || k > 0) {
        long long ni = n % MOD;
        long long ki = k % MOD;
        ret = ret * C(ni, ki) % MOD;
        n /= MOD;
        k /= MOD;
    }
    return ret;
}
```

`MOD` が大きいと全桁分の階乗前計算はできないので注意．

## 階乗の素因数の個数

$n!$ に含まれる素数 $p$ の個数．

$$
\sum_{i=1}^{\infty}\left\lfloor\frac{n}{p^i}\right\rfloor
$$

```cpp
long long count_factorial(long long n, long long p) {
    long long ret = 0;
    while(n) {
        n /= p;
        ret += n;
    }
    return ret;
}
```

