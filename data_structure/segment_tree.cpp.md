---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data_structure/segment_tree.cpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\nconst int MOD = 998244353;\n\nusing S = pair<long long,\
    \ long long>;\nS op(S l, S r) { return {l.first * r.first % MOD, (r.first * l.second\
    \ % MOD + r.second) % MOD}; }\nconstexpr S e = {1, 0};\n\ntemplate<class S, S\
    \ (*op)(S, S), S e>\nstruct SegmentTree{\n    int n;\n    vector<S> data;\n\n\
    \    SegmentTree(int sz=0) : n(1) {\n        while(n < sz) n *= 2;\n        data.resize(2\
    \ * n, e);\n    }\n\n    SegmentTree(const vector<S> &V) : n(1) {\n        int\
    \ sz = V.size();\n        while(n < sz) n *= 2;\n        data.resize(2 * n, e);\n\
    \        for(int i = 0; i < sz; i++) data[i+n] = V[i];\n        for(int i = n\
    \ - 1; i >= 1; i--) data[i] = op(data[i<<1], data[i<<1|1]);\n    }\n\n    void\
    \ set(int i, S x) {\n        i += n;\n        data[i] = x;\n        while(i >\
    \ 1) {\n            i >>= 1;\n            data[i] = op(data[i<<1], data[i<<1|1]);\n\
    \        }\n    }\n\n    S prod(int l, int r) {\n        l += n; r += n;\n   \
    \     S vl = e, vr = e;\n        while(l < r) {\n            if(l & 1) vl = op(vl,\
    \ data[l++]);\n            if(r & 1) vr = op(data[--r], vr);\n            l >>=\
    \ 1; r >>= 1;\n        }\n        return op(vl, vr);\n    }\n};\n\nint main()\
    \ {\n    int N, Q;\n    cin >> N >> Q;\n    SegmentTree<S, op, e> seg(N);\n  \
    \  for(int i = 0; i < N; i++) {\n        long long a, b;\n        cin >> a >>\
    \ b;\n        seg.set(i, {a, b});\n    }\n\n    while(Q--) {\n        int c;\n\
    \        cin >> c;\n        if(c == 0) {\n            long long p, c, d;\n   \
    \         cin >> p >> c >> d;\n            seg.set(p, {c, d});\n        }\n  \
    \      if(c == 1) {\n            long long l, r, x;\n            cin >> l >> r\
    \ >> x;\n            auto [a, b] = seg.prod(l, r);\n            cout << (a * x\
    \ % MOD + b) % MOD << endl;\n        }\n    }\n\n    return 0;\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\nconst int MOD = 998244353;\n\
    \nusing S = pair<long long, long long>;\nS op(S l, S r) { return {l.first * r.first\
    \ % MOD, (r.first * l.second % MOD + r.second) % MOD}; }\nconstexpr S e = {1,\
    \ 0};\n\ntemplate<class S, S (*op)(S, S), S e>\nstruct SegmentTree{\n    int n;\n\
    \    vector<S> data;\n\n    SegmentTree(int sz=0) : n(1) {\n        while(n <\
    \ sz) n *= 2;\n        data.resize(2 * n, e);\n    }\n\n    SegmentTree(const\
    \ vector<S> &V) : n(1) {\n        int sz = V.size();\n        while(n < sz) n\
    \ *= 2;\n        data.resize(2 * n, e);\n        for(int i = 0; i < sz; i++) data[i+n]\
    \ = V[i];\n        for(int i = n - 1; i >= 1; i--) data[i] = op(data[i<<1], data[i<<1|1]);\n\
    \    }\n\n    void set(int i, S x) {\n        i += n;\n        data[i] = x;\n\
    \        while(i > 1) {\n            i >>= 1;\n            data[i] = op(data[i<<1],\
    \ data[i<<1|1]);\n        }\n    }\n\n    S prod(int l, int r) {\n        l +=\
    \ n; r += n;\n        S vl = e, vr = e;\n        while(l < r) {\n            if(l\
    \ & 1) vl = op(vl, data[l++]);\n            if(r & 1) vr = op(data[--r], vr);\n\
    \            l >>= 1; r >>= 1;\n        }\n        return op(vl, vr);\n    }\n\
    };\n\nint main() {\n    int N, Q;\n    cin >> N >> Q;\n    SegmentTree<S, op,\
    \ e> seg(N);\n    for(int i = 0; i < N; i++) {\n        long long a, b;\n    \
    \    cin >> a >> b;\n        seg.set(i, {a, b});\n    }\n\n    while(Q--) {\n\
    \        int c;\n        cin >> c;\n        if(c == 0) {\n            long long\
    \ p, c, d;\n            cin >> p >> c >> d;\n            seg.set(p, {c, d});\n\
    \        }\n        if(c == 1) {\n            long long l, r, x;\n           \
    \ cin >> l >> r >> x;\n            auto [a, b] = seg.prod(l, r);\n           \
    \ cout << (a * x % MOD + b) % MOD << endl;\n        }\n    }\n\n    return 0;\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/segment_tree.cpp
  requiredBy: []
  timestamp: '2024-06-21 02:11:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/segment_tree.cpp
layout: document
redirect_from:
- /library/data_structure/segment_tree.cpp
- /library/data_structure/segment_tree.cpp.html
title: data_structure/segment_tree.cpp
---
