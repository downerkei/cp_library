#define PROBLEM "https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod"

#include <bits/stdc++.h>
using namespace std;

#include "../../math/binomial_coefficient.hpp"

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    int T, m;
    cin >> T >> m;

    vector<int> N(T), K(T);
    int mx = 0;
    for(int i = 0; i < T; i++) {
        cin >> N[i] >> K[i];
        mx = max(mx, N[i]);
    }

    BinomialCoefficient binom(mx, m);
    for(int i = 0; i < T; i++) {
        cout << binom(N[i], K[i]) << "\n";
    }

    return 0;
}