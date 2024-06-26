template<class S, S (*op)(S, S), S (*e)(), class F, S (*mapping)(F, S), F (*composition)(F, F), F (*id)()>
struct LazySegmentTree{
    int n;
    vector<S> data;
    vector<F> lazy;

    LazySegmentTree(int n_) {
        n = 1; while(n < n_) n *= 2;
        data.resize(2 * n, e());
        lazy.resize(2 * n, id());
    }

    LazySegmentTree(vector<S> &v) {
        int sz = v.size();
        n = 1; while(n < sz) n *= 2;
        data.resize(2 * n, e());
        lazy.resize(2 * n, id());

        for(int i = 0; i < sz; i++) {
            data[i+n] = v[i];
        }
        for(int i = n - 1; i > 0; i--) {
            data[i] = op(data[i<<1], data[i<<1|1]);
        }
    }

    void eval(int i) {
        if(lazy[i] == id()) return;
        data[i] = mapping(lazy[i], data[i]);

        if(i < n) {
            lazy[i<<1] = composition(lazy[i], lazy[i<<1]);
            lazy[i<<1|1] = composition(lazy[i], lazy[i<<1|1]);
        }

        lazy[i] = id();
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

    S prod(int a, int b, int i=1, int l=0, int r=-1) {
        if(r < 0) r = n;
        if(r <= a || b <= l) return e();

        eval(i);
        if(a <= l && r <= b) return data[i];
        int mid = (l + r) / 2;
        return op(prod(a, b, i << 1, l, mid), prod(a, b, i << 1 | 1, mid, r));
    }

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
};
