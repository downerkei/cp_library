#define PROBLEM "https://judge.yosupo.jp/problem/cartesian_tree"

#include <bits/stdc++.h>
using namespace std;

#include "../../tree/cartesian_tree.hpp"

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    CartesianTree ct(A);

    for(int i = 0; i < N; i++) {
        cout << (ct.p[i] != -1 ? ct.p[i] : i) << " ";
    }
    cout << "\n";

    return 0;
}