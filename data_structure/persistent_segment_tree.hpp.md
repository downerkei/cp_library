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
  bundledCode: "#line 1 \"data_structure/persistent_segment_tree.hpp\"\ntemplate<class\
    \ S, S (*op)(S, S), S (*e)(), int NODES = 10'000'000>\nstruct PersistentSegmentTree\
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
    \ b, n->r, m, r));\n    }\n};\n"
  code: "template<class S, S (*op)(S, S), S (*e)(), int NODES = 10'000'000>\nstruct\
    \ PersistentSegmentTree {\n    struct Node {\n        S d;\n        Node* l, *r;\n\
    \    };\n\n    PersistentSegmentTree(const vector<S>& v) : pid(0), n(v.size())\
    \ {\n        pool = new Node[NODES];\n        nil = my_new(e());\n        nil->l\
    \ = nil->r = nil;\n        roots.reserve(262144);\n        roots.push_back(build(0,\
    \ v.size(), v));\n    }\n\n    PersistentSegmentTree(int n) : pid(0), n(n) {\n\
    \        pool = new Node[NODES];\n        nil = my_new(e());\n        nil->l =\
    \ nil->r = nil;\n        roots.reserve(262144);\n        roots.push_back(nil);\n\
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
    \ b, n->r, m, r));\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/persistent_segment_tree.hpp
  requiredBy: []
  timestamp: '2025-02-18 20:03:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/persistent_segment_tree.hpp
layout: document
redirect_from:
- /library/data_structure/persistent_segment_tree.hpp
- /library/data_structure/persistent_segment_tree.hpp.html
title: data_structure/persistent_segment_tree.hpp
---
