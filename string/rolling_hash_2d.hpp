struct RollingHash2D {
    using u64 = uint64_t;

    constexpr static u64 MOD = 998244353;
    constexpr static u64 BASE1 = 132678926;
    constexpr static u64 BASE2 = 234987414;

    int H, W;
    vector<vector<u64>> hashed, power;

    template<class VType>
    RollingHash2D(const vector<VType>& V) {
        H = (int)V.size();
        W = (int)V[0].size();
        power.assign(H + 1, vector<u64>(W + 1, 0));
        hashed.assign(H + 1, vector<u64>(W + 1, 0));
        power[0][0] = 1;

        // mapping
        for(int i = 0; i < H; i++) {
            for(int j = 0; j < W; j++) {
                hashed[i + 1][j + 1] = V[i][j];
            }
        }

        // BASE1
        for(int i = 0; i <= H; i++) {
            for(int j = 0; j < W; j++) {
                power[i][j + 1] = power[i][j] * BASE1 % MOD;
                hashed[i][j + 1] += hashed[i][j] * BASE1;
                hashed[i][j + 1] %= MOD;
            }
        }

        // BASE2
        for(int i = 0; i < H; i++) {
            for(int j = 0; j <= W; j++) {
                power[i + 1][j] = power[i][j] * BASE2 % MOD;
                hashed[i + 1][j] += hashed[i][j] * BASE2;
                hashed[i + 1][j] %= MOD;
            }
        }
    }

    u64 get_hash(int l1, int r1, int l2, int r2) {
        long long v1 = hashed[r1][r2];
        long long v2 = (hashed[l1][r2] * power[r1 - l1][0]) % MOD;
        long long v3 = (hashed[r1][l2] * power[0][r2 - l2]) % MOD;
        long long v4 = (hashed[l1][l2] * power[r1 - l1][r2 - l2]) % MOD;

        return (2 * MOD + v1 - v2 - v3 + v4) % MOD;
    }
};
