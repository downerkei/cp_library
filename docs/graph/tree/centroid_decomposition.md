---
title: 重心分解
documentation_of: //graph/tree/centroid_decomposition.hpp
---

## 概要

重心分解

木において，ある頂点を取り除くといくつかの木に分裂する．分裂後の木のサイズがすべて元のサイズの半分以下の場合，その頂点を木の重心という．

重心を取り除いた部分木についても再帰的に分解を行い，最終的にサイズが1になるまで続ける．

## コンストラクタ

```cpp
CentroidDecomposition cd(const vector<vector<int>>& G);
```

* 連結リスト`G`を入力として，重心同士を結んだ根付き木`T`を連結リストで構築．また，`T`をdfs行きがけ順で探索したものを`ord`，`T`の根を`r`に格納する．