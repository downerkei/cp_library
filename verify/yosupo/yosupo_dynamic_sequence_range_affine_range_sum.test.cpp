#define PROBLEM "https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum"

#include <bits/stdc++.h>
using namespace std;

#include "../../data_structure/lazy_reversible_splay_tree.hpp"

constexpr int MOD = 998244353;

using S = pair<long long, long long>;
using F = pair<long long, long long>;
S op(S l, S r) { return {(l.first + r.first) % MOD, l.second + r.second}; }
S e() { return S(0, 0); }
void reverse_prod(S& x) {}
S mapping(F f, S x) { return {(x.first * f.first + x.second * f.second) % MOD, x.second}; }
F composition(F f, F g) { return {(f.first * g.first) % MOD, (f.first * g.second + f.second) % MOD}; }
F id() { return F(1, 0); }

void solve() {
    int N, Q;
    cin >> N >> Q;
    LazyReversibleSplayTree<S, op, e, reverse_prod, F, mapping, composition, id> st;
    for(int i = 0; i < N; i++) {
        int a;
        cin >> a;
        st.insert_at(i, {a, 1});
    }
    while(Q--) {
        int t;
        cin >> t;
        if(t == 0) {
            int i, x;
            cin >> i >> x;
            st.insert_at(i, {x, 1});
        }
        if(t == 1) {
            int i;
            cin >> i;
            st.erase_at(i);
        }
        if(t == 2) {
            int l, r;
            cin >> l >> r;
            st.reverse(l, r);
        }
        if(t == 3) {
            int l, r, b, c;
            cin >> l >> r >> b >> c;
            st.apply(l, r, {b, c});
        }
        if(t == 4) {
            int l, r;
            cin >> l >> r;
            cout << st.prod(l, r).first << endl;
        }
    }
}

int main() {
    solve();
}