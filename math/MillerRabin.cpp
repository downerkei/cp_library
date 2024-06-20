#include <bits/stdc++.h>
using namespace std;


namespace MillerRabin {
    
// モンゴメリ乗算modint
struct MontgomeryModInt64 {
    using mint = MontgomeryModInt64;
    using u64 = uint64_t;
    using u128 = __uint128_t;

    // static変数
    // R = 2 ^ 64
    static inline u64 MOD;
    static inline u64 INV_MOD;  // INV_MOD * MOD ≡ 1 (mod 2 ^ 64)
    static inline u64 T128;     // 2 ^ 128 (mod MOD)

    u64 val;

    // コンストラクタ
    // MODを足す？
    MontgomeryModInt64(): val(0) {}
    MontgomeryModInt64(long long v): val(MR((u128(v) + MOD) * T128)) {}

    // 値を返す
    u64 get() const {
        u64 res = MR(val);
        return res >= MOD ? res - MOD : res;
    }

    // static関数
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
    // モンゴメリリダクション
    static u64 MR(const u128& v) {
        return (v + u128(u64(v) * u64(-INV_MOD)) * MOD) >> 64;
    }

    // 算術演算子
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

    // その他演算子
    bool operator == (const mint& r) const {
        return (val >= MOD ? val - MOD : val) == (r.val >= MOD ? r.val - MOD : r.val);
    }
    bool operator != (const mint& r) const {
        return (val >= MOD ? val - MOD : val) != (r.val >= MOD ? r.val - MOD : r.val);
    }

    // 入力
    friend istream& operator >> (istream& is, mint& x) {
        long long t;
        is >> t;
        x = mint(t);
        return is;
    }
    // 出力
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


using mint = MontgomeryModInt64;
// ミラーラビン素数判定法で素数判定を行う
// isPrime(N): O(logN)で素数判定を行える

// ミラーラビン素数判定法を行う
// 判定する数Nと基の列Aを入力，素数かどうか判定

// 奇数Nに対し，N = 2 ^ s * d + 1と分解する．
// a ^ d ≡ 1 (mod N) と a ^ ((2 ^ r) * d) ≡ -1 (mod N) のどちらも満たさないaがあるとき，
// Nは合成数である.
bool millerRabin(long long N, vector<long long> A) {
    mint::set_mod(N);
    long long s = 0, d = N - 1;
    while(d % 2 == 0) {
        s++;
        d >>= 1;
    }

    for(long long a : A) {
        // 謎，法Nより基aが大きいと意味ない？
        if(N <= a) return true;
        mint x = mint(a).pow(d);

        if(x == 1) continue;
        long long t;
        for(t = 0; t < s; t++) {
            if(x == N - 1) break;
            x *= x;
        }

        // a ^ d ≡ 1 でも a ^ ((2 ^ r) * d) ≡ -1 でもないならば合成数
        if(t == s) return false;
    }

    // 全ての基で合成数でなければ素数
    return true;
}

bool isPrime(long long N) {
    if(N <= 1) return false;
    if(N == 2) return true;
    if(N % 2 == 0) return false;

    // 4759123141以内なら{2, 7, 61}を試せば十分
    if(N < 4759123141LL) return millerRabin(N, {2, 7, 61});

    // 64bit以内なら{2, 325, 9375, 28178, 450775, 9780504, 1795265022}を試せば十分
    return millerRabin(N, {2, 325, 9375, 28178, 450775, 9780504, 1795265022});
}
} // namespace MillerRabin

int main() {
    int Q;
    cin >> Q;
    
    while(Q--) {
        long long N;
        cin >> N;
        if(MillerRabin::isPrime(N)) cout << "Yes\n";
        else cout << "No\n";
    }

    return 0;
}