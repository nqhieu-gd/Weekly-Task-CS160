#include <iostream>
#include <climits>

int main() {
    int n, m;
    std::cout << "Enter a positive integer as number of rows: ";
    std::cin >> n;
    std::cout << "Enter a positive integer as number of columns: ";
    std::cin >> m;
    std::cout << "Please enter array elements one by one: " << '\n';
    int ar[n][m], br[n][m], cr[n*m], min = INT_MAX, k = 1, a, b;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> ar[i][j];
        }
    }
    for (int l = 0; l < n*m; l++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (ar[i][j] < min) {
                    min = ar[i][j];
                    a = i;
                    b = j;
                }
            }
        }
        cr[l] = min;
        min = INT_MAX;
        ar[a][b] = INT_MAX;
    }
//    for (int l = 0; l < n*m; l++) {
//        std::cout << cr[l] << ' ';
//    }
    br[0][0] = cr[0];
    for (int i = 0; i < n/2; i++) {
        for (int j = i + 1; j < m - i && k < n*m; j++) {
            br[i][j] = cr[k];
            k++;
        }
        for (int j = i + 1; j < n - i && k < n*m; j++) {
            br[j][m - i - 1] = cr[k];
            k++;
        }
        for (int j = m - i - 2; j >= i && k < n*m; j--) {
                br[n - i - 1][j] = cr[k];
            k++;
        }
        for (int j = n - i - 2; j > i && k < n*m; j--) {
            br[j][i] = cr[k];
            k++;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cout << br[i][j] << ' ';
        }
        std::cout << '\n';
    }
    
    return 0;
}  