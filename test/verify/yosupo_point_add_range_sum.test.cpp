#include <bits/stdc++.h>
using namespace std;

#include "../../data_structure/fenwick_tree.hpp"

int main(){
    int N, Q;
    cin >> N >> Q;

    FenwickTree<long long> bit(N); 

    for(int i = 0; i < N; i++) {
        int a;
        cin >> a;
        bit.Add(i, a);
    }

    for(int i = 0; i < Q; i++) {
        int t;
        cin >> t;
        if(t == 0) {
            int p, x;
            cin >> p >> x;
            bit.Add(p, x);
        }

        if(t == 1) {
            int l, r;
            cin >> l >> r;
            cout << bit.Sum(l, r) << endl;
        }
    }

    return 0;
}