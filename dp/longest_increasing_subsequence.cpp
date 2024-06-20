#include <bits/stdc++.h>
using namespace std;

// longest increasing subsequence
template<class T>
int longest_increasing_subsequence(const vector<T> &A) {
    vector<T> lis;
    for(const auto& p : A) {
        // 狭義
        auto it = lower_bound(lis.begin(), lis.end(), p);
        if(lis.end() == it) lis.push_back(p);
        else *it = p;
    }
    return lis.size();
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }
    cout << longest_increasing_subsequence<int>(A) << endl;

    return 0;
}