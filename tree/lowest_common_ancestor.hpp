template<class T=int>
struct LowestCommonAncestor{
    int mx_level;
    vector<vector<int>> parent;
    vector<int> depth;
    vector<T> dist;
    LowestCommonAncestor(const vector<vector<pair<int, T>>>& G, int root=0) {
        init(G, root);
    }

    LowestCommonAncestor(const vector<vector<int>>& G, int root=0) {
        init(G, root);
    }

    template<class GType>
    void init(const GType& G, int root) {
        int N = G.size();
        mx_level = 1; while((1 << mx_level) < N) mx_level++;
        parent.assign(mx_level, vector<int>(N, -1));
        depth.assign(N, -1);
        dist.assign(N, -1);
        dfs(G, root, -1, 0, 0);
        for(int lv = 1; lv < mx_level; lv++) {
            for(int i = 0; i < N; i++) {
                if(parent[lv - 1][i] == -1) parent[lv][i] = -1;
                else parent[lv][i] = parent[lv - 1][parent[lv - 1][i]];
            }
        }
    }

    template<class GType>
    void dfs(const GType& G, int v, int p, int dep, T dis) {
        parent[0][v] = p;
        depth[v] = dep;
        dist[v] = dis;
        if constexpr (is_same_v<GType, vector<vector<pair<int, T>>>>) {
            for(auto [nv, c] : G[v]) {
                if(nv == p) continue;
                dfs(G, nv, v, dep + 1, dis + c);
            }
        }
        else if constexpr (is_same_v<GType, vector<vector<int>>>) {
            for(int nv : G[v]) {
                if(nv == p) continue;
                dfs(G, nv, v, dep + 1, dis + T(1));
            }
        }
    }

    int lca(int u, int v) {
        if(depth[u] < depth[v]) swap(u, v);
        for(int lv = 0; lv < mx_level; lv++) {
            if(((depth[u] - depth[v]) >> lv) & 1) u = parent[lv][u];
        }
        if(u == v) return u;
        for(int lv = mx_level - 1; lv >= 0; lv--) {
            if(parent[lv][u] != parent[lv][v]) {
                u = parent[lv][u];
                v = parent[lv][v];
            }
        }
        return parent[0][u];
    }

    T dist_bitween(int u, int v) { return dist[u] + dist[v] - 2 * dist[lca(u, v)]; }

    int path_len(int u, int v) { return depth[u] + depth[v] - 2 * depth[lca(u, v)]; }
};
