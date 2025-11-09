#include <iostream>

int main() {
    int n, m;
    std::cout << "Enter a positive integer as number of rows: ";
    std::cin >> n;
    std::cout << "Enter a positive integer as number of columns: ";
    std::cin >> m;
    std::cout << "Please enter array elements one by one: " << '\n';
    int ar[n][m], sum[n];
    for (int i = 0; i < n; i++) {
        sum[i] = 0;
        std::cout << i << ": ";
        for (int j = 0; j < m; j++) {
            std::cin >> ar[i][j];
            sum[i] += ar[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        std::cout << "sum of values in row index " << i << " is " << sum[i] << '\n';
    }
    
    return 0;
}  