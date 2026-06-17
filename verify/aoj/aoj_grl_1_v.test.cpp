#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/GRL_1_B"

#include <bits/stdc++.h>
using namespace std;

#include "../../graph/bellman_ford.hpp"

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int V, E, r;
    cin >> V >> E >> r;

    vector<BellmanFord::Edge> edges;
    for(int i = 0; i < E; i++) {
        int s, t;
        long long d;
        cin >> s >> t >> d;
        edges.push_back({s, t, d});
    }

    BellmanFord bf;
    auto dist = bf.shortest_path(V, edges, r);

    if(bf.has_reachable_negative_cycle()) {
        cout << "NEGATIVE CYCLE" << '\n';
        return 0;
    }

    for(int i = 0; i < V; i++) {
        if(dist[i] == BellmanFord::INF) cout << "INF" << '\n';
        else cout << dist[i] << '\n';
    }

    return 0;
}
