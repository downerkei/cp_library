#include "rolling_hash.hpp"

int get_palindrome(int p, const RollingHash& a, const RollingHash& b) {
    int N = a.N;
    int q = N - p - 1;

    int lb = 0, ub = min(N - p, p + 1);
    while(ub - lb > 1) {
        int mid = (ub + lb) / 2;
        if(a.get_hash(p - mid, p + mid + 1) == b.get_hash(q - mid, q + mid + 1)) lb = mid;
        else ub = mid;
    }

    return lb;
}

vector<int> enumerate_palindromes(string S) {
    int N = S.size();
    string T = "";
    for(int i = 0; i < N; i++) {
        T += '$';
        T += S[i];
    }
    T += '$';
    RollingHash a(T);
    reverse(T.begin(), T.end());
    RollingHash b(T);
    vector<int> ret;
    for(int i = 1; i < (int)T.size() - 1; i++) {
        ret.push_back(get_palindrome(i, a, b));
    }

    return ret;
}
