long long sqrt_floor(long long N) {
    assert(0 <= N);
    unsigned long long root = sqrtl(N);
    while(root * root > N) root--;
    while((root + 1) * (root + 1) <= N) root++;
    return root;
}
