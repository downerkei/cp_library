#include "miller_rabin.hpp"

namespace fast_factorize {

long long find_prime_factor(long long N) {
    if(!(N & 1)) return 2;

    // GCDをまとめる数の上限
    long long m = pow(N, 0.125) + 1;

    for(int c = 1; c < N; c++) {
        // 疑似乱数
        auto f = [&](long long a) { return (__uint128_t(a) * a + c) % N; };
        long long y = 0;
        long long g = 1, q = 1; // g : GCD，q : |x - y|積
        long long k = 0, r = 1; // k :  
        long long ys;   // バックトラック用変数
        long long x;

        while(g == 1) {
            x = y;

            // k < 3r / 4の間はGCD計算を飛ばす
            while(k < 3 * r / 4) {
                y = f(y);
                k++;
            }

            while(k < r && g == 1) {
                // バックトラック用保存
                ys = y;
                for(int i = 0; i < min(m, r - k); i++) {
                    y = f(y);
                    q = __uint128_t(q) * abs(x - y) % N;
                }
                g = gcd(q, N);
                k += m;
            }

            k = r;
            r *= 2;
        }

        // まとめたgcdがNとなったら
        if(g == N) {
            g = 1;
            y = ys;
            while(g == 1) {
                y = f(y);
                g = gcd(abs(x - y), N);
            }
        }

        // 失敗したら次のcへ
        if(g == N) continue;
        if(is_prime(g)) return g;
        else if(is_prime(N / g)) return N / g;
        else return find_prime_factor(g);
    }
    return -1;
}

vector<pair<long long, int>> factorize(long long N) {
    vector<pair<long long, int>> ret;
    while(!is_prime(N) && N > 1) {
        long long p = find_prime_factor(N);
        int e = 0;
        while(N % p == 0) {
            e++;
            N /= p;
        }
        ret.push_back({p, e});
    }
    if(N != 1) ret.push_back({N, 1});
    sort(ret.begin(), ret.end());
    return ret;
}

} // namespace fast_factorize
