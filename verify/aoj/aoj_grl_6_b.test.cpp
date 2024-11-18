#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B"

#include <bits/stdc++.h>
using namespace std;

#include "../../flow/primal_dual.hpp"

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int V, E, F;
    cin >> V >> E >> F;
    PrimalDual<int, int> G(V);
    for(int i = 0; i < E; i++) {
        int u, v, c, d;
        cin >> u >> v >> c >> d;
        G.add_edge(u, v, c, d);
    }

    auto [flow, cost] = G.max_flow(0, V - 1, F);
    if(flow < F) cout << -1 << "\n";
    else cout << cost << "\n";

    return 0;
}