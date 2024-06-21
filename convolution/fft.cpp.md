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
  bundledCode: "#line 1 \"convolution/fft.cpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nstruct FFT{\n    // k\u756A\u76EE\u306E1\u306E\u539F\u59CBn\u4E57\u6839\
    \n    complex<double> NthRoot(int n, int k) {\n        double t = 2 * M_PI * k\
    \ / n;\n        return complex<double> (cos(t), sin(t));\n    }\n\n    // \u30D3\
    \u30C3\u30C8\u53CD\u8EE2\u5217\u306E\u751F\u6210\n    vector<int> BitReversal(int\
    \ n) {\n        vector<int> b(n, 0);\n        int p = 1, d = n / 2;\n        while(p\
    \ < n) {\n            for(int i = 0; i < p; i++) {\n                b[i | p] =\
    \ b[i] | d;\n            }\n            p *= 2;\n            d /= 2;\n       \
    \ }\n\n        return b;\n    }\n\n    // DFT\uFF0CIDFT\u3092\u884C\u3046\n  \
    \  // inv\u306B\u3088\u3063\u3066\u5207\u308A\u66FF\u3048\n    vector<complex<double>>\
    \ Transform(vector<complex<double>>& c, bool inv=false) {\n        int n = 1;\
    \ while(n < c.size()) n *= 2;\n\n        vector<int> br = BitReversal(n);\n\n\
    \        vector<complex<double>> t(n);\n\n        for(int i = 0; i < n; i++) {\n\
    \            t[br[i]] = c[i]; \n        }\n\n        for(int h = 1; h < n; h *=\
    \ 2) {\n            for(int l = 0; l < n; l += (2 * h)) {\n                for(int\
    \ i = 0; i < h; i++) {\n                    complex<double> v0 = t[l + i];\n \
    \                   complex<double> v1 = t[l + h + i] * NthRoot(h * 2, i);\n \
    \                   t[l + i] = v0 + v1;\n                    t[l + h + i] = v0\
    \ - v1;\n                }\n            }\n        }\n\n        // DFT\u306A\u3089\
    \u305D\u306E\u307E\u307E\u8FD4\u3059\n        if(!inv) return t;\n\n        //\
    \ IDFT\u306A\u3089\u9006\u9806\u306B\u4E26\u3073\u66FF\u3048\uFF0Cn\u3067\u5272\
    \u308B\n        reverse(t.begin() + 1, t.end());\n        for(int i = 0; i < n;\
    \ i++) {\n            t[i] /= n;\n        }\n\n        return t;\n    }\n\n  \
    \  // a, b\u3092\u7573\u307F\u8FBC\u3080\n    // \u51FA\u529B\u306F2\u51AA\n \
    \   vector<complex<double>> Convolution(vector<complex<double>>& a, vector<complex<double>>&\
    \ b) {\n        int n = 1; while(n < a.size() + b.size() - 1) n *= 2;\n\n    \
    \    a.resize(n);\n        b.resize(n);\n\n        auto fa = Transform(a);\n \
    \       auto fb = Transform(b);\n\n        for(int i = 0; i < n; i++) {\n    \
    \        fa[i] *= fb[i];\n        }\n\n        return Transform(fa, true);\n \
    \   }\n};\n\nint main() {\n    int N;\n    cin >> N;\n    vector<complex<double>>\
    \ A(N + 1), B(N + 1);\n    A[0] = 0;\n    B[0] = 0;\n    for(int i = 1; i <= N;\
    \ i++) {\n        cin >> A[i] >> B[i];\n    }\n\n    FFT fft;\n    auto C = fft.Convolution(A,\
    \ B);\n\n    for(int i = 1; i <= 2 * N; i++) {\n        cout << int(round(C[i].real()))\
    \ << endl;\n    }\n\n    return 0;\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\nstruct FFT{\n    // k\u756A\
    \u76EE\u306E1\u306E\u539F\u59CBn\u4E57\u6839\n    complex<double> NthRoot(int\
    \ n, int k) {\n        double t = 2 * M_PI * k / n;\n        return complex<double>\
    \ (cos(t), sin(t));\n    }\n\n    // \u30D3\u30C3\u30C8\u53CD\u8EE2\u5217\u306E\
    \u751F\u6210\n    vector<int> BitReversal(int n) {\n        vector<int> b(n, 0);\n\
    \        int p = 1, d = n / 2;\n        while(p < n) {\n            for(int i\
    \ = 0; i < p; i++) {\n                b[i | p] = b[i] | d;\n            }\n  \
    \          p *= 2;\n            d /= 2;\n        }\n\n        return b;\n    }\n\
    \n    // DFT\uFF0CIDFT\u3092\u884C\u3046\n    // inv\u306B\u3088\u3063\u3066\u5207\
    \u308A\u66FF\u3048\n    vector<complex<double>> Transform(vector<complex<double>>&\
    \ c, bool inv=false) {\n        int n = 1; while(n < c.size()) n *= 2;\n\n   \
    \     vector<int> br = BitReversal(n);\n\n        vector<complex<double>> t(n);\n\
    \n        for(int i = 0; i < n; i++) {\n            t[br[i]] = c[i]; \n      \
    \  }\n\n        for(int h = 1; h < n; h *= 2) {\n            for(int l = 0; l\
    \ < n; l += (2 * h)) {\n                for(int i = 0; i < h; i++) {\n       \
    \             complex<double> v0 = t[l + i];\n                    complex<double>\
    \ v1 = t[l + h + i] * NthRoot(h * 2, i);\n                    t[l + i] = v0 +\
    \ v1;\n                    t[l + h + i] = v0 - v1;\n                }\n      \
    \      }\n        }\n\n        // DFT\u306A\u3089\u305D\u306E\u307E\u307E\u8FD4\
    \u3059\n        if(!inv) return t;\n\n        // IDFT\u306A\u3089\u9006\u9806\u306B\
    \u4E26\u3073\u66FF\u3048\uFF0Cn\u3067\u5272\u308B\n        reverse(t.begin() +\
    \ 1, t.end());\n        for(int i = 0; i < n; i++) {\n            t[i] /= n;\n\
    \        }\n\n        return t;\n    }\n\n    // a, b\u3092\u7573\u307F\u8FBC\u3080\
    \n    // \u51FA\u529B\u306F2\u51AA\n    vector<complex<double>> Convolution(vector<complex<double>>&\
    \ a, vector<complex<double>>& b) {\n        int n = 1; while(n < a.size() + b.size()\
    \ - 1) n *= 2;\n\n        a.resize(n);\n        b.resize(n);\n\n        auto fa\
    \ = Transform(a);\n        auto fb = Transform(b);\n\n        for(int i = 0; i\
    \ < n; i++) {\n            fa[i] *= fb[i];\n        }\n\n        return Transform(fa,\
    \ true);\n    }\n};\n\nint main() {\n    int N;\n    cin >> N;\n    vector<complex<double>>\
    \ A(N + 1), B(N + 1);\n    A[0] = 0;\n    B[0] = 0;\n    for(int i = 1; i <= N;\
    \ i++) {\n        cin >> A[i] >> B[i];\n    }\n\n    FFT fft;\n    auto C = fft.Convolution(A,\
    \ B);\n\n    for(int i = 1; i <= 2 * N; i++) {\n        cout << int(round(C[i].real()))\
    \ << endl;\n    }\n\n    return 0;\n}"
  dependsOn: []
  isVerificationFile: false
  path: convolution/fft.cpp
  requiredBy: []
  timestamp: '2024-06-21 02:11:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: convolution/fft.cpp
layout: document
redirect_from:
- /library/convolution/fft.cpp
- /library/convolution/fft.cpp.html
title: convolution/fft.cpp
---