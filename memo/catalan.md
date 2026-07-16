# カタラン数

## 定義

$$
C_n = \frac{1}{n + 1}\binom{2n}{n}
$$

同値な形：

$$
C_n = \binom{2n}{n} - \binom{2n}{n + 1}
$$

最初の値：

| $n$ | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| $C_n$ | 1 | 1 | 2 | 5 | 14 | 42 | 132 | 429 | 1430 | 4862 | 16796 |

## 漸化式

$$
C_0 = 1
$$

$$
C_{n+1} = \sum_{i=0}^{n} C_i C_{n-i}
$$

また，

$$
C_n = \frac{4n - 2}{n + 1} C_{n - 1}
$$

## 典型例

以下はいずれも $C_n$ 個．

* 正しい括弧列の個数．長さ $2n$．
* $n$ 個の `+1` と $n$ 個の `-1` を並べて，途中の累積和が常に $0$ 以上になる列の個数．
* $n \times n$ グリッドで，対角線を越えずに右・上へ進む経路数．
* 凸 $(n + 2)$ 角形の三角形分割の個数．
* $n$ 個のノードを持つ二分木の形の個数．

## 経路として見る

長さ $2n$ の列で，`+1` が $n$ 個，`-1` が $n$ 個あるものは $\binom{2n}{n}$ 個．

このうち，途中で負になるものは反射法で $\binom{2n}{n + 1}$ 個なので，

$$
C_n = \binom{2n}{n} - \binom{2n}{n + 1}
$$

## 経路数の基本

$(0, 0)$ から $(h, w)$ まで，下方向に $h$ 回，右方向に $w$ 回動く最短経路数は，

$$
\binom{h + w}{h} = \binom{h + w}{w}
$$

$(a, b)$ から $(c, d)$ までの経路数は，$c \geq a, d \geq b$ のとき，

$$
\binom{(c-a)+(d-b)}{c-a}
$$

それ以外は $0$．

```cpp
long long paths(int a, int b, int c, int d) {
    int h = c - a;
    int w = d - b;
    if(h < 0 || w < 0) return 0;
    return C(h + w, h);
}
```

## 反射法

右を `+1`，上を `-1` と見る．

対角線 $y = x$ を越えない経路，つまり常に $x \geq y$ を満たす経路を数える．

$(0, 0)$ から $(n, n)$ までで，途中で $y > x$ になる経路は，最初に $y = x + 1$ へ行ったところまでを反射すると，$(0, 0)$ から $(n - 1, n + 1)$ への経路と一対一対応する．

したがって，

$$
\binom{2n}{n} - \binom{2n}{n + 1}
$$

## 一般の反射法

$(0, 0)$ から $(a, b)$ まで，常に $x \geq y$ を満たす経路数．

$a \geq b$ のとき，

$$
\binom{a + b}{b} - \binom{a + b}{b - 1}
$$

これは以下と同じ．

$$
\frac{a - b + 1}{a + 1}\binom{a + b}{b}
$$

$a < b$ なら $0$．

```cpp
long long nonnegative_path(int a, int b) {
    if(a < b) return 0;
    return (C(a + b, b) - C(a + b, b - 1) + MOD) % MOD;
}
```

## Ballot

`A` が $a$ 票，`B` が $b$ 票で，常に `A >= B` となる開票順の数．

$$
\binom{a + b}{b} - \binom{a + b}{b - 1}
$$

`A` が常に `B` より真に多い，つまり常に `A > B` となる開票順の数．

最初の1票は `A` である必要があるので，

$$
\binom{a + b - 1}{b} - \binom{a + b - 1}{b - 1}
$$

または，

$$
\frac{a - b}{a + b}\binom{a + b}{b}
$$

$a > b$ が必要．

## 下限つき累積和

長さ $n$ の列で，各ステップが `+1` または `-1`，最終的な高さが $g$，途中の高さが常に $0$ 以上になるものを数える．

`+1` の個数を $u$，`-1` の個数を $d$ とすると，

$$
u + d = n,\quad u - d = g
$$

より，

$$
u = \frac{n + g}{2},\quad d = \frac{n - g}{2}
$$

$u, d$ が整数でない，または負なら $0$．

有効な列数は，

$$
\binom{n}{d} - \binom{n}{d - 1}
$$

```cpp
long long walk_nonnegative(int n, int g) {
    if((n + g) % 2 != 0) return 0;
    int u = (n + g) / 2;
    int d = (n - g) / 2;
    if(u < 0 || d < 0) return 0;
    return (C(n, d) - C(n, d - 1) + MOD) % MOD;
}
```

## 境界が $y = x + k$

$(0, 0)$ から $(a, b)$ まで，常に $y \leq x + k$ を満たす経路数．

越える経路は，最初に $y = x + k + 1$ に到達する．反射すると始点が $(-k - 1, k + 1)$ に移るので，

$$
\binom{a + b}{b} - \binom{a + b}{b - k - 1}
$$

ただし，二項係数の範囲外は $0$ とする．

特に $k = 0$ ならカタラン型になる．

## 障害物つき経路

$(0, 0)$ から $(H, W)$ までの最短経路で，障害物を通らないものを数える．

障害物とゴールを座標の昇順にソートして，その点へ初めて到達する経路数を引いていく．

```cpp
vector<pair<int, int>> ps;

// 障害物を入れる
// ps.push_back({r, c});

ps.push_back({H, W});
sort(ps.begin(), ps.end());

int m = ps.size();
vector<long long> dp(m);

for(int i = 0; i < m; i++) {
    auto [r, c] = ps[i];
    dp[i] = paths(0, 0, r, c);

    for(int j = 0; j < i; j++) {
        auto [pr, pc] = ps[j];
        long long bad = dp[j] * paths(pr, pc, r, c) % MOD;
        dp[i] = (dp[i] - bad + MOD) % MOD;
    }
}

cout << dp[m - 1] << endl;
```

計算時間は，障害物数を $m$ として $O(m^2)$．

## 包除原理で見る

「特定の点を通る経路数」は分割して掛ける．

$(0, 0)$ から $(H, W)$ までで，$(r, c)$ を通る経路数は，

$$
\binom{r+c}{r}\binom{(H-r)+(W-c)}{H-r}
$$

複数の点を順に通るなら，同じように区間ごとの経路数を掛ける．

通ってはいけない点が少ないときは，

* 1個以上の禁止点を通る経路を引く
* 2個以上の禁止点を通る経路を足す
* 3個以上の禁止点を通る経路を引く

のように包除原理で数える．

## mod で計算

$MOD$ が素数で，$2n < MOD$ なら逆元を使って計算できる．

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

long long C(int n, int k) {
    if(k < 0 || k > n) return 0;
    return fact[n] * ifact[k] % MOD * ifact[n - k] % MOD;
}

long long catalan(int n) {
    return C(2 * n, n) * inv(n + 1) % MOD;
}
```

前計算 $O(n)$，クエリ $O(\log MOD)$．

`inv(n + 1)` も前計算しておけばクエリ $O(1)$．

## DP で計算

小さい $n$ なら漸化式で直接計算する．

```cpp
vector<long long> cat(n + 1);
cat[0] = 1;

for(int i = 0; i < n; i++) {
    for(int j = 0; j <= i; j++) {
        cat[i + 1] += cat[j] * cat[i - j];
    }
}
```

計算時間は $O(n^2)$．
