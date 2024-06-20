#include <bits/stdc++.h>
using namespace std;

template<int m> struct StaticModint {
    using mint = StaticModint;
    int _v;

    constexpr StaticModint() : _v(0) {}
    template<class T>
    constexpr StaticModint(T v) : _v((v % m + m) % m) {}

    constexpr int val() const { return _v; }

    constexpr mint& operator ++ () { return *this += 1; }
    constexpr mint& operator -- () { return *this -= 1; }
    constexpr mint operator ++ (int) { mint res = *this; ++*this; return res; }
    constexpr mint operator -- (int) { mint res = *this; --*this; return res; }

    constexpr mint& operator += (const mint& r) {
        if(_v >= m - r._v) _v -= m;
        _v += r._v; return *this;
    }
    constexpr mint& operator -= (const mint& r) {
        if(_v < r._v) _v += m;
        _v -= r._v; return *this;
    }
    constexpr mint& operator *= (const mint& r) {
        unsigned long long z = _v;
        z *= r._v;
        _v = (unsigned int)(z % m); return *this;
    }
    constexpr mint& operator /= (const mint& r) {
        return *this *= r.inv(); 
    }

    constexpr mint pow(long long n) const {
        mint x = *this, r = 1; 
        while(n) {
            if(n & 1) r *= x;
            x *= x;
            n >>= 1;
        }
        return r;
    }
    constexpr mint inv() const {
        return pow(m - 2);
    }

    constexpr mint operator + () const { return *this; }
    constexpr mint operator - () const { return mint() - *this; }

    constexpr mint operator + (const mint& r) const { return mint(*this) += r; }
    constexpr mint operator - (const mint& r) const { return mint(*this) -= r; }
    constexpr mint operator * (const mint& r) const { return mint(*this) *= r; }
    constexpr mint operator / (const mint& r) const { return mint(*this) /= r; }
    
    constexpr bool operator == (const mint& r) { return _v == r._v; }
    constexpr bool operator != (const mint& r) { return _v != r._v; }

    friend istream& operator >> (istream& is, mint& x) {
        long long t;
        is >> t;
        x = mint(t);
        return is;
    }
    friend ostream& operator << (ostream& os, const mint& x) {
        return os << x._v;
    }
};

struct NTT{
    using mint = StaticModint<998244353>;

    // n: 畳み込み後の数列のサイズ
    // nunv: nの逆数
    int n, ninv;
    const mint MOD = 998244353, g = 3;

    // br: ビット反転列
    // roots: MOD上の1のn乗根の列
    vector<int> br;
    vector<mint> roots;

    NTT() {}

    // ビット反転列の生成
    // N = 8の例
    // {0}の各要素に2 ^ 2を加えて{0, 4}
    // {0, 4}の各要素に2 ^ 1を加えて{0, 4, 2, 6}
    // {0, 4, 2, 6}の各要素に2 ^ 0を加えて{0, 4, 2, 6, 1, 5, 3, 7}
    void BitReversal(int n) {
        br.resize(n);
        int p = 1, d = n / 2;
        while(p < n) {
            for(int i = 0; i < p; i++) {
                br[i + p] = br[i] + d;
            }
            p *= 2;
            d /= 2;
        }
    }

    // MOD上1のn乗根の配列を生成
    // n: 要素数(2冪)，w: 1のn乗根のひとつ
    void NthRoots(int n, mint w) {
        roots.resize(n);
        roots[0] = 1;
        for(int i = 1; i < n; i++) {
            roots[i] = roots[i - 1] * w;
        }
    }

    // 再帰的に変換
    // l: 更新対象区間の左端，len: 更新対象区間の長さ
    void TransformRecursive(vector<mint>& c, int l, int len) {
        if(len == 1) return;
        int d = n / len, h = len / 2;

        TransformRecursive(c, l, h);
        TransformRecursive(c, l + h, h);

        // バタフライ演算
        for(int i = 0; i < h; i++) {
            mint v0 = c[l + i];
            mint v1 = c[l + h + i] * roots[d * i];
            c[l + i] = (v0 + v1);
            c[l + h + i] = (v0 - v1 + MOD);
        }
    }

    // 数論変換，長さは2冪
    // c: 変換列，inv: 逆変換かどうか
    vector<mint> Transform(vector<mint>& c, bool inv=false) {
        vector<mint> ret(n, 0);

        // ビット反転置換
        for(int i = 0; i < c.size(); i++) {
            ret[br[i]] = c[i];
        }

        TransformRecursive(ret, 0, n);

        // NTTならそのまま出力
        if(!inv) return ret;

        // INTTなら(0, N)の範囲を逆順に並び替え，Nで割る(ninvを掛ける)
        reverse(ret.begin() + 1, ret.end());
        for(int i = 0; i < n; i++) {
            ret[i] *= ninv;
        }
        return ret;
    }

    // 畳み込み
    vector<long long> Convolution(vector<long long>& a, vector<long long>& b) {
        // nの計算
        n = 1; while(n < a.size() + b.size() - 1) n *= 2;

        // ninvの計算
        ninv = mint(n).inv().val();

        BitReversal(n);

        // 1のn乗根計算
        // MOD - 1 = 119 * 2 ^ 23 = d * nと表せる(nは2冪)
        // g ^ (MOD - 1) = (g ^ d) ^ n ≡ 1なので，ω = g ^ d
        int d = ((MOD - 1) / n).val();
        mint w = g.pow(d);
        NthRoots(n, w);

        vector<mint> ma(a.size()), mb(b.size());
        for(int i = 0; i < (int)a.size(); i++) {
            ma[i] = a[i];
        }
        for(int i = 0; i < (int)b.size(); i++) {
            mb[i] = b[i];
        }

        vector<mint> fa = Transform(ma);
        vector<mint> fb = Transform(mb);

        for(int i = 0; i < n; i++) {
            fa[i] *= fb[i];
        }

        auto c = Transform(fa, true);

        vector<long long> ret(a.size() + b.size() - 1);
        for(int i = 0; i < (int)a.size() + b.size() - 1; i++) {
            ret[i] = c[i].val();
        }

        return ret;
    }
};

int main() {
    int N, M;
    cin >> N >> M;
    vector<long long> A(N), B(M);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for(int i = 0; i < M; i++) {
        cin >> B[i];
    }

    NTT ntt;

    auto c = ntt.Convolution(A, B);

    for(auto i : c) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}