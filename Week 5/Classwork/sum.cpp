#include <iostream>

int sum(int n) {
    int s = 0;
    for (int i = 1; i <= n; ++i) {
        s += n*n;
    }

    return s;
}