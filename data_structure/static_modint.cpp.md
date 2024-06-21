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
  bundledCode: "#line 1 \"data_structure/static_modint.cpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\ntemplate<int m> struct StaticModint {\n    using mint\
    \ = StaticModint;\n    int _v;\n\n    constexpr StaticModint() : _v(0) {}\n  \
    \  template<class T>\n    constexpr StaticModint(T v) : _v((v % m + m) % m) {}\n\
    \n    constexpr int val() const { return _v; }\n\n    constexpr mint& operator\
    \ ++ () { return *this += 1; }\n    constexpr mint& operator -- () { return *this\
    \ -= 1; }\n    constexpr mint operator ++ (int) { mint res = *this; ++*this; return\
    \ res; }\n    constexpr mint operator -- (int) { mint res = *this; --*this; return\
    \ res; }\n\n    constexpr mint& operator += (const mint& r) {\n        if(_v >=\
    \ m - r._v) _v -= m;\n        _v += r._v; return *this;\n    }\n    constexpr\
    \ mint& operator -= (const mint& r) {\n        if(_v < r._v) _v += m;\n      \
    \  _v -= r._v; return *this;\n    }\n    constexpr mint& operator *= (const mint&\
    \ r) {\n        unsigned long long z = _v;\n        z *= r._v;\n        _v = (unsigned\
    \ int)(z % m); return *this;\n    }\n    constexpr mint& operator /= (const mint&\
    \ r) {\n        return *this *= r.inv(); \n    }\n\n    constexpr mint pow(long\
    \ long n) const {\n        mint x = *this, r = 1; \n        while(n) {\n     \
    \       if(n & 1) r *= x;\n            x *= x;\n            n >>= 1;\n       \
    \ }\n        return r;\n    }\n    constexpr mint inv() const {\n        return\
    \ pow(m - 2);\n    }\n\n    constexpr mint operator + () const { return *this;\
    \ }\n    constexpr mint operator - () const { return mint() - *this; }\n\n   \
    \ constexpr mint operator + (const mint& r) const { return mint(*this) += r; }\n\
    \    constexpr mint operator - (const mint& r) const { return mint(*this) -= r;\
    \ }\n    constexpr mint operator * (const mint& r) const { return mint(*this)\
    \ *= r; }\n    constexpr mint operator / (const mint& r) const { return mint(*this)\
    \ /= r; }\n    \n    constexpr bool operator == (const mint& r) { return _v ==\
    \ r._v; }\n    constexpr bool operator != (const mint& r) { return _v != r._v;\
    \ }\n\n    friend istream& operator >> (istream& is, mint& x) {\n        long\
    \ long t;\n        is >> t;\n        x = mint(t);\n        return is;\n    }\n\
    \    friend ostream& operator << (ostream& os, const mint& x) {\n        return\
    \ os << x._v;\n    }\n};\n\nusing mint = StaticModint<998244353>;\n\nint main()\
    \ {\n\n\n    return 0;\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate<int m> struct\
    \ StaticModint {\n    using mint = StaticModint;\n    int _v;\n\n    constexpr\
    \ StaticModint() : _v(0) {}\n    template<class T>\n    constexpr StaticModint(T\
    \ v) : _v((v % m + m) % m) {}\n\n    constexpr int val() const { return _v; }\n\
    \n    constexpr mint& operator ++ () { return *this += 1; }\n    constexpr mint&\
    \ operator -- () { return *this -= 1; }\n    constexpr mint operator ++ (int)\
    \ { mint res = *this; ++*this; return res; }\n    constexpr mint operator -- (int)\
    \ { mint res = *this; --*this; return res; }\n\n    constexpr mint& operator +=\
    \ (const mint& r) {\n        if(_v >= m - r._v) _v -= m;\n        _v += r._v;\
    \ return *this;\n    }\n    constexpr mint& operator -= (const mint& r) {\n  \
    \      if(_v < r._v) _v += m;\n        _v -= r._v; return *this;\n    }\n    constexpr\
    \ mint& operator *= (const mint& r) {\n        unsigned long long z = _v;\n  \
    \      z *= r._v;\n        _v = (unsigned int)(z % m); return *this;\n    }\n\
    \    constexpr mint& operator /= (const mint& r) {\n        return *this *= r.inv();\
    \ \n    }\n\n    constexpr mint pow(long long n) const {\n        mint x = *this,\
    \ r = 1; \n        while(n) {\n            if(n & 1) r *= x;\n            x *=\
    \ x;\n            n >>= 1;\n        }\n        return r;\n    }\n    constexpr\
    \ mint inv() const {\n        return pow(m - 2);\n    }\n\n    constexpr mint\
    \ operator + () const { return *this; }\n    constexpr mint operator - () const\
    \ { return mint() - *this; }\n\n    constexpr mint operator + (const mint& r)\
    \ const { return mint(*this) += r; }\n    constexpr mint operator - (const mint&\
    \ r) const { return mint(*this) -= r; }\n    constexpr mint operator * (const\
    \ mint& r) const { return mint(*this) *= r; }\n    constexpr mint operator / (const\
    \ mint& r) const { return mint(*this) /= r; }\n    \n    constexpr bool operator\
    \ == (const mint& r) { return _v == r._v; }\n    constexpr bool operator != (const\
    \ mint& r) { return _v != r._v; }\n\n    friend istream& operator >> (istream&\
    \ is, mint& x) {\n        long long t;\n        is >> t;\n        x = mint(t);\n\
    \        return is;\n    }\n    friend ostream& operator << (ostream& os, const\
    \ mint& x) {\n        return os << x._v;\n    }\n};\n\nusing mint = StaticModint<998244353>;\n\
    \nint main() {\n\n\n    return 0;\n}"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/static_modint.cpp
  requiredBy: []
  timestamp: '2024-06-21 02:11:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/static_modint.cpp
layout: document
redirect_from:
- /library/data_structure/static_modint.cpp
- /library/data_structure/static_modint.cpp.html
title: data_structure/static_modint.cpp
---
