template <typename T>
struct FenwickTree {
  public:
    FenwickTree(int n) : n_(n), data(n) {}

    void Add(int p, T x) {
        p++;
        while(p <= n_) {
            data[p - 1] += x;
            p += p & -p;
        }
    }

    T Sum(int r) {
        T s = 0;
        while(r > 0) {
            s += data[r - 1];
            r -= r & -r;
        }
        return s;
    }

    T Sum(int r, int l) {
        return Sum(l) - Sum(r);
    }

  private:
    int n_;
    vector<T> data;
};