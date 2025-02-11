template <typename T=int>
struct FenwickTree {
    int n;
    vector<T> data;
    FenwickTree(int n) : n(n), data(n, 0) {}

    void add(int p, T x) {
        p++;
        while(p <= n) {
            data[p - 1] += x;
            p += p & -p;
        }
    }

    T sum(int r) {
        T s = 0;
        while(r > 0) {
            s += data[r - 1];
            r -= r & -r;
        }
        return s;
    }
    
    T sum(int l, int r) {
        return sum(r) - sum(l);
    }
};
