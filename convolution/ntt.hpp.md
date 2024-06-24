---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/static_modint.hpp
    title: data_structure/static_modint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/yosupo_convolution.test.cpp
    title: verify/yosupo/yosupo_convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data_structure/static_modint.hpp\"\ntemplate<int m=998244353>\
    \ struct StaticModint {\n    using mint = StaticModint;\n    int _v;\n\n    constexpr\
    \ StaticModint() : _v(0) {}\n    template<class T>\n    constexpr StaticModint(T\
    \ v) : _v((v % m + m) % m) {}\n\n    constexpr int Val() const { return _v; }\n\
    \n    constexpr mint& operator ++ () { return *this += 1; }\n    constexpr mint&\
    \ operator -- () { return *this -= 1; }\n    constexpr mint operator ++ (int)\
    \ { mint res = *this; ++*this; return res; }\n    constexpr mint operator -- (int)\
    \ { mint res = *this; --*this; return res; }\n\n    constexpr mint& operator +=\
    \ (const mint& r) {\n        if(_v >= m - r._v) _v -= m;\n        _v += r._v;\
    \ return *this;\n    }\n    constexpr mint& operator -= (const mint& r) {\n  \
    \      if(_v < r._v) _v += m;\n        _v -= r._v; return *this;\n    }\n    constexpr\
    \ mint& operator *= (const mint& r) {\n        unsigned long long z = _v;\n  \
    \      z *= r._v;\n        _v = (unsigned int)(z % m); return *this;\n    }\n\
    \    constexpr mint& operator /= (const mint& r) {\n        return *this *= r.Inv();\
    \ \n    }\n\n    constexpr mint Pow(long long n) const {\n        mint x = *this,\
    \ r = 1; \n        while(n) {\n            if(n & 1) r *= x;\n            x *=\
    \ x;\n            n >>= 1;\n        }\n        return r;\n    }\n    constexpr\
    \ mint Inv() const {\n        return Pow(m - 2);\n    }\n\n    constexpr mint\
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
    \ mint& x) {\n        return os << x._v;\n    }\n};\n#line 2 \"convolution/ntt.hpp\"\
    \n\nstruct NTT{\n    using mint = StaticModint<998244353>;\n\n    // n: \u7573\
    \u307F\u8FBC\u307F\u5F8C\u306E\u6570\u5217\u306E\u30B5\u30A4\u30BA\n    // nunv:\
    \ n\u306E\u9006\u6570\n    int n, ninv;\n    const mint MOD = 998244353, g = 3;\n\
    \n    // br: \u30D3\u30C3\u30C8\u53CD\u8EE2\u5217\n    // roots: MOD\u4E0A\u306E\
    1\u306En\u4E57\u6839\u306E\u5217\n    vector<int> br;\n    vector<mint> roots;\n\
    \n    NTT() {}\n\n    // \u30D3\u30C3\u30C8\u53CD\u8EE2\u5217\u306E\u751F\u6210\
    \n    // N = 8\u306E\u4F8B\n    // {0}\u306E\u5404\u8981\u7D20\u306B2 ^ 2\u3092\
    \u52A0\u3048\u3066{0, 4}\n    // {0, 4}\u306E\u5404\u8981\u7D20\u306B2 ^ 1\u3092\
    \u52A0\u3048\u3066{0, 4, 2, 6}\n    // {0, 4, 2, 6}\u306E\u5404\u8981\u7D20\u306B\
    2 ^ 0\u3092\u52A0\u3048\u3066{0, 4, 2, 6, 1, 5, 3, 7}\n    void bit_reversal(int\
    \ n) {\n        br.resize(n);\n        int p = 1, d = n / 2;\n        while(p\
    \ < n) {\n            for(int i = 0; i < p; i++) {\n                br[i + p]\
    \ = br[i] + d;\n            }\n            p *= 2;\n            d /= 2;\n    \
    \    }\n    }\n\n    // MOD\u4E0A1\u306En\u4E57\u6839\u306E\u914D\u5217\u3092\u751F\
    \u6210\n    // n: \u8981\u7D20\u6570(2\u51AA)\uFF0Cw: 1\u306En\u4E57\u6839\u306E\
    \u3072\u3068\u3064\n    void n_th_roots(int n, mint w) {\n        roots.resize(n);\n\
    \        roots[0] = 1;\n        for(int i = 1; i < n; i++) {\n            roots[i]\
    \ = roots[i - 1] * w;\n        }\n    }\n\n    // \u518D\u5E30\u7684\u306B\u5909\
    \u63DB\n    // l: \u66F4\u65B0\u5BFE\u8C61\u533A\u9593\u306E\u5DE6\u7AEF\uFF0C\
    len: \u66F4\u65B0\u5BFE\u8C61\u533A\u9593\u306E\u9577\u3055\n    void transform_recursive(vector<mint>&\
    \ c, int l, int len) {\n        if(len == 1) return;\n        int d = n / len,\
    \ h = len / 2;\n\n        transform_recursive(c, l, h);\n        transform_recursive(c,\
    \ l + h, h);\n\n        // \u30D0\u30BF\u30D5\u30E9\u30A4\u6F14\u7B97\n      \
    \  for(int i = 0; i < h; i++) {\n            mint v0 = c[l + i];\n           \
    \ mint v1 = c[l + h + i] * roots[d * i];\n            c[l + i] = (v0 + v1);\n\
    \            c[l + h + i] = (v0 - v1 + MOD);\n        }\n    }\n\n    // \u6570\
    \u8AD6\u5909\u63DB\uFF0C\u9577\u3055\u306F2\u51AA\n    // c: \u5909\u63DB\u5217\
    \uFF0Cinv: \u9006\u5909\u63DB\u304B\u3069\u3046\u304B\n    vector<mint> transform(vector<mint>&\
    \ c, bool inv=false) {\n        vector<mint> ret(n, 0);\n\n        // \u30D3\u30C3\
    \u30C8\u53CD\u8EE2\u7F6E\u63DB\n        for(int i = 0; i < c.size(); i++) {\n\
    \            ret[br[i]] = c[i];\n        }\n\n        transform_recursive(ret,\
    \ 0, n);\n\n        // NTT\u306A\u3089\u305D\u306E\u307E\u307E\u51FA\u529B\n \
    \       if(!inv) return ret;\n\n        // INTT\u306A\u3089(0, N)\u306E\u7BC4\u56F2\
    \u3092\u9006\u9806\u306B\u4E26\u3073\u66FF\u3048\uFF0CN\u3067\u5272\u308B(ninv\u3092\
    \u639B\u3051\u308B)\n        reverse(ret.begin() + 1, ret.end());\n        for(int\
    \ i = 0; i < n; i++) {\n            ret[i] *= ninv;\n        }\n        return\
    \ ret;\n    }\n\n    // \u7573\u307F\u8FBC\u307F\n    vector<long long> convolution(vector<long\
    \ long>& a, vector<long long>& b) {\n        // n\u306E\u8A08\u7B97\n        n\
    \ = 1; while(n < a.size() + b.size() - 1) n *= 2;\n\n        // ninv\u306E\u8A08\
    \u7B97\n        ninv = mint(n).Inv().Val();\n\n        bit_reversal(n);\n\n  \
    \      // 1\u306En\u4E57\u6839\u8A08\u7B97\n        // MOD - 1 = 119 * 2 ^ 23\
    \ = d * n\u3068\u8868\u305B\u308B(n\u306F2\u51AA)\n        // g ^ (MOD - 1) =\
    \ (g ^ d) ^ n \u2261 1\u306A\u306E\u3067\uFF0C\u03C9 = g ^ d\n        int d =\
    \ ((MOD - 1) / n).Val();\n        mint w = g.Pow(d);\n        n_th_roots(n, w);\n\
    \n        vector<mint> ma(a.size()), mb(b.size());\n        for(int i = 0; i <\
    \ (int)a.size(); i++) {\n            ma[i] = a[i];\n        }\n        for(int\
    \ i = 0; i < (int)b.size(); i++) {\n            mb[i] = b[i];\n        }\n\n \
    \       vector<mint> fa = transform(ma);\n        vector<mint> fb = transform(mb);\n\
    \n        for(int i = 0; i < n; i++) {\n            fa[i] *= fb[i];\n        }\n\
    \n        auto c = transform(fa, true);\n\n        vector<long long> ret(a.size()\
    \ + b.size() - 1);\n        for(int i = 0; i < (int)a.size() + b.size() - 1; i++)\
    \ {\n            ret[i] = c[i].Val();\n        }\n\n        return ret;\n    }\n\
    };\n"
  code: "#include \"../data_structure/static_modint.hpp\"\n\nstruct NTT{\n    using\
    \ mint = StaticModint<998244353>;\n\n    // n: \u7573\u307F\u8FBC\u307F\u5F8C\u306E\
    \u6570\u5217\u306E\u30B5\u30A4\u30BA\n    // nunv: n\u306E\u9006\u6570\n    int\
    \ n, ninv;\n    const mint MOD = 998244353, g = 3;\n\n    // br: \u30D3\u30C3\u30C8\
    \u53CD\u8EE2\u5217\n    // roots: MOD\u4E0A\u306E1\u306En\u4E57\u6839\u306E\u5217\
    \n    vector<int> br;\n    vector<mint> roots;\n\n    NTT() {}\n\n    // \u30D3\
    \u30C3\u30C8\u53CD\u8EE2\u5217\u306E\u751F\u6210\n    // N = 8\u306E\u4F8B\n \
    \   // {0}\u306E\u5404\u8981\u7D20\u306B2 ^ 2\u3092\u52A0\u3048\u3066{0, 4}\n\
    \    // {0, 4}\u306E\u5404\u8981\u7D20\u306B2 ^ 1\u3092\u52A0\u3048\u3066{0, 4,\
    \ 2, 6}\n    // {0, 4, 2, 6}\u306E\u5404\u8981\u7D20\u306B2 ^ 0\u3092\u52A0\u3048\
    \u3066{0, 4, 2, 6, 1, 5, 3, 7}\n    void bit_reversal(int n) {\n        br.resize(n);\n\
    \        int p = 1, d = n / 2;\n        while(p < n) {\n            for(int i\
    \ = 0; i < p; i++) {\n                br[i + p] = br[i] + d;\n            }\n\
    \            p *= 2;\n            d /= 2;\n        }\n    }\n\n    // MOD\u4E0A\
    1\u306En\u4E57\u6839\u306E\u914D\u5217\u3092\u751F\u6210\n    // n: \u8981\u7D20\
    \u6570(2\u51AA)\uFF0Cw: 1\u306En\u4E57\u6839\u306E\u3072\u3068\u3064\n    void\
    \ n_th_roots(int n, mint w) {\n        roots.resize(n);\n        roots[0] = 1;\n\
    \        for(int i = 1; i < n; i++) {\n            roots[i] = roots[i - 1] * w;\n\
    \        }\n    }\n\n    // \u518D\u5E30\u7684\u306B\u5909\u63DB\n    // l: \u66F4\
    \u65B0\u5BFE\u8C61\u533A\u9593\u306E\u5DE6\u7AEF\uFF0Clen: \u66F4\u65B0\u5BFE\u8C61\
    \u533A\u9593\u306E\u9577\u3055\n    void transform_recursive(vector<mint>& c,\
    \ int l, int len) {\n        if(len == 1) return;\n        int d = n / len, h\
    \ = len / 2;\n\n        transform_recursive(c, l, h);\n        transform_recursive(c,\
    \ l + h, h);\n\n        // \u30D0\u30BF\u30D5\u30E9\u30A4\u6F14\u7B97\n      \
    \  for(int i = 0; i < h; i++) {\n            mint v0 = c[l + i];\n           \
    \ mint v1 = c[l + h + i] * roots[d * i];\n            c[l + i] = (v0 + v1);\n\
    \            c[l + h + i] = (v0 - v1 + MOD);\n        }\n    }\n\n    // \u6570\
    \u8AD6\u5909\u63DB\uFF0C\u9577\u3055\u306F2\u51AA\n    // c: \u5909\u63DB\u5217\
    \uFF0Cinv: \u9006\u5909\u63DB\u304B\u3069\u3046\u304B\n    vector<mint> transform(vector<mint>&\
    \ c, bool inv=false) {\n        vector<mint> ret(n, 0);\n\n        // \u30D3\u30C3\
    \u30C8\u53CD\u8EE2\u7F6E\u63DB\n        for(int i = 0; i < c.size(); i++) {\n\
    \            ret[br[i]] = c[i];\n        }\n\n        transform_recursive(ret,\
    \ 0, n);\n\n        // NTT\u306A\u3089\u305D\u306E\u307E\u307E\u51FA\u529B\n \
    \       if(!inv) return ret;\n\n        // INTT\u306A\u3089(0, N)\u306E\u7BC4\u56F2\
    \u3092\u9006\u9806\u306B\u4E26\u3073\u66FF\u3048\uFF0CN\u3067\u5272\u308B(ninv\u3092\
    \u639B\u3051\u308B)\n        reverse(ret.begin() + 1, ret.end());\n        for(int\
    \ i = 0; i < n; i++) {\n            ret[i] *= ninv;\n        }\n        return\
    \ ret;\n    }\n\n    // \u7573\u307F\u8FBC\u307F\n    vector<long long> convolution(vector<long\
    \ long>& a, vector<long long>& b) {\n        // n\u306E\u8A08\u7B97\n        n\
    \ = 1; while(n < a.size() + b.size() - 1) n *= 2;\n\n        // ninv\u306E\u8A08\
    \u7B97\n        ninv = mint(n).Inv().Val();\n\n        bit_reversal(n);\n\n  \
    \      // 1\u306En\u4E57\u6839\u8A08\u7B97\n        // MOD - 1 = 119 * 2 ^ 23\
    \ = d * n\u3068\u8868\u305B\u308B(n\u306F2\u51AA)\n        // g ^ (MOD - 1) =\
    \ (g ^ d) ^ n \u2261 1\u306A\u306E\u3067\uFF0C\u03C9 = g ^ d\n        int d =\
    \ ((MOD - 1) / n).Val();\n        mint w = g.Pow(d);\n        n_th_roots(n, w);\n\
    \n        vector<mint> ma(a.size()), mb(b.size());\n        for(int i = 0; i <\
    \ (int)a.size(); i++) {\n            ma[i] = a[i];\n        }\n        for(int\
    \ i = 0; i < (int)b.size(); i++) {\n            mb[i] = b[i];\n        }\n\n \
    \       vector<mint> fa = transform(ma);\n        vector<mint> fb = transform(mb);\n\
    \n        for(int i = 0; i < n; i++) {\n            fa[i] *= fb[i];\n        }\n\
    \n        auto c = transform(fa, true);\n\n        vector<long long> ret(a.size()\
    \ + b.size() - 1);\n        for(int i = 0; i < (int)a.size() + b.size() - 1; i++)\
    \ {\n            ret[i] = c[i].Val();\n        }\n\n        return ret;\n    }\n\
    };"
  dependsOn:
  - data_structure/static_modint.hpp
  isVerificationFile: false
  path: convolution/ntt.hpp
  requiredBy: []
  timestamp: '2024-06-25 02:36:40+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/yosupo_convolution.test.cpp
documentation_of: convolution/ntt.hpp
layout: document
redirect_from:
- /library/convolution/ntt.hpp
- /library/convolution/ntt.hpp.html
title: convolution/ntt.hpp
---
