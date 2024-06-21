---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/fenwick_tree.hpp
    title: data_structure/fenwick_tree.hpp
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
  bundledCode: "#line 1 \"test/verify/yosupo_point_add_range_sum.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"data_structure/fenwick_tree.hpp\"\
    \ntemplate <typename T>\nstruct FenwickTree {\n  public:\n    FenwickTree(int\
    \ n) : n_(n), data(n) {}\n\n    void Add(int p, T x) {\n        p++;\n       \
    \ while(p <= n_) {\n            data[p - 1] += x;\n            p += p & -p;\n\
    \        }\n    }\n\n    T Sum(int r) {\n        T s = 0;\n        while(r > 0)\
    \ {\n            s += data[r - 1];\n            r -= r & -r;\n        }\n    \
    \    return s;\n    }\n\n    T Sum(int r, int l) {\n        return Sum(l) - Sum(r);\n\
    \    }\n\n  private:\n    int n_;\n    vector<T> data;\n};\n#line 7 \"test/verify/yosupo_point_add_range_sum.test.cpp\"\
    \n\nint main(){\n    int N, Q;\n    cin >> N >> Q;\n\n    FenwickTree<long long>\
    \ bit(N); \n\n    for(int i = 0; i < N; i++) {\n        int a;\n        cin >>\
    \ a;\n        bit.Add(i, a);\n    }\n\n    for(int i = 0; i < Q; i++) {\n    \
    \    int t;\n        cin >> t;\n        if(t == 0) {\n            int p, x;\n\
    \            cin >> p >> x;\n            bit.Add(p, x);\n        }\n\n       \
    \ if(t == 1) {\n            int l, r;\n            cin >> l >> r;\n          \
    \  cout << bit.Sum(l, r) << endl;\n        }\n    }\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../data_structure/fenwick_tree.hpp\"\
    \n\nint main(){\n    int N, Q;\n    cin >> N >> Q;\n\n    FenwickTree<long long>\
    \ bit(N); \n\n    for(int i = 0; i < N; i++) {\n        int a;\n        cin >>\
    \ a;\n        bit.Add(i, a);\n    }\n\n    for(int i = 0; i < Q; i++) {\n    \
    \    int t;\n        cin >> t;\n        if(t == 0) {\n            int p, x;\n\
    \            cin >> p >> x;\n            bit.Add(p, x);\n        }\n\n       \
    \ if(t == 1) {\n            int l, r;\n            cin >> l >> r;\n          \
    \  cout << bit.Sum(l, r) << endl;\n        }\n    }\n\n    return 0;\n}"
  dependsOn:
  - data_structure/fenwick_tree.hpp
  isVerificationFile: true
  path: test/verify/yosupo_point_add_range_sum.test.cpp
  requiredBy: []
  timestamp: '2024-06-21 22:22:16+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/verify/yosupo_point_add_range_sum.test.cpp
layout: document
redirect_from:
- /verify/test/verify/yosupo_point_add_range_sum.test.cpp
- /verify/test/verify/yosupo_point_add_range_sum.test.cpp.html
title: test/verify/yosupo_point_add_range_sum.test.cpp
---