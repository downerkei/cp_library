---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/tree/centroid_decomposition.hpp
    title: "\u91CD\u5FC3\u5206\u89E3"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/1002
    links:
    - https://yukicoder.me/problems/no/1002
  bundledCode: "#line 1 \"verify/yukicoder/yukicoder_1002.test.cpp\"\n#define PROBLEM\
    \ \"https://yukicoder.me/problems/no/1002\"\n\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\n#line 1 \"graph/tree/centroid_decomposition.hpp\"\nstruct\
    \ CentroidDecomposition{\n    vector<vector<int>> T;\n    vector<int> sub, ord;\n\
    \    vector<int> used;\n    int r;\n \n    CentroidDecomposition(vector<vector<int>>&\
    \ G) : T(G.size()), sub(G.size()), used(G.size()) {\n        build_dfs(G);\n \
    \   } \n \n    int calc_sub(vector<vector<int>>& G, int v, int p=-1) {\n     \
    \   sub[v] = 1;\n        for(int nv : G[v]) {\n            if(used[nv] || p ==\
    \ nv) continue;\n            sub[v] += calc_sub(G, nv, v);\n        }\n      \
    \  return sub[v];\n    }\n \n    int find_centroid(vector<vector<int>>& G, int\
    \ v, int mid, int p=-1) {\n        for(int nv : G[v]) {\n            if(used[nv]\
    \ || p == nv) continue;\n            if(sub[nv] > mid) return find_centroid(G,\
    \ nv, mid, v);\n        }\n        return v;\n    }\n \n    void build_dfs(vector<vector<int>>&\
    \ G, int v=0, int p=-1) {\n        int sz = calc_sub(G, v);\n        int centroid\
    \ = find_centroid(G, v, sz / 2);\n        used[centroid] = true;\n        ord.push_back(centroid);\n\
    \ \n        if(p == -1) r = centroid;\n        else {\n            T[p].push_back(centroid);\n\
    \            T[centroid].push_back(p);\n        }\n \n        for(int nv : G[centroid])\
    \ {\n            if(used[nv]) continue;\n            build_dfs(G, nv, centroid);\n\
    \        }\n    }\n\n    const vector<vector<int>>& get_tree() { return T; }\n\
    \n    int get_root() { return r; }\n\n    const vector<int>& get_order() { return\
    \ ord; }\n};\n#line 7 \"verify/yukicoder/yukicoder_1002.test.cpp\"\n\nint main()\
    \ {\n    int N, K;\n    cin >> N >> K;\n    vector<vector<int>> G(N);\n    vector<vector<pair<int,\
    \ int>>> E(N);\n    for(int i = 0; i < N - 1; i++) {\n        int u, v, c;\n \
    \       cin >> u >> v >> c;\n        u--; v--;\n        G[u].push_back(v);\n \
    \       G[v].push_back(u);\n        E[u].push_back({v, c});\n        E[v].push_back({u,\
    \ c});\n    }\n\n    CentroidDecomposition cd(G);\n\n    vector<bool> used(N,\
    \ false);\n    long long ans = 0;\n\n    vector<int> ord = cd.get_order();\n\n\
    \    for(int centroid : ord) {\n        \n        used[centroid] = true;\n\n \
    \       map<int, int> cnt1; // x, -\n        map<pair<int, int>, int> cnt2;  //\
    \ x, y\n        map<int, int> cnt3; // x, *\n        int cnt4 = 0;   // *, -\n\
    \        int cnt5 = 0;   // *. *\n\n        for(auto [nv, c] : E[centroid]) {\n\
    \            if(used[nv]) continue;\n            map<int, int> color1;\n     \
    \       map<pair<int, int>, int> color2;\n\n            // centroid\u306Esubtree\u306B\
    \u95A2\u3057\u3066\u8272\u306E\u30D1\u30B9\u3092\u6570\u3048\u308B\n         \
    \   // \u6700\u5927 N \u7A2E\u985E\u306E\u30D1\u30B9\n            auto dfs = [&](auto\
    \ f, int v, int p, int c1, int c2) -> void {\n                if(c2 == -1) color1[c1]++;\n\
    \                if(c2 != -1) color2[{c1, c2}]++;\n\n                for(auto\
    \ [nv, c] : E[v]) {\n                    if(used[nv] || p == nv) continue;\n \
    \                   if(c1 == c || c2 == c) f(f, nv, v, c1, c2);\n            \
    \        else if(c2 == -1) f(f, nv, v, min(c1, c), max(c1, c));\n            \
    \    }\n            };\n            dfs(dfs, nv, -1, c, -1);\n\n            //\
    \ merge\n            for(auto [c1, num] : color1) {\n                if(!cnt3.count(c1))\
    \ cnt3[c1] = 0;\n                if(!cnt1.count(c1)) cnt1[c1] = 0;\n         \
    \       ans += (long long) num * (cnt3[c1] + cnt4 - cnt1[c1]);\n            }\n\
    \            for(auto [cs, num] : color2) {\n                auto [c1, c2] = cs;\n\
    \                if(!cnt2.count(cs)) cnt2[cs] = 0;\n                if(!cnt1.count(c1))\
    \ cnt1[c1] = 0;\n                if(!cnt1.count(c2)) cnt1[c2] = 0;\n         \
    \       ans += (long long) num * (cnt2[cs] + cnt1[c1] + cnt1[c2]);\n         \
    \   }\n\n            for(auto [c1, num] : color1) {\n                cnt1[c1]\
    \ += num;\n                cnt4 += num;\n            }\n            for(auto [cs,\
    \ num] : color2) {\n                auto [c1, c2] = cs;\n                cnt2[cs]\
    \ += num;\n                cnt3[c1] += num;\n                cnt3[c2] += num;\n\
    \                cnt5 += num;\n            }\n        }\n        ans += cnt5;\n\
    \    }\n\n    cout << ans << endl;\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/1002\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#include \"../../graph/tree/centroid_decomposition.hpp\"\
    \n\nint main() {\n    int N, K;\n    cin >> N >> K;\n    vector<vector<int>> G(N);\n\
    \    vector<vector<pair<int, int>>> E(N);\n    for(int i = 0; i < N - 1; i++)\
    \ {\n        int u, v, c;\n        cin >> u >> v >> c;\n        u--; v--;\n  \
    \      G[u].push_back(v);\n        G[v].push_back(u);\n        E[u].push_back({v,\
    \ c});\n        E[v].push_back({u, c});\n    }\n\n    CentroidDecomposition cd(G);\n\
    \n    vector<bool> used(N, false);\n    long long ans = 0;\n\n    vector<int>\
    \ ord = cd.get_order();\n\n    for(int centroid : ord) {\n        \n        used[centroid]\
    \ = true;\n\n        map<int, int> cnt1; // x, -\n        map<pair<int, int>,\
    \ int> cnt2;  // x, y\n        map<int, int> cnt3; // x, *\n        int cnt4 =\
    \ 0;   // *, -\n        int cnt5 = 0;   // *. *\n\n        for(auto [nv, c] :\
    \ E[centroid]) {\n            if(used[nv]) continue;\n            map<int, int>\
    \ color1;\n            map<pair<int, int>, int> color2;\n\n            // centroid\u306E\
    subtree\u306B\u95A2\u3057\u3066\u8272\u306E\u30D1\u30B9\u3092\u6570\u3048\u308B\
    \n            // \u6700\u5927 N \u7A2E\u985E\u306E\u30D1\u30B9\n            auto\
    \ dfs = [&](auto f, int v, int p, int c1, int c2) -> void {\n                if(c2\
    \ == -1) color1[c1]++;\n                if(c2 != -1) color2[{c1, c2}]++;\n\n \
    \               for(auto [nv, c] : E[v]) {\n                    if(used[nv] ||\
    \ p == nv) continue;\n                    if(c1 == c || c2 == c) f(f, nv, v, c1,\
    \ c2);\n                    else if(c2 == -1) f(f, nv, v, min(c1, c), max(c1,\
    \ c));\n                }\n            };\n            dfs(dfs, nv, -1, c, -1);\n\
    \n            // merge\n            for(auto [c1, num] : color1) {\n         \
    \       if(!cnt3.count(c1)) cnt3[c1] = 0;\n                if(!cnt1.count(c1))\
    \ cnt1[c1] = 0;\n                ans += (long long) num * (cnt3[c1] + cnt4 - cnt1[c1]);\n\
    \            }\n            for(auto [cs, num] : color2) {\n                auto\
    \ [c1, c2] = cs;\n                if(!cnt2.count(cs)) cnt2[cs] = 0;\n        \
    \        if(!cnt1.count(c1)) cnt1[c1] = 0;\n                if(!cnt1.count(c2))\
    \ cnt1[c2] = 0;\n                ans += (long long) num * (cnt2[cs] + cnt1[c1]\
    \ + cnt1[c2]);\n            }\n\n            for(auto [c1, num] : color1) {\n\
    \                cnt1[c1] += num;\n                cnt4 += num;\n            }\n\
    \            for(auto [cs, num] : color2) {\n                auto [c1, c2] = cs;\n\
    \                cnt2[cs] += num;\n                cnt3[c1] += num;\n        \
    \        cnt3[c2] += num;\n                cnt5 += num;\n            }\n     \
    \   }\n        ans += cnt5;\n    }\n\n    cout << ans << endl;\n\n    return 0;\n\
    }"
  dependsOn:
  - graph/tree/centroid_decomposition.hpp
  isVerificationFile: true
  path: verify/yukicoder/yukicoder_1002.test.cpp
  requiredBy: []
  timestamp: '2024-08-21 01:14:30+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yukicoder/yukicoder_1002.test.cpp
layout: document
redirect_from:
- /verify/verify/yukicoder/yukicoder_1002.test.cpp
- /verify/verify/yukicoder/yukicoder_1002.test.cpp.html
title: verify/yukicoder/yukicoder_1002.test.cpp
---
