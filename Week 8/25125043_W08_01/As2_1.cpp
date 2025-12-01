#include <iostream>
#include <fstream>
#include "func.cpp"

int main() {
    std::ifstream fin;
    std::ofstream fout;
    fin.open("seq.txt");
    fout.open("out.txt");
    if (!fin) {
        std::cerr << "Error opening file.\n";
        return 1;
    }

    Node* pHead = nullptr;
    
    genList(fin, pHead);
    subList(pHead, 2);
    outList(fout, pHead);

    fout.close();
    fin.close();
    return 0;
}