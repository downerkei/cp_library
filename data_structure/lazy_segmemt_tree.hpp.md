---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/yosupo_range_affine_range_sum.test.cpp
    title: verify/yosupo/yosupo_range_affine_range_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data_structure/lazy_segmemt_tree.hpp\"\ntemplate<class S,\
    \ S (*op)(S, S), S (*e)(), class F, S (*mapping)(F, S), F (*composition)(F, F),\
    \ F (*id)()>\nstruct LazySegmentTree{\n    int n, log;\n    vector<S> data;\n\
    \    vector<F> lazy;\n\n    LazySegmentTree(int n) : LazySegmentTree(vector<S>(n,\
    \ e())) {}\n\n    LazySegmentTree(vector<S> &v) {\n        int sz = v.size();\n\
    \        n = 1; \n        log = 0;\n        while(n < sz) {\n            n <<=\
    \ 1;\n            log++;\n        }\n\n        data.resize(2 * n, e());\n    \
    \    lazy.resize(2 * n, id());\n\n        for(int i = 0; i < sz; i++) data[i +\
    \ n] = v[i];\n        for(int i = n; --i;) data[i] = op(data[i << 1], data[i <<\
    \ 1 | 1]);\n    }\n\n    S prod(int l, int r) {\n        if(l == r) return e();\n\
    \        l += n; r += n;\n\n        for(int i = log; i >= 1; i--) {\n        \
    \    if(((l >> i) << i) != l) push(l >> i);\n            if(((r >> i) << i) !=\
    \ r) push(r >> i);\n        }\n\n        S vl = e(), vr = e();\n        while(l\
    \ < r) {\n            if(l & 1) vl = op(vl, data[l++]);\n            if(r & 1)\
    \ vr = op(data[--r], vr);\n            l >>= 1; r >>= 1;\n        }\n\n      \
    \  return op(vl, vr);\n    }\n\n    void apply(int l, int r, F f) {\n        if(l\
    \ == r) return;\n        l += n; r += n;\n        \n        for(int i = log; i\
    \ >= 1; i--) {\n            if(((l >> i) << i) != l) push(l >> i);\n         \
    \   if(((r >> i) << i) != r) push((r - 1) >> i);\n        }\n\n        {\n   \
    \         int l2 = l, r2 = r;\n            while(l < r) {\n                if(l\
    \ & 1) all_apply(l++, f);\n                if(r & 1) all_apply(--r, f);\n    \
    \            l >>= 1;\n                r >>= 1;\n            }\n            l\
    \ = l2; r = r2;\n        }\n\n        for(int i = 1; i <= log; i++) {\n      \
    \      if(((l >> i) << i) != l) update(l >> i);\n            if(((r >> i) << i)\
    \ != r) update((r - 1) >> i);\n        }\n    }\n\n    inline void update(int\
    \ k) { data[k] = op(data[k << 1], data[k << 1 | 1]); }\n    inline void all_apply(int\
    \ k, F f) {\n        data[k] = mapping(f, data[k]);\n        if(k < n) lazy[k]\
    \ = composition(f, lazy[k]);\n    }\n    inline void push(int k) {\n        all_apply(k\
    \ << 1, lazy[k]);\n        all_apply(k << 1 | 1, lazy[k]);\n        lazy[k] =\
    \ id();\n    }\n};\n"
  code: "template<class S, S (*op)(S, S), S (*e)(), class F, S (*mapping)(F, S), F\
    \ (*composition)(F, F), F (*id)()>\nstruct LazySegmentTree{\n    int n, log;\n\
    \    vector<S> data;\n    vector<F> lazy;\n\n    LazySegmentTree(int n) : LazySegmentTree(vector<S>(n,\
    \ e())) {}\n\n    LazySegmentTree(vector<S> &v) {\n        int sz = v.size();\n\
    \        n = 1; \n        log = 0;\n        while(n < sz) {\n            n <<=\
    \ 1;\n            log++;\n        }\n\n        data.resize(2 * n, e());\n    \
    \    lazy.resize(2 * n, id());\n\n        for(int i = 0; i < sz; i++) data[i +\
    \ n] = v[i];\n        for(int i = n; --i;) data[i] = op(data[i << 1], data[i <<\
    \ 1 | 1]);\n    }\n\n    S prod(int l, int r) {\n        if(l == r) return e();\n\
    \        l += n; r += n;\n\n        for(int i = log; i >= 1; i--) {\n        \
    \    if(((l >> i) << i) != l) push(l >> i);\n            if(((r >> i) << i) !=\
    \ r) push(r >> i);\n        }\n\n        S vl = e(), vr = e();\n        while(l\
    \ < r) {\n            if(l & 1) vl = op(vl, data[l++]);\n            if(r & 1)\
    \ vr = op(data[--r], vr);\n            l >>= 1; r >>= 1;\n        }\n\n      \
    \  return op(vl, vr);\n    }\n\n    void apply(int l, int r, F f) {\n        if(l\
    \ == r) return;\n        l += n; r += n;\n        \n        for(int i = log; i\
    \ >= 1; i--) {\n            if(((l >> i) << i) != l) push(l >> i);\n         \
    \   if(((r >> i) << i) != r) push((r - 1) >> i);\n        }\n\n        {\n   \
    \         int l2 = l, r2 = r;\n            while(l < r) {\n                if(l\
    \ & 1) all_apply(l++, f);\n                if(r & 1) all_apply(--r, f);\n    \
    \            l >>= 1;\n                r >>= 1;\n            }\n            l\
    \ = l2; r = r2;\n        }\n\n        for(int i = 1; i <= log; i++) {\n      \
    \      if(((l >> i) << i) != l) update(l >> i);\n            if(((r >> i) << i)\
    \ != r) update((r - 1) >> i);\n        }\n    }\n\n    inline void update(int\
    \ k) { data[k] = op(data[k << 1], data[k << 1 | 1]); }\n    inline void all_apply(int\
    \ k, F f) {\n        data[k] = mapping(f, data[k]);\n        if(k < n) lazy[k]\
    \ = composition(f, lazy[k]);\n    }\n    inline void push(int k) {\n        all_apply(k\
    \ << 1, lazy[k]);\n        all_apply(k << 1 | 1, lazy[k]);\n        lazy[k] =\
    \ id();\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/lazy_segmemt_tree.hpp
  requiredBy: []
  timestamp: '2024-11-21 06:41:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/yosupo_range_affine_range_sum.test.cpp
documentation_of: data_structure/lazy_segmemt_tree.hpp
layout: document
redirect_from:
- /library/data_structure/lazy_segmemt_tree.hpp
- /library/data_structure/lazy_segmemt_tree.hpp.html
title: data_structure/lazy_segmemt_tree.hpp
---
