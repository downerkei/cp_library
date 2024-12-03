template<typename S>
struct MergeSortTree {
    int N;
    vector<vector<S>> data;
    const S INF = numeric_limits<S>::max();
    
    MergeSortTree(const vector<S>& V) : N(1) {
        int sz = V.size();
        while(N < sz) N <<= 1;
        data.resize(2 * N);
        for(int i = 0; i < sz; i++) data[i + N].push_back(V[i]);
        for(int i = sz; i < N; i++) data[i + N].push_back(INF);
        for(int i = N; --i;) merge_sort(i);
    }

    void merge_sort(int k) {
        int sz = data[k << 1].size();
        int i1 = 0, i2 = 0;
        while(i1 < sz || i2 < sz) {
            if(i2 == sz || (i1 != sz && data[k << 1][i1] < data[k << 1 | 1][i2])) data[k].push_back(data[k << 1][i1++]);
            else data[k].push_back(data[k << 1 | 1][i2++]);
        }
    }

    int count_between(int l, int r, S lo, S up) {
        l += N; r += N;
        int ans = 0;
        auto get_between = [&](int k) { return upper_bound(data[k].begin(), data[k].end(), up) - lower_bound(data[k].begin(), data[k].end(), lo); };
        while(l < r) {
            if(l & 1) ans += get_between(l++);
            if(r & 1) ans += get_between(--r);
            l >>= 1; r >>= 1;
        }
        return ans;
    }
};
