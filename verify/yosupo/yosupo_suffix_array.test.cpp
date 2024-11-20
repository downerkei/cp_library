#define PROBLEM "https://judge.yosupo.jp/problem/suffixarray"

#include <bits/stdc++.h>
using namespace std;

#include "../../string/suffix_array.hpp"

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    string S;
    cin >> S;
    for(auto ans : calc_suffix_array(S)) {
        cout << ans << " ";
    }
    cout << endl;

    return 0;
}