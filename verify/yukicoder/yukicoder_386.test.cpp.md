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
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/386\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#include \"../../graph/tree/lowest_common_ancestor.hpp\"\
    \n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n  \
    \  \n    int N;\n    cin >> N;\n    vector<int> A(N - 1), B(N - 1);\n    for(int\
    \ i = 0; i < N - 1; i++) {\n        cin >> A[i] >> B[i];\n    }\n    vector<int>\
    \ C(N);\n    for(int i = 0; i < N; i++) {\n        cin >> C[i];\n    }\n\n   \
    \ vector<vector<pair<int, int>>> G(N);\n    for(int i = 0; i < N - 1; i++) {\n\
    \        G[A[i]].push_back({B[i], C[A[i]] + C[B[i]]});\n        G[B[i]].push_back({A[i],\
    \ C[A[i]] + C[B[i]]});\n    }\n    LowestCommonAncestor<int> lca(G);\n\n    int\
    \ M;\n    cin >> M;\n    long long ans = 0;\n    while(M--) {\n        int a,\
    \ b, c;\n        cin >> a >> b >> c;\n        int tax = lca.dist_bitween(a, b)\
    \ + C[a] + C[b];\n        tax = tax / 2 * c;\n        ans += tax;\n    }\n   \
    \ cout << ans << endl;\n\n    return 0;\n}"
  dependsOn: []
  isVerificationFile: true
  path: verify/yukicoder/yukicoder_386.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/yukicoder/yukicoder_386.test.cpp
layout: document
redirect_from:
- /verify/verify/yukicoder/yukicoder_386.test.cpp
- /verify/verify/yukicoder/yukicoder_386.test.cpp.html
title: verify/yukicoder/yukicoder_386.test.cpp
---
