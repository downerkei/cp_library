---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/yosupo_double_ended_priority_queue.test.cpp
    title: verify/yosupo/yosupo_double_ended_priority_queue.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data_structure/binary_search_tree.hpp\"\ntemplate<class\
    \ T=int>\nstruct BinarySearchTree{\n    struct Node{\n        T val;\n       \
    \ Node* l = nullptr;\n        Node* r = nullptr;\n        Node* p = nullptr;\n\
    \        Node(T x) : val(x) {}\n    };\n\n    Node* root = nullptr;\n\n    Node*\
    \ Find(T x) {\n        Node* cur = root;\n        while(cur) {\n            if(cur->val\
    \ == x) return cur;\n            if(cur->val < x) cur = cur->r;\n            else\
    \ cur = cur->l;\n        }\n        return cur;\n    }\n\n    void Insert(T x)\
    \ {\n        Node* new_node = new Node(x);\n        Node* cur = root;\n      \
    \  Node* pre = nullptr;\n        while(cur) {\n            pre = cur;\n      \
    \      if(cur->val < x) cur = cur->r;\n            else cur = cur->l;\n      \
    \  }\n        if(!pre) root = new_node;\n        else if(pre->val < x) pre->r\
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
    \        if(!pre) return -1;\n        return pre->val;\n    }\n};\n"
  code: "template<class T=int>\nstruct BinarySearchTree{\n    struct Node{\n     \
    \   T val;\n        Node* l = nullptr;\n        Node* r = nullptr;\n        Node*\
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
    \        if(!pre) return -1;\n        return pre->val;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/binary_search_tree.hpp
  requiredBy: []
  timestamp: '2024-06-21 22:30:47+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/yosupo_double_ended_priority_queue.test.cpp
documentation_of: data_structure/binary_search_tree.hpp
layout: document
redirect_from:
- /library/data_structure/binary_search_tree.hpp
- /library/data_structure/binary_search_tree.hpp.html
title: data_structure/binary_search_tree.hpp
---
