#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_palindromes"

#include <bits/stdc++.h>
using namespace std;

#include "../../string/manacher.hpp"

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    string S;
    cin >> S;

    string T;
    for(int i = 0; i < S.size(); i++) {
        T += '$';
        T += S[i];
    }
    T += '$';

    auto ans = manacher(T);
    for(int i = 1; i < ans.size() - 1; i++) {
        cout << ans[i] - 1 << " ";
    }
    cout << "\n";

    return 0;
}