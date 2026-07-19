---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/scc.hpp
    title: graph/scc.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/scc
    links:
    - https://judge.yosupo.jp/problem/scc
  bundledCode: "#line 1 \"verify/yosupo/yosupo_scc.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/scc\"\n\n#include <bits/stdc++.h>\nusing namespace\
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
    \    }\n\n    return scc;\n}\n#line 7 \"verify/yosupo/yosupo_scc.test.cpp\"\n\n\
    int main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n    \n\
    \    int N, M;\n    cin >> N >> M;\n    vector<vector<int>> G(N);\n    for(int\
    \ i = 0; i < M; i++) {\n        int a, b;\n        cin >> a >> b;\n        G[a].push_back(b);\n\
    \    }\n\n    auto ans = calc_scc(G);\n    cout << ans.size() << \"\\n\";\n\n\
    \    for(auto C : ans) {\n        cout << ssize(C) << \" \";\n        for(auto\
    \ v : C) {\n            cout << v << \" \";\n        }\n        cout << \"\\n\"\
    ;\n    }\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#include \"../../graph/scc.hpp\"\n\nint main() {\n   \
    \ cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n    \n    int N, M;\n \
    \   cin >> N >> M;\n    vector<vector<int>> G(N);\n    for(int i = 0; i < M; i++)\
    \ {\n        int a, b;\n        cin >> a >> b;\n        G[a].push_back(b);\n \
    \   }\n\n    auto ans = calc_scc(G);\n    cout << ans.size() << \"\\n\";\n\n \
    \   for(auto C : ans) {\n        cout << ssize(C) << \" \";\n        for(auto\
    \ v : C) {\n            cout << v << \" \";\n        }\n        cout << \"\\n\"\
    ;\n    }\n\n    return 0;\n}"
  dependsOn:
  - graph/scc.hpp
  isVerificationFile: true
  path: verify/yosupo/yosupo_scc.test.cpp
  requiredBy: []
  timestamp: '2026-07-20 03:16:12+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/yosupo_scc.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/yosupo_scc.test.cpp
- /verify/verify/yosupo/yosupo_scc.test.cpp.html
title: verify/yosupo/yosupo_scc.test.cpp
---
