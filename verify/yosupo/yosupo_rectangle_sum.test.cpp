#define PROBLEM "https://judge.yosupo.jp/problem/rectangle_sum"

#include <bits/stdc++.h>
using namespace std;

#include "../../data_structure/persistent_segment_tree.hpp"

using S = long long;
S op(S l, S r) { return l + r; }
S e() { return 0; }

constexpr int MX = 1e9;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int N, Q;
    cin >> N >> Q;
    
    vector<array<int, 3>> ps(N);
    for(int i = 0; i < N; i++) {
        cin >> ps[i][0] >> ps[i][1] >> ps[i][2];
    }

    sort(ps.begin(), ps.end());

    vector<int> xs(N);
    for(int i = 0; i < N; i++) {
        xs[i] = ps[i][0];
    }

    vector<int> ord(N);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int i, int j) { return ps[i][1] < ps[j][1]; });

    PersistentSegmentTree<S, op, e> seg(N);

    vector<int> ys;
    for(int i : ord) {
        seg.add(i, ps[i][2]);
        ys.push_back(ps[i][1]);
    }

    while(Q--) {
        int l, d, r, u;
        cin >> l >> d >> r >> u;
        int li = lower_bound(xs.begin(), xs.end(), l) - xs.begin();
        int ri = lower_bound(xs.begin(), xs.end(), r) - xs.begin();
        int di = lower_bound(ys.begin(), ys.end(), d) - ys.begin();
        int ui = lower_bound(ys.begin(), ys.end(), u) - ys.begin();
        cout << seg.prod(ui, li, ri) - seg.prod(di, li, ri) << "\n";
    }


    return 0;
}