#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/GRL_1_C"

#include <bits/stdc++.h>
using namespace std;

#include "../../graph/warshall_floyd.hpp"

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int V, E;
    cin >> V >> E;

    vector<WarshallFloyd::Edge> edges;
    for(int i = 0; i < E; i++) {
        int s, t;
        long long d;
        cin >> s >> t >> d;
        edges.push_back({s, t, d});
    }

    WarshallFloyd wf;
    auto dist = wf.shortest_path(V, edges);

    if(wf.has_negative_cycle()) {
        cout << "NEGATIVE CYCLE" << '\n';
        return 0;
    }

    for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++) {
            if(j) cout << ' ';
            if(dist[i][j] == WarshallFloyd::INF) cout << "INF";
            else cout << dist[i][j];
        }
        cout << '\n';
    }

    return 0;
}
