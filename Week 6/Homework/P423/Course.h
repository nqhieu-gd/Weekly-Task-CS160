#pragma once
#include <fstream>

struct Student {
    char name[51];
    char id[9];
    int dob[3];
    float gpa;
};

struct Course {
    char id[16];
    char name[81];
    int sn;
    Student li[181];
    bool isopen;
    int ma, mi;
};

Course CoIn(std::ifstream &fin);

void CoOut(std::ofstream &fout);

void MinCheck(Course &a);

void MaxCheck(Course &a);

Course AddStu(Course a);

Course SubStu(Course a);

void dobMonCheck(Course a);

void dobCheck(Course a);

void DrivingReady(Course a);

void FindK19(std::ofstream &fout, Course a);

void FindID(std::ofstream &fout, Course a);

void FindGN(std::ofstream &fout, Course a);

void SortID(std::ofstream &fout, Course &a);

void SortFirstname(std::ofstream &fout, Course &a);

void SortGPA(std::ofstream &fout, Course &a);

void SortDOB(std::ofstream &fout, Course &a);

void infs(Student &a);

void outfs(Student &a);

void sw(Student &a, Student &b);