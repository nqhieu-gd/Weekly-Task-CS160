#include <fstream>
#include <iostream>
#include "DynamicArray.h"

void GenArray(int size, DA &d) {
    int k = 0;
    d.alloc();
    for (int i = 0; i < size; i++) {
        std::cin >> k;
        d.push(k);
    }
}

void FArrayOut(std::ofstream& fout, DA &d, const char* file) {
    fout.open(file);
    if (!fout) {
        std::cerr << "Error opening file.";
        return;
    }
    fout.write((char*)&(d.store), sizeof(d.store));
    for (int i = 0; i < d.store; i++) {
        fout.write((char*)&(d.p[i]), sizeof(d.p[i]));
    }
    d.dealloc();
    fout.close();
}

void FiMed(DA &d, int &med) {
    if (d.store%2 == 1) med = d.p[d.store/2];
    else med = (float) (d.p[d.store/2 - 1] + d.p[d.store/2])/2;
    std::cout << med;
}

void FArrayIn(std::ifstream& fin, DA &d, const char* file) {
    fin.open(file);
    if (!fin) {
        std::cerr << "Error opening file.";
        return;
    }
    d.alloc();
    fin.read((char*) &(d.store), sizeof(d.store));
    for (int i = 0; i < d.store; i++) {
        fin.read((char*)&(d.p[i]), sizeof(d.p[i]));
    }
    fin.close();
    int med = 0;
    FiMed(d, med);
    d.dealloc();
}