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

// 転倒数を求める
// FenwickTreeが必要
template<typename T>
long long inversion_number(const vector<T>& A) {
    vector<T> B = A;
    sort(B.begin(), B.end());
    B.erase(unique(B.begin(), B.end()), B.end());

    FenwickTree<T> bit(B.size());

    long long ret = 0;
    for(int i = 0; i < (int)A.size(); i++) {
        int rank = lower_bound(B.begin(), B.end(), A[i]) - B.begin() + 1;
        ret += i - bit.sum(rank);
        bit.add(rank, 1);
    }
    return ret;
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }
    cout << inversion_number<int> (A) << endl;

    return 0;
}