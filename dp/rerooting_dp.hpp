template<class E, E (*merge)(E, E), E (*e)(), E(*put_v)(E, int)>
struct RerootingDP{
    int n;
    vector<vector<int>> G;
    vector<E> dp1, dp2, ans;
    RerootingDP(int n) : n(n), G(n), dp1(n, e()), dp2(n, e()), ans(n, e()) {}

    void AddEdge(int u, int v) {
        G[u].push_back(v);
        G[v].push_back(u);
    }

    void DFS1(int v, int p=-1) {
        for(int nv : G[v]) {
            if(nv == p) continue;
            DFS1(nv, v);
            dp1[v] = merge(dp1[v], dp1[nv]);
        }
        dp1[v] = put_v(dp1[v], v);
    }

    void DFS2(int v, int p=-1) {
        vector<E> lp(G[v].size(), e()), rp(G[v].size(), e());
        for(int i = 0; i < (int)G[v].size(); i++) {
            int nv = G[v][i];
            if(i - 1 >= 0) lp[i] = lp[i - 1];
            if(nv == p) continue;
            lp[i] = merge(lp[i], dp1[nv]);
        }
        for(int i = G[v].size() - 1; i >= 0; i--) {
            int nv = G[v][i];
            if(i + 1 < (int)G[v].size()) rp[i] = rp[i + 1];
            if(nv == p) continue;
            rp[i] = merge(rp[i], dp1[nv]);
        }
        for(int i = 0; i < (int)G[v].size(); i++) {
            int nv = G[v][i];
            if(nv == p) continue;
            dp2[nv] = dp2[v];
            if(i - 1 >= 0) dp2[nv] = merge(dp2[nv], lp[i - 1]);
            if(i + 1 < (int)G[v].size()) dp2[nv] = merge(dp2[nv], rp[i + 1]);
            dp2[nv] = put_v(dp2[nv], nv);
            DFS2(nv, v);
        }
    }

    void DFS3(int v, int p=-1) {
        for(int nv : G[v]) {
            if(nv == p) continue;
            ans[v] = merge(ans[v], dp1[nv]);
            DFS3(nv, v);
        }
        ans[v] = merge(ans[v], dp2[v]);
    }

    vector<E> Solve() {
        DFS1(0);
        DFS2(0);
        DFS3(0);
        return ans;
    }
};