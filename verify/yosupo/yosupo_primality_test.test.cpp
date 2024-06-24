#define PROBLEM "https://judge.yosupo.jp/problem/primality_test"

#include <bits/stdc++.h>
using namespace std;

#include "../../math/miller_rabin.hpp"

int main() {
    int Q;
    cin >> Q;
    while(Q--) {
        long long N;
        cin >> N;
        if(fast_factorize::is_prime(N)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
}