#include <iostream>
#include <fstream>

int main() {
    int k = 0;
    std::ifstream fin;
    fin.open("Binary.bin");
    while(fin) {
        fin.read((char*) &k, sizeof(k));
        std::cout << k << '\n';
    }

    return 0;
}