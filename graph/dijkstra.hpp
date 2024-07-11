struct Dijkstra{
    static constexpr long long INF = 2e18;
    vector<long long> dist;
    vector<int> pre;
    vector<vector<pair<int, long long>>> G;

    Dijkstra(int N) : G(N), dist(N, INF), pre(N, -1) {}

    void add_edge(int a, int b, long long c) {
        G[a].push_back({b, c});
    }

    vector<long long> solve(int s) {
        dist[s] = 0;
        priority_queue<pair<long long, int>> pq;
        pq.push({0, s});
        while(pq.size()) {
            auto [d, v] = pq.top(); pq.pop();
            if(dist[v] < -d) continue;
            for(auto [nv, c] : G[v]) {
                if(dist[nv] <= dist[v] + c) continue;
                dist[nv] = dist[v] + c;
                pre[nv] = v;
                pq.push({-dist[nv], nv});
            }
        }
        for(int i = 0; i < (int)G.size(); i++) {
            if(dist[i] == INF) dist[i] = -1;
        }
        return dist;
    }

    vector<int> calc_path(int t) {
        vector<int> path;
        for(; t != -1; t = pre[t]) path.push_back(t);
        reverse(path.begin(), path.end());
        return path;
    }
};
