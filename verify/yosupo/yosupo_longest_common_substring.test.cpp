#define PROBLEM "https://judge.yosupo.jp/problem/longest_common_substring"

#include <bits/stdc++.h>
using namespace std;

#include "../../string/suffix_array.hpp"
#include "../../string/lcp_array.hpp"

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    string S, T;
    cin >> S >> T;

    int ssz = S.size();

    S += "$";
    S += T;

    auto sa = suffix_array(S);
    auto lcp = lcp_array(S, sa);

    int N = S.size();
    int a = 0, b = 0, c = 0, d = 0;
    for(int i = 0; i < N - 1; i++) {
        int i1 = i, i2 = i + 1;
        if(sa[i1] > sa[i2]) swap(i1, i2);
        if(lcp[i] <= b - a) continue;
        if(sa[i1] < ssz && ssz < sa[i2]) {
            a = sa[i1];
            b = a + lcp[i];
            c = sa[i2] - ssz - 1;
            d = c + lcp[i];
        }
    }

    cout << a << " " << b << " " << c << " " << d << "\n";

    return 0;
}