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
    \ F), F (*id)()>\nstruct LazySegmentTree{\n    int n, log;\n    vector<S> data;\n\
    \    vector<F> lazy;\n\n    LazySegmentTree(int n) : LazySegmentTree(vector<S>(n,\
    \ e())) {}\n\n    LazySegmentTree(const vector<S> &v) {\n        int sz = v.size();\n\
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
    \ id();\n    }\n};\n#line 1 \"data_structure/static_modint.hpp\"\ntemplate<int\
    \ m> struct StaticModint {\n    using mint = StaticModint;\n    int _v;\n\n  \
    \  constexpr StaticModint() : _v(0) {}\n    template<class T>\n    constexpr StaticModint(T\
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
    \ os, const mint& x) {\n        return os << x._v;\n    }\n};\n\n// using mint\
    \ = StaticModint<998244353>;\n// using mint = StaticModint<1000000007>;\n#line\
    \ 8 \"verify/yosupo/yosupo_range_affine_range_sum.test.cpp\"\n\nusing mint = StaticModint<998244353>;\n\
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
  dependsOn:
  - data_structure/lazy_segmemt_tree.hpp
  - data_structure/static_modint.hpp
  isVerificationFile: true
  path: verify/yosupo/yosupo_range_affine_range_sum.test.cpp
  requiredBy: []
  timestamp: '2024-12-04 23:54:58+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/yosupo_range_affine_range_sum.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/yosupo_range_affine_range_sum.test.cpp
- /verify/verify/yosupo/yosupo_range_affine_range_sum.test.cpp.html
title: verify/yosupo/yosupo_range_affine_range_sum.test.cpp
---
