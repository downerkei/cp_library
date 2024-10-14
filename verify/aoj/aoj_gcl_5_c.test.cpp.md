---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../graph/tree/lowest_common_ancestor.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C&lang=ja\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../graph/tree/lowest_common_ancestor.hpp\"\
    \n\nint main() {\n    int N;\n    cin >> N;\n\n    vector<vector<pair<int, int>>>\
    \ G(N);\n\n    for(int i = 0; i < N; i++) {\n        int k;\n        cin >> k;\n\
    \        for(int j = 0; j < k; j++) {\n            int c;\n            cin >>\
    \ c;\n            G[i].push_back({c, 1});\n            G[c].push_back({i, 1});\n\
    \        }\n    }\n\n    LowestCommonAncestor<int> lca(G, 0);\n\n    int Q;\n\
    \    cin >> Q;\n    while(Q--) {\n        int u, v;\n        cin >> u >> v;\n\
    \        cout << lca.lca(u, v) << endl;\n    }\n\n    return 0;\n}"
  dependsOn: []
  isVerificationFile: true
  path: verify/aoj/aoj_gcl_5_c.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/aoj/aoj_gcl_5_c.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj/aoj_gcl_5_c.test.cpp
- /verify/verify/aoj/aoj_gcl_5_c.test.cpp.html
title: verify/aoj/aoj_gcl_5_c.test.cpp
---
