#include <bits/stdc++.h>
using namespace std;

inline long long safe_mod(long long a, long long m) {
    return (a % m + m) % m;
}

// 拡張ユークリッド
// ax + by = gcd(a, b)を満たす(gcd(a, b), x, y)を返す
tuple<long long, long long, long long> extGCD(long long a, long long b) {
    if(b == 0) return {a, 1, 0};
    auto [d, y, x] = extGCD(b, a % b);
    y -= a / b * x;
    return {d, x, y};
}

// 中国剰余定理
// x ≡ b1 mod m1, x ≡ b2 mod m2をみたすxがx ≡ r mod mと書けるとき，
// (r, m)を返す，解がなければ(0, -1)を返す

// x ≡ b1 mod m1, x ≡ b2 mod m2をみたすx ≡ r mod mが存在するには，
// b1 ≡ b2 mod gcd(m1, m2)が必要

// d = gcd(m1, m2)とおくと，m1p + m2q = dを満たす(p, q)が構成できる
// b1 ≡ b2 mod dより，b2 - b1はdで割り切れる．
// s = (b2 - b1) / dとおくと，sm1p + sm2q = b2 - b1となる．
// 式変形し，b1 + sm1p = b2 - sm2qとし，左辺をxとおくと，
// x ≡ b1 mod m1, x ≡ b2 mod m2を満たす．
pair<long long, long long> CRT(const vector<long long>& b, const vector<long long>& m) {
    long long r = 0, M = 1;
    for(int i = 0; i < (int)b.size(); i++) {
        auto [d, p, q] = extGCD(M, m[i]);
        if((b[i] - r) % d != 0) return {0, -1};
        long long tmp = (b[i] - r) / d * p % (m[i] / d);
        r += M * tmp;
        M *= m[i] / d;
    }
    r = safe_mod(r, M);
    return {r, M};
}

int main() {
    vector<long long> b(3), m(3);
    for(int i = 0; i < 3; i++) {
        cin >> b[i] >> m[i];
    }
    auto [R, M] = CRT(b, m);
    if(M == -1) cout << -1 << endl;
    else if(R == 0) cout << M << endl;
    else cout << R << endl;

    return 0;
}