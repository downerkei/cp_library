#define PROBLEM "https://yukicoder.me/problems/no/430"

#include <bits/stdc++.h>
using namespace std;

#include "../../string/aho_corasick.hpp"

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    string S;
    int M;
    cin >> S >> M;

    for(char& c : S) c += 32;

    AhoCorasick ac;
    for(int i = 0; i < M; i++) {
        string C;
        cin >> C;

        for(char& c : C) c += 32;
        
        ac.insert(C, i);
    }

    ac.build();
    auto matches = ac.search(S);
    cout << matches.size() << "\n";

    return 0;
}