template<class T>
int longest_increasing_subsequence(const vector<T> &A) {
    vector<T> lis;
    for(const auto& p : A) {
        // 狭義
        auto it = lower_bound(lis.begin(), lis.end(), p);
        if(lis.end() == it) lis.push_back(p);
        else *it = p;
    }
    return lis.size();
}