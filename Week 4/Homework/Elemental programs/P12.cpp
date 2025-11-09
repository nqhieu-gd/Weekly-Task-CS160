#include <iostream>

int main() {
    int n, max, max2;
    std::cout << "Enter a positive integer: ";
    std::cin >> n;
    if (n < 2) {
        std::cout << "Try again for valid number(s) (>=2).";
        return 0;
    }
    std::cout << "Please enter array elements one by one: ";
    int ar[n];
    std::cin >> ar[0];
    max = ar[0];
    max2 = max + 1;
    for (int i = 1; i < n; i++) {
        std::cin >> ar[i];
        if (ar[i] > max) {
            max2 = max;
            max = ar[i];
        }
        if (ar[i] < max && ar[i] > max2) max2 = ar[i];
    }
    if (max2 == max + 1) {
        std::cout << "There is no second largest number.";
        return 0;
    }
    std::cout << "The second largest number is: " << max2;

    return 0;
}  