#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_palindromes"

#include <bits/stdc++.h>
using namespace std;

#include "../../string/enumerate_palindromes.hpp"

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    string S;
    cin >> S;
    for(auto ans : enumerate_palindromes(S)) {
        cout << ans << " ";
    }
    cout << "\n";

    return 0;
}