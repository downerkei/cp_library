vector<vector<int>> calc_scc(const vector<vector<int>>& G) {
    int N = G.size();
    vector<vector<int>> RG(N);
    for(int i = 0; i < N; i++) {
        for(int j : G[i]) {
            RG[j].push_back(i);
        }
    }

    stack<int> st;
    vector<bool> used(N, false);
    auto dfs = [&](auto dfs, int v) -> void {
        used[v] = true;
        for(int nv : G[v]) {
            if(used[nv]) continue;
            dfs(dfs, nv);
        }
        st.push(v);
    };
    for(int s = 0; s < N; s++) {
        if(used[s]) continue;
        dfs(dfs, s);
    }

    vector<vector<int>> scc;
    used.assign(N, false);
    while(st.size()) {
        int s = st.top();
        st.pop();
        if(used[s]) continue;

        vector<int> component;
        auto dfs2 = [&](auto dfs2, int v) -> void {
            used[v] = true;
            component.push_back(v);
            for(int nv : RG[v]) {
                if(used[nv]) continue;
                dfs2(dfs2, nv);
            }
        };
        dfs2(dfs2, s);

        scc.push_back(component);
    }

    return scc;
}
