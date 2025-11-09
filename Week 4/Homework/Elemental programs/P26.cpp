#include <iostream>

int main() {
    int n, m;
    std::cout << "Enter a positive integer as the first array's length: ";
    std::cin >> n;
    std::cout << "Enter a positive integer as the second array's length: ";
    std::cin >> m;
    std::cout << "Please enter first array's elements one by one: ";
    int ar[n], br[m];
    for (int i = 0; i < n; i++) {
        std::cin >> ar[i];
    }
    std::cout << "Please enter second array's elements one by one: ";
    for (int i = 0; i < m; i++) {
        std::cin >> br[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (ar[i] == br[j]) {
                std::cout << ar[i] << ' ';
            }
    }
    }

    return 0;
}  