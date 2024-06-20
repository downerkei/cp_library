#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct FenwickTree {
  public:
    FenwickTree(int n) : n_(n), data(n) {}

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

int main(){
    int N, Q;
    cin >> N >> Q;

    FenwickTree<long long> bit(N); 

    for(int i = 0; i < N; i++) {
        int a;
        cin >> a;
        bit.add(i, a);
    }

    for(int i = 0; i < Q; i++) {
        int t;
        cin >> t;
        if(t == 0) {
            int p, x;
            cin >> p >> x;
            bit.add(p, x);
        }

        if(t == 1) {
            int l, r;
            cin >> l >> r;
            cout << bit.sum(l, r) << endl;
        }
    }

    return 0;
}