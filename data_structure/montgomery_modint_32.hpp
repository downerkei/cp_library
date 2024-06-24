// mod奇数の剰余計算高速
struct MontgomeryModint32 {
    using mint = MontgomeryModint32;
    using u32 = uint32_t;
    using u64 = uint64_t;

    u32 _v;

    // static変数
    // R = 2 ^ 32
    static inline u32 MOD;
    static inline u32 INV_MOD;  // INV_MOD * MOD ≡ 1 (mod 2 ^ 32)
    static inline u32 T64;     // 2 ^ 64 (mod MOD)

    // static関数
    static void set_mod(u32 mod) {
        MOD = mod;
        T64 = -u64(mod) % mod;
        INV_MOD = get_inv_mod();
    }
    // ニュートン法で逆元を求める
    static u32 get_inv_mod() {
        u32 res = MOD;
        for(int i = 0; i < 4; ++i) res *= 2 - MOD * res;
        return res;
    }
    // モンゴメリリダクション
    static u32 MR(const u64& v) {
        return (v + u64(u32(v) * u32(-INV_MOD)) * MOD) >> 32;
    }

    mint inv() const { return pow(MOD - 2); }
    mint pow(u64 n) const {
        mint res(1), mul(*this);
        while(n) {
            if(n & 1) res *= mul;
            mul *= mul;
            n >>= 1;
        }
        return res;
    }

    u32 val() const {
        u32 res = MR(_v);
        return res >= MOD ? res - MOD : res;
    }

    MontgomeryModint32(): _v(0) {}
    MontgomeryModint32(long long v): _v(MR((u64(v) + MOD) * T64)) {}

    
    mint operator + () const { return *this; }
    mint operator - () const { return mint() - mint(*this); }

    mint& operator ++ () { return *this += 1; }
    mint& operator -- () { return *this -= 1; }
    mint operator ++ (int) { mint res = *this; ++*this; return res; }
    mint operator -- (int) { mint res = *this; --*this; return res; }

    mint operator + (const mint& r) const { return mint(*this) += r; }
    mint operator - (const mint& r) const { return mint(*this) -= r; }
    mint operator * (const mint& r) const { return mint(*this) *= r; }
    mint operator / (const mint& r) const { return mint(*this) /= r; }

    mint& operator += (const mint& r) {
        if((_v += r._v) >= 2 * MOD) _v -= 2 * MOD;
        return *this;
    }
    mint& operator -= (const mint& r) {
        if((_v += 2 * MOD - r._v) >= 2 * MOD) _v -= 2 * MOD;
        return *this;
    }
    mint& operator *= (const mint& r) {
        _v = MR(u64(_v) * r._v);
        return *this;
    }
    mint& operator /= (const mint& r) {
        *this *= r.inv();
        return *this;
    }

    bool operator == (const mint& r) const {
        return (_v >= MOD ? _v - MOD : _v) == (r._v >= MOD ? r._v - MOD : r._v);
    }
    bool operator != (const mint& r) const {
        return (_v >= MOD ? _v - MOD : _v) != (r._v >= MOD ? r._v - MOD : r._v);
    }

    friend istream& operator >> (istream& is, mint& x) {
        long long t;
        is >> t;
        x = mint(t);
        return is;
    }
    friend ostream& operator << (ostream& os, const mint& x) {
        return os << x.val();
    }
};