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
  bundledCode: "#line 1 \"data_structure/dual_segment_tree.hpp\"\ntemplate<class S,\
    \ S (*op)(S, S), S (*e)()>\nstruct DualSegmentTree{\n    int n;\n    vector<S>\
    \ data;\n\n    DualSegmentTree(int sz=0) : n(1) {\n        while(n < sz) n *=\
    \ 2;\n        data.resize(2 * n, e());\n    }\n\n    DualSegmentTree(const vector<S>\
    \ &V) : n(1) {\n        int sz = V.size();\n        while(n < sz) n *= 2;\n  \
    \      data.resize(2 * n, e());\n        for(int i = 0; i < sz; i++) data[i+n]\
    \ = V[i];\n    }\n\n    S get(int i) {\n        i += n;\n        S v = data[i];\n\
    \        while(i > 1) {\n            i >>= 1;\n            v = op(v, data[i]);\n\
    \        }\n        return v;\n    }\n\n    void apply(int l, int r, S x) {\n\
    \        l += n, r += n;\n        while(l < r) {\n            if(l & 1) data[l]\
    \ = op(data[l], x), l++;\n            if(r & 1) r--, data[r] = op(data[r], x);\n\
    \            l >>= 1, r >>= 1;\n        }\n    } \n};\n"
  code: "template<class S, S (*op)(S, S), S (*e)()>\nstruct DualSegmentTree{\n   \
    \ int n;\n    vector<S> data;\n\n    DualSegmentTree(int sz=0) : n(1) {\n    \
    \    while(n < sz) n *= 2;\n        data.resize(2 * n, e());\n    }\n\n    DualSegmentTree(const\
    \ vector<S> &V) : n(1) {\n        int sz = V.size();\n        while(n < sz) n\
    \ *= 2;\n        data.resize(2 * n, e());\n        for(int i = 0; i < sz; i++)\
    \ data[i+n] = V[i];\n    }\n\n    S get(int i) {\n        i += n;\n        S v\
    \ = data[i];\n        while(i > 1) {\n            i >>= 1;\n            v = op(v,\
    \ data[i]);\n        }\n        return v;\n    }\n\n    void apply(int l, int\
    \ r, S x) {\n        l += n, r += n;\n        while(l < r) {\n            if(l\
    \ & 1) data[l] = op(data[l], x), l++;\n            if(r & 1) r--, data[r] = op(data[r],\
    \ x);\n            l >>= 1, r >>= 1;\n        }\n    } \n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/dual_segment_tree.hpp
  requiredBy: []
  timestamp: '2025-02-27 04:34:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/dual_segment_tree.hpp
layout: document
redirect_from:
- /library/data_structure/dual_segment_tree.hpp
- /library/data_structure/dual_segment_tree.hpp.html
title: data_structure/dual_segment_tree.hpp
---
