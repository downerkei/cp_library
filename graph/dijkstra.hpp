struct Dijkstra{
    static constexpr long long INF = 2e18;
    vector<long long> dis;
    vector<int> pre;
    priority_queue<pair<long long, int>> pq;
    vector<int> p;
    Dijkstra(vector<vector<pair<int, long long>>>& G, int s) : dis(G.size(), INF), pre(G.size(), -1) {
        dis[s] = 0;
        pq.push({0, s});
        while(pq.size()) {
            auto [d, v] = pq.top(); pq.pop();
            if(dis[v] < -d) continue;
            for(auto [nv, c] : G[v]) {
                if(dis[nv] <= dis[v] + c) continue;
                dis[nv] = dis[v] + c;
                pre[nv] = v;
                pq.push({-dis[nv], nv});
            }
        }
    }

    long long dist(int t) { return (dis[t] == INF) ? -1 : dis[t]; }
    vector<int> path(int t) {
        if(p.size()) return p;
        for(; t != -1; t = pre[t]) p.push_back(t);
        reverse(p.begin(), p.end());
        return p;
    }
};
