```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    // 座標圧縮したい数列
    vector<int> A = {8, 100, 33, 33, 33, 12, 6, 1211};

    // コピー
    vector<int> B = A;
    
    // B を小さい順にソート
    sort(B.begin(), B.end());
    
    // B から重複を除去する (A が相異なるときは省略可)
    B.erase(unique(B.begin(), B.end()), B.end());

    
    for (auto b: B) cout << b << ", ";
    cout << endl;
}
```