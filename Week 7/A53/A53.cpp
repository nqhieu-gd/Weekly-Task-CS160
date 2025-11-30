#include <iostream>
#include <fstream>
#include "A53.h"

int main() {
    Grading a;
    a.ReadAnswers();
    a.ReadStudentAnswers();
    a.Missed();
    a.Grade(a.score);
    a.decon();
    
    return 0;
}