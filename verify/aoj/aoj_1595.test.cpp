#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1595"

#include <bits/stdc++.h>
using namespace std;

#include "../../dp/rerooting_dp.hpp"

constexpr int INF = 1e9;
using E = int;
E merge(E l, E r) { return max(l, r); }
E e() { return 0; }
E put_v(E e, int v) { return e + 1; }

int main() {
    int N;
    cin >> N;

    RerootingDP<E, merge, e, put_v> G(N);
    for(int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        G.add_edge(u, v);
    }

    for(auto ans : G.solve()) {
        cout << 2 * N - 2 - ans << endl;
    }

    return 0;
}