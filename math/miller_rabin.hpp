#include "../data_structure/montgomery_modint_64.hpp"

namespace fast_factorize {

using mint = MontgomeryModint64;
bool miller_rabin(long long N, vector<long long> A) {
    mint::set_mod(N);
    long long s = 0, d = N - 1;
    while(!(d & 1)) {
        s++;
        d >>= 1;
    }
    for(long long a : A) {
        if(N <= a) return true;
        mint x = mint(a).pow(d);
        if(x == 1) continue;
        long long t;
        for(t = 0; t < s; t++) {
            if(x == N - 1) break;
            x *= x;
        }
        if(t == s) return false;
    }
    return true;
}

bool is_prime(long long N) {
    if(N <= 1) return false;
    if(N == 2) return true;
    if(!(N & 1)) return false;

    if(N < 4759123141LL) return miller_rabin(N, {2, 7, 61});

    return miller_rabin(N, {2, 325, 9375, 28178, 450775, 9780504, 1795265022});
}

} // namespace fast_factorize
