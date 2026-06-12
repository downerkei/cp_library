#pragma once

#include <bits/stdc++.h>
using namespace std;

struct Parser {
    string s;
    int pos = 0;

    Parser(const string& s) : s(s) {}

    bool eof() const {
        return pos >= (int)s.size();
    }

    char peek() const {
        if (eof()) return '\0';
        return s[pos];
    }

    bool accept(char c) {
        if (peek() == c) {
            pos++;
            return true;
        }
        return false;
    }

    void expect(char c) {
        assert(accept(c));
    }

    int number() {
        assert(isdigit(peek()));

        int val = 0;
        while (!eof() && isdigit(peek())) {
            val = val * 10 + (peek() - '0');
            pos++;
        }
        return val;
    }
};
