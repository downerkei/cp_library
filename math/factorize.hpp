vector<pair<long long, int>> factorize(long long N) {
    assert(0 < N);
    vector<pair<long long, int>> ret;
    for(long long p = 2; p * p <= N; p++) {
        if(N % p != 0) continue;
        int e = 0;
        while(N % p == 0) {
            N /= p;
            e++;
        }
        ret.push_back({p, e});
    }
    if(N != 1) ret.push_back({N, 1});
    return ret;
}