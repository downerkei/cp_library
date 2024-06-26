---
title: 遅延伝搬反転可能スプレー木
documentation_of: //data_structure/lazy_reversible_splay_tree.hpp
---

## 概要

遅延伝搬反転可能スプレー木

挿入，削除，区間作用，区間反転，区間積取得が償却 $O(\log n)$ で行える配列

## コンストラクタ

```cpp
LazyReversibleSplayTree<S, op, e, reverse_prod, F, mapping, composition, id> st;
```

* モノイドの型`S`
* $S \times S \to S$ を計算する関数`S op(S l, S r)`
* $e$ を返す関数`S e()`
* $S$ を反転させる関数`void reverse_prod(S& x)`
* 写像の型`F`
* $f(x)$ を返す関数`S mapping(F f, S x)`
* $f \circ g$ を返す関数`F composition(F f, F g)`
* $id$ を返す関数`F id()`


## insert_at

```cpp
void st.insert_at(int k, S x)
```

* 長さ$n$ の数列 $a$ に対し，$x$ を $a_k$ の直前に挿入する．
* $k = n$ ならば，数列の末尾に挿入する．

### 制約

* $0 \leq k \leq n$ 

### 計算時間

* 償却 $O(\log n)$


## erase_at

```cpp
void st.erase_at(int k)
```

* 長さ $n$ の数列 $a$ に対し，$a_k$ を削除する．
* 残った要素は連結される．

### 制約

* $0 \leq k < n$

### 計算時間

* 償却 $O(\log n)$


## get

```cpp
S st.get(int k)
```

* 配列の $k$ 番目の要素を返す.

### 制約

* $0 \leq k < n$

### 計算時間

* 償却 $O(\log n)$


## prod

```cpp
S st.prod(int l, int r)
```

* `op(a[l], ..., a[r - 1])` を，モノイドの性質を満たしていると仮定して計算する．$l=r$ のときは `e()` を返す．

### 制約

* $0 \leq l \leq r \leq n$

### 計算時間

* 償却 $O(\log n)$


## apply

```cpp
void st.apply(int l, int r, F f)
```

* `i = l..r-1` について `a[i] = f(a[i])`

### 制約

* $0 \leq l \leq r \leq n$

### 計算時間

* 償却 $O(\log n)$


## reverse

```cpp
void st.reverse(int l, int r)
```

* 区間 $[l, r)$ を反転させる．

### 制約

* $0 \leq l \leq r \leq n$

### 計算時間

* 償却 $O(\log n)$
