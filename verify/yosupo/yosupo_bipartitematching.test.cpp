#define PROBLEM "https://judge.yosupo.jp/problem/bipartitematching"

#include <bits/stdc++.h>
using namespace std;

#include "../../flow/dinic.hpp"

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int L, R, M;
    cin >> L >> R >> M;

    Dinic<int> dinic(L + R + 2);

    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        dinic.add_edge(a, L + b, 1);
    }

    for(int i = 0; i < L; i++) {
        dinic.add_edge(L + R, i, 1);
    }

    for(int i = 0; i < R; i++) {
        dinic.add_edge(L + i, L + R + 1, 1);
    }

    cout << dinic.max_flow(L + R, L + R + 1) << endl;

    const auto& edges = dinic.edges();

    for(const auto& e : edges) {
        if(e.cap) continue;
        if(e.from == L + R || e.to == L + R + 1) continue;
        cout << e.from << ' ' << e.to - L << endl;
    }

    return 0;
}