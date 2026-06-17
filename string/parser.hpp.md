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
  bundledCode: "#line 1 \"string/parser.hpp\"\n// \u69CB\u6587\u89E3\u6790\u3072\u306A\
    \u578B\nstruct Parser {\n    string S;\n    int N, it = 0;\n\n    Parser(const\
    \ string& S) : S(S), N(S.size()) {}\n\n    // \u8AAD\u307F\u7D42\u308F\u308A\u3092\
    \u5224\u5B9A\u3059\u308B\uFF0E\n    bool eof() const {  \n        return it >=\
    \ N;\n    }\n\n    // \u4ECA\u306E\u6587\u5B57\u3092\u8FD4\u3059\uFF0Cit\u306F\
    \u9032\u3081\u306A\u3044\uFF0E\n    char peek() const {\n        return eof()\
    \ ? '\\0' : S[it];\n    }\n\n    // \u3042\u308C\u3070\u8AAD\u3080\uFF0Cbool\u3092\
    \u8FD4\u3059\uFF0E\n    bool accept(char c) {\n        if (peek() == c) {\n  \
    \          it++;\n            return true;\n        }\n        return false;\n\
    \    }\n\n    // \u5FC5\u305A\u8AAD\u3080\uFF0Cassert\u304B\u304B\u308B\uFF0E\n\
    \    void expect(char c) {\n        assert(accept(c));\n    }\n\n    // \u6570\
    \u5B57\u3092\u8FD4\u3059\uFF0Cint\u306B\u6CE8\u610F\uFF0E\n    int number() {\n\
    \        assert(isdigit(peek()));\n\n        int val = 0;\n        while (!eof()\
    \ && isdigit(peek())) {\n            val = val * 10 + (peek() - '0');\n      \
    \      it++;\n        }\n        return val;\n    }\n};\n"
  code: "// \u69CB\u6587\u89E3\u6790\u3072\u306A\u578B\nstruct Parser {\n    string\
    \ S;\n    int N, it = 0;\n\n    Parser(const string& S) : S(S), N(S.size()) {}\n\
    \n    // \u8AAD\u307F\u7D42\u308F\u308A\u3092\u5224\u5B9A\u3059\u308B\uFF0E\n\
    \    bool eof() const {  \n        return it >= N;\n    }\n\n    // \u4ECA\u306E\
    \u6587\u5B57\u3092\u8FD4\u3059\uFF0Cit\u306F\u9032\u3081\u306A\u3044\uFF0E\n \
    \   char peek() const {\n        return eof() ? '\\0' : S[it];\n    }\n\n    //\
    \ \u3042\u308C\u3070\u8AAD\u3080\uFF0Cbool\u3092\u8FD4\u3059\uFF0E\n    bool accept(char\
    \ c) {\n        if (peek() == c) {\n            it++;\n            return true;\n\
    \        }\n        return false;\n    }\n\n    // \u5FC5\u305A\u8AAD\u3080\uFF0C\
    assert\u304B\u304B\u308B\uFF0E\n    void expect(char c) {\n        assert(accept(c));\n\
    \    }\n\n    // \u6570\u5B57\u3092\u8FD4\u3059\uFF0Cint\u306B\u6CE8\u610F\uFF0E\
    \n    int number() {\n        assert(isdigit(peek()));\n\n        int val = 0;\n\
    \        while (!eof() && isdigit(peek())) {\n            val = val * 10 + (peek()\
    \ - '0');\n            it++;\n        }\n        return val;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: string/parser.hpp
  requiredBy: []
  timestamp: '2026-06-14 02:28:21+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/parser.hpp
layout: document
redirect_from:
- /library/string/parser.hpp
- /library/string/parser.hpp.html
title: string/parser.hpp
---
