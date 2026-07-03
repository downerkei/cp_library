# DP

## 基本形

```cpp
template<class T> bool chmin(T& a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

template<class T> bool chmax(T& a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

const long long INF = 4e18;
```

```cpp
vector<long long> dp(n + 1, INF);
dp[0] = 0;

for(int i = 0; i < n; i++) {
    if(dp[i] == INF) continue;

    // 遷移
    chmin(dp[i + 1], dp[i] + cost);
}
```

## 配るDP

```cpp
vector<long long> dp(n + 1, INF);
dp[0] = 0;

for(int i = 0; i < n; i++) {
    if(dp[i] == INF) continue;

    for(auto [ni, cost] : nxt[i]) {
        chmin(dp[ni], dp[i] + cost);
    }
}
```

## もらうDP

```cpp
vector<long long> dp(n + 1, INF);
dp[0] = 0;

for(int i = 1; i <= n; i++) {
    for(auto [j, cost] : prv[i]) {
        chmin(dp[i], dp[j] + cost);
    }
}
```

## 01ナップサック

同じ品物を2回使わないので，重さは大きい方から見る．

```cpp
vector<long long> dp(W + 1, -INF);
dp[0] = 0;

for(int i = 0; i < n; i++) {
    for(int w = W; w >= weight[i]; w--) {
        chmax(dp[w], dp[w - weight[i]] + value[i]);
    }
}
```

## 個数制限なしナップサック

同じ品物を何回でも使えるので，重さは小さい方から見る．

```cpp
vector<long long> dp(W + 1, -INF);
dp[0] = 0;

for(int i = 0; i < n; i++) {
    for(int w = weight[i]; w <= W; w++) {
        chmax(dp[w], dp[w - weight[i]] + value[i]);
    }
}
```

## グリッドDP

```cpp
vector dp(h, vector<long long>(w, 0));
dp[0][0] = 1;

for(int i = 0; i < h; i++) {
    for(int j = 0; j < w; j++) {
        if(i + 1 < h) dp[i + 1][j] += dp[i][j];
        if(j + 1 < w) dp[i][j + 1] += dp[i][j];
    }
}
```

## 区間DP

長さの短い区間から埋める．

```cpp
vector dp(n + 1, vector<long long>(n + 1, INF));

for(int i = 0; i < n; i++) dp[i][i + 1] = 0;

for(int len = 2; len <= n; len++) {
    for(int l = 0; l + len <= n; l++) {
        int r = l + len;

        for(int m = l + 1; m < r; m++) {
            chmin(dp[l][r], dp[l][m] + dp[m][r] + cost(l, m, r));
        }
    }
}
```

## 部分集合DP

```cpp
vector<long long> dp(1 << n, INF);
dp[0] = 0;

for(int s = 0; s < (1 << n); s++) {
    if(dp[s] == INF) continue;

    for(int v = 0; v < n; v++) {
        if(s >> v & 1) continue;

        int ns = s | (1 << v);
        chmin(dp[ns], dp[s] + cost(s, v));
    }
}
```

部分集合の部分集合を列挙する．

```cpp
for(int s = 0; s < (1 << n); s++) {
    for(int t = s; ; t = (t - 1) & s) {
        // t は s の部分集合

        if(t == 0) break;
    }
}
```

## 桁DP

`tight`: 上限と一致しているか．  
`started`: 非0の桁がもう出たか．

```cpp
string S;
cin >> S;

vector dp(S.size() + 1, vector(2, vector(2, 0LL)));
dp[0][1][0] = 1;

for(int i = 0; i < (int)S.size(); i++) {
    for(int tight = 0; tight < 2; tight++) {
        for(int started = 0; started < 2; started++) {
            int lim = tight ? S[i] - '0' : 9;

            for(int d = 0; d <= lim; d++) {
                int ntight = tight && (d == lim);
                int nstarted = started || (d != 0);

                dp[i + 1][ntight][nstarted] += dp[i][tight][started];
            }
        }
    }
}
```

## 木DP

```cpp
vector<vector<int>> G(n);
vector<long long> dp(n, 1);

auto dfs = [&](auto self, int v, int p) -> void {
    for(int nv : G[v]) {
        if(nv == p) continue;

        self(self, nv, v);
        dp[v] += dp[nv];
    }
};

dfs(dfs, 0, -1);
```

## 全方位木DP

各頂点を根にしたときの距離和．

```cpp
vector<vector<int>> G(n);
vector<long long> sz(n, 1), dp(n, 0), ans(n, 0);

auto dfs1 = [&](auto self, int v, int p) -> void {
    for(int nv : G[v]) {
        if(nv == p) continue;

        self(self, nv, v);
        sz[v] += sz[nv];
        dp[v] += dp[nv] + sz[nv];
    }
};

auto dfs2 = [&](auto self, int v, int p) -> void {
    for(int nv : G[v]) {
        if(nv == p) continue;

        ans[nv] = ans[v] - sz[nv] + (n - sz[nv]);
        self(self, nv, v);
    }
};

dfs1(dfs1, 0, -1);
ans[0] = dp[0];
dfs2(dfs2, 0, -1);
```

根を `v` から子 `nv` に動かすと，`nv` の部分木は距離が $1$ 減って，それ以外は距離が $1$ 増える．

```cpp
ans[nv] = ans[v] - sz[nv] + (n - sz[nv]);
```

最大値などでも，考え方は「子側を一度消して，親側からの値を足す」．

```cpp
vector<long long> dp(n, 0), ans(n, 0);

auto dfs1 = [&](auto self, int v, int p) -> void {
    for(int nv : G[v]) {
        if(nv == p) continue;

        self(self, nv, v);
        dp[v] = max(dp[v], dp[nv] + 1);
    }
};

auto dfs2 = [&](auto self, int v, int p, long long from_parent) -> void {
    vector<long long> vals;
    vals.push_back(from_parent);

    for(int nv : G[v]) {
        if(nv == p) continue;
        vals.push_back(dp[nv] + 1);
    }

    long long mx1 = -1, mx2 = -1;
    for(long long x : vals) {
        if(x > mx1) {
            mx2 = mx1;
            mx1 = x;
        } else if(x > mx2) {
            mx2 = x;
        }
    }

    ans[v] = mx1;

    for(int nv : G[v]) {
        if(nv == p) continue;

        long long use = (dp[nv] + 1 == mx1 ? mx2 : mx1);
        self(self, nv, v, use + 1);
    }
};

dfs1(dfs1, 0, -1);
dfs2(dfs2, 0, -1, 0);
```

## LIS

狭義単調増加なら `lower_bound`，広義単調増加なら `upper_bound`．

```cpp
vector<long long> lis;

for(long long x : A) {
    auto it = lower_bound(lis.begin(), lis.end(), x);

    if(it == lis.end()) lis.push_back(x);
    else *it = x;
}

cout << lis.size() << endl;
```
