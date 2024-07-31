template<typename flow_t>
struct FordFulkerson{
    struct Edge{
        int from, to, rev;
        flow_t cap;
        bool is_rev;
        Edge(int f, int t, int r, flow_t c, bool b) : from(f), to(t), rev(r), cap(c), is_rev(b) {}
    };

    vector<vector<Edge>> G;
    vector<bool> used;
    const flow_t INF = numeric_limits<flow_t>::max();

    FordFulkerson(int N) : G(N), used(N, false) {}

    void add_edge(int from, int to, flow_t cap) {
        int fromrev = G[from].size();
        int torev = G[to].size();
        G[from].push_back(Edge(from, to, torev, cap, 0));
        G[to].push_back(Edge(to, from, fromrev, 0, 1));
    }

    flow_t dfs(int v, int t, flow_t f) {
        if(v == t) return f;
        used[v] = true;

        for(Edge& e : G[v]) {
            if(used[e.to]) continue;
            if(e.cap == 0) continue;
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
            used.assign(G.size(), false);
            flow_t flow = dfs(s, t, INF);
            if(flow == 0) break;
            ret += flow;
        }
        return ret;
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
};
