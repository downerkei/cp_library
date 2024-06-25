#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_5_D"

#include <bits/stdc++.h>
using namespace std;

#include "../../math/inversion_number.hpp"

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    cout << inversion_number<int>(A) << endl;
    

    return 0;
}
