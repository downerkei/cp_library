struct CentroidDecomposition{
    vector<vector<int>> T;
    vector<int> sub, ord;
    vector<int> used;
    int r;
 
    CentroidDecomposition(vector<vector<int>>& G) : T(G.size()), sub(G.size()), used(G.size()) {
        build_dfs(G);
    } 
 
    int calc_sub(vector<vector<int>>& G, int v, int p=-1) {
        sub[v] = 1;
        for(int nv : G[v]) {
            if(used[nv] || p == nv) continue;
            sub[v] += calc_sub(G, nv, v);
        }
        return sub[v];
    }
 
    int find_centroid(vector<vector<int>>& G, int v, int mid, int p=-1) {
        for(int nv : G[v]) {
            if(used[nv] || p == nv) continue;
            if(sub[nv] > mid) return find_centroid(G, nv, mid, v);
        }
        return v;
    }
 
    void build_dfs(vector<vector<int>>& G, int v=0, int p=-1) {
        int sz = calc_sub(G, v);
        int centroid = find_centroid(G, v, sz / 2);
        used[centroid] = true;
        ord.push_back(centroid);
 
        if(p == -1) r = centroid;
        else {
            T[p].push_back(centroid);
            T[centroid].push_back(p);
        }
 
        for(int nv : G[centroid]) {
            if(used[nv]) continue;
            build_dfs(G, nv, centroid);
        }
    }

    const vector<vector<int>>& get_tree() { return T; }

    int get_root() { return r; }

    const vector<int>& get_order() { return ord; }
};
