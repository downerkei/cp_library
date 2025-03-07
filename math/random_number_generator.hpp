struct RandomNumberGenerator {
    mt19937 mt;
    RandomNumberGenerator() : mt(random_device()()) {}
    long long operator()(long long a, long long b) { return uniform_int_distribution<long long>(a, b - 1)(mt); }
    long long operator()(long long b) { return (*this)(0, b); }
};
