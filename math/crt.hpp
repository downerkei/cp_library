#include "ext_gcd.hpp"

inline long long safe_mod(long long a, long long m) {
    return (a % m + m) % m;
}

pair<long long, long long> crt(const vector<long long>& b, const vector<long long>& m) {
    assert(b.size() == m.size());
    long long r = 0, M = 1;
    for(int i = 0; i < (int)b.size(); i++) {
        auto [d, p, q] = ext_gcd(M, m[i]);
        if((b[i] - r) % d != 0) return {0, -1};
        long long tmp = (b[i] - r) / d * p % (m[i] / d);
        r += M * tmp;
        M *= m[i] / d;
    }
    r = safe_mod(r, M);
    return {r, M};
}