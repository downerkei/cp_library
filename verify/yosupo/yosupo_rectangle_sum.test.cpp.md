---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/persistent_segment_tree.hpp
    title: data_structure/persistent_segment_tree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/rectangle_sum
    links:
    - https://judge.yosupo.jp/problem/rectangle_sum
  bundledCode: "#line 1 \"verify/yosupo/yosupo_rectangle_sum.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/rectangle_sum\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#line 1 \"data_structure/persistent_segment_tree.hpp\"\
    \ntemplate<class S, S (*op)(S, S), S (*e)(), int NODES = 10'000'000>\nstruct PersistentSegmentTree\
    \ {\n    struct Node {\n        S d;\n        Node* l, *r;\n    };\n\n    PersistentSegmentTree(const\
    \ vector<S>& v) : pid(0), n(v.size()) {\n        pool = new Node[NODES];\n   \
    \     nil = my_new(e());\n        nil->l = nil->r = nil;\n        roots.reserve(262144);\n\
    \        roots.push_back(build(0, v.size(), v));\n    }\n\n    PersistentSegmentTree(int\
    \ n) : pid(0), n(n) {\n        pool = new Node[NODES];\n        nil = my_new(e());\n\
    \        nil->l = nil->r = nil;\n        roots.reserve(262144);\n        roots.push_back(nil);\n\
    \    }\n\n    ~PersistentSegmentTree() { delete[] pool; }\n\n    Node* set(int\
    \ p, const S& x) {\n        Node* root = set(p, x, roots.back(), 0, n);\n    \
    \    roots.push_back(root);\n        return root;\n    }\n    Node* set(int t,\
    \ int p, const S& x) {\n        Node* root = set(p, x, roots[t], 0, n);\n    \
    \    roots.push_back(root);\n        return root;\n    }\n\n    Node* add(int\
    \ p, const S& x) {\n        Node* root = add(p, x, roots.back(), 0, n);\n    \
    \    roots.push_back(root);\n        return root;\n    }\n    Node* add(int t,\
    \ int p, const S& x) {\n        Node* root = add(p, x, roots[t], 0, n);\n    \
    \    roots.push_back(root);\n        return root;\n    }\n\n    S prod(int l,\
    \ int r) { return prod(l, r, roots.back(), 0, n); }\n    S prod(int t, int l,\
    \ int r) { return prod(l, r, roots[t], 0, n); }\n\n  private:\n    Node* pool;\n\
    \    int pid;\n    int n;\n    Node* nil;\n    vector<Node*> roots;\n\n    Node*\
    \ my_new(const S& d) {\n        pool[pid].d = d;\n        pool[pid].l = pool[pid].r\
    \ = nil;\n        return &(pool[pid++]);\n    }\n    \n    Node* merge(Node* l,\
    \ Node* r) {\n        pool[pid].d = op(l->d, r->d);\n        pool[pid].l = l;\n\
    \        pool[pid].r = r;\n        return &(pool[pid++]);\n    }\n\n    Node*\
    \ build(int l, int r, const vector<S>& v) {\n        if(l + 1 == r) return my_new(v[l]);\n\
    \        int m = (l + r) >> 1;\n        return merge(build(l, m, v), build(m,\
    \ r, v));\n    }\n\n    Node* set(int p, const S& x, Node* n, int l, int r) {\n\
    \        if(l + 1 == r) return my_new(x);\n        int m = (l + r) >> 1;\n   \
    \     if(p < m) return merge(set(p, x, n->l, l, m), n->r);\n        return merge(n->l,\
    \ set(p, x, n->r, m, r));\n    }\n\n    Node* add(int p, const S& x, Node* n,\
    \ int l, int r) {\n        if(l + 1 == r) return my_new(op(n->d, x));\n      \
    \  int m = (l + r) >> 1;\n        if(p < m) return merge(add(p, x, n->l, l, m),\
    \ n->r);\n        return merge(n->l, add(p, x, n->r, m, r));\n    }\n\n    S prod(int\
    \ a, int b, Node* n, int l, int r) {\n        if(n == nil) return e();\n     \
    \   if(r <= a || b <= l) return e();\n        if(a <= l && r <= b) return n->d;\n\
    \        int m = (l + r) >> 1;\n        return op(prod(a, b, n->l, l, m), prod(a,\
    \ b, n->r, m, r));\n    }\n};\n#line 7 \"verify/yosupo/yosupo_rectangle_sum.test.cpp\"\
    \n\nusing S = long long;\nS op(S l, S r) { return l + r; }\nS e() { return 0;\
    \ }\n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \    int N, Q;\n    cin >> N >> Q;\n    \n    vector<array<int, 3>> ps(N);\n \
    \   for(int i = 0; i < N; i++) {\n        cin >> ps[i][0] >> ps[i][1] >> ps[i][2];\n\
    \    }\n\n    sort(ps.begin(), ps.end());\n\n    vector<int> xs(N);\n    for(int\
    \ i = 0; i < N; i++) {\n        xs[i] = ps[i][0];\n    }\n\n    vector<int> ord(N);\n\
    \    iota(ord.begin(), ord.end(), 0);\n    sort(ord.begin(), ord.end(), [&](int\
    \ i, int j) { return ps[i][1] < ps[j][1]; });\n\n    PersistentSegmentTree<S,\
    \ op, e> seg(N);\n\n    vector<int> ys;\n    for(int i : ord) {\n        seg.add(i,\
    \ ps[i][2]);\n        ys.push_back(ps[i][1]);\n    }\n\n    while(Q--) {\n   \
    \     int l, d, r, u;\n        cin >> l >> d >> r >> u;\n        int li = lower_bound(xs.begin(),\
    \ xs.end(), l) - xs.begin();\n        int ri = lower_bound(xs.begin(), xs.end(),\
    \ r) - xs.begin();\n        int di = lower_bound(ys.begin(), ys.end(), d) - ys.begin();\n\
    \        int ui = lower_bound(ys.begin(), ys.end(), u) - ys.begin();\n       \
    \ cout << seg.prod(ui, li, ri) - seg.prod(di, li, ri) << \"\\n\";\n    }\n\n\n\
    \    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/rectangle_sum\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../data_structure/persistent_segment_tree.hpp\"\
    \n\nusing S = long long;\nS op(S l, S r) { return l + r; }\nS e() { return 0;\
    \ }\n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \    int N, Q;\n    cin >> N >> Q;\n    \n    vector<array<int, 3>> ps(N);\n \
    \   for(int i = 0; i < N; i++) {\n        cin >> ps[i][0] >> ps[i][1] >> ps[i][2];\n\
    \    }\n\n    sort(ps.begin(), ps.end());\n\n    vector<int> xs(N);\n    for(int\
    \ i = 0; i < N; i++) {\n        xs[i] = ps[i][0];\n    }\n\n    vector<int> ord(N);\n\
    \    iota(ord.begin(), ord.end(), 0);\n    sort(ord.begin(), ord.end(), [&](int\
    \ i, int j) { return ps[i][1] < ps[j][1]; });\n\n    PersistentSegmentTree<S,\
    \ op, e> seg(N);\n\n    vector<int> ys;\n    for(int i : ord) {\n        seg.add(i,\
    \ ps[i][2]);\n        ys.push_back(ps[i][1]);\n    }\n\n    while(Q--) {\n   \
    \     int l, d, r, u;\n        cin >> l >> d >> r >> u;\n        int li = lower_bound(xs.begin(),\
    \ xs.end(), l) - xs.begin();\n        int ri = lower_bound(xs.begin(), xs.end(),\
    \ r) - xs.begin();\n        int di = lower_bound(ys.begin(), ys.end(), d) - ys.begin();\n\
    \        int ui = lower_bound(ys.begin(), ys.end(), u) - ys.begin();\n       \
    \ cout << seg.prod(ui, li, ri) - seg.prod(di, li, ri) << \"\\n\";\n    }\n\n\n\
    \    return 0;\n}"
  dependsOn:
  - data_structure/persistent_segment_tree.hpp
  isVerificationFile: true
  path: verify/yosupo/yosupo_rectangle_sum.test.cpp
  requiredBy: []
  timestamp: '2025-02-18 22:39:17+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/yosupo_rectangle_sum.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/yosupo_rectangle_sum.test.cpp
- /verify/verify/yosupo/yosupo_rectangle_sum.test.cpp.html
title: verify/yosupo/yosupo_rectangle_sum.test.cpp
---
