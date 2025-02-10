template<typename T=long long>
struct ConvexHullTrickAddMonotone {
    vector<pair<T, T>> lines;
    int ptr = 0;

    inline double intersect_x(const pair<T, T>& a, const pair<T, T>& b) {
        return double(b.second - a.second) / double(a.first - b.first);
    }

    inline T f(const pair<T, T>& l, T x) {
        return l.first * x + l.second;
    }

    void add(T a, T b) {
        pair<T, T> new_line = {a, b};
        while(lines.size() >= 2) {
            double x_last = intersect_x(lines[lines.size() - 2], lines.back());
            double x_new = intersect_x(lines[lines.size() - 2], new_line);
            if(x_new <= x_last) lines.pop_back();
            else break;
        }
        lines.push_back(new_line);
    }

    T get_min(T x) {
        if(ptr >= (int)lines.size()) ptr = lines.size() - 1;
        while(ptr < (int)lines.size() - 1 && f(lines[ptr], x) >= f(lines[ptr + 1], x)) ptr++;
        return f(lines[ptr], x);
    }
};
