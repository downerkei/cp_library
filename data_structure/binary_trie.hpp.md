---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/yosupo/yosupo_set_xor_min.test.cpp
    title: verify/yosupo/yosupo_set_xor_min.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data_structure/binary_trie.hpp\"\ntemplate<typename U =\
    \ unsigned, int B = 32>\nstruct BinaryTrie {\n    struct Node {\n        int cnt;\n\
    \        Node *ch[2];\n        Node() : cnt(0), ch{nullptr, nullptr} {}\n    };\n\
    \n    BinaryTrie() {}\n\n    void insert(U val) { root = insert(root, val); }\n\
    \    void erase(U val) { root = erase(root, val); }\n    bool find(U val) { return\
    \ find(root, val); }\n    U xor_max(U val) { return xor_min(root, ~val); }\n \
    \   U xor_min(U val) { return xor_min(root, val); }\n\n  private: \n    Node*\
    \ root;\n\n    Node* insert(Node* n, U val, int b = B - 1) {\n        if(n ==\
    \ nullptr) n = new Node();\n        n->cnt++;\n        if(b >= 0) n->ch[(val >>\
    \ b) & 1] = insert(n->ch[(val >> b) & 1], val, b - 1);\n        return n;\n  \
    \  }\n\n    Node* erase(Node* n, U val, int b = B - 1) {\n        if(b >= 0) n->ch[(val\
    \ >> b) & 1] = erase(n->ch[(val >> b) & 1], val, b - 1);\n        n->cnt--;\n\
    \        if(n->cnt == 0) { delete n; return nullptr; }\n        return n;\n  \
    \  }\n\n    bool find(Node* n, U val, int b = B - 1) {\n        if(b < 0) return\
    \ true;\n        int f = (val >> b) & 1;\n        if(n->ch[f] == nullptr) return\
    \ false;\n        return find(n->ch[f], val, b - 1);\n    }\n\n    U xor_min(Node*\
    \ n, U val, int b = B - 1) {\n        if(b < 0) return 0;\n        bool f = (val\
    \ >> b) & 1;\n        if(n->ch[f] == nullptr) f ^= 1;\n        return xor_min(n->ch[f],\
    \ val, b - 1) | ((U)f << b);\n    }\n};\n"
  code: "template<typename U = unsigned, int B = 32>\nstruct BinaryTrie {\n    struct\
    \ Node {\n        int cnt;\n        Node *ch[2];\n        Node() : cnt(0), ch{nullptr,\
    \ nullptr} {}\n    };\n\n    BinaryTrie() {}\n\n    void insert(U val) { root\
    \ = insert(root, val); }\n    void erase(U val) { root = erase(root, val); }\n\
    \    bool find(U val) { return find(root, val); }\n    U xor_max(U val) { return\
    \ xor_min(root, ~val); }\n    U xor_min(U val) { return xor_min(root, val); }\n\
    \n  private: \n    Node* root;\n\n    Node* insert(Node* n, U val, int b = B -\
    \ 1) {\n        if(n == nullptr) n = new Node();\n        n->cnt++;\n        if(b\
    \ >= 0) n->ch[(val >> b) & 1] = insert(n->ch[(val >> b) & 1], val, b - 1);\n \
    \       return n;\n    }\n\n    Node* erase(Node* n, U val, int b = B - 1) {\n\
    \        if(b >= 0) n->ch[(val >> b) & 1] = erase(n->ch[(val >> b) & 1], val,\
    \ b - 1);\n        n->cnt--;\n        if(n->cnt == 0) { delete n; return nullptr;\
    \ }\n        return n;\n    }\n\n    bool find(Node* n, U val, int b = B - 1)\
    \ {\n        if(b < 0) return true;\n        int f = (val >> b) & 1;\n       \
    \ if(n->ch[f] == nullptr) return false;\n        return find(n->ch[f], val, b\
    \ - 1);\n    }\n\n    U xor_min(Node* n, U val, int b = B - 1) {\n        if(b\
    \ < 0) return 0;\n        bool f = (val >> b) & 1;\n        if(n->ch[f] == nullptr)\
    \ f ^= 1;\n        return xor_min(n->ch[f], val, b - 1) | ((U)f << b);\n    }\n\
    };\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/binary_trie.hpp
  requiredBy: []
  timestamp: '2025-03-01 10:52:25+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/yosupo/yosupo_set_xor_min.test.cpp
documentation_of: data_structure/binary_trie.hpp
layout: document
redirect_from:
- /library/data_structure/binary_trie.hpp
- /library/data_structure/binary_trie.hpp.html
title: data_structure/binary_trie.hpp
---
