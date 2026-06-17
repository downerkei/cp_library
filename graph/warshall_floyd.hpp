struct WarshallFloyd {
    static constexpr long long INF = 2e18;

    struct Edge {
        int from, to;
        long long weight;
    };

    vector<vector<long long>> dist;

    vector<vector<long long>> shortest_path(int N, const vector<Edge>& edges) {
        dist.assign(N, vector<long long>(N, INF));
        for(int i = 0; i < N; i++) dist[i][i] = 0;
        for(auto [from, to, weight] : edges) {
            dist[from][to] = min(dist[from][to], weight);
        }
        return shortest_path(dist);
    }

    vector<vector<long long>> shortest_path(vector<vector<long long>> d) {
        dist = d;
        int N = dist.size();
        for(int k = 0; k < N; k++) {
            for(int i = 0; i < N; i++) {
                if(dist[i][k] == INF) continue;
                for(int j = 0; j < N; j++) {
                    if(dist[k][j] == INF) continue;
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        return dist;
    }

    bool has_negative_cycle() const {
        for(int i = 0; i < (int)dist.size(); i++) {
            if(dist[i][i] < 0) return true;
        }
        return false;
    }
};
