struct UnionFind {
    vector<int> par, siz;

    UnionFind(int n) : par(n, -1), siz(n, 1) {}

    int root(int v) {
        if(par[v] == -1) return v;
        return par[v] = root(par[v]);
    }

    bool same(int u, int v) {
        return root(u) == root(v);
    }

    bool unite(int u, int v) {
        u = root(u);
        v = root(v);
        if(u == v) return false;
        if(siz[u] < siz[v]) swap(u, v);
        par[v] = u;
        siz[u] += siz[v];
        // write something
        return true;
    }

    int size(int v) {
        return siz[root(v)];
    }
};
