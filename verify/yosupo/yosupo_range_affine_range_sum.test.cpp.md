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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../data_structure/lazy_segmemt_tree.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../data_structure/lazy_segmemt_tree.hpp\"\
    \n#include \"../../data_structure/static_modint.hpp\"\n\nusing mint = StaticModint<998244353>;\n\
    \nusing S = pair<mint, mint>;\nS op(S l, S r) { return {l.first + r.first, l.second\
    \ + r.second}; }\nS e() { return {0, 0}; }\nusing F = pair<mint, mint>;\nS mapping(F\
    \ f, S x) { return {x.first * f.first + x.second * f.second, x.second}; }\nF composition(F\
    \ f, F g) { return {f.first * g.first, f.first * g.second + f.second}; }\nF id()\
    \ { return {1, 0}; }\n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \    int N, Q;\n    cin >> N >> Q;\n    vector<S> A(N);\n    for(int i = 0; i\
    \ < N; i++) {\n        int a;\n        cin >> a;\n        A[i] = {a, 1};\n   \
    \ }\n\n    LazySegmentTree<S, op, e, F, mapping, composition, id> seg(A);\n\n\
    \    while(Q--) {\n        int q;\n        cin >> q;\n        if(q == 0) {\n \
    \           int l, r, b, c;\n            cin >> l >> r >> b >> c;\n          \
    \  seg.apply(l, r, {b, c});\n        }\n        if(q == 1) {\n            int\
    \ l, r;\n            cin >> l >> r;\n            cout << seg.prod(l, r).first\
    \ << \"\\n\";\n        }\n    }\n\n    return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: verify/yosupo/yosupo_range_affine_range_sum.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/yosupo/yosupo_range_affine_range_sum.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/yosupo_range_affine_range_sum.test.cpp
- /verify/verify/yosupo/yosupo_range_affine_range_sum.test.cpp.html
title: verify/yosupo/yosupo_range_affine_range_sum.test.cpp
---
