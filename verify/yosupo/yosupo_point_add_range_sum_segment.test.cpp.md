---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/segment_tree.hpp
    title: data_structure/segment_tree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "#line 1 \"verify/yosupo/yosupo_point_add_range_sum_segment.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"data_structure/segment_tree.hpp\"\
    \ntemplate<class S, S (*op)(S, S), S (*e)()>\nstruct SegmentTree{\n    int n;\n\
    \    vector<S> data;\n\n    SegmentTree(int sz=0) : n(1) {\n        while(n <\
    \ sz) n *= 2;\n        data.resize(2 * n, e());\n    }\n\n    SegmentTree(const\
    \ vector<S> &V) : n(1) {\n        int sz = V.size();\n        while(n < sz) n\
    \ *= 2;\n        data.resize(2 * n, e());\n        for(int i = 0; i < sz; i++)\
    \ data[i+n] = V[i];\n        for(int i = n - 1; i >= 1; i--) data[i] = op(data[i<<1],\
    \ data[i<<1|1]);\n    }\n\n    void set(int i, S x) {\n        i += n;\n     \
    \   data[i] = x;\n        while(i > 1) {\n            i >>= 1;\n            data[i]\
    \ = op(data[i<<1], data[i<<1|1]);\n        }\n    }\n\n    S prod(int l, int r)\
    \ {\n        l += n; r += n;\n        S vl = e(), vr = e();\n        while(l <\
    \ r) {\n            if(l & 1) vl = op(vl, data[l++]);\n            if(r & 1) vr\
    \ = op(data[--r], vr);\n            l >>= 1; r >>= 1;\n        }\n        return\
    \ op(vl, vr);\n    }\n\n    S all_prod() { return prod(0, n); }\n\n    S get(int\
    \ i) { return data[i + n]; }\n};\n#line 7 \"verify/yosupo/yosupo_point_add_range_sum_segment.test.cpp\"\
    \n\nusing S = long long;\nS op(S l, S r) { return l + r; }\nS e() { return 0;\
    \ }\n\nint main() {\n    int N, Q;\n    cin >> N >> Q;\n    vector<long long>\
    \ A(N);\n    for(int i = 0; i < N; i++) {\n        cin >> A[i];\n    }\n\n   \
    \ SegmentTree<S, op, e> seg(A);\n\n    while(Q--) {\n        int q;\n        cin\
    \ >> q;\n        if(q == 0) {\n            long long p, x;\n            cin >>\
    \ p >> x;\n            seg.set(p, x + seg.get(p));\n        }\n        if(q ==\
    \ 1) {\n            int l, r;\n            cin >> l >> r;\n            cout <<\
    \ seg.prod(l, r) << endl;\n        } \n    }\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../data_structure/segment_tree.hpp\"\
    \n\nusing S = long long;\nS op(S l, S r) { return l + r; }\nS e() { return 0;\
    \ }\n\nint main() {\n    int N, Q;\n    cin >> N >> Q;\n    vector<long long>\
    \ A(N);\n    for(int i = 0; i < N; i++) {\n        cin >> A[i];\n    }\n\n   \
    \ SegmentTree<S, op, e> seg(A);\n\n    while(Q--) {\n        int q;\n        cin\
    \ >> q;\n        if(q == 0) {\n            long long p, x;\n            cin >>\
    \ p >> x;\n            seg.set(p, x + seg.get(p));\n        }\n        if(q ==\
    \ 1) {\n            int l, r;\n            cin >> l >> r;\n            cout <<\
    \ seg.prod(l, r) << endl;\n        } \n    }\n\n    return 0;\n}"
  dependsOn:
  - data_structure/segment_tree.hpp
  isVerificationFile: true
  path: verify/yosupo/yosupo_point_add_range_sum_segment.test.cpp
  requiredBy: []
  timestamp: '2024-07-23 19:46:23+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/yosupo_point_add_range_sum_segment.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/yosupo_point_add_range_sum_segment.test.cpp
- /verify/verify/yosupo/yosupo_point_add_range_sum_segment.test.cpp.html
title: verify/yosupo/yosupo_point_add_range_sum_segment.test.cpp
---
