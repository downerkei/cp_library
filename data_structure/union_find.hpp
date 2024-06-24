struct UnionFind {
  public:
    UnionFind(int n) : par(n, -1), rank(n, 0), siz(n, 1) {}

    int root(int a) {
        if(par[a] == -1) return a;
        else return par[a] = root(par[a]);
    }

    bool same(int a, int b) {
        return root(a) == root(b);
    }

    bool unite(int a, int b) {
        int ra = root(a), rb = root(b);
        if(ra == rb) return false;
        if(rank[ra] < rank[rb]) swap(ra, rb);
        par[rb] = ra;
        if(rank[ra] == rank[rb]) rank[ra]++;
        siz[ra] += siz[rb];
        return true;
    }

    int dize(int a) {
        return siz[root(a)];
    }

  private:
    vector<int> par, rank, siz;
};