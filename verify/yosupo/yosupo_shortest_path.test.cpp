#define PROBLEM "https://judge.yosupo.jp/problem/shortest_path"

#include <bits/stdc++.h>
using namespace std;

#include "../../graph/dijkstra.hpp"

int main() {
    int N, M, s, t;
    cin >> N >> M >> s >> t;
    vector<vector<pair<int, long long>>> G(N);
    for(int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        G[a].push_back({b, c});
    }

    Dijkstra dijkstra(G, s);

    if(dijkstra.dist(t) == -1) {
        cout << -1 << endl;
        return 0;
    }

    auto path = dijkstra.path(t);

    cout << dijkstra.dist(t) << " " << path.size() - 1 << endl;
    for(int i = 0; i < (int)path.size() - 1; i++) {
        cout << path[i] << " " << path[i + 1] << endl;
    }

    return 0;
}