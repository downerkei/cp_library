#include <bits/stdc++.h>
using namespace std;

vector<pair<long long, int>> factorize(long long N) {
    vector<pair<long long, int>> ret;
    for(long long p = 2; p * p <= N; p++) {
        if(N % p != 0) continue;
        int e = 0;
        while(N % p == 0) {
            N /= p;
            e++;
        }
        ret.push_back({p, e});
    }
    if(N != 1) ret.push_back({N, 1});
    return ret;
}

int main() {
    long long N;
    cin >> N;
    auto ans = factorize(N);
    for(auto [p, e] : ans) {
        while(e--) {
            cout << p << " ";
        }
    }
    cout << endl;

    return 0;
}