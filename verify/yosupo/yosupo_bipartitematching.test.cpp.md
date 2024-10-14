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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../graph/flow/dinic.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/bipartitematching\"\n\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../graph/flow/dinic.hpp\"\
    \n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\n\
    \    int L, R, M;\n    cin >> L >> R >> M;\n\n    Dinic<int> dinic(L + R + 2);\n\
    \n    for(int i = 0; i < M; i++) {\n        int a, b;\n        cin >> a >> b;\n\
    \        dinic.add_edge(a, L + b, 1);\n    }\n\n    for(int i = 0; i < L; i++)\
    \ {\n        dinic.add_edge(L + R, i, 1);\n    }\n\n    for(int i = 0; i < R;\
    \ i++) {\n        dinic.add_edge(L + i, L + R + 1, 1);\n    }\n\n    cout << dinic.max_flow(L\
    \ + R, L + R + 1) << endl;\n\n    const auto& edges = dinic.edges();\n\n    for(const\
    \ auto& e : edges) {\n        if(e.cap) continue;\n        if(e.from == L + R\
    \ || e.to == L + R + 1) continue;\n        cout << e.from << ' ' << e.to - L <<\
    \ endl;\n    }\n\n    return 0;\n}"
  dependsOn: []
  isVerificationFile: true
  path: verify/yosupo/yosupo_bipartitematching.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/yosupo/yosupo_bipartitematching.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/yosupo_bipartitematching.test.cpp
- /verify/verify/yosupo/yosupo_bipartitematching.test.cpp.html
title: verify/yosupo/yosupo_bipartitematching.test.cpp
---
