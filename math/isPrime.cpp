#include <bits/stdc++.h>
using namespace std;

bool isPrime(int p) {
    if(p < 2) return false;

    for(int i = 2; i * i <= p; i++) {
        if(p % i == 0) return false;
    }

    return true;
}

int main() {
    for(int i = 0; i < 10; i++) {
        cout << i << ": " << isPrime(i) << endl;
    }

    return 0;
}