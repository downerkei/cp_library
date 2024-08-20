struct LowestCommonAncestor{
    vector<vector<int>> parent;
    vector<int> dist;
    LowestCommonAncestor(const vector<vector<int>>& G, int root=0) {
        init(G, root);
    }

    void init(const vector<vector<int>>& G, int root=0) {
        int N = G.size();
        int M = 1; while((1 << M) < N) M++;
        parent.assign(M, vector<int>(N, -1));
        dist.assign(N, -1);
        dfs(G, root, -1, 0);
        for(int lv = 1; lv < M; lv++) {
            for(int i = 0; i < N; i++) {
                if(parent[lv - 1][i] == -1) parent[lv][i] = -1;
                else parent[lv][i] = parent[lv - 1][parent[lv - 1][i]];
            }
        }
    }

    void dfs(const vector<vector<int>>& G, int v, int p, int d) {
        parent[0][v] = p;
        dist[v] = d;
        for(int nv : G[v]) {
            if(nv == p) continue;
            dfs(G, nv, v, d + 1);
        }
    }

    int lca(int u, int v) {
        if(dist[u] < dist[v]) swap(u, v);
        int M = parent.size();
        for(int lv = 0; lv < M; lv++) {
            if(((dist[u] - dist[v]) >> lv) & 1) u = parent[lv][u];
        }
        if(u == v) return u;
        for(int lv = M - 1; lv >= 0; lv--) {
            if(parent[lv][u] != parent[lv][v]) {
                u = parent[lv][u];
                v = parent[lv][v];
            }
        }
        return parent[0][u];
    }

    int dist_bitween(int u, int v) { return dist[u] + dist[v] - 2 * dist[lca(u, v)]; }
};
