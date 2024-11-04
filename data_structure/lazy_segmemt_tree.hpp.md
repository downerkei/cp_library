---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/yosupo/yosupo_range_affine_range_sum.test.cpp
    title: verify/yosupo/yosupo_range_affine_range_sum.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data_structure/lazy_segmemt_tree.hpp\"\ntemplate<class S,\
    \ S (*op)(S, S), S (*e)(), class F, S (*mapping)(F, S), F (*composition)(F, F),\
    \ F (*id)()>\nstruct LazySegmentTree{\n    int n;\n    vector<S> data;\n    vector<F>\
    \ lazy;\n\n    LazySegmentTree(int n_) {\n        n = 1; while(n < n_) n *= 2;\n\
    \        data.resize(2 * n, e());\n        lazy.resize(2 * n, id());\n    }\n\n\
    \    LazySegmentTree(vector<S> &v) {\n        int sz = v.size();\n        n =\
    \ 1; while(n < sz) n *= 2;\n        data.resize(2 * n, e());\n        lazy.resize(2\
    \ * n, id());\n\n        for(int i = 0; i < sz; i++) {\n            data[i+n]\
    \ = v[i];\n        }\n        for(int i = n - 1; i > 0; i--) {\n            data[i]\
    \ = op(data[i<<1], data[i<<1|1]);\n        }\n    }\n\n    void eval(int i) {\n\
    \        if(lazy[i] == id()) return;\n        data[i] = mapping(lazy[i], data[i]);\n\
    \n        if(i < n) {\n            lazy[i<<1] = composition(lazy[i], lazy[i<<1]);\n\
    \            lazy[i<<1|1] = composition(lazy[i], lazy[i<<1|1]);\n        }\n\n\
    \        lazy[i] = id();\n    }\n\n    void apply(int a, int b, F x, int i=1,\
    \ int l=0, int r=-1) {\n        if(r < 0) r = n;\n        eval(i);\n        if(r\
    \ <= a || b <= l) return;\n        if(a <= l && r <= b) {\n            lazy[i]\
    \ = x;\n            eval(i);\n        }\n        else {\n            int mid =\
    \ (l + r) / 2;\n            apply(a, b, x, i << 1, l, mid);\n            apply(a,\
    \ b, x, i << 1 | 1, mid, r);\n            data[i] = op(data[i<<1], data[i<<1|1]);\n\
    \        }\n    }\n\n//     void apply(int l, int r, F f) {\n//         l += n;\
    \ r += n;\n\n//         for(int i = log; i >= 1; i--) {\n//             if(((l\
    \ >> i) << i) != l) eval(l >> i);\n//             if(((r >> i) << i) != r) eval((r\
    \ - 1) >> i);\n//         }\n\n//         int l2 = l, r2 = r;\n//         while(l\
    \ < r) {\n//             if(l & 1) { \n//                 lazy[l] = composition(f,\
    \ lazy[l]);\n//                 eval(l);\n//                 l++;\n//        \
    \     }\n//             if(r & 1) {\n//                 r--;\n//             \
    \    lazy[r] = composition(f, lazy[r]);\n//                 eval(r);\n//     \
    \        }\n//             l >>= 1;\n//             r >>= 1;\n//         }\n//\
    \         l = l2;\n//         r = r2;\n\n//         for(int i = 1; i <= log; i++)\
    \ {\n//             if(((l >> i) << i) != l) data[l>>i] = op(data[l>>(i+1)], data[l>>(i+1)|1]);\n\
    //             if(((r >> i) << i) != r) data[(r-1)>>i] = op(data[(r-1)>>(i+1)],\
    \ data[(r-1)>>(i+1)|1]);\n//         }\n//     }\n\n    S prod(int a, int b, int\
    \ i=1, int l=0, int r=-1) {\n        if(r < 0) r = n;\n        if(r <= a || b\
    \ <= l) return e();\n\n        eval(i);\n        if(a <= l && r <= b) return data[i];\n\
    \        int mid = (l + r) / 2;\n        return op(prod(a, b, i << 1, l, mid),\
    \ prod(a, b, i << 1 | 1, mid, r));\n    }\n\n//     S prod(int l, int r) {\n//\
    \         l += n;\n//         r += n;\n        \n//         for(int i = log; i\
    \ >= 1; i--) {\n//             if(((l >> i) << i) != l) eval(l >> i);\n//    \
    \         if(((r >> i) << i) != r) eval((r - 1) >> i);\n//         }\n\n//   \
    \      S vl = e, vr = e;\n//         while(l < r) {\n//             if(l & 1)\
    \ vl = op(vl, data[l++]);\n//             if(r & 1) vr = op(data[--r], vr);\n\
    //             l >>= 1;\n//             r >>= 1;\n//         }\n\n//         return\
    \ op(vl, vr);\n//     }\n};\n"
  code: "template<class S, S (*op)(S, S), S (*e)(), class F, S (*mapping)(F, S), F\
    \ (*composition)(F, F), F (*id)()>\nstruct LazySegmentTree{\n    int n;\n    vector<S>\
    \ data;\n    vector<F> lazy;\n\n    LazySegmentTree(int n_) {\n        n = 1;\
    \ while(n < n_) n *= 2;\n        data.resize(2 * n, e());\n        lazy.resize(2\
    \ * n, id());\n    }\n\n    LazySegmentTree(vector<S> &v) {\n        int sz =\
    \ v.size();\n        n = 1; while(n < sz) n *= 2;\n        data.resize(2 * n,\
    \ e());\n        lazy.resize(2 * n, id());\n\n        for(int i = 0; i < sz; i++)\
    \ {\n            data[i+n] = v[i];\n        }\n        for(int i = n - 1; i >\
    \ 0; i--) {\n            data[i] = op(data[i<<1], data[i<<1|1]);\n        }\n\
    \    }\n\n    void eval(int i) {\n        if(lazy[i] == id()) return;\n      \
    \  data[i] = mapping(lazy[i], data[i]);\n\n        if(i < n) {\n            lazy[i<<1]\
    \ = composition(lazy[i], lazy[i<<1]);\n            lazy[i<<1|1] = composition(lazy[i],\
    \ lazy[i<<1|1]);\n        }\n\n        lazy[i] = id();\n    }\n\n    void apply(int\
    \ a, int b, F x, int i=1, int l=0, int r=-1) {\n        if(r < 0) r = n;\n   \
    \     eval(i);\n        if(r <= a || b <= l) return;\n        if(a <= l && r <=\
    \ b) {\n            lazy[i] = x;\n            eval(i);\n        }\n        else\
    \ {\n            int mid = (l + r) / 2;\n            apply(a, b, x, i << 1, l,\
    \ mid);\n            apply(a, b, x, i << 1 | 1, mid, r);\n            data[i]\
    \ = op(data[i<<1], data[i<<1|1]);\n        }\n    }\n\n//     void apply(int l,\
    \ int r, F f) {\n//         l += n; r += n;\n\n//         for(int i = log; i >=\
    \ 1; i--) {\n//             if(((l >> i) << i) != l) eval(l >> i);\n//       \
    \      if(((r >> i) << i) != r) eval((r - 1) >> i);\n//         }\n\n//      \
    \   int l2 = l, r2 = r;\n//         while(l < r) {\n//             if(l & 1) {\
    \ \n//                 lazy[l] = composition(f, lazy[l]);\n//                \
    \ eval(l);\n//                 l++;\n//             }\n//             if(r & 1)\
    \ {\n//                 r--;\n//                 lazy[r] = composition(f, lazy[r]);\n\
    //                 eval(r);\n//             }\n//             l >>= 1;\n//   \
    \          r >>= 1;\n//         }\n//         l = l2;\n//         r = r2;\n\n\
    //         for(int i = 1; i <= log; i++) {\n//             if(((l >> i) << i)\
    \ != l) data[l>>i] = op(data[l>>(i+1)], data[l>>(i+1)|1]);\n//             if(((r\
    \ >> i) << i) != r) data[(r-1)>>i] = op(data[(r-1)>>(i+1)], data[(r-1)>>(i+1)|1]);\n\
    //         }\n//     }\n\n    S prod(int a, int b, int i=1, int l=0, int r=-1)\
    \ {\n        if(r < 0) r = n;\n        if(r <= a || b <= l) return e();\n\n  \
    \      eval(i);\n        if(a <= l && r <= b) return data[i];\n        int mid\
    \ = (l + r) / 2;\n        return op(prod(a, b, i << 1, l, mid), prod(a, b, i <<\
    \ 1 | 1, mid, r));\n    }\n\n//     S prod(int l, int r) {\n//         l += n;\n\
    //         r += n;\n        \n//         for(int i = log; i >= 1; i--) {\n// \
    \            if(((l >> i) << i) != l) eval(l >> i);\n//             if(((r >>\
    \ i) << i) != r) eval((r - 1) >> i);\n//         }\n\n//         S vl = e, vr\
    \ = e;\n//         while(l < r) {\n//             if(l & 1) vl = op(vl, data[l++]);\n\
    //             if(r & 1) vr = op(data[--r], vr);\n//             l >>= 1;\n//\
    \             r >>= 1;\n//         }\n\n//         return op(vl, vr);\n//    \
    \ }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/lazy_segmemt_tree.hpp
  requiredBy: []
  timestamp: '2024-06-27 08:22:20+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/yosupo/yosupo_range_affine_range_sum.test.cpp
documentation_of: data_structure/lazy_segmemt_tree.hpp
layout: document
redirect_from:
- /library/data_structure/lazy_segmemt_tree.hpp
- /library/data_structure/lazy_segmemt_tree.hpp.html
title: data_structure/lazy_segmemt_tree.hpp
---
