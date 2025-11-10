#include <iostream>
#include <fstream>
#include "divisors.cpp"
#include "sum.cpp"
#include "Fraction.h"

int main() {
    int choice;
    std::cout << "Enter your choice (1-4): ";
    std::cin >> choice;
    if (choice < 1 || choice > 4 || (!choice)) {
        std::cout << "Invalid choice!" << std::endl;
        return 0;
    }
    if (choice == 1) {
        std::cout << "Proceed to run P02 problem." << std::endl;
        int n;
        std::cout << "Enter a non-negative integer: ";
        std::cin >> n;
        if (n < 0) {
            std::cout << "Invalid input.";
            return 0;
        }
        else std::cout << "Sum of squares up to " << n << " is " << sum(n) << std::endl;
    }
    else if (choice == 2) {
        std::cout << "Proceed to run P20 problem." << std::endl;
        int n;
        std::cout << "Enter a positive integer: ";
        std::cin >> n;
        if (n <= 0) {
            std::cout << "Invalid input.";
            return 0;
        }
        else {
            std::cout << "List of all divisors of " << n << " : ";
            list(n);
        }
    }
    else if (choice == 3) {
        std::cout << "Proceed to run P23 problem." << std::endl;
        int n;
        std::cout << "Enter a positive integer: ";
        std::cin >> n;
        if (n <= 0) {
            std::cout << "Invalid input.";
            return 0;
        }
        else {
            std::cout << "Number of divisors of " << n << " : " << num(n);
        }
    }
    else {
        std::cout << "Proceed to run P400 problem." << std::endl;
        Fraction a, b;
        std::cout << "Enter numerator and denominator of first fraction: ";
        std::cin >> a.numerator >> a.denominator;
        std::cout << "Enter numerator and denominator of second fraction: ";
        std::cin >> b.numerator >> b.denominator;

        Fraction add_x = add(a, b);
        Fraction sub_x = sub(a, b);

        std::cout << "Sum of the 2 fractions: " << add_x.numerator << "/" << add_x.denominator << std::endl;
        std::cout << "Sub of the 2 fractions: " << sub_x.numerator << "/" << sub_x.denominator << std::endl;
    }

    return 0;
}