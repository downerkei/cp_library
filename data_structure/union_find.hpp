struct UnionFind {
  public:
    UnionFind(int n) : par(n, -1), rank(n, 0), siz(n, 1) {}

    int Root(int a) {
        if(par[a] == -1) return a;
        else return par[a] = Root(par[a]);
    }

    bool Same(int a, int b) {
        return Root(a) == Root(b);
    }

    bool Unite(int a, int b) {
        int ra = Root(a), rb = Root(b);
        if(ra == rb) return false;
        if(rank[ra] < rank[rb]) swap(ra, rb);
        par[rb] = ra;
        if(rank[ra] == rank[rb]) rank[ra]++;
        siz[ra] += siz[rb];
        return true;
    }

    int Size(int a) {
        return siz[Root(a)];
    }

  private:
    vector<int> par, rank, siz;
};