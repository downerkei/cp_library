#define PROBLEM "https://yukicoder.me/problems/no/1094"

#include <bits/stdc++.h>
using namespace std;

#include "../../tree/lowest_common_ancestor.hpp"

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<vector<pair<int, int>>> G(N);
    for(int i = 0; i < N - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        G[a].push_back({b, c});
        G[b].push_back({a, c});
    }

    LowestCommonAncestor lca(G);

    int Q;
    cin >> Q;
    while(Q--) {
        int s, t;
        cin >> s >> t;
        s--; t--;
        cout << lca.dist_bitween(s, t) << "\n";
    }

    return 0;
}