#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C"

#include <bits/stdc++.h>
using namespace std;

#include "../../math/is_prime.hpp"

int main() {
    int N;
    cin >> N;
    int ans = 0;
    while(N--) {
        int a;
        cin >> a;
        ans += is_prime(a);
    }
    cout << ans << endl;

    return 0;
}
