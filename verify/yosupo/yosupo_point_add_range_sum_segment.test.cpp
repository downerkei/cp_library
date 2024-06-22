#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include <bits/stdc++.h>
using namespace std;

#include "../../data_structure/segment_tree.hpp"

using S = long long;
S op(S l, S r) { return l + r; }
S e() { return 0; }

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<long long> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    SegmentTree<S, op, e> seg(A);

    while(Q--) {
        int q;
        cin >> q;
        if(q == 0) {
            long long p, x;
            cin >> p >> x;
            seg.Set(p, x + seg.Get(p));
        }
        if(q == 1) {
            int l, r;
            cin >> l >> r;
            cout << seg.Prod(l, r) << endl;
        } 
    }

    return 0;
}