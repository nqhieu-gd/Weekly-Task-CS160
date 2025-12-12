#include <iostream>
#include <fstream>
#include "Func.cpp"
#include "cmd.cpp"
#include "Bitmap\Func.cpp"

int main() {
    std::ifstream fin;
    std::ofstream fout;
    int choice = 0;
    Selection(choice);
    while (choice != 0) {
        switch (choice) {
            case 1: {
                SubSelection(choice);
                DA<int> d;
                int med = 0;
                if (choice == 1) {
                    FArrayOut(fout, d, "Binary.bin");
                }
                else {
                    FArrayIn(fin, d, "Binary.bin");
                    FiMed(d, med);
                    std::cout << med << '\n';
                }
                Selection(choice);
                break;
            }
            case 2: {
                SubSelection(choice);
                DA<Date> da;
                if (choice == 1) {
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
            case 3: {
                cmd c;
                std::string st;
                std::cin.ignore();
                std::getline(std::cin, st);
                c.MYCOPYFILE(st);
                Selection(choice);
                break;
            }
            case 4: {
                cmd c;
                std::string st;
                std::cin.ignore();
                std::getline(std::cin, st);
                c.MYSPLITFILE(st);
                Selection(choice);
                break;
            }
            case 5: {
                cmd c;
                std::string st;
                std::cin.ignore();
                std::getline(std::cin, st);
                c.MYMERGEFILE(st);
                Selection(choice);
                break;
            }
            case 6: {
                int a, b;
                std::cout << "Enter the flag's width: ";
                std::cin >> a;
                std::cout << "Enter the flag's height: ";
                std::cin >> b;
                std::cin.ignore();
                Image img(a, b);
                img.FlagGen();
                img.Export("Bitmap.bmp");
                Selection(choice);
                break;
            }
            Default: break;
        }
    }

    return 0;
}