#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B&lang=jp"

#include <bits/stdc++.h>
using namespace std;

#include "../../math/pow.hpp"

int main() {
    int m, n;
    cin >> m >> n;

    cout << modpow(m, n, (int)1e9+7) << endl;

    return 0;
}