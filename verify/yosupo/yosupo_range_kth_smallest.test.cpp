#define PROBLEM "https://judge.yosupo.jp/problem/range_kth_smallest"

#include <bits/stdc++.h>
using namespace std;

#include "../../data_structure/merge_sort_tree.hpp"

constexpr int INF = 1e9 + 10;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    MergeSortTree<int> mst(A);

    while(Q--) {
        int l, r, k;
        cin >> l >> r >> k;
        int lb = -1, ub = INF;
        while(ub - lb > 1) {
            int mid = (lb + ub) / 2;
            if(mst.count_between(l, r, 0, mid) <= k) lb = mid;
            else ub = mid;
        }
        cout << ub << "\n";
    }

    return 0;
}