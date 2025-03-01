---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/yosupo_set_xor_min.test.cpp
    title: verify/yosupo/yosupo_set_xor_min.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data_structure/binary_trie.hpp\"\ntemplate<typename U =\
    \ unsigned, int B = 32>\nstruct BinaryTrie {\n    struct Node {\n        int cnt;\n\
    \        Node *ch[2];\n        Node() : cnt(0), ch{nullptr, nullptr} {}\n    };\n\
    \n    BinaryTrie() : root(nullptr) {}\n\n    void insert(U x) { insert(root, x);\
    \ }\n    void erase(U x) { erase(root, x); }\n    bool find(U x) { return find(root,\
    \ x); }\n    U xor_max(U x) { return xor_min(root, ~x); }\n    U xor_min(U x)\
    \ { return xor_min(root, x); }\n\n  private: \n    Node* root;\n\n    void insert(Node*&\
    \ n, U x, int b = B - 1) {\n        if(n == nullptr) n = new Node();\n       \
    \ n->cnt++;\n        if(b >= 0) insert(n->ch[(x >> b) & 1], x, b - 1);\n    }\
    \    \n\n    void erase(Node*& n, U x, int b = B - 1) {\n        if(b >= 0) erase(n->ch[(x\
    \ >> b) & 1], x, b - 1);\n        if(n && --n->cnt == 0) { delete n; n = nullptr;\
    \ }\n    }\n\n    bool find(Node* n, U x, int b = B - 1) {\n        if(n == nullptr)\
    \ return false;\n        if(b < 0) return true;\n        if(n->ch[(x >> b) & 1]\
    \ == nullptr) return false;\n        return find(n->ch[(x >> b) & 1], x, b - 1);\n\
    \    }\n\n    U xor_min(Node* n, U x, int b = B - 1) {\n        if(b < 0) return\
    \ 0;\n        bool f = (x >> b) & 1;\n        if(n->ch[f] == nullptr) f ^= 1;\n\
    \        return xor_min(n->ch[f], x, b - 1) | ((U)f << b);\n    }\n};\n"
  code: "template<typename U = unsigned, int B = 32>\nstruct BinaryTrie {\n    struct\
    \ Node {\n        int cnt;\n        Node *ch[2];\n        Node() : cnt(0), ch{nullptr,\
    \ nullptr} {}\n    };\n\n    BinaryTrie() : root(nullptr) {}\n\n    void insert(U\
    \ x) { insert(root, x); }\n    void erase(U x) { erase(root, x); }\n    bool find(U\
    \ x) { return find(root, x); }\n    U xor_max(U x) { return xor_min(root, ~x);\
    \ }\n    U xor_min(U x) { return xor_min(root, x); }\n\n  private: \n    Node*\
    \ root;\n\n    void insert(Node*& n, U x, int b = B - 1) {\n        if(n == nullptr)\
    \ n = new Node();\n        n->cnt++;\n        if(b >= 0) insert(n->ch[(x >> b)\
    \ & 1], x, b - 1);\n    }    \n\n    void erase(Node*& n, U x, int b = B - 1)\
    \ {\n        if(b >= 0) erase(n->ch[(x >> b) & 1], x, b - 1);\n        if(n &&\
    \ --n->cnt == 0) { delete n; n = nullptr; }\n    }\n\n    bool find(Node* n, U\
    \ x, int b = B - 1) {\n        if(n == nullptr) return false;\n        if(b <\
    \ 0) return true;\n        if(n->ch[(x >> b) & 1] == nullptr) return false;\n\
    \        return find(n->ch[(x >> b) & 1], x, b - 1);\n    }\n\n    U xor_min(Node*\
    \ n, U x, int b = B - 1) {\n        if(b < 0) return 0;\n        bool f = (x >>\
    \ b) & 1;\n        if(n->ch[f] == nullptr) f ^= 1;\n        return xor_min(n->ch[f],\
    \ x, b - 1) | ((U)f << b);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/binary_trie.hpp
  requiredBy: []
  timestamp: '2025-03-01 16:55:18+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/yosupo_set_xor_min.test.cpp
documentation_of: data_structure/binary_trie.hpp
layout: document
redirect_from:
- /library/data_structure/binary_trie.hpp
- /library/data_structure/binary_trie.hpp.html
title: data_structure/binary_trie.hpp
---
