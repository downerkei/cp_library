#include "../data_structure/fenwick_tree.hpp"

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