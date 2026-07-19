#define PROBLEM "https://judge.yosupo.jp/problem/static_range_frequency"

#include <bits/stdc++.h>
using namespace std;

#include "../../data_structure/merge_sort_tree.hpp"

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    MergeSortTree<int> ms(A);

    for(int i = 0; i < Q; i++) {
        int l, r, x;
        cin >> l >> r >> x;
        cout << ms.count_range(l, r, x, x + 1) << "\n";
    }

    return 0;
}