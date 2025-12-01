#pragma once
#include <fstream>

struct Student {
    char name[51];
    char id[9];
    int dob[3];
    float gpa;
};

struct Des {
    Student* p;
    int size;
    int ma, mi;
    bool isopen = 1;

    void con() {
        p = new Student[size];
    }

    void decon() {
        delete[] p;
    }

    void inst(Student a, int i) {
        p[i] = a;
    }

    void add(Student val) {
        Student* temp = new Student[size + 1];
        for (int i = 0; i < size; i++) {
            temp[i] = p[i];
        }
        delete[] p;
        p = temp;
        p[size++] = val;
    }

    void Sub(int num) {
        if (num >= 1 && num <= size) {
            for (int i = num - 1; i < size - 1; i++) {
                p[i] = p[i + 1];
            }
            size--;
        }
    }

    void update() {
        if (size < mi || size > ma) isopen = 0;
        else isopen = 1;
    }
};

struct Course {
    char id[16];
    char name[81];
    Des li;
};

struct List {
    int size = 0;
    Course* q;

    void conL() {
        q = new Course[size];
    }

    void decon() {
        delete[] q;
    }

    void addL(Course val) {
        Course* temp = new Course[size + 1];
        for (int i = 0; i < size; i++) {
            temp[i] = q[i];
        }
        delete[] q;
        q = temp;
        q[size++] = val;
    }
};

Course CoIn(std::ifstream &fin);

void CoOut(std::ofstream &fout);

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