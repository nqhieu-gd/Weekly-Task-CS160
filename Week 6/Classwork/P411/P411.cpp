#include <iostream>

int myAtoi(std::string s) {
    int id = 0;
    int n = s.length();
    while (id < n && s[id] == ' ') {
        id++;
    }
    if (id >= n) return 0;
    int mul = 1;
    if (s[id] == '+' || s[id] == '-') {
        mul = (s[id] == '-') ? -1 : 1;
        id++;
    }
    if (id >= n || s[id] < '0' || s[id] > '9') return 0;

    long long res = 0;
    while (id < n && s[id] >= '0' && s[id] <= '9') {
        res = res * 10 + (s[id] - '0');
        if (res * mul > INT_MAX) return INT_MAX;
        if (res * mul < INT_MIN) return INT_MIN;
        
        id++;
    }
    
    return (int)(res * mul);
}