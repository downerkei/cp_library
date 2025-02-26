template <typename T=int>
struct FenwickTree {
    int n;
    vector<T> data;
    FenwickTree(int n) : n(n), data(n, 0) {}

    void add(int p, T x) {
        for(p++; p <= n; p += p & -p) data[p - 1] += x;
    }

    T sum(int r) {
        T s = 0;
        for(; r; r -= r & -r) s += data[r - 1];
        return s;
    }
    
    T sum(int l, int r) {
        return sum(r) - sum(l);
    }
};
