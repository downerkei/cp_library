#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include <bits/stdc++.h>
using namespace std;

#include "../../data_structure/fenwick_tree.hpp"

int main(){
    int N, Q;
    cin >> N >> Q;

    FenwickTree<long long> bit(N); 

    for(int i = 0; i < N; i++) {
        int a;
        cin >> a;
        bit.add(i, a);
    }

    for(int i = 0; i < Q; i++) {
        int t;
        cin >> t;
        if(t == 0) {
            int p, x;
            cin >> p >> x;
            bit.add(p, x);
        }

        if(t == 1) {
            int l, r;
            cin >> l >> r;
            cout << bit.sum(l, r) << endl;
        }
    }

    return 0;
}