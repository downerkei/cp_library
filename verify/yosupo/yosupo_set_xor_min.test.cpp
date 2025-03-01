#define PROBLEM "https://judge.yosupo.jp/problem/set_xor_min"

#include <bits/stdc++.h>
using namespace std;

#include "../../data_structure/binary_trie.hpp"

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int Q;
    cin >> Q;

    BinaryTrie bt;

    while(Q--) {
        int t, x;
        cin >> t >> x;
        if(t == 0) {
            if(!bt.find(x)) bt.insert(x);
        }
        if(t == 1) {
            if(bt.find(x)) bt.erase(x);
        }
        if(t == 2) {
            cout << (bt.xor_min(x) ^ x) << "\n";
        }
    }

    return 0;
}