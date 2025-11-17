#pragma once

struct Fraction {
    int numerator;
    int denominator;
};

Fraction FraIn();

void FraOut(Fraction a);

Fraction FraAdd(Fraction a, Fraction b);

Fraction FraSub(Fraction a, Fraction b);