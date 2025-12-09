#include <iostream>
#include <fstream>
#include "Func.cpp"

int main() {
    std::ifstream fin;
    std::ofstream fout;
    int choice = 0;
    std::cout << "Choose a function:";
    Selection(choice);
    while (choice != 0) {
        switch (choice) {
            case 1: {
                SubSelection(choice);
                DA<int> d;
                int med = 0;
                if (choice == 1) {
                    int s;
                    std::cin >> s;
                    GenArray(s, d);
                    FArrayOut(fout, d, "Binary.bin");
                }
                else {
                    FArrayIn(fin, d, "Binary.bin");
                    FiMed(d, med);
                    std::cout << med;
                }
                Selection(choice);
                break;
            }
            case 2: {
                SubSelection(choice);
                DA<Date> da;
                if (choice == 1) {
                    int s;
                    std::cin >> s;
                    GenArray(s, da);
                    FDateOut(fout, da, "Binary.bin");
                }
                else {
                    Date d;
                    FDateIn(fin, da, "Binary.bin");
                    NewestDate(da, d);
                    DisplayDate(d);
                }
                Selection(choice);
                break;
            }
            Default: break;
        }
    }

    return 0;
}