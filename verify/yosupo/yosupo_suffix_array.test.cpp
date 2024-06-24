#define PROBLEM "https://judge.yosupo.jp/problem/suffixarray"

#include <bits/stdc++.h>
using namespace std;

#include "../../string/rollong_hash.hpp"

int main() {
    string S;
    cin >> S;
    RollingHash rh(S);
    for(auto ans : rh.suffix_array()) {
        cout << ans << " ";
    }
    cout << endl;

    return 0;
}