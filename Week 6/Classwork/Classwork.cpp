#include <iostream>
#include "Fraction.h"
#include <cmath>
#include "Triangle.h"

int main() {
    int choice = 0;
    std::cout << "Choose one problem (2 or 3): ";
    std::cin >> choice;
    if (choice == 2) {
        std::cout << "Proceed to P412 problem.\n";
        Fraction d;
        std::cout << "Enter your desired work(1-4): ";
        std::cin >> choice;
        if (choice == 1)  {
            std::cout << "Proceed to input a fraction.";
            d = FraIn();
        }
        else if (choice == 2) {
            std::cout << "Proceed to output the last input fraction.";
            FraOut(d);
        }
        else if (choice == 3) {
            Fraction a, b;
            std::cout << "Proceed to add 2 fractions.\n";
            std::cout << "Enter the first fraction: \n";
            a = FraIn();
            std::cout << "Enter the second fraction: \n";
            b = FraIn();
            std::cout << "Sum of 2 fractions: ";
            FraOut(FraAdd(a,b));
        }
        else if (choice == 4) {
            Fraction a, b;
            std::cout << "Proceed to subtract 2 fractions.\n";
            std::cout << "Enter the first fraction: \n";
            a = FraIn();
            std::cout << "Enter the second fraction: \n";
            b = FraIn();
            std::cout << "Sub of 2 fractions: ";
            FraOut(FraSub(a,b));
        }
    }
}