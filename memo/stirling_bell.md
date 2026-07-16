# Stirling 数・Bell 数

## 第二種 Stirling 数

$n$ 個の区別するものを，$k$ 個の空でない区別しないグループへ分ける方法．

$$
S(n,k)
$$

漸化式：

$$
S(0,0)=1
$$

$$
S(n,k)=S(n-1,k-1)+kS(n-1,k)
$$

最後の要素が，

* 1個だけの新しいグループになる
* 既存の $k$ グループのどれかに入る

と見る．

```cpp
vector<vector<long long>> stirling2(int n) {
    vector dp(n + 1, vector<long long>(n + 1));
    dp[0][0] = 1;

    for(int i = 1; i <= n; i++) {
        for(int k = 1; k <= i; k++) {
            dp[i][k] = (dp[i - 1][k - 1] + k * dp[i - 1][k]) % MOD;
        }
    }
    return dp;
}
```

計算時間は $O(n^2)$．

## 第二種 Stirling 数の包除公式

$k$ 個の区別する箱へ全射する方法は $k!S(n,k)$．

包除原理より，

$$
k!S(n,k)=\sum_{i=0}^{k}(-1)^i\binom{k}{i}(k-i)^n
$$

したがって，

$$
S(n,k)=\frac{1}{k!}\sum_{i=0}^{k}(-1)^i\binom{k}{i}(k-i)^n
$$

## Bell 数

$n$ 個の区別するものを，いくつかの空でない区別しないグループへ分ける方法．

$$
B_n=\sum_{k=0}^{n}S(n,k)
$$

最初の値：

| $n$ | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| $B_n$ | 1 | 1 | 2 | 5 | 15 | 52 | 203 | 877 | 4140 |

## Bell 三角形

```cpp
vector<long long> bell(int n) {
    vector tri(n + 1, vector<long long>(n + 1));
    tri[0][0] = 1;

    for(int i = 1; i <= n; i++) {
        tri[i][0] = tri[i - 1][i - 1];
        for(int j = 1; j <= i; j++) {
            tri[i][j] = (tri[i][j - 1] + tri[i - 1][j - 1]) % MOD;
        }
    }

    vector<long long> ret(n + 1);
    for(int i = 0; i <= n; i++) ret[i] = tri[i][0];
    return ret;
}
```

計算時間は $O(n^2)$．

## 第一種 Stirling 数

$n$ 個の置換で，cycle がちょうど $k$ 個あるものの個数．

符号なし第一種 Stirling 数を，

$$
c(n,k)
$$

と書く．

漸化式：

$$
c(0,0)=1
$$

$$
c(n,k)=c(n-1,k-1)+(n-1)c(n-1,k)
$$

最後の要素が，

* 1個だけの新しい cycle になる
* 既存の置換のどこかに挿入される

と見る．

```cpp
vector<vector<long long>> stirling1(int n) {
    vector dp(n + 1, vector<long long>(n + 1));
    dp[0][0] = 1;

    for(int i = 1; i <= n; i++) {
        for(int k = 1; k <= i; k++) {
            dp[i][k] = (dp[i - 1][k - 1] + (i - 1) * dp[i - 1][k]) % MOD;
        }
    }
    return dp;
}
```

計算時間は $O(n^2)$．

## Lah 数

$n$ 個の区別するものを，$k$ 個の空でない順序付きリストへ分ける方法．

グループ同士は区別しないが，各グループ内は順序を区別する．

$$
L(n,k)=\binom{n-1}{k-1}\frac{n!}{k!}
$$

## 使い分け

* グループも中身も順序なし: 第二種 Stirling 数
* グループを区別する: $k!S(n,k)$
* いくつかのグループへ分ける: Bell 数
* 置換の cycle 数: 第一種 Stirling 数
* グループ内が列: Lah 数

