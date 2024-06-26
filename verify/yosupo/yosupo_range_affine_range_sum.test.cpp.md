---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/lazy_segmemt_tree.hpp
    title: data_structure/lazy_segmemt_tree.hpp
  - icon: ':heavy_check_mark:'
    path: data_structure/static_modint.hpp
    title: data_structure/static_modint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_affine_range_sum
  bundledCode: "#line 1 \"verify/yosupo/yosupo_range_affine_range_sum.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\n\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"data_structure/lazy_segmemt_tree.hpp\"\
    \ntemplate<class S, S (*op)(S, S), S (*e)(), class F, S (*mapping)(F, S), F (*composition)(F,\
    \ F), F (*id)()>\nstruct LazySegmentTree{\n    int n;\n    vector<S> data;\n \
    \   vector<F> lazy;\n\n    LazySegmentTree(int n_) {\n        n = 1; while(n <\
    \ n_) n *= 2;\n        data.resize(2 * n, e());\n        lazy.resize(2 * n, id());\n\
    \    }\n\n    LazySegmentTree(vector<S> &v) {\n        int sz = v.size();\n  \
    \      n = 1; while(n < sz) n *= 2;\n        data.resize(2 * n, e());\n      \
    \  lazy.resize(2 * n, id());\n\n        for(int i = 0; i < sz; i++) {\n      \
    \      data[i+n] = v[i];\n        }\n        for(int i = n - 1; i > 0; i--) {\n\
    \            data[i] = op(data[i<<1], data[i<<1|1]);\n        }\n    }\n\n   \
    \ void eval(int i) {\n        if(lazy[i] == id()) return;\n        data[i] = mapping(lazy[i],\
    \ data[i]);\n\n        if(i < n) {\n            lazy[i<<1] = composition(lazy[i],\
    \ lazy[i<<1]);\n            lazy[i<<1|1] = composition(lazy[i], lazy[i<<1|1]);\n\
    \        }\n\n        lazy[i] = id();\n    }\n\n    void apply(int a, int b, F\
    \ x, int i=1, int l=0, int r=-1) {\n        if(r < 0) r = n;\n        eval(i);\n\
    \        if(r <= a || b <= l) return;\n        if(a <= l && r <= b) {\n      \
    \      lazy[i] = x;\n            eval(i);\n        }\n        else {\n       \
    \     int mid = (l + r) / 2;\n            apply(a, b, x, i << 1, l, mid);\n  \
    \          apply(a, b, x, i << 1 | 1, mid, r);\n            data[i] = op(data[i<<1],\
    \ data[i<<1|1]);\n        }\n    }\n\n//     void apply(int l, int r, F f) {\n\
    //         l += n; r += n;\n\n//         for(int i = log; i >= 1; i--) {\n// \
    \            if(((l >> i) << i) != l) eval(l >> i);\n//             if(((r >>\
    \ i) << i) != r) eval((r - 1) >> i);\n//         }\n\n//         int l2 = l, r2\
    \ = r;\n//         while(l < r) {\n//             if(l & 1) { \n//           \
    \      lazy[l] = composition(f, lazy[l]);\n//                 eval(l);\n//   \
    \              l++;\n//             }\n//             if(r & 1) {\n//        \
    \         r--;\n//                 lazy[r] = composition(f, lazy[r]);\n//    \
    \             eval(r);\n//             }\n//             l >>= 1;\n//        \
    \     r >>= 1;\n//         }\n//         l = l2;\n//         r = r2;\n\n//   \
    \      for(int i = 1; i <= log; i++) {\n//             if(((l >> i) << i) != l)\
    \ data[l>>i] = op(data[l>>(i+1)], data[l>>(i+1)|1]);\n//             if(((r >>\
    \ i) << i) != r) data[(r-1)>>i] = op(data[(r-1)>>(i+1)], data[(r-1)>>(i+1)|1]);\n\
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
    \ }\n};\n#line 1 \"data_structure/static_modint.hpp\"\ntemplate<int m=998244353>\
    \ struct StaticModint {\n    using mint = StaticModint;\n    int _v;\n\n    constexpr\
    \ StaticModint() : _v(0) {}\n    template<class T>\n    constexpr StaticModint(T\
    \ v) : _v((v % m + m) % m) {}\n\n    constexpr int val() const { return _v; }\n\
    \n    constexpr mint& operator ++ () { return *this += 1; }\n    constexpr mint&\
    \ operator -- () { return *this -= 1; }\n    constexpr mint operator ++ (int)\
    \ { mint res = *this; ++*this; return res; }\n    constexpr mint operator -- (int)\
    \ { mint res = *this; --*this; return res; }\n\n    constexpr mint& operator +=\
    \ (const mint& r) {\n        if(_v >= m - r._v) _v -= m;\n        _v += r._v;\
    \ return *this;\n    }\n    constexpr mint& operator -= (const mint& r) {\n  \
    \      if(_v < r._v) _v += m;\n        _v -= r._v; return *this;\n    }\n    constexpr\
    \ mint& operator *= (const mint& r) {\n        unsigned long long z = _v;\n  \
    \      z *= r._v;\n        _v = (unsigned int)(z % m); return *this;\n    }\n\
    \    constexpr mint& operator /= (const mint& r) {\n        return *this *= r.inv();\
    \ \n    }\n\n    constexpr mint pow(long long n) const {\n        mint x = *this,\
    \ r = 1; \n        while(n) {\n            if(n & 1) r *= x;\n            x *=\
    \ x;\n            n >>= 1;\n        }\n        return r;\n    }\n    constexpr\
    \ mint inv() const {\n        return pow(m - 2);\n    }\n\n    constexpr mint\
    \ operator + () const { return *this; }\n    constexpr mint operator - () const\
    \ { return mint() - *this; }\n\n    constexpr mint operator + (const mint& r)\
    \ const { return mint(*this) += r; }\n    constexpr mint operator - (const mint&\
    \ r) const { return mint(*this) -= r; }\n    constexpr mint operator * (const\
    \ mint& r) const { return mint(*this) *= r; }\n    constexpr mint operator / (const\
    \ mint& r) const { return mint(*this) /= r; }\n    \n    constexpr bool operator\
    \ == (const mint& r) const { return _v == r._v; }\n    constexpr bool operator\
    \ != (const mint& r) const { return _v != r._v; }\n\n    friend istream& operator\
    \ >> (istream& is, mint& x) {\n        long long t;\n        is >> t;\n      \
    \  x = mint(t);\n        return is;\n    }\n    friend ostream& operator << (ostream&\
    \ os, const mint& x) {\n        return os << x._v;\n    }\n};\n#line 8 \"verify/yosupo/yosupo_range_affine_range_sum.test.cpp\"\
    \n\nusing mint = StaticModint<998244353>;\n\nusing S = pair<mint, mint>;\nS op(S\
    \ l, S r) { return {l.first + r.first, l.second + r.second}; }\nS e() { return\
    \ {0, 0}; }\nusing F = pair<mint, mint>;\nS mapping(F f, S x) { return {x.first\
    \ * f.first + x.second * f.second, x.second}; }\nF composition(F f, F g) { return\
    \ {f.first * g.first, f.first * g.second + f.second}; }\nF id() { return {1, 0};\
    \ }\n\nint main() {\n    int N, Q;\n    cin >> N >> Q;\n    vector<S> A(N);\n\
    \    for(int i = 0; i < N; i++) {\n        int a;\n        cin >> a;\n       \
    \ A[i] = {a, 1};\n    }\n\n    LazySegmentTree<S, op, e, F, mapping, composition,\
    \ id> seg(A);\n\n    while(Q--) {\n        int q;\n        cin >> q;\n       \
    \ if(q == 0) {\n            int l, r, b, c;\n            cin >> l >> r >> b >>\
    \ c;\n            seg.apply(l, r, {b, c});\n        }\n        if(q == 1) {\n\
    \            int l, r;\n            cin >> l >> r;\n            cout << seg.prod(l,\
    \ r).first << endl;\n        }\n    }\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../data_structure/lazy_segmemt_tree.hpp\"\
    \n#include \"../../data_structure/static_modint.hpp\"\n\nusing mint = StaticModint<998244353>;\n\
    \nusing S = pair<mint, mint>;\nS op(S l, S r) { return {l.first + r.first, l.second\
    \ + r.second}; }\nS e() { return {0, 0}; }\nusing F = pair<mint, mint>;\nS mapping(F\
    \ f, S x) { return {x.first * f.first + x.second * f.second, x.second}; }\nF composition(F\
    \ f, F g) { return {f.first * g.first, f.first * g.second + f.second}; }\nF id()\
    \ { return {1, 0}; }\n\nint main() {\n    int N, Q;\n    cin >> N >> Q;\n    vector<S>\
    \ A(N);\n    for(int i = 0; i < N; i++) {\n        int a;\n        cin >> a;\n\
    \        A[i] = {a, 1};\n    }\n\n    LazySegmentTree<S, op, e, F, mapping, composition,\
    \ id> seg(A);\n\n    while(Q--) {\n        int q;\n        cin >> q;\n       \
    \ if(q == 0) {\n            int l, r, b, c;\n            cin >> l >> r >> b >>\
    \ c;\n            seg.apply(l, r, {b, c});\n        }\n        if(q == 1) {\n\
    \            int l, r;\n            cin >> l >> r;\n            cout << seg.prod(l,\
    \ r).first << endl;\n        }\n    }\n\n    return 0;\n}\n"
  dependsOn:
  - data_structure/lazy_segmemt_tree.hpp
  - data_structure/static_modint.hpp
  isVerificationFile: true
  path: verify/yosupo/yosupo_range_affine_range_sum.test.cpp
  requiredBy: []
  timestamp: '2024-06-27 08:22:20+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/yosupo_range_affine_range_sum.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/yosupo_range_affine_range_sum.test.cpp
- /verify/verify/yosupo/yosupo_range_affine_range_sum.test.cpp.html
title: verify/yosupo/yosupo_range_affine_range_sum.test.cpp
---
