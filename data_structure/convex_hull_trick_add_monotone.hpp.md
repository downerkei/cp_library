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
  bundledCode: "#line 1 \"data_structure/convex_hull_trick_add_monotone.hpp\"\ntemplate<typename\
    \ T=long long>\nstruct ConvexHullTrickAddMonotone {\n    vector<pair<T, T>> lines;\n\
    \    int ptr = 0;\n\n    inline double intersect_x(const pair<T, T>& a, const\
    \ pair<T, T>& b) {\n        return double(b.second - a.second) / double(a.first\
    \ - b.first);\n    }\n\n    inline T f(const pair<T, T>& l, T x) {\n        return\
    \ l.first * x + l.second;\n    }\n\n    void add(T a, T b) {\n        pair<T,\
    \ T> new_line = {a, b};\n        while(lines.size() >= 2) {\n            double\
    \ x_last = intersect_x(lines[lines.size() - 2], lines.back());\n            double\
    \ x_new = intersect_x(lines[lines.size() - 2], new_line);\n            if(x_new\
    \ <= x_last) lines.pop_back();\n            else break;\n        }\n        lines.push_back(new_line);\n\
    \    }\n\n    T get_min(T x) {\n        if(ptr >= (int)lines.size()) ptr = lines.size()\
    \ - 1;\n        while(ptr < (int)lines.size() - 1 && f(lines[ptr], x) >= f(lines[ptr\
    \ + 1], x)) ptr++;\n        return f(lines[ptr], x);\n    }\n};\n"
  code: "template<typename T=long long>\nstruct ConvexHullTrickAddMonotone {\n   \
    \ vector<pair<T, T>> lines;\n    int ptr = 0;\n\n    inline double intersect_x(const\
    \ pair<T, T>& a, const pair<T, T>& b) {\n        return double(b.second - a.second)\
    \ / double(a.first - b.first);\n    }\n\n    inline T f(const pair<T, T>& l, T\
    \ x) {\n        return l.first * x + l.second;\n    }\n\n    void add(T a, T b)\
    \ {\n        pair<T, T> new_line = {a, b};\n        while(lines.size() >= 2) {\n\
    \            double x_last = intersect_x(lines[lines.size() - 2], lines.back());\n\
    \            double x_new = intersect_x(lines[lines.size() - 2], new_line);\n\
    \            if(x_new <= x_last) lines.pop_back();\n            else break;\n\
    \        }\n        lines.push_back(new_line);\n    }\n\n    T get_min(T x) {\n\
    \        if(ptr >= (int)lines.size()) ptr = lines.size() - 1;\n        while(ptr\
    \ < (int)lines.size() - 1 && f(lines[ptr], x) >= f(lines[ptr + 1], x)) ptr++;\n\
    \        return f(lines[ptr], x);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/convex_hull_trick_add_monotone.hpp
  requiredBy: []
  timestamp: '2025-02-11 03:05:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/convex_hull_trick_add_monotone.hpp
layout: document
title: "\u50BE\u304D\u5358\u8ABFCHT"
---

## 概要

直線 $ax + b$ の追加クエリとある点 $x$ での最小値クエリ．

追加クエリの傾き $a$ が単調減少の場合のみ．

$a$ が単調増加で最大値クエリの場合は $a$ と $b$ をそれぞれ符号反転して，傾き単調減少な最小値クエリとする．

## コンストラクタ

```cpp
ConvexHullTrickAddMonotone<T> cht;
```

* デフォルトコンストラクタ．初期状態で直線はない．

### 制約

* $T$ は整数型．直線 $ax + b$ における $a, b, x$ の型．


## add

```cpp
void cht.add(T a, T b);
```

* 直線 $ax + b$ を追加する．

### 制約

* $a$ は追加順で単調減少である必要がある．

### 計算時間

* 償却 $O(1)$


## get_min

```cpp
T cht.get_min(T x);
```

* $ax + b$ の最小値を求める．

### 制約

* $x$ が単調増加である必要がある．

* $x$ が単調減少の場合，`lines` 末尾の2つを比較し，最小となるまで `lines.pop_back()` を繰り返す．

* $x$ が単調でない場合，`lines` 上で二分探索．

### 計算時間

* $x$ が単調の場合，償却 $O(1)$

* $x$ が単調でない場合，直線の数を $n$ として $O(\log n)$


## 使用例

```cpp
int main() {
    int N;
    cin >> N;
    vector<long long> A(N), B(N), dp(N, 0);
    for(int i = 0; i < N; i++) 
        cin >> A[i];
    
    for(int i = 0; i < N; i++) 
        cin >> B[i];
    

    ConvexHullTrickAddMonotone cht;
    cht.add(B[0], dp[0]);
    for(int i = 1; i < N; i++) {
        dp[i] = cht.get_min(A[i]);
        cht.add(B[i], dp[i]);
    }

    cout << dp[N - 1] << "\n";

    return 0;
}
```