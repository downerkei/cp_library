#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_E"

#include <bits/stdc++.h>
using namespace std;

#include "../../math/ext_gcd.hpp"

int main() {
    int a, b;
    cin >> a >> b;
    auto [d, x, y] = ext_gcd(a, b);
    cout << x << " " << y << endl;

    return 0;
}
