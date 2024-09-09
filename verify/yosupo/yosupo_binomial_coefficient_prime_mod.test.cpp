#define PROBLEM "https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod"

#include <bits/stdc++.h>
using namespace std;

#include "../../math/binomial_coefficient.hpp"

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    int T, m;
    cin >> T >> m;

    BinomialCoefficient binom(min((int)1e7, m), m);

    while(T--) {
        int n, k;
        cin >> n >> k;
        cout << binom(n, k) << endl;
    }

    return 0;
}