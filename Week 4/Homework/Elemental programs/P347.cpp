#include <iostream>

int main() {
    int n, m;
    std::cout << "Enter a positive integer as number of rows: ";
    std::cin >> n;
    std::cout << "Enter a positive integer as number of columns: ";
    std::cin >> m;
    std::cout << "Please enter array elements one by one: " << '\n';
    int ar[n][m], saddle = 0, max;
    for (int i = 0; i < n; i++) {
        std::cout << i << ": ";
        for (int j = 0; j < m; j++) {
            std::cin >> ar[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        max = INT_MIN;
        for (int j = 0; j < m; j++) {
            if (ar[i][j] > max) {
                max = ar[i][j];
            }
            for (int k = 0; k < n; k++) {
                if (ar[k][j] < max) {
                    break;
                }
                if (k == n - 1 && ar[k][j] >= max) {
                    saddle += 1;
                }
            }
        }
    }
    std::cout << "Number of saddle points: " << saddle;
    
    return 0;
}  