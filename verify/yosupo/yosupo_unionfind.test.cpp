#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

#include <bits/stdc++.h>
using namespace std;

#include "../../data_structure/union_find.hpp"

int main() {
    int N, Q;
    cin >> N >> Q;

    UnionFind uf(N);

    for(int i = 0; i < Q; i++) {
        int t, u, v;
        cin >> t >> u >> v;

        if(t == 0) {
            uf.unite(u, v);
        }

        if(t == 1) {
            cout << uf.same(u, v) << endl;
        }
    }

    return 0;
}