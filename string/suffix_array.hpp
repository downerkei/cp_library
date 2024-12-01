vector<int> suffix_array(const string& S) {
    int N = S.size();
    vector<int> rank(N), sa(N);

    for(int i = 0; i < N; i++) {
        sa[i] = i;
        rank[i] = S[i];
    }

    for(int k = 1; k < N; k *= 2) {
        auto get_rank = [&](int i) -> int { return (i < N) ? rank[i] : 0; };

        auto radix_sort = [&](int k) -> void {
            const int CHAR_SIZE = 130;
            vector<int> backet(max(N + 1, CHAR_SIZE), 0), nsa(N);
            for(int i = 0; i < N; i++) {
                backet[get_rank(i + k)]++;
            }
            for(int i = 1; i < backet.size(); i++) {
                backet[i] += backet[i - 1];
            }
            for(int i = N; i--;) {
                int& x = backet[get_rank(sa[i] + k)];
                nsa[--x] = sa[i];
            }
            swap(sa, nsa);
        };
        radix_sort(k);
        radix_sort(0);

        vector<int> nrank(N);
        nrank[sa[0]] = 1;
        for(int i = 1; i < N; i++) {
            bool is_different = (get_rank(sa[i - 1]) != get_rank(sa[i]) || get_rank(sa[i - 1] + k) != get_rank(sa[i] + k));
            nrank[sa[i]] = nrank[sa[i - 1]] + is_different;
        }
        swap(rank, nrank);
    }

    return sa;
}
