---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/lazy_reversible_splay_tree.hpp
    title: "\u9045\u5EF6\u4F1D\u642C\u53CD\u8EE2\u53EF\u80FD\u30B9\u30D7\u30EC\u30FC\
      \u6728"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum
  bundledCode: "#line 1 \"verify/yosupo/yosupo_dynamic_sequence_range_affine_range_sum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"data_structure/lazy_reversible_splay_tree.hpp\"\
    \ntemplate<class S,\n         S (*op)(S, S),\n         S (*e)(), \n         void\
    \ (*reverse_prod)(S&), \n         class F, \n         S (*mapping)(F, S), \n \
    \        F (*composition)(F, F), \n         F (*id)()>\nstruct LazyReversibleSplayTree{\n\
    \    struct Node{\n        Node* l = nullptr;\n        Node* r = nullptr;\n  \
    \      Node* p = nullptr;\n        S val = e();\n        S prod = e();\n     \
    \   F f = id();\n        int i = -1;\n        int sz = 1;\n        int rev = 0;\n\
    \        Node(S x) : val(x), prod(x) {}\n    };\n\n    Node* root = nullptr;\n\
    \    vector<Node*> A;\n\n    void right_rotate(Node* v) {\n        Node* u = v->l;\n\
    \        v->l = u->r;\n        if (u->r) u->r->p = v;\n        u->p = v->p;\n\
    \        if (!v->p) root = u;\n        else if (v == v->p->l) v->p->l = u;\n \
    \       else v->p->r = u;\n        u->r = v;\n        v->p = u;\n    }\n\n   \
    \ void left_rotate(Node* v) {\n        Node* u = v->r;\n        v->r = u->l;\n\
    \        if (u->l) u->l->p = v;\n        u->p = v->p;\n        if (!v->p) root\
    \ = u;\n        else if (v == v->p->l) v->p->l = u;\n        else v->p->r = u;\n\
    \        u->l = v;\n        v->p = u;\n    }\n\n    void splay(Node* v) {\n  \
    \      if(!v) return;\n        propagate(v);\n        while (v->p) {\n       \
    \     Node* p = v->p;\n            Node* g = p->p;\n            if(g) propagate(g);\n\
    \            propagate(p);\n            propagate(v);\n            if (!g) { //\
    \ zig\n                if (p->l == v) right_rotate(p);\n                else left_rotate(p);\n\
    \            } else if (p->l == v && g->l == p) { // zigzig\n                right_rotate(g);\n\
    \                right_rotate(p);\n            } else if (p->r == v && g->r ==\
    \ p) { // zigzig\n                left_rotate(g);\n                left_rotate(p);\n\
    \            } else if (p->l == v && g->r == p) { // zigzag\n                right_rotate(p);\n\
    \                left_rotate(g);\n            } else { // zigzag\n           \
    \     left_rotate(p);\n                right_rotate(g);\n            }\n     \
    \       if(g) all_apply(g);\n            all_apply(p);\n            all_apply(v);\n\
    \        }\n        all_apply(v);\n    }\n\n    void propagate(Node* v) {\n  \
    \      if(!v) return;\n        if(v->l) {\n            v->l->val = mapping(v->f,\
    \ v->l->val);\n            v->l->prod = mapping(v->f, v->l->prod);\n         \
    \   v->l->f = composition(v->f, v->l->f);\n        }\n        if(v->r) {\n   \
    \         v->r->val = mapping(v->f, v->r->val);\n            v->r->prod = mapping(v->f,\
    \ v->r->prod);\n            v->r->f = composition(v->f, v->r->f);\n        }\n\
    \        if(v->rev) {\n            swap(v->l, v->r);\n            if(v->l) {\n\
    \                v->l->rev ^= 1;\n                reverse_prod(v->l->prod);\n\
    \            }\n            if(v->r) {\n                v->r->rev ^= 1;\n    \
    \            reverse_prod(v->r->prod);\n            }\n            v->rev = 0;\n\
    \        }\n        v->f = id();\n    }\n\n    void all_apply(Node* v) {\n   \
    \     v->sz = 1;\n        if(v->l) v->sz += v->l->sz;\n        if(v->r) v->sz\
    \ += v->r->sz;\n        v->prod = e();\n        if(v->l) v->prod = op(v->prod,\
    \ v->l->prod);\n        v->prod = op(v->prod, v->val);\n        if(v->r) v->prod\
    \ = op(v->prod, v->r->prod);\n    }\n\n    Node* kth_element(int k) {\n      \
    \  Node* cur = root;\n        while(cur) {\n            propagate(cur);\n    \
    \        if(!cur->l && k == 0) break;\n            if(cur->l && cur->l->sz ==\
    \ k) break;\n            else if(cur->l && cur->l->sz > k) cur = cur->l;\n   \
    \         else {\n                k -= 1;\n                if(cur->l) k -= cur->l->sz;\n\
    \                cur = cur->r;\n            }\n        }\n        propagate(cur);\n\
    \        splay(cur);\n        return cur;\n    }\n\n    void insert_at(int k,\
    \ S x) {\n        Node* nv = new Node(x);\n        nv->i = A.size();\n       \
    \ A.push_back(nv);\n        if(k == 0) {\n            nv->r = root;\n        \
    \    if(root) root->p = nv;\n            root = nv;\n            all_apply(nv);\n\
    \            return;\n        }\n        if(root && k == root->sz) {\n       \
    \     nv->l = root;\n            if(root) root->p = nv;\n            root = nv;\n\
    \            all_apply(nv);\n            return;\n        }\n        Node* p =\
    \ kth_element(k);\n        nv->l = p->l;\n        nv->r = p;\n        root = nv;\n\
    \        if(nv->l) nv->l->p = nv;\n        p->p = nv;\n        p->l = nullptr;\n\
    \        all_apply(p);\n        all_apply(nv);\n    }\n\n    void erase_at(int\
    \ k) {\n        Node* p = kth_element(k);\n        if(k == 0) {\n            root\
    \ = p->r;\n            if(root) root->p = nullptr;\n        }\n        else if(root\
    \ && k == root->sz - 1) {\n            root = p->l;\n            if(root) root->p\
    \ = nullptr;\n        }\n        else {\n            Node* l = p->l;\n       \
    \     Node* r = p->r;\n            r->p = nullptr;\n            root = r;\n  \
    \          kth_element(0);\n            r = root;\n            r->l = l;\n   \
    \         l->p = r;\n            all_apply(r);\n        }\n        swap(p->i,\
    \ A.back()->i);\n        swap(A[p->i], A[A.back()->i]);\n        A.pop_back();\n\
    \        delete p;\n    }\n\n    Node* between(int l, int r) {\n        if(l ==\
    \ 0 && r == root->sz) return root;\n        if(l == 0) return kth_element(r)->l;\n\
    \        if(r == root->sz) return kth_element(l - 1)->r;\n        Node* rp = kth_element(r);\n\
    \        Node* lp = rp->l;\n        root = lp;\n        lp->p = nullptr;\n   \
    \     lp = kth_element(l - 1);\n        root = rp;\n        rp->l = lp;\n    \
    \    lp->p = rp;\n        all_apply(rp);\n        return lp->r;\n    }\n\n   \
    \ void reverse(int l, int r) {\n        Node* v = between(l, r);\n        v->rev\
    \ ^= 1;\n        reverse_prod(v->prod);\n        splay(v);\n    }\n\n    void\
    \ apply(int l, int r, F f) {\n        Node* v = between(l, r);\n        v->val\
    \ = mapping(f, v->val);\n        v->prod = mapping(f, v->prod);\n        v->f\
    \ = composition(f, v->f);\n        splay(v);\n    }\n\n    S prod(int l, int r)\
    \ {\n        return between(l, r)->prod;\n    }\n\n    int size() {\n        if(!root)\
    \ return 0;\n        return root->sz;\n    }\n\n    S get(int k) {\n        return\
    \ prod(k, k + 1);\n    }\n};\n#line 7 \"verify/yosupo/yosupo_dynamic_sequence_range_affine_range_sum.test.cpp\"\
    \n\nconstexpr int MOD = 998244353;\n\nusing S = pair<long long, long long>;\n\
    using F = pair<long long, long long>;\nS op(S l, S r) { return {(l.first + r.first)\
    \ % MOD, l.second + r.second}; }\nS e() { return S(0, 0); }\nvoid reverse_prod(S&\
    \ x) {}\nS mapping(F f, S x) { return {(x.first * f.first + x.second * f.second)\
    \ % MOD, x.second}; }\nF composition(F f, F g) { return {(f.first * g.first) %\
    \ MOD, (f.first * g.second + f.second) % MOD}; }\nF id() { return F(1, 0); }\n\
    \nvoid solve() {\n    int N, Q;\n    cin >> N >> Q;\n    LazyReversibleSplayTree<S,\
    \ op, e, reverse_prod, F, mapping, composition, id> st;\n    for(int i = 0; i\
    \ < N; i++) {\n        int a;\n        cin >> a;\n        st.insert_at(i, {a,\
    \ 1});\n    }\n    while(Q--) {\n        int t;\n        cin >> t;\n        if(t\
    \ == 0) {\n            int i, x;\n            cin >> i >> x;\n            st.insert_at(i,\
    \ {x, 1});\n        }\n        if(t == 1) {\n            int i;\n            cin\
    \ >> i;\n            st.erase_at(i);\n        }\n        if(t == 2) {\n      \
    \      int l, r;\n            cin >> l >> r;\n            st.reverse(l, r);\n\
    \        }\n        if(t == 3) {\n            int l, r, b, c;\n            cin\
    \ >> l >> r >> b >> c;\n            st.apply(l, r, {b, c});\n        }\n     \
    \   if(t == 4) {\n            int l, r;\n            cin >> l >> r;\n        \
    \    cout << st.prod(l, r).first << endl;\n        }\n    }\n}\n\nint main() {\n\
    \    solve();\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../data_structure/lazy_reversible_splay_tree.hpp\"\
    \n\nconstexpr int MOD = 998244353;\n\nusing S = pair<long long, long long>;\n\
    using F = pair<long long, long long>;\nS op(S l, S r) { return {(l.first + r.first)\
    \ % MOD, l.second + r.second}; }\nS e() { return S(0, 0); }\nvoid reverse_prod(S&\
    \ x) {}\nS mapping(F f, S x) { return {(x.first * f.first + x.second * f.second)\
    \ % MOD, x.second}; }\nF composition(F f, F g) { return {(f.first * g.first) %\
    \ MOD, (f.first * g.second + f.second) % MOD}; }\nF id() { return F(1, 0); }\n\
    \nvoid solve() {\n    int N, Q;\n    cin >> N >> Q;\n    LazyReversibleSplayTree<S,\
    \ op, e, reverse_prod, F, mapping, composition, id> st;\n    for(int i = 0; i\
    \ < N; i++) {\n        int a;\n        cin >> a;\n        st.insert_at(i, {a,\
    \ 1});\n    }\n    while(Q--) {\n        int t;\n        cin >> t;\n        if(t\
    \ == 0) {\n            int i, x;\n            cin >> i >> x;\n            st.insert_at(i,\
    \ {x, 1});\n        }\n        if(t == 1) {\n            int i;\n            cin\
    \ >> i;\n            st.erase_at(i);\n        }\n        if(t == 2) {\n      \
    \      int l, r;\n            cin >> l >> r;\n            st.reverse(l, r);\n\
    \        }\n        if(t == 3) {\n            int l, r, b, c;\n            cin\
    \ >> l >> r >> b >> c;\n            st.apply(l, r, {b, c});\n        }\n     \
    \   if(t == 4) {\n            int l, r;\n            cin >> l >> r;\n        \
    \    cout << st.prod(l, r).first << endl;\n        }\n    }\n}\n\nint main() {\n\
    \    solve();\n}"
  dependsOn:
  - data_structure/lazy_reversible_splay_tree.hpp
  isVerificationFile: true
  path: verify/yosupo/yosupo_dynamic_sequence_range_affine_range_sum.test.cpp
  requiredBy: []
  timestamp: '2024-06-26 09:03:42+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/yosupo_dynamic_sequence_range_affine_range_sum.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/yosupo_dynamic_sequence_range_affine_range_sum.test.cpp
- /verify/verify/yosupo/yosupo_dynamic_sequence_range_affine_range_sum.test.cpp.html
title: verify/yosupo/yosupo_dynamic_sequence_range_affine_range_sum.test.cpp
---
