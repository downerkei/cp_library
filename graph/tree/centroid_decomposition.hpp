struct CentroidDecomposition{
    vector<vector<int>> G, T;
    vector<int> sub, ord;
    vector<int> used;
    int r;
 
    CentroidDecomposition(vector<vector<int>>& G) : G(G), T(G.size()), sub(G.size()), used(G.size()) {
        build_dfs();
    } 
 
    int calc_sub(int v, int p=-1) {
        sub[v] = 1;
        for(int nv : G[v]) {
            if(used[nv] || p == nv) continue;
            sub[v] += calc_sub(nv, v);
        }
        return sub[v];
    }
 
    int find_centroid(int v, int mid, int p=-1) {
        for(int nv : G[v]) {
            if(used[nv] || p == nv) continue;
            if(sub[nv] > mid) return find_centroid(nv, mid, v);
        }
        return v;
    }
 
    void build_dfs(int v=0, int p=-1) {
        int sz = calc_sub(v);
        int centroid = find_centroid(v, sz / 2);
        used[centroid] = true;
        ord.push_back(centroid);
 
        if(p == -1) r = centroid;
        else {
            T[p].push_back(centroid);
            T[centroid].push_back(p);
        }
 
        for(int nv : G[centroid]) {
            if(used[nv]) continue;
            build_dfs(nv, centroid);
        }
    }
};
