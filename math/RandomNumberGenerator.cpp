#include <bits/stdc++.h>
using namespace std;

struct RandomNumberGenerator {
    mt19937 mt;

    RandomNumberGenerator() : mt(random_device()()) {}

    // [a, b)の範囲
    long long operator()(long long a, long long b) {
        uniform_int_distribution<long long> dist(a, b - 1);
        return dist(mt);
    }

    // [0, b)の範囲
    long long operator()(long long b) {
        return (*this)(0, b);
    }
};

int main() {
    RandomNumberGenerator rnd;

    cout << rnd(10) << endl;

    return 0;
}