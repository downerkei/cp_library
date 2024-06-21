#define PROBLEM "https://atcoder.jp/contests/atc001/tasks/fft_c"

#include <bits/stdc++.h>
using namespace std;

#include "../../convolution/fft.hpp"

int main() {
    int N;
    cin >> N;
    vector<complex<double>> A(N + 1), B(N + 1);
    A[0] = 0;
    B[0] = 0;
    for(int i = 1; i <= N; i++) {
        cin >> A[i] >> B[i];
    }

    FFT fft;
    auto C = fft.Convolution(A, B);

    for(int i = 1; i <= 2 * N; i++) {
        cout << int(round(C[i].real())) << endl;
    }

    return 0;
}