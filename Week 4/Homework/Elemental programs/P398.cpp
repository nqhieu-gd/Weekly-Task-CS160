#include <iostream>

int main() {
    int n, m;
    std::cout << "Enter a positive integer as number of rows: ";
    std::cin >> n;
    std::cout << "Enter a positive integer as number of columns: ";
    std::cin >> m;
    std::cout << "Please enter array elements one by one: " << '\n';
    int ar[n][m], br[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> ar[i][j];
        }
    }
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < m - 1; j++) {
            br[i][j] = ar[i][j];
        }
    }
    for (int j = 1; j < m; j++) {
        br[0][j] = ar[0][j - 1];
        br[n-1][m - 1 - j] = ar[n-1][m - j];
    }
    for (int j = 1; j < n; j++) {
        br[n - 1 - j][0] = ar[n - j][0];
        br[j][m - 1] = ar[j - 1][m - 1];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cout << br[i][j] << ' ';
        }
        std::cout << '\n';
    }
    
    return 0;
}  