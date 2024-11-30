struct RollingHash{
    using u64 = uint64_t;

    constexpr static u64 MASK30 = (1UL << 30) - 1;
    constexpr static u64 MASK31 = (1UL << 31) - 1;
    constexpr static u64 MASK61 = (1UL << 61) - 1;
    constexpr static u64 MOD = (1UL << 61) - 1;
    constexpr static u64 POSITIVIZER = MOD * 4;

    static inline u64 base;

    int N;
    vector<u64> hashed, power;
    
    constexpr u64 mul(const u64& a, const u64& b) const {
        u64 au = a >> 31;
        u64 ad = a & MASK31;
        u64 bu = b >> 31;
        u64 bd = b & MASK31;
        u64 mid = ad * bu + au * bd;
        u64 midu = mid >> 30;
        u64 midd = mid & MASK30;
        return au * bu * 2 + midu + (midd << 31) + ad * bd;
    }

    constexpr u64 calc_mod(const u64& x) const {
        u64 xu = x >> 61;
        u64 xd = x & MASK61;
        u64 ret = xu + xd;
        if(ret >= MOD) ret -= MOD;
        return ret;
    }

    void gen_base() {
        random_device seed_gen;
        mt19937_64 engine(seed_gen());
        uniform_int_distribution<u64> rand(0, MOD - 1);
        base = rand(engine);
    }

    template<class VType>
    constexpr RollingHash(const VType& V) {
        if(base == 0) gen_base();

        N = (int)V.size();
        power.resize(N + 1, 0);
        hashed.resize(N + 1, 0);

        power[0] = 1;
        for(int i = 0; i < N; i++) {
            power[i + 1] = calc_mod(mul(power[i], base));
            hashed[i + 1] = calc_mod(mul(hashed[i], base) + (long long)V[i]);
        }
    }
    
    constexpr u64 get_hash(int l, int r) const {
        return calc_mod(hashed[r] + POSITIVIZER - mul(hashed[l], power[r - l]));
    }
};
