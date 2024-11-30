vector<int> suffix_array(const string& S) {
    int N = S.size();
    vector<int> rank(N), sa(N);

    // 1文字のランク計算
    for(int i = 0; i < N; i++) {
        sa[i] = i;
        rank[i] = S[i] - 'a';
    }

    for(int k = 1; k < N; k *= 2) {
        // rankに基づいてソート
        auto cmp = [&](int i, int j) {
            if(rank[i] != rank[j]) return rank[i] < rank[j];
            int ri = i + k < N ? rank[i + k] : -1;
            int rj = j + k < N ? rank[j + k] : -1;
            return ri < rj;
        };
        sort(sa.begin(), sa.end(), cmp);

        // 次のrank計算
        vector<int> nrank(N);
        nrank[sa[0]] = 0;
        for(int i = 1; i < N; i++) {
            nrank[sa[i]] = nrank[sa[i - 1]] + cmp(sa[i - 1], sa[i]);
        }
        swap(rank, nrank);
    }

    return sa;
}
