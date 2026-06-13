#pragma once

#include <bits/stdc++.h>
using namespace std;

// 構文解析ひな型
struct Parser {
    string S;
    int N, it = 0;

    Parser(const string& S) : S(S), N(S.size()) {}

    // 読み終わりを判定する．
    bool eof() const {  
        return it >= N;
    }

    // 今の文字を返す，itは進めない．
    char peek() const {
        return eof() ? '\0' : S[it];
    }

    // あれば読む，boolを返す．
    bool accept(char c) {
        if (peek() == c) {
            it++;
            return true;
        }
        return false;
    }

    // 必ず読む，assertかかる．
    void expect(char c) {
        assert(accept(c));
    }

    // 数字を返す，intに注意．
    int number() {
        assert(isdigit(peek()));

        int val = 0;
        while (!eof() && isdigit(peek())) {
            val = val * 10 + (peek() - '0');
            it++;
        }
        return val;
    }
};
