#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include <bits/stdc++.h>
using namespace std;

#include "../../math/sqrt_floor.hpp"
#include "../../math/random_number_generator.hpp"

RandomNumberGenerator rnd;

void test() {
    assert(sqrt_floor(0) == 0);
    assert(sqrt_floor(1) == 1);
    assert(sqrt_floor(4) == 2);
    assert(sqrt_floor(9) == 3);
    assert(sqrt_floor(16) == 4);

    assert(sqrt_floor(2) == 1);
    assert(sqrt_floor(3) == 1);
    assert(sqrt_floor(5) == 2);
    assert(sqrt_floor(8) == 2);
    assert(sqrt_floor(10) == 3);

    assert(sqrt_floor(1000000000000000000LL) == 1000000000);
    assert(sqrt_floor(999999999999999999LL) == 999999999);

    assert(sqrt_floor(9223372030926249001LL) == 3037000499LL);
    assert(sqrt_floor(9223372036854775807LL) == 3037000499LL);

    for(int i = 0; i < 1e7; i++) {
        long long a = rnd(INT64_MAX);
        unsigned long long root = sqrt_floor(a);
        assert(root * root <= a);
        assert((root + 1) * (root + 1) > a);
    }

    for(int i = 0; i < 1e7; i++) {
        long long a = rnd(INT32_MAX);
        long long a2 = a * a;
        assert(sqrt_floor(a2) == a);
    }

    cerr << "All tests passed" << endl;
}

int main() {
    test();
    int A, B;
    cin >> A >> B;
    cout << A + B << endl;

    return 0;
}
