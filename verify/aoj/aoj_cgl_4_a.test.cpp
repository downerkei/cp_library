#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_A"

#include <bits/stdc++.h>
using namespace std;

#include "library/geometry/convex_hull.hpp"

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    int N;
    cin >> N;
    vector<Point> V(N);
    for(int i = 0; i < N; i++) {
        cin >> V[i].x >> V[i].y;
    }

    auto hull = convex_hull(V);

    cout << hull.size() << "\n";
    for(auto p : hull) {
        cout << p.x << " " << p.y << "\n";
    }

    return 0;
}