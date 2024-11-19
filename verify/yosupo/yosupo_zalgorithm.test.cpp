#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"

#include <bits/stdc++.h>
using namespace std;

#include "../../string/rolling_hash.hpp"

int main() {
    string S;
    cin >> S;
    RollingHash rh(S);
    for(auto ans : rh.all_LCP()) {
        cout << ans << " ";
    }
    cout << endl;

    return 0;
}