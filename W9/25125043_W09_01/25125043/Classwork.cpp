#include <iostream>
#include <fstream>
#include "Func.cpp"

int main() {
    std::ifstream fin;
    std::ofstream fout;
    DA d;
    int choice = 0;
    std::cout << "Choose a function: \n" << "1. Output an array from keyboard to binary file.\n" << "2. Find median of an array.\n";
    std::cin >> choice;
    if (choice < 1 || choice > 2) {
        std::cerr << "Invalid choice.";
        return 1;
    }
    else if (choice == 1) {
        int s;
        std::cin >> s;
        GenArray(s, d);
        FArrayOut(fout, d, "Binary.bin");
    }
    else {
        FArrayIn(fin, d, "Binary.bin");
    }

    return 0;
}