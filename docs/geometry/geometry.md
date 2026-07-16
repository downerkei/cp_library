---
title: Geometry
documentation_of: //geometry/geometry.hpp
---

## 概要

2次元幾何ライブラリ．

点，直線・線分，多角形，円に対する基本演算をまとめている．
実数型は `double`，誤差判定は `EPS = 1e-7` を使う．

```cpp
#include "geometry/geometry.hpp"
```

## 基本

```cpp
using Real = double;
constexpr Real EPS = 1e-7;
constexpr Real PI = numbers::pi;
```

### sgn

```cpp
int sgn(Real a)
```

* `a < -EPS` なら `-1`
* `-EPS <= a <= EPS` なら `0`
* `EPS < a` なら `1`

計算時間は $O(1)$．

## Point

```cpp
struct Point {
    Real x, y;
};
```

2次元ベクトルを表す．複素数のように足し算，引き算，スカラー倍，回転などができる．

### コンストラクタ

```cpp
Point p(Real x = 0, Real y = 0)
```

### 演算

```cpp
p + q
p - q
p * k
k * p
p / k
-p
```

`Point` 同士の `*`，`/` は複素数としての積・商を表す．

```cpp
p * q
p / q
```

比較は `x`，次に `y` の辞書順で行う．等号は `EPS` を考慮する．

```cpp
p < q
p == q
```

### 関数

```cpp
Real norm2(Point p)
Real norm(Point p)
Real arg(Point p)
Point rot(Point p, Real theta)
Point rot90(Point p)
Point conj(Point p)
Real dot(Point a, Point b)
Real cross(Point a, Point b)
Point polar(Real r, Real theta)
```

* `norm2(p)` は $|p|^2$ を返す．
* `norm(p)` は $|p|$ を返す．
* `arg(p)` は偏角を返す．
* `rot(p, theta)` は `p` を `theta` ラジアン回転する．
* `rot90(p)` は `p` を反時計回りに $90^\circ$ 回転する．
* `conj(p)` は `p` の共役を返す．
* `dot(a, b)` は内積を返す．
* `cross(a, b)` は外積を返す．
* `polar(r, theta)` は極座標 $(r, theta)$ の点を返す．

計算時間はいずれも $O(1)$．

## ccw

```cpp
int ccw(Point a, Point b, Point c)
```

点 `a` から見た `b`，`c` の位置関係を返す．

| 返り値 | 意味 |
| --- | --- |
| `1` | `a -> b -> c` が反時計回り |
| `-1` | `a -> b -> c` が時計回り |
| `2` | `c, a, b` の順に一直線上 |
| `-2` | `a, b, c` の順に一直線上 |
| `0` | `c` が線分 `ab` 上 |

計算時間は $O(1)$．

## Line

```cpp
struct Line {
    Point s, t;
};
```

直線または線分を表す．関数名の `l` は直線，`s` は線分として扱うことを表す．

### コンストラクタ

```cpp
Line l(Point s = Point(0, 0), Point t = Point(0, 0))
```

### 関数

```cpp
Point dir(Line l)
Real norm(Line l)
Point normalize(Line l)
Point projection(Line l, Point p)
Point reflection(Line l, Point p)
bool is_parallel(Line a, Line b)
bool is_orthogonal(Line a, Line b)
bool is_intersect(Line a, Line b)
Point cross_ll(Line a, Line b)
```

* `dir(l)` は方向ベクトル `l.t - l.s` を返す．
* `norm(l)` は `dir(l)` の長さを返す．
* `normalize(l)` は単位方向ベクトルを返す．
* `projection(l, p)` は点 `p` の直線 `l` への射影を返す．
* `reflection(l, p)` は点 `p` の直線 `l` に関する反射点を返す．
* `is_parallel(a, b)` は2直線が平行かを返す．
* `is_orthogonal(a, b)` は2直線が直交するかを返す．
* `is_intersect(a, b)` は2線分が交差するかを返す．
* `cross_ll(a, b)` は2直線の交点を返す．平行でないことが前提．

計算時間はいずれも $O(1)$．

## 距離

```cpp
Real dist_pp(Point a, Point b)
Real dist_lp(Line l, Point p)
Real dist_sp(Line s, Point p)
Real dist_ss(Line a, Line b)
```

* `dist_pp(a, b)` は点と点の距離を返す．
* `dist_lp(l, p)` は直線 `l` と点 `p` の距離を返す．
* `dist_sp(s, p)` は線分 `s` と点 `p` の距離を返す．
* `dist_ss(a, b)` は線分 `a` と線分 `b` の距離を返す．

計算時間はいずれも $O(1)$．

## Polygon

```cpp
struct Polygon : public vector<Point> {};
```

多角形を表す．頂点は順番に入れる．

### 関数

```cpp
Real area(Polygon pol)
bool is_convex(Polygon pol)
pair<int, int> diameter(Polygon pol)
int contain(Polygon pol, Point p)
Polygon convex_hull(Polygon pol)
Polygon convex_cut(Polygon pol, Line l)
Real closest_pair(vector<Point> ps)
```

* `area(pol)` は符号付き面積を返す．頂点が反時計回りなら正になる．
* `is_convex(pol)` は凸多角形かを返す．時計回りの曲がりがあると `false`．
* `diameter(pol)` は凸多角形の最遠点対の添字を返す．`pol` が凸であることが前提．
* `contain(pol, p)` は点 `p` と多角形 `pol` の包含関係を返す．
* `convex_hull(pol)` は点集合の凸包を返す．
* `convex_cut(pol, l)` は凸多角形 `pol` を直線 `l` の左側で切った凸多角形を返す．
* `closest_pair(ps)` は点集合の最近点対距離を返す．

### contain

```cpp
int contain(Polygon pol, Point p)
```

| 返り値 | 意味 |
| --- | --- |
| `2` | 内部 |
| `1` | 辺上 |
| `0` | 外部 |

### 計算時間

* `area`: $O(n)$
* `is_convex`: $O(n)$
* `diameter`: $O(n)$
* `contain`: $O(n)$
* `convex_hull`: $O(n \log n)$
* `convex_cut`: $O(n)$
* `closest_pair`: $O(n \log n)$

## Circle

```cpp
struct Circle {
    Point p;
    Real r;
};
```

中心 `p`，半径 `r` の円を表す．

### コンストラクタ

```cpp
Circle c()
Circle c(Point p, Real r)
```

## 円の関数

```cpp
int intersection(Circle c1, Circle c2)
pair<Point, Point> cross_cl(Circle c, Line l)
Circle incircle(Point a, Point b, Point c)
Circle outcircle(Point a, Point b, Point c)
pair<Point, Point> cross_cc(Circle c1, Circle c2)
pair<Point, Point> tangent_cp(Circle c, Point p)
vector<Line> tangent_cc(Circle c1, Circle c2)
Real common_area_cp(Circle c, Polygon pol)
Real common_area_cc(Circle c1, Circle c2)
```

* `intersection(c1, c2)` は2円の位置関係を返す．
* `cross_cl(c, l)` は円 `c` と直線 `l` の交点を返す．交点があることが前提．
* `incircle(a, b, c)` は三角形 `abc` の内接円を返す．
* `outcircle(a, b, c)` は三角形 `abc` の外接円を返す．
* `cross_cc(c1, c2)` は2円の交点を返す．交点があることが前提．
* `tangent_cp(c, p)` は点 `p` から円 `c` へ引いた2本の接線の接点を返す．
* `tangent_cc(c1, c2)` は2円の共通接線を返す．
* `common_area_cp(c, pol)` は円 `c` と多角形 `pol` の共通部分の面積を返す．
* `common_area_cc(c1, c2)` は2円の共通部分の面積を返す．

### intersection

```cpp
int intersection(Circle c1, Circle c2)
```

| 返り値 | 意味 |
| --- | --- |
| `4` | 離れている |
| `3` | 外接する |
| `2` | 2点で交わる |
| `1` | 内接する |
| `0` | 一方が他方の内部にあり交わらない |

### 計算時間

* `intersection`: $O(1)$
* `cross_cl`: $O(1)$
* `incircle`: $O(1)$
* `outcircle`: $O(1)$
* `cross_cc`: $O(1)$
* `tangent_cp`: $O(1)$
* `tangent_cc`: $O(1)$
* `common_area_cp`: $O(n)$
* `common_area_cc`: $O(1)$

## 使用例

```cpp
#include <bits/stdc++.h>
#include "geometry/geometry.hpp"
using namespace std;

int main() {
    Point a(0, 0), b(3, 0), c(0, 4);

    cout << dist_pp(a, b) << endl;       // 3
    cout << area(Polygon{a, b, c}) << endl; // 6

    Line s(a, b);
    cout << dist_sp(s, c) << endl;       // 4
}
```
