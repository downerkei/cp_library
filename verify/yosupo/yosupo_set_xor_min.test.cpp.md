---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: data_structure/binary_trie.hpp
    title: data_structure/binary_trie.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/set_xor_min
    links:
    - https://judge.yosupo.jp/problem/set_xor_min
  bundledCode: "#line 1 \"verify/yosupo/yosupo_set_xor_min.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/set_xor_min\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#line 1 \"data_structure/binary_trie.hpp\"\ntemplate<typename\
    \ U = unsigned, int B = 32>\nstruct BinaryTrie {\n    struct Node {\n        int\
    \ cnt;\n        Node *ch[2];\n        Node() : cnt(0), ch{nullptr, nullptr} {}\n\
    \    };\n\n    BinaryTrie() {}\n\n    void insert(U val) { root = insert(root,\
    \ val); }\n    void erase(U val) { root = erase(root, val); }\n    bool find(U\
    \ val) { return find(root, val); }\n    U xor_max(U val) { return xor_min(root,\
    \ ~val); }\n    U xor_min(U val) { return xor_min(root, val); }\n\n  private:\
    \ \n    Node* root;\n\n    Node* insert(Node* n, U val, int b = B - 1) {\n   \
    \     if(n == nullptr) n = new Node();\n        n->cnt++;\n        if(b >= 0)\
    \ n->ch[(val >> b) & 1] = insert(n->ch[(val >> b) & 1], val, b - 1);\n       \
    \ return n;\n    }\n\n    Node* erase(Node* n, U val, int b = B - 1) {\n     \
    \   if(b >= 0) n->ch[(val >> b) & 1] = erase(n->ch[(val >> b) & 1], val, b - 1);\n\
    \        n->cnt--;\n        if(n->cnt == 0) { delete n; return nullptr; }\n  \
    \      return n;\n    }\n\n    bool find(Node* n, U val, int b = B - 1) {\n  \
    \      if(b < 0) return true;\n        int f = (val >> b) & 1;\n        if(n->ch[f]\
    \ == nullptr) return false;\n        return find(n->ch[f], val, b - 1);\n    }\n\
    \n    U xor_min(Node* n, U val, int b = B - 1) {\n        if(b < 0) return 0;\n\
    \        bool f = (val >> b) & 1;\n        if(n->ch[f] == nullptr) f ^= 1;\n \
    \       return xor_min(n->ch[f], val, b - 1) | ((U)f << b);\n    }\n};\n#line\
    \ 7 \"verify/yosupo/yosupo_set_xor_min.test.cpp\"\n\nint main() {\n    cin.tie(nullptr);\n\
    \    ios::sync_with_stdio(false);\n    int Q;\n    cin >> Q;\n\n    BinaryTrie\
    \ bt;\n\n    while(Q--) {\n        int t, x;\n        cin >> t >> x;\n       \
    \ if(t == 0) {\n            if(!bt.find(x)) bt.insert(x);\n        }\n       \
    \ if(t == 1) {\n            if(bt.find(x)) bt.erase(x);\n        }\n        if(t\
    \ == 2) {\n            cout << (bt.xor_min(x) ^ x) << \"\\n\";\n        }\n  \
    \  }\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/set_xor_min\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../data_structure/binary_trie.hpp\"\
    \n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n  \
    \  int Q;\n    cin >> Q;\n\n    BinaryTrie bt;\n\n    while(Q--) {\n        int\
    \ t, x;\n        cin >> t >> x;\n        if(t == 0) {\n            if(!bt.find(x))\
    \ bt.insert(x);\n        }\n        if(t == 1) {\n            if(bt.find(x)) bt.erase(x);\n\
    \        }\n        if(t == 2) {\n            cout << (bt.xor_min(x) ^ x) << \"\
    \\n\";\n        }\n    }\n\n    return 0;\n}"
  dependsOn:
  - data_structure/binary_trie.hpp
  isVerificationFile: true
  path: verify/yosupo/yosupo_set_xor_min.test.cpp
  requiredBy: []
  timestamp: '2025-03-01 10:52:25+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/yosupo/yosupo_set_xor_min.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/yosupo_set_xor_min.test.cpp
- /verify/verify/yosupo/yosupo_set_xor_min.test.cpp.html
title: verify/yosupo/yosupo_set_xor_min.test.cpp
---
