#include "../graph/scc.hpp"

struct TwoSat {
    int n;
    vector<bool> ans;
    vector<vector<int>> G;
    TwoSat(int n) : n(n), ans(n), G(2 * n) {}

    void add_clause(int i, bool f, int j, bool g) {
        G[2 * i + (f ? 0 : 1)].push_back(2 * j + (g ? 1 : 0));
        G[2 * j + (g ? 0 : 1)].push_back(2 * i + (f ? 1 : 0));
    }

    bool satisfiable() {
        auto scc = calc_scc(G);
        vector<int> scc_id(2 * n);
        for(int i = 0; i < (int)scc.size(); i++) {
            for(int v : scc[i]) {
                scc_id[v] = i;
            }
        }

        for(int i = 0; i < n; i++) {
            if(scc_id[2 * i] == scc_id[2 * i + 1]) return false;
            ans[i] = scc_id[2 * i] < scc_id[2 * i + 1];
        }
        return true;
    }

    vector<bool> answer() {
        return ans;
    }
};