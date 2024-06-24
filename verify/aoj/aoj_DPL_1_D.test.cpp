#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_D"

#include <bits/stdc++.h>
using namespace std;

#include "../../dp/longest_increasing_subsequence.hpp"

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    for(int i = 0; i < n; i++) {
        cin >> A[i];
    }
    cout << longest_increasing_subsequence<int>(A) << endl;

    return 0;
}