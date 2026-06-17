struct BellmanFord {
    static constexpr long long INF = 2e18;

    struct Edge {
        int from, to;
        long long weight;
    };

    vector<long long> dist;
    vector<int> prev;
    vector<bool> negative_inf;

    vector<long long> shortest_path(const vector<vector<pair<int, long long>>>& G, int s) {
        vector<Edge> edges;
        for(int v = 0; v < (int)G.size(); v++) {
            for(auto [nv, weight] : G[v]) edges.push_back({v, nv, weight});
        }
        return shortest_path(G.size(), edges, s);
    }

    vector<long long> shortest_path(int N, const vector<Edge>& edges, int s) {
        dist.assign(N, INF);
        prev.assign(N, -1);
        negative_inf.assign(N, false);
        dist[s] = 0;

        for(int i = 0; i < N - 1; i++) {
            bool updated = false;
            for(auto [from, to, weight] : edges) {
                if(dist[from] == INF) continue;
                if(dist[to] <= dist[from] + weight) continue;
                dist[to] = dist[from] + weight;
                prev[to] = from;
                updated = true;
            }
            if(!updated) break;
        }

        for(int i = 0; i < N; i++) {
            for(auto [from, to, weight] : edges) {
                if(dist[from] == INF) continue;
                if(dist[to] > dist[from] + weight) {
                    dist[to] = dist[from] + weight;
                    negative_inf[to] = true;
                }
                if(negative_inf[from]) negative_inf[to] = true;
            }
        }

        return dist;
    }

    bool has_reachable_negative_cycle() const {
        for(bool f : negative_inf) {
            if(f) return true;
        }
        return false;
    }

    bool is_negative_inf(int v) const { return negative_inf[v]; }

    vector<int> restore_path(int t) {
        vector<int> path;
        if(dist[t] == INF || negative_inf[t]) return path;
        for(; t != -1; t = prev[t]) path.push_back(t);
        reverse(path.begin(), path.end());
        return path;
    }
};
