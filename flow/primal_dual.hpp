template<typename Cap, typename Cost> struct PrimalDual {
    struct Edge {
        int from, to, rev;
        Cap cap;
        Cost cost;
        Edge(int f, int t, int r, Cap ca, Cost co) : from(f), to(t), rev(r), cap(ca), cost(co) {}
    };

    int N;
    const Cost COST_INF = numeric_limits<Cost>::max();
    const Cap CAP_INF = numeric_limits<Cap>::max();
    vector<vector<Edge>> G;
    vector<pair<int, int>> pos;

    PrimalDual(int N) : N(N), G(N) {}

    void add_edge(int from, int to, Cap cap, Cost cost) {
        pos.push_back({from, G[from].size()});
        int from_id = G[from].size();
        int to_id = G[to].size();
        if(from == to) to_id++;
        G[from].push_back(Edge(from, to, to_id, cap, cost));
        G[to].push_back(Edge(to, from, from_id, 0, -cost));
    }

    pair<Cap, Cost> max_flow(int s, int t) {
        return max_flow(s, t, CAP_INF);
    }
    pair<Cap, Cost> max_flow(int s, int t, Cap flow_limit) {
        return slope(s, t, flow_limit).back();
    }
    vector<pair<Cap, Cost>> slope(int s, int t) {
        return slope(s, t, CAP_INF);
    }

    // s -> tへ(flow_limitまで)流せるだけ流し，(流量，最小コスト)のvectorを返す
    vector<pair<Cap, Cost>> slope(int s, int t, Cap flow_limit) {
        vector<Cost> dual(N, 0), dist(N);
        vector<int> pv(N), pe(N);
        vector<bool> vis(N);

        // dijkstra
        auto dual_ref = [&]() -> bool {
            fill(dist.begin(), dist.end(), COST_INF);
            fill(pv.begin(), pv.end(), -1);
            fill(pe.begin(), pe.end(), -1);
            fill(vis.begin(), vis.end(), false);

            using Pi = pair<Cost, int>;
            priority_queue<Pi, vector<Pi>, greater<Pi>> que;    // 最小ヒープ  
            dist[s] = 0;
            que.push({0, s});
            while(que.size()) {
                int v = que.top().second; que.pop();
                if(vis[v]) continue;
                vis[v] = true;
                if(v == t) break;
                for(int i = 0; i < (int)G[v].size(); i++) {
                    auto e = G[v][i];

                    if(vis[e.to] || e.cap == 0) continue;
                    Cost cost = e.cost - dual[e.to] + dual[v];

                    if(dist[e.to] <= cost + dist[v]) continue;
                    dist[e.to] = dist[v] + cost;
                    pv[e.to] = v;
                    pe[e.to] = i;
                    que.push({dist[e.to], e.to});
                }
            }

            if(!vis[t]) return false;

            for(int v = 0; v < N; v++) {
                if(!vis[v]) continue;
                dual[v] -= dist[t] - dist[v];
            }
            return true;
        };

        Cap flow = 0;
        Cost cost = 0, prev_cost_per_flow = -1;
        vector<pair<Cap, Cost>> ret;
        ret.push_back({flow, cost});
        while(flow < flow_limit) {
            if(!dual_ref()) break;
            Cap c = flow_limit - flow;

            // ダイクストラで求めた経路を復元してmax流す
            for(int v = t; v != s; v = pv[v]) {
                c = min(c, G[pv[v]][pe[v]].cap);
            }

            for(int v = t; v != s; v = pv[v]) {
                auto& e = G[pv[v]][pe[v]];
                e.cap -= c;
                G[v][e.rev].cap += c;
            }

            Cost d = -dual[s];
            flow += c;
            cost += c * d;
            if(prev_cost_per_flow == d) {
                ret.pop_back();
            }
            ret.push_back({flow, cost});
            prev_cost_per_flow = d;
        }
        return ret;
    }
};