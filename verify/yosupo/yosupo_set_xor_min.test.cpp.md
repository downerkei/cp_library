---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/binary_trie.hpp
    title: data_structure/binary_trie.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
    \    };\n\n    BinaryTrie() : root(nullptr) {}\n\n    void insert(U x) { insert(root,\
    \ x); }\n    void erase(U x) { erase(root, x); }\n    bool find(U x) { return\
    \ find(root, x); }\n    U xor_max(U x) { return xor_min(root, ~x); }\n    U xor_min(U\
    \ x) { return xor_min(root, x); }\n\n  private: \n    Node* root;\n\n    void\
    \ insert(Node*& n, U x, int b = B - 1) {\n        if(n == nullptr) n = new Node();\n\
    \        n->cnt++;\n        if(b >= 0) insert(n->ch[(x >> b) & 1], x, b - 1);\n\
    \    }    \n\n    void erase(Node*& n, U x, int b = B - 1) {\n        if(b >=\
    \ 0) erase(n->ch[(x >> b) & 1], x, b - 1);\n        if(n && --n->cnt == 0) { delete\
    \ n; n = nullptr; }\n    }\n\n    bool find(Node* n, U x, int b = B - 1) {\n \
    \       if(n == nullptr) return false;\n        if(b < 0) return true;\n     \
    \   if(n->ch[(x >> b) & 1] == nullptr) return false;\n        return find(n->ch[(x\
    \ >> b) & 1], x, b - 1);\n    }\n\n    U xor_min(Node* n, U x, int b = B - 1)\
    \ {\n        if(b < 0) return 0;\n        bool f = (x >> b) & 1;\n        if(n->ch[f]\
    \ == nullptr) f ^= 1;\n        return xor_min(n->ch[f], x, b - 1) | ((U)f << b);\n\
    \    }\n};\n#line 7 \"verify/yosupo/yosupo_set_xor_min.test.cpp\"\n\nint main()\
    \ {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n    int Q;\n   \
    \ cin >> Q;\n\n    BinaryTrie bt;\n\n    while(Q--) {\n        int t, x;\n   \
    \     cin >> t >> x;\n        if(t == 0) {\n            if(!bt.find(x)) bt.insert(x);\n\
    \        }\n        if(t == 1) {\n            if(bt.find(x)) bt.erase(x);\n  \
    \      }\n        if(t == 2) {\n            cout << (bt.xor_min(x) ^ x) << \"\\\
    n\";\n        }\n    }\n\n    return 0;\n}\n"
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
  timestamp: '2025-03-01 16:55:18+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/yosupo_set_xor_min.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/yosupo_set_xor_min.test.cpp
- /verify/verify/yosupo/yosupo_set_xor_min.test.cpp.html
title: verify/yosupo/yosupo_set_xor_min.test.cpp
---
