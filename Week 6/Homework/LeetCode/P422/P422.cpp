class Solution {
public:
    double myPow(double x, int n) {
        if (n == 1) return x;
        if (x == 1) return 1;
        if (x == -1) {
            if (n%2 == 0) return 1;
            else return -1;
        }
        if (x == 0) {
            if (n > 0) return 0;
            else return -1;
        }
        if (n > 0) {
            double a = (double) x;
            while (n != 1) {
                x *= a;
                n--;
            }

            return x;
        }
        else if (n < 0) {
            x = (double) 1/x;
            double a = (double) x;
            while (n != -1 && x != 0) {
                x *= a;
                n++;
            }

            return x;
        }
        else return 1;
    }
};