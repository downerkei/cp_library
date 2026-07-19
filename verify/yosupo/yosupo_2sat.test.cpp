#define PROBLEM "https://judge.yosupo.jp/problem/two_sat"

#include <bits/stdc++.h>
using namespace std;

#include "../../math/two_sat.hpp"

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    string a, b;
    int N, M;
    cin >> a >> b >> N >> M;

    TwoSat ts(N);
    for(int i = 0; i < M; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        ts.add_clause(abs(x) - 1, (x > 0), abs(y) - 1, (y > 0));
    }

    if(ts.satisfiable()) {
        cout << "s SATISFIABLE\nv ";
        for(int i = 0; i < N; i++) {
            cout << (ts.ans[i] ? 1 : -1) * (i + 1) << " ";
        }
        cout << "0\n";
    }
    else {
        cout << "s UNSATISFIABLE\n";
    }

    return 0;
}
