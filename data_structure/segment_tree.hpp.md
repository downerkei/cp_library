---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/yosupo_point_add_range_sum_segment.test.cpp
    title: verify/yosupo/yosupo_point_add_range_sum_segment.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/yosupo_staticrmq.test.cpp
    title: verify/yosupo/yosupo_staticrmq.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data_structure/segment_tree.hpp\"\ntemplate<class S, S (*op)(S,\
    \ S), S (*e)()>\nstruct SegmentTree{\n    int n;\n    vector<S> data;\n\n    SegmentTree(int\
    \ sz=0) : n(1) {\n        while(n < sz) n *= 2;\n        data.resize(2 * n, e());\n\
    \    }\n\n    SegmentTree(const vector<S> &V) : n(1) {\n        int sz = V.size();\n\
    \        while(n < sz) n *= 2;\n        data.resize(2 * n, e());\n        for(int\
    \ i = 0; i < sz; i++) data[i+n] = V[i];\n        for(int i = n - 1; i >= 1; i--)\
    \ data[i] = op(data[i<<1], data[i<<1|1]);\n    }\n\n    void set(int i, S x) {\n\
    \        i += n;\n        data[i] = x;\n        while(i > 1) {\n            i\
    \ >>= 1;\n            data[i] = op(data[i<<1], data[i<<1|1]);\n        }\n   \
    \ }\n\n    S prod(int l, int r) {\n        l += n; r += n;\n        S vl = e(),\
    \ vr = e();\n        while(l < r) {\n            if(l & 1) vl = op(vl, data[l++]);\n\
    \            if(r & 1) vr = op(data[--r], vr);\n            l >>= 1; r >>= 1;\n\
    \        }\n        return op(vl, vr);\n    }\n\n    S get(int i) { return data[i\
    \ + n]; }\n};\n"
  code: "template<class S, S (*op)(S, S), S (*e)()>\nstruct SegmentTree{\n    int\
    \ n;\n    vector<S> data;\n\n    SegmentTree(int sz=0) : n(1) {\n        while(n\
    \ < sz) n *= 2;\n        data.resize(2 * n, e());\n    }\n\n    SegmentTree(const\
    \ vector<S> &V) : n(1) {\n        int sz = V.size();\n        while(n < sz) n\
    \ *= 2;\n        data.resize(2 * n, e());\n        for(int i = 0; i < sz; i++)\
    \ data[i+n] = V[i];\n        for(int i = n - 1; i >= 1; i--) data[i] = op(data[i<<1],\
    \ data[i<<1|1]);\n    }\n\n    void set(int i, S x) {\n        i += n;\n     \
    \   data[i] = x;\n        while(i > 1) {\n            i >>= 1;\n            data[i]\
    \ = op(data[i<<1], data[i<<1|1]);\n        }\n    }\n\n    S prod(int l, int r)\
    \ {\n        l += n; r += n;\n        S vl = e(), vr = e();\n        while(l <\
    \ r) {\n            if(l & 1) vl = op(vl, data[l++]);\n            if(r & 1) vr\
    \ = op(data[--r], vr);\n            l >>= 1; r >>= 1;\n        }\n        return\
    \ op(vl, vr);\n    }\n\n    S get(int i) { return data[i + n]; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/segment_tree.hpp
  requiredBy: []
  timestamp: '2024-06-25 02:44:34+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/yosupo_point_add_range_sum_segment.test.cpp
  - verify/yosupo/yosupo_staticrmq.test.cpp
documentation_of: data_structure/segment_tree.hpp
layout: document
redirect_from:
- /library/data_structure/segment_tree.hpp
- /library/data_structure/segment_tree.hpp.html
title: data_structure/segment_tree.hpp
---
