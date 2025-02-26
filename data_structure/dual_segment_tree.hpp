template<class S, S (*op)(S, S), S (*e)()>
struct DualSegmentTree{
    int n;
    vector<S> data;

    DualSegmentTree(int sz=0) : n(1) {
        while(n < sz) n *= 2;
        data.resize(2 * n, e());
    }

    DualSegmentTree(const vector<S> &V) : n(1) {
        int sz = V.size();
        while(n < sz) n *= 2;
        data.resize(2 * n, e());
        for(int i = 0; i < sz; i++) data[i+n] = V[i];
    }

    S get(int i) {
        i += n;
        S v = data[i];
        while(i > 1) {
            i >>= 1;
            v = op(v, data[i]);
        }
        return v;
    }

    void apply(int l, int r, S x) {
        l += n, r += n;
        while(l < r) {
            if(l & 1) data[l] = op(data[l], x), l++;
            if(r & 1) r--, data[r] = op(data[r], x);
            l >>= 1, r >>= 1;
        }
    } 
};
