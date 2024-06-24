#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include <bits/stdc++.h>
using namespace std;

#include "../../data_structure/montgomery_modint_32.hpp"
#include "../../math/random_number_generator.hpp"

using mint = MontgomeryModint32;
RandomNumberGenerator rnd;

void set_test() {
    for(int i = 0; i < 1e6; i++) {
        int mod = rnd(1e9);
        if(mod % 2 == 0) mod += 1;

        mint::set_mod(mod);

        int v = rnd(mod + 1, 1e9);

        assert(mint(v) == v % mod);
    }
}

void operator_test(int mod) {
    mint::set_mod(mod);
    for(int i = 0; i < 1e5; i++) {
        int a = rnd(mod);
        if(rnd(1e9) % 10 == 0) a = 0;
        if(rnd(1e9) % 10 == 0) a = mod - 1;
        mint A = a;
        assert(A.val() == a);

        int b = rnd(mod);
        if(rnd(1e9) % 10 == 0) b = 0;
        if(rnd(1e9) % 10 == 0) b = mod - 1;
        mint B = b;
        assert(B.val() == b);

        int c = (a + b) % mod;
        mint C = A + B;
        assert(C.val() == c);

        int d = (a + mod - b) % mod;
        mint D = A - B;
        assert(D.val() == d);

        int e = (1LL * a * b) % mod;
        mint E = A * B;
        assert(E.val() == e);

        mint F = rnd(1, mod);
        mint G = F.inv();
        if(F * G != 1) cerr << mod << endl;
        assert(F * G == 1);
    }
}

void test() {
    set_test();
    operator_test(998244353);
    operator_test(1000000007);
    operator_test(1);
    operator_test(3);
    operator_test(5);
    operator_test(7);
    operator_test(11);
    operator_test(101);
    
    cerr << "ok" << endl;
}

int main() {
    test();

    int a, b;
    cin >> a >> b;
    cout << a + b << endl;
}