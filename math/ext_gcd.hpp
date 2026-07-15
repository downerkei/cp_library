array<long long, 3> ext_gcd(long long a, long long b) {
    if(b == 0) return {a, 1, 0};
    auto [d, y, x] = ext_gcd(b, a % b);
    y -= a / b * x;
    return {d, x, y};
}
