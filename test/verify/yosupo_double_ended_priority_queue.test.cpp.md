---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/binary_search_tree.hpp
    title: data_structure/binary_search_tree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/double_ended_priority_queue
    links:
    - https://judge.yosupo.jp/problem/double_ended_priority_queue
  bundledCode: "#line 1 \"test/verify/yosupo_double_ended_priority_queue.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/double_ended_priority_queue\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"data_structure/binary_search_tree.hpp\"\
    \ntemplate<class T=int>\nstruct BinarySearchTree{\n    struct Node{\n        T\
    \ val;\n        Node* l = nullptr;\n        Node* r = nullptr;\n        Node*\
    \ p = nullptr;\n        Node(T x) : val(x) {}\n    };\n\n    Node* root = nullptr;\n\
    \n    Node* Find(T x) {\n        Node* cur = root;\n        while(cur) {\n   \
    \         if(cur->val == x) return cur;\n            if(cur->val < x) cur = cur->r;\n\
    \            else cur = cur->l;\n        }\n        return cur;\n    }\n\n   \
    \ void Insert(T x) {\n        Node* new_node = new Node(x);\n        Node* cur\
    \ = root;\n        Node* pre = nullptr;\n        while(cur) {\n            pre\
    \ = cur;\n            if(cur->val < x) cur = cur->r;\n            else cur = cur->l;\n\
    \        }\n        if(!pre) root = new_node;\n        else if(pre->val < x) pre->r\
    \ = new_node;\n        else pre->l = new_node;\n        new_node->p = pre;\n \
    \   }\n\n    bool Erase(T x) {\n        Node* del = Find(x);\n        if(!del)\
    \ return false;\n        if(!del->l) Transplant(del, del->r);\n        else if(!del->r)\
    \ Transplant(del, del->l);\n        else {\n            Node* nxt = del->r;\n\
    \            while(nxt->l) nxt = nxt->l;\n            if(del->r != nxt) {\n  \
    \              Transplant(nxt, nxt->r);    \n                nxt->r = del->r;\n\
    \                nxt->r->p = nxt;\n            }\n            Transplant(del,\
    \ nxt);\n            nxt->l = del->l;\n            nxt->l->p = nxt;\n        }\n\
    \        delete del;\n        return true;\n    }\n\n    void Transplant(Node*\
    \ u, Node* v) {\n        if(u == root) root = v;\n        else if(u == u->p->l)\
    \ u->p->l = v;\n        else u->p->r = v;\n        if(v) v->p = u->p;\n    }\n\
    \n    T Minimum() {\n        Node* cur = root;\n        Node* pre = nullptr;\n\
    \        while(cur) {\n            pre = cur;\n            cur = cur->l;\n   \
    \     }\n        if(!pre) return -1;\n        return pre->val;\n    }\n\n    T\
    \ Maximum() {\n        Node* cur = root;\n        Node* pre = nullptr;\n     \
    \   while(cur) {\n            pre = cur;\n            cur = cur->r;\n        }\n\
    \        if(!pre) return -1;\n        return pre->val;\n    }\n};\n#line 7 \"\
    test/verify/yosupo_double_ended_priority_queue.test.cpp\"\n\nint main() {\n  \
    \  int N, Q;\n    cin >> N >> Q;\n    BinarySearchTree bst;\n    while(N--) {\n\
    \        int a;\n        cin >> a;\n        bst.Insert(a);\n    }\n    while(Q--)\
    \ {\n        int q;\n        cin >> q;\n        if(q == 0) {\n            int\
    \ x;\n            cin >> x;\n            bst.Insert(x);\n        }\n        if(q\
    \ == 1) {\n            int out = bst.Minimum();\n            bst.Erase(out);\n\
    \            cout << out << endl;\n        }\n        if(q == 2) {\n         \
    \   int out = bst.Maximum();\n            bst.Erase(out);\n            cout <<\
    \ out << endl;\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/double_ended_priority_queue\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../data_structure/binary_search_tree.hpp\"\
    \n\nint main() {\n    int N, Q;\n    cin >> N >> Q;\n    BinarySearchTree bst;\n\
    \    while(N--) {\n        int a;\n        cin >> a;\n        bst.Insert(a);\n\
    \    }\n    while(Q--) {\n        int q;\n        cin >> q;\n        if(q == 0)\
    \ {\n            int x;\n            cin >> x;\n            bst.Insert(x);\n \
    \       }\n        if(q == 1) {\n            int out = bst.Minimum();\n      \
    \      bst.Erase(out);\n            cout << out << endl;\n        }\n        if(q\
    \ == 2) {\n            int out = bst.Maximum();\n            bst.Erase(out);\n\
    \            cout << out << endl;\n        }\n    }\n}"
  dependsOn:
  - data_structure/binary_search_tree.hpp
  isVerificationFile: true
  path: test/verify/yosupo_double_ended_priority_queue.test.cpp
  requiredBy: []
  timestamp: '2024-06-21 22:30:47+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/verify/yosupo_double_ended_priority_queue.test.cpp
layout: document
redirect_from:
- /verify/test/verify/yosupo_double_ended_priority_queue.test.cpp
- /verify/test/verify/yosupo_double_ended_priority_queue.test.cpp.html
title: test/verify/yosupo_double_ended_priority_queue.test.cpp
---
