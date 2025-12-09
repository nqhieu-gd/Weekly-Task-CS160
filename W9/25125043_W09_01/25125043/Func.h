#pragma once
#include <iostream>

struct Date {
    int day = 0;
    int month = 0;
    int year = 0;
    int M[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    void GenDate();
};