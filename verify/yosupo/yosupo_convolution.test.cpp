#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"

#include <bits/stdc++.h>
using namespace std;

#include "../../convolution/ntt.hpp"

int main() {
    int N, M;
    cin >> N >> M;
    vector<long long> A(N), B(M);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for(int i = 0; i < M; i++) {
        cin >> B[i];
    }

    NTT ntt;

    auto c = ntt.convolution(A, B);

    for(auto i : c) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}