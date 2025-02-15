---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: string/aho_corasick.hpp
    title: string/aho_corasick.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/430
    links:
    - https://yukicoder.me/problems/no/430
  bundledCode: "#line 1 \"verify/yukicoder/yukicoder_430.test.cpp\"\n#define PROBLEM\
    \ \"https://yukicoder.me/problems/no/430\"\n\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\n#line 1 \"string/aho_corasick.hpp\"\ntemplate <int ALPHA_SIZE=26>\n\
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
    \        }\n        return matches;\n    }\n};\n#line 7 \"verify/yukicoder/yukicoder_430.test.cpp\"\
    \n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n  \
    \  string S;\n    int M;\n    cin >> S >> M;\n\n    for(char& c : S) c += 32;\n\
    \n    AhoCorasick ac;\n    for(int i = 0; i < M; i++) {\n        string C;\n \
    \       cin >> C;\n\n        for(char& c : C) c += 32;\n        \n        ac.insert(C,\
    \ i);\n    }\n\n    ac.build();\n    auto matches = ac.search(S);\n    cout <<\
    \ matches.size() << \"\\n\";\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/430\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#include \"../../string/aho_corasick.hpp\"\n\nint main()\
    \ {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n    string S;\n\
    \    int M;\n    cin >> S >> M;\n\n    for(char& c : S) c += 32;\n\n    AhoCorasick\
    \ ac;\n    for(int i = 0; i < M; i++) {\n        string C;\n        cin >> C;\n\
    \n        for(char& c : C) c += 32;\n        \n        ac.insert(C, i);\n    }\n\
    \n    ac.build();\n    auto matches = ac.search(S);\n    cout << matches.size()\
    \ << \"\\n\";\n\n    return 0;\n}"
  dependsOn:
  - string/aho_corasick.hpp
  isVerificationFile: true
  path: verify/yukicoder/yukicoder_430.test.cpp
  requiredBy: []
  timestamp: '2025-02-16 03:13:12+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yukicoder/yukicoder_430.test.cpp
layout: document
redirect_from:
- /verify/verify/yukicoder/yukicoder_430.test.cpp
- /verify/verify/yukicoder/yukicoder_430.test.cpp.html
title: verify/yukicoder/yukicoder_430.test.cpp
---
