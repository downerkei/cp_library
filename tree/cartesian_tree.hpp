template<typename T=int>
struct CartesianTree {
    int n;
    int root;
    vector<int> lc, rc, p;

    CartesianTree(const vector<T>& a) : n(a.size()), lc(n, -1), rc(n, -1), p(n, -1) {
        vector<int> st;
        for(int i = 0; i < n; i++) {
            int last_pop = -1;
            // Max-Cartesian Treeなら a[top] < a[i]
            while(!st.empty() && a[st.back()] > a[i]) {
                last_pop = st.back();
                st.pop_back();
            }

            if(last_pop != -1) {
                lc[i] = last_pop;
                p[last_pop] = i;
            }

            if(!st.empty()) {
                rc[st.back()] = i;
                p[i] = st.back();
            }

            st.push_back(i);
        }
        if(!st.empty()) root = st.front();
        else root = -1;
    }
};
