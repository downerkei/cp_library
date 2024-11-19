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
    
    u64 mul(const u64& a, const u64& b) const {
        u64 au = a >> 31;
        u64 ad = a & MASK31;
        u64 bu = b >> 31;
        u64 bd = b & MASK31;
        u64 mid = ad * bu + au * bd;
        u64 midu = mid >> 30;
        u64 midd = mid & MASK30;
        return au * bu * 2 + midu + (midd << 31) + ad * bd;
    }

    u64 calc_mod(const u64& x) const {
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

    RollingHash(const string& S) { init<string>(S); }
    RollingHash(const vector<int>& V) { init<vector<int>>(V); }

    template<class VType>
    void init(const VType& V) {
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
    
    u64 get_hash(int l, int r) const {
        return calc_mod(hashed[r] + POSITIVIZER - mul(hashed[l], power[r - l]));
    }

    // p始点のLCP計算，O(logN)
    int get_LCP(int p) {
        int lb = -1, ub = N - p + 1;
        while(ub - lb > 1) {
            int mid = (ub + lb) / 2;
            if(get_hash(p, p + mid) == get_hash(0, mid)) lb = mid;
            else ub = mid;
        }
        return lb;
    }

    // 全てのLCPを返す，O(NlogN)
    vector<int> all_LCP() {
        vector<int> ret(N);
        for(int i = 0; i < N; i++) {
            ret[i] = get_LCP(i);
        }
        return ret;
    }

    // 比較関数，O(logN)でiとjの接尾辞を比較，substr(i) < substr(j)を返す
    bool comp(const int& i, const int& j) {
        if(get_hash(i, i + 1) != get_hash(j, j + 1)) return get_hash(i, i + 1) < get_hash(j, j + 1);

        // 指数探索で上界を決める
        int lb = 0, ub = 1, ma = N - max(i, j) + 1;
        while(get_hash(i, i + ub) == get_hash(j, j + ub)) {
            ub *= 5;
            if(ub >= ma) {
                ub = ma;
                break;
            }
        }

        // 二分探索で最大共通接頭辞長を得る
        while(ub - lb > 1) {
            int mid = (ub + lb) / 2;
            if(get_hash(i, i + mid) == get_hash(j, j + mid)) lb = mid;
            else ub = mid;
        }
        if(i + lb == N) return true;
        if(j + lb == N) return false;
        return get_hash(i + lb, i + lb + 1) < get_hash(j + lb, j + lb + 1);
    }

    // SAを返す，O(Nlog^2N)
    vector<int> suffix_array() {
        vector<int> ret(N);
        iota(ret.begin(), ret.end(), 0);
        sort(ret.begin(), ret.end(), [this](const int& i, const int& j) { return comp(i, j); });
        return ret;
    }
};
