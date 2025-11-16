#pragma once
#include <iostream>
#include <fstream>
#include "Date.h"

struct student {
    int id;
    std::string fullname;
    float gpa;
    std::string address;
    date dob;
};

student input_student(student s);

void output_student(student s);

student fin_student(student s, std::ifstream &file);

void fout_student(student s, std::ofstream &file);

void fout_student_remake(student s, std::ofstream &file);

void class_check(student s, std::ofstream &file);

student later_id(student a, student b);

student higher_gpa(student a, student b);

student later_name(student a, student b);

student later_first_name(student a, student b);

student later_last_name(student a, student b);

student older_dob(student a, student b);