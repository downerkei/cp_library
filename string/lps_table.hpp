template<typename VType>
vector<int> lps_table(const VType& s) {
    int n = s.size();
    vector<int> lps(n + 1);
    lps[0] = -1;
    int j = -1;
    for(int i = 0; i < n; i++) {
        while(j >= 0 && s[i] != s[j]) j = lps[j];
        j++;
        lps[i + 1] = j;
    }
    return lps;
}
