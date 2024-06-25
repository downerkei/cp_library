#define PROBLEM "https://yukicoder.me/problems/no/186"

#include <bits/stdc++.h>
using namespace std;

#include "../../math/crt.hpp"

int main() {
    vector<long long> X(3), Y(3);
    for(int i = 0; i < 3; i++) {
        cin >> X[i] >> Y[i];
    }
    auto [r, m] = crt(X, Y);
    
    if(m == -1) cout << -1 << endl;
    else if(r == 0) cout << m << endl;
    else cout << r << endl;

    return 0;
}
