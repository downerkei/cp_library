struct BellmanFord {
    static constexpr long long INF = 2e18;

    struct Edge {
        int from, to;
        long long cost;
    };

    vector<long long> dist;
    vector<int> pre;
    vector<bool> negative;

    vector<long long> solve(const vector<vector<pair<int, long long>>>& G, int s) {
        vector<Edge> edges;
        for(int v = 0; v < (int)G.size(); v++) {
            for(auto [nv, c] : G[v]) edges.push_back({v, nv, c});
        }
        return solve(G.size(), edges, s);
    }

    vector<long long> solve(int N, const vector<Edge>& edges, int s) {
        dist.assign(N, INF);
        pre.assign(N, -1);
        negative.assign(N, false);
        dist[s] = 0;

        for(int i = 0; i < N - 1; i++) {
            bool updated = false;
            for(auto [from, to, cost] : edges) {
                if(dist[from] == INF) continue;
                if(dist[to] <= dist[from] + cost) continue;
                dist[to] = dist[from] + cost;
                pre[to] = from;
                updated = true;
            }
            if(!updated) break;
        }

        for(int i = 0; i < N; i++) {
            for(auto [from, to, cost] : edges) {
                if(dist[from] == INF) continue;
                if(dist[to] > dist[from] + cost) {
                    dist[to] = dist[from] + cost;
                    negative[to] = true;
                }
                if(negative[from]) negative[to] = true;
            }
        }

        return dist;
    }

    bool has_negative_cycle(int v) const { return negative[v]; }

    vector<int> calc_path(int t) {
        vector<int> path;
        if(negative[t]) return path;
        for(; t != -1; t = pre[t]) path.push_back(t);
        reverse(path.begin(), path.end());
        return path;
    }
};
