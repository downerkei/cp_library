#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"

#include <bits/stdc++.h>
using namespace std;

#include "../../data_structure/lazy_segmemt_tree.hpp"
#include "../../data_structure/static_modint.hpp"

using mint = StaticModint<998244353>;

using S = pair<mint, mint>;
S op(S l, S r) { return {l.first + r.first, l.second + r.second}; }
S e() { return {0, 0}; }
using F = pair<mint, mint>;
S mapping(F f, S x) { return {x.first * f.first + x.second * f.second, x.second}; }
F composition(F f, F g) { return {f.first * g.first, f.first * g.second + f.second}; }
F id() { return {1, 0}; }

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<S> A(N);
    for(int i = 0; i < N; i++) {
        int a;
        cin >> a;
        A[i] = {a, 1};
    }

    LazySegmentTree<S, op, e, F, mapping, composition, id> seg(A);

    while(Q--) {
        int q;
        cin >> q;
        if(q == 0) {
            int l, r, b, c;
            cin >> l >> r >> b >> c;
            seg.apply(l, r, {b, c});
        }
        if(q == 1) {
            int l, r;
            cin >> l >> r;
            cout << seg.prod(l, r).first << endl;
        }
    }

    return 0;
}
