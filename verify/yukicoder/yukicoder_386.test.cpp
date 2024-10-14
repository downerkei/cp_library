#define PROBLEM "https://yukicoder.me/problems/no/386"

#include <bits/stdc++.h>
using namespace std;

#include "../../tree/lowest_common_ancestor.hpp"

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    int N;
    cin >> N;
    vector<int> A(N - 1), B(N - 1);
    for(int i = 0; i < N - 1; i++) {
        cin >> A[i] >> B[i];
    }
    vector<int> C(N);
    for(int i = 0; i < N; i++) {
        cin >> C[i];
    }

    vector<vector<pair<int, int>>> G(N);
    for(int i = 0; i < N - 1; i++) {
        G[A[i]].push_back({B[i], C[A[i]] + C[B[i]]});
        G[B[i]].push_back({A[i], C[A[i]] + C[B[i]]});
    }
    LowestCommonAncestor<int> lca(G);

    int M;
    cin >> M;
    long long ans = 0;
    while(M--) {
        int a, b, c;
        cin >> a >> b >> c;
        int tax = lca.dist_bitween(a, b) + C[a] + C[b];
        tax = tax / 2 * c;
        ans += tax;
    }
    cout << ans << endl;

    return 0;
}