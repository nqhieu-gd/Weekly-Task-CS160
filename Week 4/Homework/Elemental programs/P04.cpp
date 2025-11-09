#include <iostream>
#include <cmath>

int main() {
    int n;
    std::cout << "Enter a positive integer (1-100): ";
    std::cin >> n;
    if (n < 1 || n > 100) {
        std::cout << "Try again for valid number(s).";
        return 0;
    }
    std::cout << "Please enter array elements one by one: ";
    int ar[n];
    for (int i = 0; i < n; i++) {
        std::cin >> ar[i];
    }
    std::cout << "Prime number found (if there are any): ";
    for (int x : ar) {
        if(x % 2 == 0 && x > 2) {
            continue;
        }
        else if (x < 2) {
            continue;
        }
        else {
            bool isp = false;
            for (int i = 3; i <= sqrt(x); i++){
                if (x % i == 0) {
                    isp = true;
                    break;
                }
            }
            if (isp) continue;
            else std::cout << x << ' ';
        }
    }

    return 0;
}  