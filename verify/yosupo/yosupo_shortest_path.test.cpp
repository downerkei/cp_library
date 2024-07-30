#define PROBLEM "https://judge.yosupo.jp/problem/shortest_path"

#include <bits/stdc++.h>
using namespace std;

#include "../../graph/shortest_path/dijkstra.hpp"

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int N, M, s, t;
    cin >> N >> M >> s >> t;
    
    Dijkstra dij(N);
    for(int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        dij.add_edge(a, b, c);
    }

    auto dist = dij.solve(s);

    if(dist[t] == -1) {
        cout << -1 << endl;
        return 0;
    }

    auto path = dij.calc_path(t);

    cout << dist[t] << " " << path.size() - 1 << endl;
    for(int i = 0; i < (int)path.size() - 1; i++) {
        cout << path[i] << " " << path[i + 1] << endl;
    }

    return 0;
}
