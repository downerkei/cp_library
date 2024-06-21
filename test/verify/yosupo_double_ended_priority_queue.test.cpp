#define PROBLEM "https://judge.yosupo.jp/problem/double_ended_priority_queue"

#include <bits/stdc++.h>
using namespace std;

#include "../../data_structure/binary_search_tree.hpp"

int main() {
    int N, Q;
    cin >> N >> Q;
    BinarySearchTree bst;
    while(N--) {
        int a;
        cin >> a;
        bst.Insert(a);
    }
    while(Q--) {
        int q;
        cin >> q;
        if(q == 0) {
            int x;
            cin >> x;
            bst.Insert(x);
        }
        if(q == 1) {
            int out = bst.Minimum();
            bst.Erase(out);
            cout << out << endl;
        }
        if(q == 2) {
            int out = bst.Maximum();
            bst.Erase(out);
            cout << out << endl;
        }
    }
}