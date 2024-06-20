#include <bits/stdc++.h>
using namespace std;

// gale-shapleyアルゴリズム
// 安定マッチング

// 入力：各人好みの順位の二次元配列x2
// A[i][j]: i番目の人がj番目に好きな人
// 出力：マッチング(pair)のvector
vector<pair<int, int>> gale_shapley(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int N = A.size();
    int M = B.size();

    // B_rank[i][j]: i番目の人から見てjは何番目か
    // Bから見たAの人のランク
    vector<vector<int>> B_rank(M, vector<int>(N));
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            B_rank[i][B[i][j]] = j;
        }
    }

    // Aの人が入るキュー
    queue<int> q;
    for(int i = 0; i < N; i++) {
        q.push(i);
    }

    // Aが振られていない中で再上位の順位を管理
    vector<int> A_best_rank(N, 0);

    // Bがキープしている人の優先順位
    vector<int> B_keep_rank(M, N);

    // 誰にもキープされてないAがいれば今まで振られていない中で再上位に声をかける
    while(q.size()) {
        int a = q.front(); q.pop();
        if(A_best_rank[a] < M) {
            int a_rank = A_best_rank[a];
            int b = A[a][a_rank];

            // B_keep_rank vs bから見たaのランク
            // 受理パターン
            if(B_keep_rank[b] > B_rank[b][a]) {
                int dumpted_rank = B_keep_rank[b];
                // 相手がいれば振る
                if(dumpted_rank != N) {
                    int dumpted = B[b][dumpted_rank];
                    q.push(dumpted);
                    A_best_rank[dumpted]++;
                }

                // ペア更新
                B_keep_rank[b] = B_rank[b][a];
            }

            // 拒否パターン
            else {
                // aが振られる
                q.push(a);
                A_best_rank[a]++;
            }
        }
    }

    for(int i = 0; i < M; i++) {
        cout << i << " " << B_keep_rank[i] << endl;
    }

    // 返り値構築
    vector<pair<int, int>> ret;
    for(int i = 0; i < M; i++) {
        int a_rank = B_keep_rank[i];
        if(a_rank == N) continue;
        int a = B[i][a_rank];
        ret.push_back({a, i});
    }

    return ret;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> A(N, vector<int>(M)), B(M, vector<int>(N));

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> A[i][j];
        }
    }

    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            cin >> B[i][j];
        }
    }

    auto ans = gale_shapley(A, B);


    cout << ans.size() << endl;
    for(auto [a, b] : ans) {
        cout << a << " " << b << endl;
    }
    

    return 0;
}