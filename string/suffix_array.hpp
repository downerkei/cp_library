#include "rolling_hash.hpp"

bool comp(const int& i, const int& j, const RollingHash& rh) {
    if(rh.get_hash(i, i + 1) != rh.get_hash(j, j + 1)) return rh.get_hash(i, i + 1) < rh.get_hash(j, j + 1);

    int lb = 0, ub = 1, mx = rh.N - max(i, j) + 1;
    while(rh.get_hash(i, i + ub) == rh.get_hash(j, j + ub)) {
        ub *= 5;
        if(ub >= mx) continue;
        ub = mx;
        break;
    }

    while(ub - lb > 1) {
        int mid = (ub + lb) / 2;
        if(rh.get_hash(i, i + mid) == rh.get_hash(j, j + mid)) lb = mid;
        else ub = mid;
    }

    if(i + lb == rh.N) return true;
    if(j + lb == rh.N) return false;
    return rh.get_hash(i + lb, i + lb + 1) < rh.get_hash(j + lb, j + lb + 1);
}

vector<int> calc_suffix_array(const string& S) {
    RollingHash rh(S);
    vector<int> ret(rh.N);
    iota(ret.begin(), ret.end(), 0);
    sort(ret.begin(), ret.end(), [&rh](const int& i, const int& j) { return comp(i, j, rh); });
    return ret;
}