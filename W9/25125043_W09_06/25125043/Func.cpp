#include <fstream>
#include <iostream>
#include "DynamicArray.h"
#include "Func.h"

void Selection (int &choice) {
    std::cout << "Choose a problem: ";
    std::cin >> choice;
    if (choice < 0 || choice > 6) {
        std::cerr << "Invalid choice. Try again. ";
        Selection(choice);
    }
}

void SubSelection (int choice) {
    std::cout << "Choose a function: ";
    std::cin >> choice;
    if (choice < 1 || choice > 2) {
        std::cerr << "Invalid choice. Try again. ";
        SubSelection(choice);
    }
}

void GenArray(int size, DA<int> &d) {
    int k = 0;
    d.alloc();
    for (int i = 0; i < size; i++) {
        std::cin >> k;
        d.push(k);
    }
}

void FArrayOut(std::ofstream& fout, DA<int> &d, const char* file) {
    fout.open(file);
    if (!fout) {
        std::cerr << "Error opening file.";
        return;
    }
    int s;
    std::cin >> s;
    GenArray(s, d);
    fout.write((char*)&(d.store), sizeof(d.store));
    for (int i = 0; i < d.store; i++) {
        fout.write((char*)&(d.p[i]), sizeof(d.p[i]));
    }
    d.dealloc();
    fout.close();
}

void FiMed(DA<int> &d, int &med) {
    if (d.store%2 == 1) med = d.p[d.store/2];
    else med = (float) (d.p[d.store/2 - 1] + d.p[d.store/2])/2;
}

void FArrayIn(std::ifstream& fin, DA<int> &d, const char* file) {
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
    d.dealloc();
}

Date date;

void Date :: GenDate() {
    int a, b, c;
    std::cin >> a >> b >> c;
    if (c % 4 == 0 && c % 100 != 0 || c %400 == 0) date.M[1] = 29;
    if (b >= 0 && b <= 12 && a >= 0 && a <= date.M[b - 1]) {
        date.day = a;
        date.month = b;
        date.year = c;
    }
    else std::cerr << "Invalid input, please try again.";
}

void GenArray(int size, DA<Date> &da) {
    Date k;
    da.alloc();
    for (int i = 0; i < size; i++) {
        k.GenDate();
        da.push(k);
    }
}

void FDateOut(std::ofstream &fout, DA<Date> &da, const char* file) {
    fout.open(file);
    if (!fout) {
        std::cerr << "Error opening file.";
        return;
    }
    int s;
    std::cin >> s;
    GenArray(s, da);
    fout.write((char*) &(da.store), sizeof(da.store));
    for (int i = 0; i < da.store; i++) {
        fout.write((char*) &(da.p[i]), sizeof(da.p[i]));
    }
    da.dealloc();
    fout.close();
}

bool CompDate(Date a, Date b) {
    return (a.year > b.year || a.year == b.year && a.month > b.month || a.year == b.year && a.month == b.month && a.day >= b.day)? 1 : 0;
}

void NewestDate(DA<Date> da, Date &d) {
    d = da.p[0];
    for (int i = 1; i < da.store; i++) {
        if (CompDate(da.p[i], d)) d = da.p[i];
    }
}

void FDateIn(std::ifstream &fin, DA<Date> &da, const char* file) {
    fin.open(file);
    if (!fin) {
        std::cerr << "Error opening file.";
        return;
    }
    da.alloc();
    fin.read((char*) &(da.store), sizeof(da.store));
    for (int i = 0; i < da.store; i++) {
        fin.read((char*)&(da.p[i]), sizeof(da.p[i]));
    }
    fin.close();
    da.dealloc();
}

void DisplayDate(Date d) {
    std::cout << d.day << '/' << d.month << d.year;
}