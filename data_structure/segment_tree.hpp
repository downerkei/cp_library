template<class S, S (*op)(S, S), S (*e)()>
struct SegmentTree{
    int n;
    vector<S> data;

    SegmentTree(int sz=0) : n(1) {
        while(n < sz) n *= 2;
        data.resize(2 * n, e());
    }

    SegmentTree(const vector<S> &V) : n(1) {
        int sz = V.size();
        while(n < sz) n *= 2;
        data.resize(2 * n, e());
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
        S vl = e(), vr = e();
        while(l < r) {
            if(l & 1) vl = op(vl, data[l++]);
            if(r & 1) vr = op(data[--r], vr);
            l >>= 1; r >>= 1;
        }
        return op(vl, vr);
    }

    S all_prod() { return prod(0, n); }

    S get(int i) { return data[i + n]; }
};