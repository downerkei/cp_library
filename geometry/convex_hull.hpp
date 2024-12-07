#include "ccw.hpp"

vector<Point> convex_hull(vector<Point> V) {
    int N = V.size();

    auto cmp = [&](Point& a, Point& b) -> bool {
        return (a.y < b.y || (a.y == b.y && a.x < b.x));
    };

    sort(V.begin(), V.end(), cmp);

    vector<Point> ret;
    for(int i = 0; i < N; i++) {
        while(ret.size() > 1 && ccw(ret[ret.size() - 2], ret.back(), V[i]) == -1) ret.pop_back();
        ret.push_back(V[i]);
    }

    int t = ret.size();
    for(int i = N - 2; i >= 0; i--) {
        while(ret.size() > t && ccw(ret[ret.size() - 2], ret.back(), V[i]) == -1) ret.pop_back();
        ret.push_back(V[i]);
    }
    ret.pop_back();
    
    return ret;
}
