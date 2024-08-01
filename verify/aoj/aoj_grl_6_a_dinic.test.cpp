#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A&lang=jp"

#include <bits/stdc++.h>
using namespace std;

#include "../../graph/flow/dinic.hpp"

int main() {
    int V, E;
    cin >> V >> E;

    Dinic<int> dinic(V);

    for(int i = 0; i < E; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        dinic.add_edge(u, v, c);
    }

    cout << dinic.max_flow(0, V - 1) << endl;

    return 0;
}