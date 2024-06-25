#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A&lang=ja"

#include <bits/stdc++.h>
using namespace std;

#include "../../math/factorize.hpp"

int main() {
    int N;
    cin >> N;
    auto primes = factorize(N);
    cout << N << ':';
    for(auto [p, e] : primes) {
        while(e--) {
            cout << ' ' << p;
        }
    }
    cout << endl;

    return 0;
}