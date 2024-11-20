#include "rolling_hash.hpp"

int get_lcp(int p, const RollingHash& rh) {
    int lb = 0, ub = rh.N - p + 1;
    while(ub - lb > 1) {
        int mid = (ub + lb) / 2;
        if(rh.get_hash(p, p + mid) == rh.get_hash(0, mid)) lb = mid;
        else ub = mid;
    }
    return lb;
}

vector<int> enumerate_lcp(const string& S) {
    RollingHash rh(S);
    vector<int> ret(rh.N);
    for(int i = 0; i < rh.N; i++) {
        ret[i] = get_lcp(i, rh);
    }
    return ret;
}
