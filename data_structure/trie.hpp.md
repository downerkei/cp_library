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
  bundledCode: "#line 1 \"data_structure/trie.hpp\"\ntemplate <int ALPHA_SIZE=26>\n\
    struct Trie {\n    struct Node {\n        vector<Node*> children;\n        bool\
    \ is_end;\n        Node() : is_end(false), children(ALPHA_SIZE, nullptr) {}\n\
    \    };\n\n    Node* root;\n\n    Trie() : root(new Node()) {}\n\n    void insert(const\
    \ string& word) {\n        Node* cur_node = root;\n        for(char c : word)\
    \ {\n            int idx = c - 'a';\n            if(cur_node->children[idx] ==\
    \ nullptr) cur_node->children[idx] = new Node();\n            cur_node = cur_node->children[idx];\n\
    \        }\n\n        cur_node->is_end = true;\n    }\n\n    bool search(const\
    \ string& word) {\n        Node* cur_node = root;\n        for(char c : word)\
    \ {\n            int idx = c - 'a';\n            if(cur_node->children[idx] ==\
    \ nullptr) return false;\n            cur_node = cur_node->children[idx];\n  \
    \      }\n        return cur_node->is_end;\n    }\n};\n"
  code: "template <int ALPHA_SIZE=26>\nstruct Trie {\n    struct Node {\n        vector<Node*>\
    \ children;\n        bool is_end;\n        Node() : is_end(false), children(ALPHA_SIZE,\
    \ nullptr) {}\n    };\n\n    Node* root;\n\n    Trie() : root(new Node()) {}\n\
    \n    void insert(const string& word) {\n        Node* cur_node = root;\n    \
    \    for(char c : word) {\n            int idx = c - 'a';\n            if(cur_node->children[idx]\
    \ == nullptr) cur_node->children[idx] = new Node();\n            cur_node = cur_node->children[idx];\n\
    \        }\n\n        cur_node->is_end = true;\n    }\n\n    bool search(const\
    \ string& word) {\n        Node* cur_node = root;\n        for(char c : word)\
    \ {\n            int idx = c - 'a';\n            if(cur_node->children[idx] ==\
    \ nullptr) return false;\n            cur_node = cur_node->children[idx];\n  \
    \      }\n        return cur_node->is_end;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/trie.hpp
  requiredBy: []
  timestamp: '2025-02-16 02:36:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/trie.hpp
layout: document
redirect_from:
- /library/data_structure/trie.hpp
- /library/data_structure/trie.hpp.html
title: data_structure/trie.hpp
---
