template<typename flow_t>
struct Dinic{
    struct Edge{
        int from, to, rev;
        flow_t cap;
        bool is_rev;
        Edge(int f, int t, int r, flow_t c, bool b) : from(f), to(t), rev(r), cap(c), is_rev(b) {}
    };

    vector<vector<Edge>> G;
    vector<int> dist;
    vector<int> iter;
    const flow_t INF = numeric_limits<flow_t>::max();

    Dinic(int N) : G(N), dist(N), iter(N) {}

    void add_edge(int from, int to, flow_t cap) {
        int fromrev = G[from].size();
        int torev = G[to].size();
        G[from].push_back(Edge(from, to, torev, cap, 0));
        G[to].push_back(Edge(to, from, fromrev, 0, 1));
    }

    void bfs(int s) {
        fill(dist.begin(), dist.end(), -1);
        dist[s] = 0;
        queue<int> q;
        q.push(s);
        while(q.size()) {
            int v = q.front(); q.pop();
            for(const Edge& e: G[v]) {
                if(e.cap == 0 || dist[e.to] >= 0) continue;
                dist[e.to] = dist[v] + 1;
                q.push(e.to);
            }
        }
    }

    flow_t dfs(int v, int t, flow_t f) {
        if(v == t) return f;
        if(f == 0) return 0;

        for(int& i = iter[v]; i < (int)G[v].size(); i++) {
            Edge& e = G[v][i];
            if(e.cap == 0 || dist[v] >= dist[e.to]) continue;
            flow_t flow = dfs(e.to, t, min(f, e.cap));
            if(flow == 0) continue;

            e.cap -= flow;
            G[e.to][e.rev].cap += flow;

            return flow;
        }
        return 0;
    }

    flow_t max_flow(int s, int t) {
        flow_t ret = 0;

        while(true) {
            bfs(s);
            if(dist[t] < 0) return ret;

            fill(iter.begin(), iter.end(), 0);
            while(true) {
                flow_t flow = dfs(s, t, INF);
                if(flow == 0) break;
                ret += flow;
            }
        }

        return 0;
    }

    vector<Edge> edges() {
        vector<Edge> ret;
        for(const auto& v : G) {
            for(const auto& e : v) {
                if(e.is_rev) continue;
                ret.push_back(e);
            }
        }
        return ret;
    }

    void debug() {
        for(const auto& v : G) {
            for(const auto& e : v) {
                if(e.is_rev) continue;
                cout << e.from << " -> " << e.to << " (flow : " << G[e.to][e.rev].cap << " / "
                    << e.cap + G[e.to][e.rev].cap << ")" << endl;
            }
        }
    }
};
