template<class S, S (*op)(S, S), S (*e)(), class F, S (*mapping)(F, S), F (*composition)(F, F), F (*id)()>
struct LazySegmentTree{
    int n, log;
    vector<S> data;
    vector<F> lazy;

    LazySegmentTree(int n) : LazySegmentTree(vector<S>(n, e())) {}

    LazySegmentTree(const vector<S> &v) {
        int sz = v.size();
        n = 1; 
        log = 0;
        while(n < sz) {
            n <<= 1;
            log++;
        }

        data.resize(2 * n, e());
        lazy.resize(2 * n, id());

        for(int i = 0; i < sz; i++) data[i + n] = v[i];
        for(int i = n; --i;) data[i] = op(data[i << 1], data[i << 1 | 1]);
    }

    S prod(int l, int r) {
        if(l == r) return e();
        l += n; r += n;

        for(int i = log; i >= 1; i--) {
            if(((l >> i) << i) != l) push(l >> i);
            if(((r >> i) << i) != r) push(r >> i);
        }

        S vl = e(), vr = e();
        while(l < r) {
            if(l & 1) vl = op(vl, data[l++]);
            if(r & 1) vr = op(data[--r], vr);
            l >>= 1; r >>= 1;
        }

        return op(vl, vr);
    }

    void apply(int l, int r, F f) {
        if(l == r) return;
        l += n; r += n;
        
        for(int i = log; i >= 1; i--) {
            if(((l >> i) << i) != l) push(l >> i);
            if(((r >> i) << i) != r) push((r - 1) >> i);
        }

        {
            int l2 = l, r2 = r;
            while(l < r) {
                if(l & 1) all_apply(l++, f);
                if(r & 1) all_apply(--r, f);
                l >>= 1;
                r >>= 1;
            }
            l = l2; r = r2;
        }

        for(int i = 1; i <= log; i++) {
            if(((l >> i) << i) != l) update(l >> i);
            if(((r >> i) << i) != r) update((r - 1) >> i);
        }
    }

    inline void update(int k) { data[k] = op(data[k << 1], data[k << 1 | 1]); }
    inline void all_apply(int k, F f) {
        data[k] = mapping(f, data[k]);
        if(k < n) lazy[k] = composition(f, lazy[k]);
    }
    inline void push(int k) {
        all_apply(k << 1, lazy[k]);
        all_apply(k << 1 | 1, lazy[k]);
        lazy[k] = id();
    }
};
