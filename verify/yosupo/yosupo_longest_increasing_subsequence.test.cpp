#define PROBLEM "https://judge.yosupo.jp/problem/longest_increasing_subsequence"

#include <bits/stdc++.h>
using namespace std;

#include "../../dp/longest_increasing_subsequence.hpp"

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    int N;
    cin >> N;
    vector<int> A(N);

    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    auto lis = longest_increasing_subsequence<int>(A);

    vector<int> ans(lis.size(), 0);
    int it = 0;
    for(int i = 0; i < N; i++) {
        if(A[i] == lis[it]) {
            ans[it] = i;
            it++;
            if(it == lis.size()) break;
        }
    }

    cout << ans.size() << "\n";
    for(auto a : ans) {
        cout << a << " ";
    }
    cout << "\n";

    return 0;
}
