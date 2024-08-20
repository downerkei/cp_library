#define PROBLEM "https://judge.yosupo.jp/problem/lca"

#include <bits/stdc++.h>
using namespace std;

#include "../../graph/tree/lowest_common_ancestor.hpp"

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int N, Q;
    cin >> N >> Q;
    vector<vector<int>> G(N);
    for(int i = 1; i < N; i++) {
        int p;
        cin >> p;
        G[i].push_back(p);
        G[p].push_back(i);
    }

    LowestCommonAncestor lca(G);

    while(Q--) {
        int u, v;
        cin >> u >> v;

        cout << lca.lca(u, v) << "\n";
    }

    return 0;
}