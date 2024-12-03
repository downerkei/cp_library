---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data_structure/merge_sort_tree.hpp\"\ntemplate<typename\
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
    \      }\n        return ans;\n    }\n};\n"
  code: "template<typename S>\nstruct MergeSortTree {\n    int N;\n    vector<vector<S>>\
    \ data;\n    const S INF = numeric_limits<S>::max();\n    \n    MergeSortTree(const\
    \ vector<S>& V) : N(1) {\n        int sz = V.size();\n        while(N < sz) N\
    \ <<= 1;\n        data.resize(2 * N);\n        for(int i = 0; i < sz; i++) data[i\
    \ + N].push_back(V[i]);\n        for(int i = sz; i < N; i++) data[i + N].push_back(INF);\n\
    \        for(int i = N; --i;) merge_sort(i);\n    }\n\n    void merge_sort(int\
    \ k) {\n        int sz = data[k << 1].size();\n        int i1 = 0, i2 = 0;\n \
    \       while(i1 < sz || i2 < sz) {\n            if(i2 == sz || (i1 != sz && data[k\
    \ << 1][i1] < data[k << 1 | 1][i2])) data[k].push_back(data[k << 1][i1++]);\n\
    \            else data[k].push_back(data[k << 1 | 1][i2++]);\n        }\n    }\n\
    \n    int count_between(int l, int r, S lo, S up) {\n        l += N; r += N;\n\
    \        int ans = 0;\n        auto get_between = [&](int k) { return upper_bound(data[k].begin(),\
    \ data[k].end(), up) - lower_bound(data[k].begin(), data[k].end(), lo); };\n \
    \       while(l < r) {\n            if(l & 1) ans += get_between(l++);\n     \
    \       if(r & 1) ans += get_between(--r);\n            l >>= 1; r >>= 1;\n  \
    \      }\n        return ans;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/merge_sort_tree.hpp
  requiredBy: []
  timestamp: '2024-12-04 03:56:00+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/merge_sort_tree.hpp
layout: document
redirect_from:
- /library/data_structure/merge_sort_tree.hpp
- /library/data_structure/merge_sort_tree.hpp.html
title: data_structure/merge_sort_tree.hpp
---
