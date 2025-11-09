#include <iostream>
#include <cmath>
#include <vector>

int main() {
    int n, m, p, c;
    std::cout << "Enter a positive integer: ";
    std::cin >> n;
    std::cout << "Please enter starting index number: ";
    std::cin >> m;
    std::cout << "Please enter number of input to be deleted: ";
    std::cin >> p;
    std::cout << "Please enter array elements one by one: ";
    std::vector<int> ar;
    for (int i = 0; i < n; i++) {
        std::cin >> c;
        ar.push_back(c);
    }
    ar.erase(ar.begin() + m, ar.begin() + m + p);
    std::cout << "Array after process: ";
    for (int x : ar) {
        std::cout << x << ' ';
    }

    return 0;
}  