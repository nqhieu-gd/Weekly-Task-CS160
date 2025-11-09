#include <iostream>

int main() {
    int n, m;
    std::cout << "Enter a positive integer as number of rows: ";
    std::cin >> n;
    std::cout << "Enter a positive integer as number of columns: ";
    std::cin >> m;
    if (n != m) {
        std::cout << "Matrix is not symmetrical.";
        return 0;
    }
    std::cout << "Please enter array elements one by one: " << '\n';
    int ar[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> ar[i][j];
        }
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < m; j++) {
            if (ar[i][j] != ar[j][i]) {
                std::cout << "Matrix is not symmetrical.";
                return 0;
            }
        }
    }
    std::cout << "Matrix is symmetrical in respect to the main diagonal.";
    
    return 0;
}  