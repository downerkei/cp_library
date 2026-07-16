# グリッド経路

## 最短経路数

$(0, 0)$ から $(h, w)$ へ，下に $h$ 回，右に $w$ 回進む経路数．

$$
\binom{h+w}{h}
$$

$(a, b)$ から $(c, d)$ へ進む経路数．

$$
\binom{(c-a)+(d-b)}{c-a}
$$

$c<a$ または $d<b$ なら $0$．

```cpp
long long paths(int a, int b, int c, int d) {
    int h = c - a;
    int w = d - b;
    if(h < 0 || w < 0) return 0;
    return C(h + w, h);
}
```

## 特定の点を通る

$(0, 0)$ から $(H, W)$ までで，$(r, c)$ を通る経路数．

前半と後半の経路数を掛ける．

$$
\binom{r+c}{r}
\times
\binom{(H-r)+(W-c)}{H-r}
$$

## 複数の点を順に通る

点 $p_0, p_1, \dots, p_m$ をこの順に通るなら，区間ごとの経路数を掛ける．

```cpp
long long ret = 1;

for(int i = 0; i + 1 < (int)ps.size(); i++) {
    auto [a, b] = ps[i];
    auto [c, d] = ps[i + 1];
    ret = ret * paths(a, b, c, d) % MOD;
}
```

途中で戻る必要があるなら `paths` が $0$ を返す．

## 障害物つき経路

障害物を通らずに $(0, 0)$ から $(H, W)$ へ行く経路数．

障害物とゴールをソートし，その点に初めて到達する経路数を求める．

```cpp
vector<pair<int, int>> ps;

// 障害物
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

計算時間は障害物数を $m$ として $O(m^2)$．

## 対角線を越えない

$(0, 0)$ から $(a, b)$ まで，常に $x \geq y$ を満たす経路数．

$$
\binom{a+b}{b} - \binom{a+b}{b-1}
$$

$a < b$ なら $0$．

特に $(n, n)$ までならカタラン数．

$$
C_n = \frac{1}{n+1}\binom{2n}{n}
$$

## 斜め境界

$(0, 0)$ から $(a, b)$ まで，常に $y \leq x + k$ を満たす経路数．

$$
\binom{a+b}{b} - \binom{a+b}{b-k-1}
$$

二項係数の範囲外は $0$．

## DP で数える

障害物が多い，移動方向が複雑，重みがある，などの場合は DP．

```cpp
vector dp(H + 1, vector<long long>(W + 1));
dp[0][0] = 1;

for(int i = 0; i <= H; i++) {
    for(int j = 0; j <= W; j++) {
        if(blocked[i][j]) {
            dp[i][j] = 0;
            continue;
        }

        if(i + 1 <= H) dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % MOD;
        if(j + 1 <= W) dp[i][j + 1] = (dp[i][j + 1] + dp[i][j]) % MOD;
    }
}
```

計算時間は $O(HW)$．

## 最短経路の辞書順復元

経路数を数えながら，$K$ 番目の経路を復元する典型．

右を `R`，下を `D` として辞書順で `D < R` とする．

```cpp
string kth_path(int h, int w, long long k) {
    string ret;

    while(h > 0 || w > 0) {
        if(h == 0) {
            ret += 'R';
            w--;
        }
        else if(w == 0) {
            ret += 'D';
            h--;
        }
        else {
            long long cnt = C(h + w - 1, h - 1); // 次を D にする数
            if(k <= cnt) {
                ret += 'D';
                h--;
            }
            else {
                ret += 'R';
                w--;
                k -= cnt;
            }
        }
    }

    return ret;
}
```

`k` は 1-indexed．
