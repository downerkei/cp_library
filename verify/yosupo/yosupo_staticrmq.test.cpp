#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include <bits/stdc++.h>
using namespace std;

#include "../../data_structure/segment_tree.hpp"

constexpr int INF = 1e9 + 10;

using S = int;
inline S op(S l, S r) { return min(l, r); }
inline S e() { return INF; }

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    SegmentTree<S, op, e> seg(A);

    while(Q--) {
        int l, r;
        cin >> l >> r;
        cout << seg.prod(l, r) << endl;
    }


    return 0;
}