#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C&lang=ja"

#include <bits/stdc++.h>
using namespace std;

#include "../../tree/lowest_common_ancestor.hpp"

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;

    vector<vector<int>> G(N);

    for(int i = 0; i < N; i++) {
        int k;
        cin >> k;
        for(int j = 0; j < k; j++) {
            int c;
            cin >> c;
            G[i].push_back(c);
            G[c].push_back(i);
        }
    }

    LowestCommonAncestor lca(G, 0);

    int Q;
    cin >> Q;
    while(Q--) {
        int u, v;
        cin >> u >> v;
        cout << lca.lca(u, v) << "\n";
    }

    return 0;
}