#include <climits>

int reverse(int x) {
    int a = INT_MAX, b = INT_MIN, r = 0;
    while (x != 0) {
        if (!(x < 10 && (r > a/10 || r == a/10 && x > 7 || r < b/10 || r == b/10 && x < -8))) {
            r = r*10 + x%10;
            x = x/10;
        }
        else return 0;
    }

    return r;
}