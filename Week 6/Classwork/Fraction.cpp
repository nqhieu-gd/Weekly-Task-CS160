#include <iostream>
#include "Fraction.h"

Fraction sim(Fraction a) {
    int m, n, d = a.denominator;
    while (!(a.numerator % d == 0 && a.denominator % d == 0 || d == 1)) {
        d = a.numerator % d;
        if (a.denominator % d != 0) {
            d = a.denominator % d;
        }
    }
    a.denominator = a.denominator/d;
    a.numerator = a.numerator/d;

    return a;
}

Fraction FraIn() {
    Fraction a;
    std::cout << "Enter the fraction's numerator: ";
    std::cin >> a.numerator;
    std::cout << "Enter the fraction's denominator: ";
    std::cin >> a.denominator;

    return a;
}

void FraOut(Fraction a) {
    std::cout << a.numerator << "/" << a.denominator;
}

Fraction FraAdd(Fraction a, Fraction b) {
    Fraction d;
    d.numerator = b.numerator*a.denominator + a.numerator*b.denominator;
    d.denominator = (a.denominator)*(b.denominator);

    return d;
}

Fraction FraSub(Fraction a, Fraction b) {
    Fraction d;
    d.numerator = b.numerator*a.denominator - a.numerator*b.denominator;
    d.denominator = (a.denominator)*(b.denominator);

    return d;
}