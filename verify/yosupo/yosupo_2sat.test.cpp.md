---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/scc.hpp
    title: graph/scc.hpp
  - icon: ':heavy_check_mark:'
    path: math/two_sat.hpp
    title: math/two_sat.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/two_sat
    links:
    - https://judge.yosupo.jp/problem/two_sat
  bundledCode: "#line 1 \"verify/yosupo/yosupo_2sat.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/two_sat\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n#line 1 \"graph/scc.hpp\"\nvector<vector<int>> calc_scc(const vector<vector<int>>&\
    \ G) {\n    int N = G.size();\n    vector<vector<int>> RG(N);\n    for(int i =\
    \ 0; i < N; i++) {\n        for(int j : G[i]) {\n            RG[j].push_back(i);\n\
    \        }\n    }\n\n    stack<int> st;\n    vector<bool> used(N, false);\n  \
    \  auto dfs = [&](auto dfs, int v) -> void {\n        used[v] = true;\n      \
    \  for(int nv : G[v]) {\n            if(used[nv]) continue;\n            dfs(dfs,\
    \ nv);\n        }\n        st.push(v);\n    };\n    for(int s = 0; s < N; s++)\
    \ {\n        if(used[s]) continue;\n        dfs(dfs, s);\n    }\n\n    vector<vector<int>>\
    \ scc;\n    used.assign(N, false);\n    while(st.size()) {\n        int s = st.top();\n\
    \        st.pop();\n        if(used[s]) continue;\n\n        vector<int> component;\n\
    \        auto dfs2 = [&](auto dfs2, int v) -> void {\n            used[v] = true;\n\
    \            component.push_back(v);\n            for(int nv : RG[v]) {\n    \
    \            if(used[nv]) continue;\n                dfs2(dfs2, nv);\n       \
    \     }\n        };\n        dfs2(dfs2, s);\n\n        scc.push_back(component);\n\
    \    }\n\n    return scc;\n}\n#line 2 \"math/two_sat.hpp\"\n\nstruct TwoSat {\n\
    \    int n;\n    vector<bool> ans;\n    vector<vector<int>> G;\n    TwoSat(int\
    \ n) : n(n), ans(n), G(2 * n) {}\n\n    void add_clause(int i, bool f, int j,\
    \ bool g) {\n        G[2 * i + (f ? 0 : 1)].push_back(2 * j + (g ? 1 : 0));\n\
    \        G[2 * j + (g ? 0 : 1)].push_back(2 * i + (f ? 1 : 0));\n    }\n\n   \
    \ bool satisfiable() {\n        auto scc = calc_scc(G);\n        vector<int> scc_id(2\
    \ * n);\n        for(int i = 0; i < (int)scc.size(); i++) {\n            for(int\
    \ v : scc[i]) {\n                scc_id[v] = i;\n            }\n        }\n\n\
    \        for(int i = 0; i < n; i++) {\n            if(scc_id[2 * i] == scc_id[2\
    \ * i + 1]) return false;\n            ans[i] = scc_id[2 * i] < scc_id[2 * i +\
    \ 1];\n        }\n        return true;\n    }\n\n    vector<bool> answer() {\n\
    \        return ans;\n    }\n};\n#line 7 \"verify/yosupo/yosupo_2sat.test.cpp\"\
    \n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n  \
    \  \n    string a, b;\n    int N, M;\n    cin >> a >> b >> N >> M;\n\n    TwoSat\
    \ ts(N);\n    for(int i = 0; i < M; i++) {\n        int x, y, z;\n        cin\
    \ >> x >> y >> z;\n        ts.add_clause(abs(x) - 1, (x > 0), abs(y) - 1, (y >\
    \ 0));\n    }\n\n    if(ts.satisfiable()) {\n        cout << \"s SATISFIABLE\\\
    nv \";\n        for(int i = 0; i < N; i++) {\n            cout << (ts.ans[i] ?\
    \ 1 : -1) * (i + 1) << \" \";\n        }\n        cout << \"0\\n\";\n    }\n \
    \   else {\n        cout << \"s UNSATISFIABLE\\n\";\n    }\n\n    return 0;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/two_sat\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#include \"../../math/two_sat.hpp\"\n\nint main() {\n\
    \    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n    \n    string a,\
    \ b;\n    int N, M;\n    cin >> a >> b >> N >> M;\n\n    TwoSat ts(N);\n    for(int\
    \ i = 0; i < M; i++) {\n        int x, y, z;\n        cin >> x >> y >> z;\n  \
    \      ts.add_clause(abs(x) - 1, (x > 0), abs(y) - 1, (y > 0));\n    }\n\n   \
    \ if(ts.satisfiable()) {\n        cout << \"s SATISFIABLE\\nv \";\n        for(int\
    \ i = 0; i < N; i++) {\n            cout << (ts.ans[i] ? 1 : -1) * (i + 1) <<\
    \ \" \";\n        }\n        cout << \"0\\n\";\n    }\n    else {\n        cout\
    \ << \"s UNSATISFIABLE\\n\";\n    }\n\n    return 0;\n}\n"
  dependsOn:
  - math/two_sat.hpp
  - graph/scc.hpp
  isVerificationFile: true
  path: verify/yosupo/yosupo_2sat.test.cpp
  requiredBy: []
  timestamp: '2026-07-20 02:02:53+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/yosupo_2sat.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/yosupo_2sat.test.cpp
- /verify/verify/yosupo/yosupo_2sat.test.cpp.html
title: verify/yosupo/yosupo_2sat.test.cpp
---
