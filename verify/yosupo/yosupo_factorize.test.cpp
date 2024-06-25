#define PROBLEM "https://judge.yosupo.jp/problem/factorize"

#include <bits/stdc++.h>
using namespace std;

#include "../../math/fast_factorize.hpp"

int main() {
    int Q;
    cin >> Q;
    while(Q--) {
        long long a;
        cin >> a;
        
        auto ans = fast_factorize::factorize(a);

        int k = 0;
        for(auto [p, e] : ans) {
            k += e;
        }
        cout << k << " ";
        for(auto [p, e] : ans) {
            while(e--) {
                cout << p << " ";
            }
        }
        cout << endl;
    }

    return 0;
}