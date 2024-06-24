#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_palindromes"

#include <bits/stdc++.h>
using namespace std;

#include "../../string/rollong_hash.hpp"

int main() {
    string S;
    cin >> S;
    for(auto ans : enumerate_palindromes(S)) {
        cout << ans << " ";
    }
    cout << endl;

    return 0;
}