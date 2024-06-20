#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

using S = pair<long long, long long>;
S op(S l, S r) { return {l.first * r.first % MOD, (r.first * l.second % MOD + r.second) % MOD}; }
constexpr S e = {1, 0};

template<class S, S (*op)(S, S), S e>
struct SegmentTree{
    int n;
    vector<S> data;

    SegmentTree(int sz=0) : n(1) {
        while(n < sz) n *= 2;
        data.resize(2 * n, e);
    }

    SegmentTree(const vector<S> &V) : n(1) {
        int sz = V.size();
        while(n < sz) n *= 2;
        data.resize(2 * n, e);
        for(int i = 0; i < sz; i++) data[i+n] = V[i];
        for(int i = n - 1; i >= 1; i--) data[i] = op(data[i<<1], data[i<<1|1]);
    }

    void set(int i, S x) {
        i += n;
        data[i] = x;
        while(i > 1) {
            i >>= 1;
            data[i] = op(data[i<<1], data[i<<1|1]);
        }
    }

    S prod(int l, int r) {
        l += n; r += n;
        S vl = e, vr = e;
        while(l < r) {
            if(l & 1) vl = op(vl, data[l++]);
            if(r & 1) vr = op(data[--r], vr);
            l >>= 1; r >>= 1;
        }
        return op(vl, vr);
    }
};

int main() {
    int N, Q;
    cin >> N >> Q;
    SegmentTree<S, op, e> seg(N);
    for(int i = 0; i < N; i++) {
        long long a, b;
        cin >> a >> b;
        seg.set(i, {a, b});
    }

    while(Q--) {
        int c;
        cin >> c;
        if(c == 0) {
            long long p, c, d;
            cin >> p >> c >> d;
            seg.set(p, {c, d});
        }
        if(c == 1) {
            long long l, r, x;
            cin >> l >> r >> x;
            auto [a, b] = seg.prod(l, r);
            cout << (a * x % MOD + b) % MOD << endl;
        }
    }

    return 0;
}