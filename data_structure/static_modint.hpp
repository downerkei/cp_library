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

    friend constexpr mint operator + (long long l, const mint& r) { return mint(l) + r; }
    friend constexpr mint operator - (long long l, const mint& r) { return mint(l) - r; }
    friend constexpr mint operator * (long long l, const mint& r) { return mint(l) * r; }
    friend constexpr mint operator / (long long l, const mint& r) { return mint(l) / r; }
    
    constexpr bool operator == (const mint& r) const { return _v == r._v; }
    constexpr bool operator != (const mint& r) const { return _v != r._v; }

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

// using mint = StaticModint<998244353>;
// using mint = StaticModint<1000000007>;
