vector<int> lcp_array(const string& S, const vector<int>& sa) {
    int N = S.size();
    vector<int> rank(N);
    for(int i = 0; i < N; i++) {
        rank[sa[i]] = i;
    }
    vector<int> lcp(N - 1);
    int h = 0;
    for(int i = 0; i < N; i++) {
        if(h > 0) h--;
        if(rank[i] == 0) continue;
        int j = sa[rank[i] - 1];
        while(i + h < N && j + h < N && S[i + h] == S[j + h]) h++;
        lcp[rank[i] - 1] = h;
    }
    return lcp;
}
