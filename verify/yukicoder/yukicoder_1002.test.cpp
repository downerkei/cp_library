#define PROBLEM "https://yukicoder.me/problems/no/1002"

#include <bits/stdc++.h>
using namespace std;

#include "../../graph/centroid_decomposition.hpp"

int main() {
    int N, K;
    cin >> N >> K;
    vector<vector<int>> G(N);
    vector<vector<pair<int, int>>> E(N);
    for(int i = 0; i < N - 1; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
        E[u].push_back({v, c});
        E[v].push_back({u, c});
    }

    CentroidDecomposition cd(G);

    vector<bool> used(N, false);
    long long ans = 0;
    for(int centroid : cd.ord) {
        
        used[centroid] = true;

        map<int, int> cnt1; // x, -
        map<pair<int, int>, int> cnt2;  // x, y
        map<int, int> cnt3; // x, *
        int cnt4 = 0;   // *, -
        int cnt5 = 0;   // *. *

        for(auto [nv, c] : E[centroid]) {
            if(used[nv]) continue;
            map<int, int> color1;
            map<pair<int, int>, int> color2;

            // centroidのsubtreeに関して色のパスを数える
            // 最大 N 種類のパス
            auto dfs = [&](auto f, int v, int p, int c1, int c2) -> void {
                if(c2 == -1) color1[c1]++;
                if(c2 != -1) color2[{c1, c2}]++;

                for(auto [nv, c] : E[v]) {
                    if(used[nv] || p == nv) continue;
                    if(c1 == c || c2 == c) f(f, nv, v, c1, c2);
                    else if(c2 == -1) f(f, nv, v, min(c1, c), max(c1, c));
                }
            };
            dfs(dfs, nv, -1, c, -1);

            // merge
            for(auto [c1, num] : color1) {
                if(!cnt3.count(c1)) cnt3[c1] = 0;
                if(!cnt1.count(c1)) cnt1[c1] = 0;
                ans += (long long) num * (cnt3[c1] + cnt4 - cnt1[c1]);
            }
            for(auto [cs, num] : color2) {
                auto [c1, c2] = cs;
                if(!cnt2.count(cs)) cnt2[cs] = 0;
                if(!cnt1.count(c1)) cnt1[c1] = 0;
                if(!cnt1.count(c2)) cnt1[c2] = 0;
                ans += (long long) num * (cnt2[cs] + cnt1[c1] + cnt1[c2]);
            }

            for(auto [c1, num] : color1) {
                cnt1[c1] += num;
                cnt4 += num;
            }
            for(auto [cs, num] : color2) {
                auto [c1, c2] = cs;
                cnt2[cs] += num;
                cnt3[c1] += num;
                cnt3[c2] += num;
                cnt5 += num;
            }
        }
        ans += cnt5;
    }

    cout << ans << endl;

    return 0;
}