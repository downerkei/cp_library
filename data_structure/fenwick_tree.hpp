template <typename T>
struct FenwickTree {
    int n_;
    vector<T> data;
    FenwickTree(int n) : n_(n), data(n, 0) {}

    // data[p] += x
    void add(int p, T x) {
        p++;
        while(p <= n_) {
            data[p - 1] += x;
            p += p & -p;
        }
    }

    // sum[0, r)
    T sum(int r) {
        T s = 0;
        while(r > 0) {
            s += data[r - 1];
            r -= r & -r;
        }
        return s;
    }
    
    // sum[l, r)
    T sum(int l, int r) {
        return sum(r) - sum(l);
    }
};