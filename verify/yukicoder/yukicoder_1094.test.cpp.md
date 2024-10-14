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
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/1094\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#include \"../../graph/tree/lowest_common_ancestor.hpp\"\
    \n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n  \
    \  int N;\n    cin >> N;\n    vector<vector<pair<int, int>>> G(N);\n    for(int\
    \ i = 0; i < N - 1; i++) {\n        int a, b, c;\n        cin >> a >> b >> c;\n\
    \        a--; b--;\n        G[a].push_back({b, c});\n        G[b].push_back({a,\
    \ c});\n    }\n\n    LowestCommonAncestor<int> lca(G);\n\n    int Q;\n    cin\
    \ >> Q;\n    while(Q--) {\n        int s, t;\n        cin >> s >> t;\n       \
    \ s--; t--;\n        cout << lca.dist_bitween(s, t) << \"\\n\";\n    }\n\n   \
    \ return 0;\n}"
  dependsOn: []
  isVerificationFile: true
  path: verify/yukicoder/yukicoder_1094.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/yukicoder/yukicoder_1094.test.cpp
layout: document
redirect_from:
- /verify/verify/yukicoder/yukicoder_1094.test.cpp
- /verify/verify/yukicoder/yukicoder_1094.test.cpp.html
title: verify/yukicoder/yukicoder_1094.test.cpp
---
