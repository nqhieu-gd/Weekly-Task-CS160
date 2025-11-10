#include <iostream>
#include "Fraction.h"

Fraction simple(Fraction f) {
    int check = 1;
    if (f.denominator != 0) {
        for (int i = 1; i <= f.denominator && i <= f.numerator; ++i) {
            if (f.numerator % i == 0 && f.denominator % i == 0) {
                check = i;
            }
        }
    }
    Fraction a;
    a.numerator = f.numerator / check;
    a.denominator = f.denominator / check;

    return a;
}

Fraction add(Fraction a, Fraction b) {
    Fraction f;
    f.numerator = a.numerator * b.denominator + b.numerator * a.denominator;
    f.denominator = a.denominator * b.denominator;
    f = simple(f);

    return f;
}

Fraction sub(Fraction a, Fraction b) {
    Fraction f;
    f.numerator = a.numerator * b.denominator - b.numerator * a.denominator;
    f.denominator = a.denominator * b.denominator;
    f = simple(f);

    return f;
}