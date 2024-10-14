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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../graph/flow/ford_fulkerson.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A&lang=jp\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../graph/flow/ford_fulkerson.hpp\"\
    \n\nint main() {\n    int V, E;\n    cin >> V >> E;\n    FordFulkerson<int> ff(V);\n\
    \n    for(int i = 0; i < E; i++) {\n        int u, v, c;\n        cin >> u >>\
    \ v >> c;\n        ff.add_edge(u, v, c);\n    }\n\n    cout << ff.max_flow(0,\
    \ V - 1) << endl;\n\n    return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: verify/aoj/aoj_grl_6_a_ford_fulkerson.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/aoj/aoj_grl_6_a_ford_fulkerson.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj/aoj_grl_6_a_ford_fulkerson.test.cpp
- /verify/verify/aoj/aoj_grl_6_a_ford_fulkerson.test.cpp.html
title: verify/aoj/aoj_grl_6_a_ford_fulkerson.test.cpp
---
