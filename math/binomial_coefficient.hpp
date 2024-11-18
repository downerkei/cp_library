struct BinomialCoefficient{
    int MOD;
    vector<long long> fact, fact_inv, inv;

    BinomialCoefficient(int n=1e5, int p=998244353) : MOD(p), fact(n + 1), fact_inv(n + 1), inv(n + 1) {
        fact[0] = fact[1] = 1;
        fact_inv[0] = fact_inv[1] = 1;
        inv[1] = 1;

        for(int i = 2; i <= n; i++) {
            fact[i] = fact[i-1] * i % MOD;
            inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
            fact_inv[i] = fact_inv[i-1] * inv[i] % MOD;
        }
    }

    long long operator() (int n, int r) {
        if(n < 0 || n < r || r < 0) return 0;
        assert(n < fact.size());
        return fact[n] * fact_inv[n-r] % MOD * fact_inv[r] % MOD;
    }
};
