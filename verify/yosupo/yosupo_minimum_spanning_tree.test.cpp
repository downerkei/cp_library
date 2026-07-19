#define PROBLEM "https://judge.yosupo.jp/problem/minimum_spanning_tree"

#include <bits/stdc++.h>
using namespace std;

#include "../../data_structure/union_find.hpp"

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    int N, M; 
    cin >> N >> M;

    vector<array<int, 4>> E(M);
    for(int i = 0; i < M; i++) {
        cin >> E[i][1] >> E[i][2] >> E[i][0];
        E[i][3] = i;
    }

    ranges::sort(E);

    long long cost = 0;
    vector<int> ans;
    UnionFind uf(N);
    for(auto [c, a, b, i] : E) {
        if(uf.unite(a, b)) {
            cost += c;
            ans.push_back(i);
        } 
    }

    cout << cost << "\n";
    for(int a : ans) {
        cout << a << " ";
    }
    cout << "\n";

    return 0;
}