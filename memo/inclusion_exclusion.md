# 包除原理

## 基本

条件 $A_1,A_2,\dots,A_n$ の少なくとも1つを満たすものの個数．

$$
\left|\bigcup_{i=1}^{n} A_i\right|
= \sum_i |A_i|
- \sum_{i<j}|A_i\cap A_j|
+ \sum_{i<j<k}|A_i\cap A_j\cap A_k|
- \cdots
$$

「全部から悪いものを引く」形でよく使う．

## どれも満たさない

全体集合を $U$ とする．

$$
\left|U \setminus \bigcup_i A_i\right|
= \sum_{S \subseteq \{1,\dots,n\}}(-1)^{|S|}
\left|\bigcap_{i\in S}A_i\right|
$$

$S = \emptyset$ の項は $|U|$．

## 全射

$n$ 個の区別する玉を，$k$ 個の区別する箱へ入れる．空箱がない入れ方．

$$
\sum_{i=0}^{k}(-1)^i\binom{k}{i}(k-i)^n
$$

```cpp
long long surjection(int n, int k) {
    long long ret = 0;
    for(int i = 0; i <= k; i++) {
        long long add = C(k, i) * modpow(k - i, n) % MOD;
        if(i & 1) ret = (ret - add + MOD) % MOD;
        else ret = (ret + add) % MOD;
    }
    return ret;
}
```

## derangement

$n$ 個の置換で，固定点がないものの個数．

$$
!n = \sum_{i=0}^{n}(-1)^i\binom{n}{i}(n-i)!
$$

漸化式：

$$
!0 = 1,\quad !1 = 0
$$

$$
!n = (n-1)(!(n-1)+!(n-2))
$$

```cpp
vector<long long> derangement(int n) {
    vector<long long> dp(n + 1);
    dp[0] = 1;
    if(n >= 1) dp[1] = 0;

    for(int i = 2; i <= n; i++) {
        dp[i] = (i - 1) * (dp[i - 1] + dp[i - 2]) % MOD;
    }
    return dp;
}
```

## 上限つき重複組合せ

$$
x_1+x_2+\dots+x_n=k,\quad 0 \leq x_i \leq m
$$

包除で上限を超える変数を選ぶ．

$$
\sum_{j=0}^{n}(-1)^j\binom{n}{j}
\binom{k-j(m+1)+n-1}{n-1}
$$

```cpp
long long bounded_nonnegative(int n, int k, int m) {
    long long ret = 0;
    for(int j = 0; j <= n; j++) {
        long long add = C(n, j) * C(k - j * (m + 1) + n - 1, n - 1) % MOD;
        if(j & 1) ret = (ret - add + MOD) % MOD;
        else ret = (ret + add) % MOD;
    }
    return ret;
}
```

## gcd が 1 の個数

$1$ 以上 $N$ 以下から $k$ 個選ぶ・並べるとき，gcd が $1$ であるものを数える典型．

「全てが $d$ の倍数」を数えてメビウス反転する．

$$
\sum_{d=1}^{N}\mu(d)\left\lfloor\frac{N}{d}\right\rfloor^k
$$

メビウス関数 $\mu$：

* 平方因子を持つなら $0$
* 相異なる素因数の個数が偶数なら $1$
* 相異なる素因数の個数が奇数なら $-1$

## bit 全探索

条件数が小さいときは部分集合を全探索する．

```cpp
long long ret = 0;

for(int s = 0; s < (1 << n); s++) {
    int cnt = __builtin_popcount(s);

    long long ways = count_intersection(s);

    if(cnt & 1) ret = (ret - ways + MOD) % MOD;
    else ret = (ret + ways) % MOD;
}
```

「どれも満たさない」を数えるときは，空集合の項が全体数になる．

## SOS DP

$f[S]$ から，

$$
g[S] = \sum_{T \subseteq S} f[T]
$$

を全部求める．

```cpp
vector<long long> g = f;

for(int i = 0; i < n; i++) {
    for(int s = 0; s < (1 << n); s++) {
        if(s >> i & 1) {
            g[s] += g[s ^ (1 << i)];
        }
    }
}
```

計算時間は $O(n2^n)$．

