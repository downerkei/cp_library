template<class T = long long>
vector<T> longest_increasing_subsequence(const vector<T>& A) {
    vector<T> tail;
    vector<int> tail_idx;
    vector<int> pre_idx(A.size(), -1);
    for(int i = 0; i < ssize(A); i++) {
        // strictly -> lb, nondecreasing -> ub
        int len = ranges::lower_bound(tail, A[i]) - tail.begin();

        if(len > 0) pre_idx[i] = tail_idx[len - 1];
        if(len == ssize(tail)) {
            tail.push_back(A[i]);
            tail_idx.push_back(i);
        }
        else {
            tail[len] = A[i];
            tail_idx[len] = i;
        }
    }

    vector<T> lis;
    if(tail_idx.empty()) return lis;

    for(int i = tail_idx.back(); i != -1; i = pre_idx[i]) {
        lis.push_back(A[i]);
    }

    ranges::reverse(lis);
    return lis;
}


template<class T=long long>
int longest_increasing_subsequence_size(const vector<T> &A) {
    vector<T> lis;
    for(const auto& p : A) {
        // strictly -> lb, nondecreasing -> ub
        auto it = ranges::lower_bound(lis, p);
        if(lis.end() == it) lis.push_back(p);
        else *it = p;
    }
    return lis.size();
}
