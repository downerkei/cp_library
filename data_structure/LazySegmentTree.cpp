#include <bits/stdc++.h>
using namespace std;

const long long MOD = 998244353;

using S = pair<long long, long long>;
using F = pair<long long, long long>;
S op(S l, S r) { return {(l.first + r.first) % MOD, l.second + r.second}; }
S e = {0, 0};
S mapping(F f, S x) { return {(x.first * f.first + x.second * f.second) % MOD, x.second}; }
F composition(F f, F g) { return {(f.first * g.first) % MOD, (f.first * g.second + f.second) % MOD}; }
F id = {1, 0};

// 動く
struct LazySegmentTree{
    int n;
    vector<S> data;
    vector<F> lazy;

    LazySegmentTree(vector<S> &v) {
        int sz = v.size();
        n = 1; while(n < sz) n *= 2;
        data.resize(2 * n, e);
        lazy.resize(2 * n, id);

        for(int i = 0; i < sz; i++) {
            data[i+n] = v[i];
        }
        for(int i = n - 1; i > 0; i--) {
            data[i] = op(data[i<<1], data[i<<1|1]);
        }
    }

    void eval(int i) {
        if(lazy[i] == id) return;
        data[i] = mapping(lazy[i], data[i]);

        if(i < n) {
            lazy[i<<1] = composition(lazy[i], lazy[i<<1]);
            lazy[i<<1|1] = composition(lazy[i], lazy[i<<1|1]);
        }

        lazy[i] = id;
    }

    void apply(int a, int b, F x, int i=1, int l=0, int r=-1) {
        if(r < 0) r = n;
        eval(i);
        if(r <= a || b <= l) return;
        if(a <= l && r <= b) {
            lazy[i] = x;
            eval(i);
        }
        else {
            int mid = (l + r) / 2;
            apply(a, b, x, i << 1, l, mid);
            apply(a, b, x, i << 1 | 1, mid, r);
            data[i] = op(data[i<<1], data[i<<1|1]);
        }
    }

    S prod(int a, int b, int i=1, int l=0, int r=-1) {
        if(r < 0) r = n;
        if(r <= a || b <= l) return e;

        eval(i);
        if(a <= l && r <= b) return data[i];
        int mid = (l + r) / 2;
        return op(prod(a, b, i << 1, l, mid), prod(a, b, i << 1 | 1, mid, r));
    }
};

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<S> A(N);
    for(int i = 0; i < N; i++) {
        long long a;
        cin >> a;
        A[i] = {a, 1};
    }

    LazySegmentTree seg(A);

    while(Q--) {
        int c, l, r;
        cin >> c >> l >> r;
        if(c == 0) {
            long long b, c;
            cin >> b >> c;
            seg.apply(l, r, F(b, c));
        }
        if(c == 1) {
            cout << seg.prod(l, r).first << endl;
        }
    }

    return 0;
}



// 試作
// struct LazySegmentTree{
//     int n, log;
//     vector<S> data;
//     vector<F> lazy;

//     LazySegmentTree(int n_) {
//         n = 1; log = 0; while(n < n_) { n *= 2; log++; }
//         data.resize(2 * n, e);
//         lazy.resize(2 * n, id);
//     }

//     LazySegmentTree(vector<S> &v) {
//         int sz = v.size();
//         n = 1; log = 0; while(n < sz) { n *= 2; log++; }
//         data.resize(2 * n, e);
//         lazy.resize(2 * n, id);

//         for(int i = 0; i < sz; i++) {
//             data[i + n] = v[i];
//         } 
//         for(int i = n - 1; i >= 0; i--) {
//             data[i] = op(data[i<<1], data[i<<1|1]);
//         }
//     }

//     void eval(int i) {
//         if(lazy[i] == id) return;
//         data[i] = mapping(lazy[i], data[i]);

//         if(i < n) {
//             lazy[i<<1] = composition(lazy[i], lazy[i<<1]);
//             lazy[i<<1|1] = composition(lazy[i], lazy[i<<1|1]);
//         }

//         lazy[i] = id;
//     }

//     void apply(int l, int r, F f) {
//         l += n; r += n;

//         for(int i = log; i >= 1; i--) {
//             if(((l >> i) << i) != l) eval(l >> i);
//             if(((r >> i) << i) != r) eval((r - 1) >> i);
//         }

//         int l2 = l, r2 = r;
//         while(l < r) {
//             if(l & 1) { 
//                 lazy[l] = composition(f, lazy[l]);
//                 eval(l);
//                 l++;
//             }
//             if(r & 1) {
//                 r--;
//                 lazy[r] = composition(f, lazy[r]);
//                 eval(r);
//             }
//             l >>= 1;
//             r >>= 1;
//         }
//         l = l2;
//         r = r2;

//         for(int i = 1; i <= log; i++) {
//             if(((l >> i) << i) != l) data[l>>i] = op(data[l>>(i+1)], data[l>>(i+1)|1]);
//             if(((r >> i) << i) != r) data[(r-1)>>i] = op(data[(r-1)>>(i+1)], data[(r-1)>>(i+1)|1]);
//         }
//     }

//     S prod(int l, int r) {
//         l += n;
//         r += n;
        
//         for(int i = log; i >= 1; i--) {
//             if(((l >> i) << i) != l) eval(l >> i);
//             if(((r >> i) << i) != r) eval((r - 1) >> i);
//         }

//         S vl = e, vr = e;
//         while(l < r) {
//             if(l & 1) vl = op(vl, data[l++]);
//             if(r & 1) vr = op(data[--r], vr);
//             l >>= 1;
//             r >>= 1;
//         }

//         return op(vl, vr);
//     }
// };