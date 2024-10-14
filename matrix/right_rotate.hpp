template<class T=int>
vector<vector<T>> right_rotate(const vector<vector<T>>& A) {
    int N = A.size();
    vector<vector<T>> ret(N, vector<T>(N));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            ret[j][N - i - 1] = A[i][j];
        }
    }
    return ret;
}
