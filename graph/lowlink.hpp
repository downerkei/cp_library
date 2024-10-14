struct Lowlink {
    int N;
    vector<int> ord, low;
    vector<pair<int, int>> bridges;

    Lowlink(const vector<vector<int>>& G) : N(G.size()), ord(N, -1), low(N, -1) { build(G); }

    void build(const vector<vector<int>>& G) {
        int cnt = 0;

        auto dfs = [&](auto f, int v, int p) -> void {
            ord[v] = cnt++;
            low[v] = ord[v];
            for(int nv : G[v]) {
                if(nv == p) continue;
                // 木辺
                if(ord[nv] == -1) {
                    f(f, nv, v);
                    low[v] = min(low[v], low[nv]);
                    if(ord[v] < low[nv]) bridges.push_back({min(v, nv), max(v, nv)});
                } 

                // 後退辺
                else low[v] = min(low[v], ord[nv]);
            }
        };

        for(int i = 0; i < N; i++) {
            if(ord[i] != -1) continue;
            dfs(dfs, i, -1);
        }
    }

    const vector<pair<int, int>>& get_bridges() { return bridges; }
    const vector<int>& get_ord() { return ord; }
    const vector<int>& get_low() { return low; }
};
