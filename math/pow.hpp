long long mypow(long long b, long long e) {
    long long ret = 1;
    while(e) {
        if(e & 1) ret *= b;
        b *= b;
        e >>= 1;
    }
    return ret;
}

long long modpow(long long b, long long e, long long MOD=998244353) {
    long long ret = 1;
    b %= MOD;
    while(e) {
        if(e & 1) ret = ret * b % MOD;
        b = b * b % MOD;
        e >>= 1;
    }
    return ret;
}
