struct MontgomeryModint64 {
    using mint = MontgomeryModint64;
    using u64 = uint64_t;
    using u128 = __uint128_t;

    static inline u64 MOD;
    static inline u64 INV_MOD;  // INV_MOD * MOD ≡ 1 (mod 2 ^ 64)
    static inline u64 T128;     // 2 ^ 128 (mod MOD)

    u64 val;

    MontgomeryModint64(): val(0) {}
    MontgomeryModint64(long long v): val(MR((u128(v) + MOD) * T128)) {}

    u64 get() const {
        u64 res = MR(val);
        return res >= MOD ? res - MOD : res;
    }

    static u64 get_mod() { return MOD; }
    static void set_mod(u64 mod) {
        MOD = mod;
        T128 = -u128(mod) % mod;
        INV_MOD = get_inv_mod();
    }
    // ニュートン法で逆元を求める
    static u64 get_inv_mod() {
        u64 res = MOD;
        for(int i = 0; i < 5; ++i) res *= 2 - MOD * res;
        return res;
    }
    static u64 MR(const u128& v) {
        return (v + u128(u64(v) * u64(-INV_MOD)) * MOD) >> 64;
    }

    mint operator + () const { return mint(*this); }
    mint operator - () const { return mint() - mint(*this); }

    mint operator + (const mint& r) const { return mint(*this) += r; }
    mint operator - (const mint& r) const { return mint(*this) -= r; }
    mint operator * (const mint& r) const { return mint(*this) *= r; }
    mint operator / (const mint& r) const { return mint(*this) /= r; }

    mint& operator += (const mint& r) {
        if((val += r.val) >= 2 * MOD) val -= 2 * MOD;
        return *this;
    }
    mint& operator -= (const mint& r) {
        if((val += 2 * MOD - r.val) >= 2 * MOD) val -= 2 * MOD;
        return *this;
    }
    mint& operator *= (const mint& r) {
        val = MR(u128(val) * r.val);
        return *this;
    }
    mint& operator /= (const mint& r) {
        *this *= r.inv();
        return *this;
    }

    mint inv() const { return pow(MOD - 2); }
    mint pow(u128 n) const {
        mint res(1), mul(*this);
        while(n > 0) {
            if(n & 1) res *= mul;
            mul *= mul;
            n >>= 1;
        }
        return res;
    }

    bool operator == (const mint& r) const {
        return (val >= MOD ? val - MOD : val) == (r.val >= MOD ? r.val - MOD : r.val);
    }
    bool operator != (const mint& r) const {
        return (val >= MOD ? val - MOD : val) != (r.val >= MOD ? r.val - MOD : r.val);
    }

    friend istream& operator >> (istream& is, mint& x) {
        long long t;
        is >> t;
        x = mint(t);
        return is;
    }
    friend ostream& operator << (ostream& os, const mint& x) {
        return os << x.get();
    }
    friend mint modpow(const mint& r, long long n) {
        return r.pow(n);
    } 
    friend mint modinv(const mint& r) {
        return r.inv();
    }
};