#define PROBLEM "https://judge.yosupo.jp/problem/scc"

#include <bits/stdc++.h>
using namespace std;

#include "../../graph/scc.hpp"

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N);
    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
    }

    auto ans = calc_scc(G);
    cout << ans.size() << "\n";

    for(auto C : ans) {
        cout << ssize(C) << " ";
        for(auto v : C) {
            cout << v << " ";
        }
        cout << "\n";
    }

    return 0;
}