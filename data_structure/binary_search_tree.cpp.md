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
  bundledCode: "#line 1 \"data_structure/binary_search_tree.cpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n// \u4E8C\u5206\u63A2\u7D22\u6728\ntemplate<class T=int>\n\
    struct BinarySearchTree{\n    struct Node{\n        T val;\n        Node* l =\
    \ nullptr;\n        Node* r = nullptr;\n        Node* p = nullptr;\n        Node(T\
    \ x) : val(x) {}\n    };\n\n    Node* root = nullptr;\n    \n    Node* Find(T\
    \ x) {\n        Node* cur = root;\n        while(cur) {\n            if(cur->val\
    \ == x) return cur;\n            if(cur->val < x) cur = cur->r;\n            else\
    \ cur = cur->l;\n        }\n        return cur;\n    }\n\n    void Insert(T x)\
    \ {\n        Node* new_node = new Node(x);\n        Node* cur = root;\n      \
    \  Node* pre = nullptr;\n        while(cur) {\n            pre = cur;\n      \
    \      if(cur->val < x) cur = cur->r;\n            else cur = cur->l;\n      \
    \  }\n        if(!pre) root = new_node;\n        else if(pre->val < x) pre->r\
    \ = new_node;\n        else pre->l = new_node;\n        new_node->p = pre;\n \
    \   }\n\n    bool Erase(T x) {\n        Node* del = find(x);\n        if(!del)\
    \ return false;\n        if(!del->l) transplant(del, del->r);\n        else if(!del->r)\
    \ transplant(del, del->l);\n        else {\n            Node* nxt = del->r;\n\
    \            while(nxt->l) nxt = nxt->l;\n            if(del->r != nxt) {\n  \
    \              transplant(nxt, nxt->r);    \n                nxt->r = del->r;\n\
    \                nxt->r->p = nxt;\n            }\n            transplant(del,\
    \ nxt);\n            nxt->l = del->l;\n            nxt->l->p = nxt;\n        }\n\
    \        delete del;\n        return true;\n    }\n\n    void Transplant(Node*\
    \ u, Node* v) {\n        if(u == root) root = v;\n        else if(u == u->p->l)\
    \ u->p->l = v;\n        else u->p->r = v;\n        if(v) v->p = u->p;\n    }\n\
    };\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\n// \u4E8C\u5206\u63A2\u7D22\
    \u6728\ntemplate<class T=int>\nstruct BinarySearchTree{\n    struct Node{\n  \
    \      T val;\n        Node* l = nullptr;\n        Node* r = nullptr;\n      \
    \  Node* p = nullptr;\n        Node(T x) : val(x) {}\n    };\n\n    Node* root\
    \ = nullptr;\n    \n    Node* Find(T x) {\n        Node* cur = root;\n       \
    \ while(cur) {\n            if(cur->val == x) return cur;\n            if(cur->val\
    \ < x) cur = cur->r;\n            else cur = cur->l;\n        }\n        return\
    \ cur;\n    }\n\n    void Insert(T x) {\n        Node* new_node = new Node(x);\n\
    \        Node* cur = root;\n        Node* pre = nullptr;\n        while(cur) {\n\
    \            pre = cur;\n            if(cur->val < x) cur = cur->r;\n        \
    \    else cur = cur->l;\n        }\n        if(!pre) root = new_node;\n      \
    \  else if(pre->val < x) pre->r = new_node;\n        else pre->l = new_node;\n\
    \        new_node->p = pre;\n    }\n\n    bool Erase(T x) {\n        Node* del\
    \ = find(x);\n        if(!del) return false;\n        if(!del->l) transplant(del,\
    \ del->r);\n        else if(!del->r) transplant(del, del->l);\n        else {\n\
    \            Node* nxt = del->r;\n            while(nxt->l) nxt = nxt->l;\n  \
    \          if(del->r != nxt) {\n                transplant(nxt, nxt->r);    \n\
    \                nxt->r = del->r;\n                nxt->r->p = nxt;\n        \
    \    }\n            transplant(del, nxt);\n            nxt->l = del->l;\n    \
    \        nxt->l->p = nxt;\n        }\n        delete del;\n        return true;\n\
    \    }\n\n    void Transplant(Node* u, Node* v) {\n        if(u == root) root\
    \ = v;\n        else if(u == u->p->l) u->p->l = v;\n        else u->p->r = v;\n\
    \        if(v) v->p = u->p;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/binary_search_tree.cpp
  requiredBy: []
  timestamp: '2024-06-21 20:30:10+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/binary_search_tree.cpp
layout: document
redirect_from:
- /library/data_structure/binary_search_tree.cpp
- /library/data_structure/binary_search_tree.cpp.html
title: data_structure/binary_search_tree.cpp
---
