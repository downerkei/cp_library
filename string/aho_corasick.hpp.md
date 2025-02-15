---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yukicoder/yukicoder_430.test.cpp
    title: verify/yukicoder/yukicoder_430.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"string/aho_corasick.hpp\"\ntemplate <int ALPHA_SIZE=26>\n\
    struct AhoCorasick {\n    struct Node {\n        vector<Node*> children;\n   \
    \     Node* fail;\n        vector<int> output;\n        Node() : children(ALPHA_SIZE,\
    \ nullptr), fail(nullptr) {}\n    };\n\n    Node* root;\n    vector<string> patterns;\n\
    \n    AhoCorasick() : root(new Node()) {}\n\n    void insert(const string& word,\
    \ int index) {\n        Node* cur = root;\n        for(char c : word) {\n    \
    \        int idx = c - 'a';\n            if(cur->children[idx] == nullptr) cur->children[idx]\
    \ = new Node();\n            cur = cur->children[idx];\n        }\n        cur->output.push_back(index);\n\
    \    }\n\n    void build() {\n        queue<Node*> q;\n        root->fail = root;\n\
    \        for(int i = 0; i < ALPHA_SIZE; i++) {\n            if(root->children[i])\
    \ {\n                root->children[i]->fail = root;\n                q.push(root->children[i]);\n\
    \            }\n            else root->children[i] = root;\n        }\n      \
    \  while(q.size()) {\n            Node* cur = q.front();\n            q.pop();\n\
    \            for(int i = 0; i < ALPHA_SIZE; i++) {\n                Node* child\
    \ = cur->children[i];\n                if(child) {\n                    child->fail\
    \ = cur->fail->children[i];\n                    child->output.insert(child->output.end(),\
    \ child->fail->output.begin(), child->fail->output.end());\n                 \
    \   q.push(child);\n                }\n                else cur->children[i] =\
    \ cur->fail->children[i];\n            }\n        }\n    }\n\n    vector<pair<int,\
    \ int>> search(const string& word) {\n        vector<pair<int, int>> matches;\n\
    \        Node* cur = root;\n        for(int i = 0; i < (int)word.size(); i++)\
    \ {\n            int idx = word[i] - 'a';\n            cur = cur->children[idx];\n\
    \            for(int pat_idx : cur->output) matches.emplace_back(i, pat_idx);\n\
    \        }\n        return matches;\n    }\n};\n"
  code: "template <int ALPHA_SIZE=26>\nstruct AhoCorasick {\n    struct Node {\n \
    \       vector<Node*> children;\n        Node* fail;\n        vector<int> output;\n\
    \        Node() : children(ALPHA_SIZE, nullptr), fail(nullptr) {}\n    };\n\n\
    \    Node* root;\n    vector<string> patterns;\n\n    AhoCorasick() : root(new\
    \ Node()) {}\n\n    void insert(const string& word, int index) {\n        Node*\
    \ cur = root;\n        for(char c : word) {\n            int idx = c - 'a';\n\
    \            if(cur->children[idx] == nullptr) cur->children[idx] = new Node();\n\
    \            cur = cur->children[idx];\n        }\n        cur->output.push_back(index);\n\
    \    }\n\n    void build() {\n        queue<Node*> q;\n        root->fail = root;\n\
    \        for(int i = 0; i < ALPHA_SIZE; i++) {\n            if(root->children[i])\
    \ {\n                root->children[i]->fail = root;\n                q.push(root->children[i]);\n\
    \            }\n            else root->children[i] = root;\n        }\n      \
    \  while(q.size()) {\n            Node* cur = q.front();\n            q.pop();\n\
    \            for(int i = 0; i < ALPHA_SIZE; i++) {\n                Node* child\
    \ = cur->children[i];\n                if(child) {\n                    child->fail\
    \ = cur->fail->children[i];\n                    child->output.insert(child->output.end(),\
    \ child->fail->output.begin(), child->fail->output.end());\n                 \
    \   q.push(child);\n                }\n                else cur->children[i] =\
    \ cur->fail->children[i];\n            }\n        }\n    }\n\n    vector<pair<int,\
    \ int>> search(const string& word) {\n        vector<pair<int, int>> matches;\n\
    \        Node* cur = root;\n        for(int i = 0; i < (int)word.size(); i++)\
    \ {\n            int idx = word[i] - 'a';\n            cur = cur->children[idx];\n\
    \            for(int pat_idx : cur->output) matches.emplace_back(i, pat_idx);\n\
    \        }\n        return matches;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: string/aho_corasick.hpp
  requiredBy: []
  timestamp: '2025-02-16 02:36:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yukicoder/yukicoder_430.test.cpp
documentation_of: string/aho_corasick.hpp
layout: document
redirect_from:
- /library/string/aho_corasick.hpp
- /library/string/aho_corasick.hpp.html
title: string/aho_corasick.hpp
---
