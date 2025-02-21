#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"

#include <bits/stdc++.h>
using namespace std;

#include "../../string/z_algorithm.hpp"

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    string S;
    cin >> S;
    for(auto ans : z_algorithm(S)) {
        cout << ans << " ";
    }
    cout << endl;

    return 0;
}