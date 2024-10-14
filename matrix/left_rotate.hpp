template<class T=int>
vector<vector<T>> left_rotate(const vector<vector<T>>& A) {
    int N = A.size();
    vector<vector<T>> ret(N, vector<T>(N));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            ret[N - j - 1][i] = A[i][j];
        }
    }
    return ret;
}
