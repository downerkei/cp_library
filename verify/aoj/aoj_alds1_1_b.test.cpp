#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_1_B"

#include <bits/stdc++.h>
using namespace std;

#include "../../math/gcd.hpp"

int main() {
    int x, y;
    cin >> x >> y;
    cout << gcd(x, y) << endl;

    return 0;
}
