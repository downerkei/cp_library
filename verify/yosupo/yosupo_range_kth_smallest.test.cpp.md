---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/merge_sort_tree.hpp
    title: data_structure/merge_sort_tree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_kth_smallest
    links:
    - https://judge.yosupo.jp/problem/range_kth_smallest
  bundledCode: "#line 1 \"verify/yosupo/yosupo_range_kth_smallest.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/range_kth_smallest\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#line 1 \"data_structure/merge_sort_tree.hpp\"\ntemplate<typename\
    \ S>\nstruct MergeSortTree {\n    int N;\n    vector<vector<S>> data;\n    const\
    \ S INF = numeric_limits<S>::max();\n    \n    MergeSortTree(const vector<S>&\
    \ V) : N(1) {\n        int sz = V.size();\n        while(N < sz) N <<= 1;\n  \
    \      data.resize(2 * N);\n        for(int i = 0; i < sz; i++) data[i + N].push_back(V[i]);\n\
    \        for(int i = sz; i < N; i++) data[i + N].push_back(INF);\n        for(int\
    \ i = N; --i;) merge_sort(i);\n    }\n\n    void merge_sort(int k) {\n       \
    \ int sz = data[k << 1].size();\n        int i1 = 0, i2 = 0;\n        while(i1\
    \ < sz || i2 < sz) {\n            if(i2 == sz || (i1 != sz && data[k << 1][i1]\
    \ < data[k << 1 | 1][i2])) data[k].push_back(data[k << 1][i1++]);\n          \
    \  else data[k].push_back(data[k << 1 | 1][i2++]);\n        }\n    }\n\n    int\
    \ count_between(int l, int r, S lo, S up) {\n        l += N; r += N;\n       \
    \ int ans = 0;\n        auto get_between = [&](int k) { return upper_bound(data[k].begin(),\
    \ data[k].end(), up) - lower_bound(data[k].begin(), data[k].end(), lo); };\n \
    \       while(l < r) {\n            if(l & 1) ans += get_between(l++);\n     \
    \       if(r & 1) ans += get_between(--r);\n            l >>= 1; r >>= 1;\n  \
    \      }\n        return ans;\n    }\n};\n#line 7 \"verify/yosupo/yosupo_range_kth_smallest.test.cpp\"\
    \n\nconstexpr int INF = 1e9 + 10;\n\nint main() {\n    cin.tie(nullptr);\n   \
    \ ios::sync_with_stdio(false);\n    int N, Q;\n    cin >> N >> Q;\n    vector<int>\
    \ A(N);\n    for(int i = 0; i < N; i++) {\n        cin >> A[i];\n    }\n\n   \
    \ MergeSortTree<int> mst(A);\n\n    while(Q--) {\n        int l, r, k;\n     \
    \   cin >> l >> r >> k;\n        int lb = -1, ub = INF;\n        while(ub - lb\
    \ > 1) {\n            int mid = (lb + ub) / 2;\n            if(mst.count_between(l,\
    \ r, 0, mid) <= k) lb = mid;\n            else ub = mid;\n        }\n        cout\
    \ << ub << \"\\n\";\n    }\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_kth_smallest\"\n\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../data_structure/merge_sort_tree.hpp\"\
    \n\nconstexpr int INF = 1e9 + 10;\n\nint main() {\n    cin.tie(nullptr);\n   \
    \ ios::sync_with_stdio(false);\n    int N, Q;\n    cin >> N >> Q;\n    vector<int>\
    \ A(N);\n    for(int i = 0; i < N; i++) {\n        cin >> A[i];\n    }\n\n   \
    \ MergeSortTree<int> mst(A);\n\n    while(Q--) {\n        int l, r, k;\n     \
    \   cin >> l >> r >> k;\n        int lb = -1, ub = INF;\n        while(ub - lb\
    \ > 1) {\n            int mid = (lb + ub) / 2;\n            if(mst.count_between(l,\
    \ r, 0, mid) <= k) lb = mid;\n            else ub = mid;\n        }\n        cout\
    \ << ub << \"\\n\";\n    }\n\n    return 0;\n}"
  dependsOn:
  - data_structure/merge_sort_tree.hpp
  isVerificationFile: true
  path: verify/yosupo/yosupo_range_kth_smallest.test.cpp
  requiredBy: []
  timestamp: '2024-12-04 23:13:29+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/yosupo_range_kth_smallest.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/yosupo_range_kth_smallest.test.cpp
- /verify/verify/yosupo/yosupo_range_kth_smallest.test.cpp.html
title: verify/yosupo/yosupo_range_kth_smallest.test.cpp
---
