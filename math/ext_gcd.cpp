#include <bits/stdc++.h>
using namespace std;

// 拡張ユークリッド
// ax + by = gcd(a, b)となる(x, y)を計算し，d = gcd(a, b)を返す

// aをdで割って a = qb + rとする
// 方程式に代入すると．
// (qb + r)x + by = d ⇔ b(qx + y) + rx = d
// として，(a, b)の問題を(b, r)の問題に帰着する
// bs + rt = dを満たす(s, t)が得られたとすると，
// x = t, y = s - qtと元の解を構成できる

// dx + 0y = dとなるのが終了条件
// (x, y) = (1, 0)となる

// 逆元計算
// aのm上での逆元を求めたい(a, mは互いに素)
// ax + my = 1 ⇒ ax ≡ 1 mod m
// x = a ^ -1
tuple<long long, long long, long long> extGCD(long long a, long long b) {
    if(b == 0) return {a, 1, 0};
    auto [d, y, x] = extGCD(b, a % b);
    y -= a / b * x;
    return {d, x, y};
}

int main() {
    long long a, b;
    cin >> a >> b;
    auto [d, x, y] = extGCD(a, b);

    cout << x << " " << y << endl;

    return 0;
}