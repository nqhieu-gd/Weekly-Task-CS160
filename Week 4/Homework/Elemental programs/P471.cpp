#include <iostream>

int main() {
    int n, m, p, q;
    std::cout << "Enter a positive integer as number of rows of the first array: ";
    std::cin >> n;
    std::cout << "Enter a positive integer as number of columns of the first array: ";
    std::cin >> m;
    std::cout << "Please enter array elements one by one: " << '\n';
    int ar[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> ar[i][j];
        }
    }
    std::cout << "Enter a positive integer as number of rows of the second array: ";
    std::cin >> p;
    std::cout << "Enter a positive integer as number of columns of the second array: ";
    std::cin >> q;
    if (m != p) {
        std::cout << "Unable to calculate the product of the two matrices.";
        return 0;
    }
    std::cout << "Please enter array elements one by one: " << '\n';
    int br[p][q], cr[n][q];
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < q; j++) {
            std::cin >> br[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < q; j++) {
            cr[i][j] = 0;
            for (int k = 0; k < p; k++) {
                cr[i][j] += ar[i][k] * br[k][j];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < q; j++) {
            std::cout << cr[i][j] << ' ';
        }
        std::cout << '\n';
    }
    
    return 0;
}  