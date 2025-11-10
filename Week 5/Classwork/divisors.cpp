#include <iostream>

void list(int n) {
    for (int i = 1; i <= n; ++i) {
        if (n % i == 0) {
            std::cout << i << " ";
        }
    }
}

int num(int n) {
    int count = 0;
    for (int i = 1; i*i <=  n; ++i) {
        if (n % i == 0) {
            count+= 2;
        }
        if (i*i == n) {
            count--;
        }
    }
    return count;
}