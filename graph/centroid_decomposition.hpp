namespace centroid_decomposition{

vector<vector<int>> G, T;
vector<int> sub;
vector<bool> used;

int calc_subtree(int v, int p=-1) {
    sub[v] = 1;
    for(int& nv : G[v]) {
        if(used[nv] || p == nv) continue;
        sub[v] += calc_subtree(nv, v);
    }
    return sub[v];
}

int find_centroid(int v, int mid, int p=-1) {
    for(int& nv : G[v]) {
        if(used[nv] || p == nv) continue;
        if(sub[nv] > mid) return find_centroid(nv, mid, v);
    }
    return v;
}

void build_dfs(int v=0, int p=-1) {
    int sz = calc_subtree(v);
    int centroid = find_centroid(v, sz / 2);

    used[centroid] = true;

    if(p != -1) {
        T[p].push_back(centroid);
        T[centroid].push_back(p);
    }

    for(int& nv : G[centroid]) {
        if(used[nv] || p == nv) continue;
        build_dfs(nv, centroid);
    }
}

vector<vector<int>> centroid_decomposition(const vector<vector<int>>& G_) {
    G = G_;
    sub.resize(G.size());
    used.resize(G.size());

    build_dfs();

    return T;
}

} // namespace centroid_decomposition
