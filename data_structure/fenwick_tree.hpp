template <typename T>
struct FenwickTree {
  public:
    FenwickTree(int n) : n_(n), data(n, 0) {}

    void add(int p, T x) {
        p++;
        while(p <= n_) {
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

    T sum(int r, int l) {
        return sum(l) - sum(r);
    }

  private:
    int n_;
    vector<T> data;
};