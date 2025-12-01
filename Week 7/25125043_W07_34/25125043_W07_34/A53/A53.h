#pragma once
#include <fstream>
#include <iostream>

struct Grading {
    char* ca = NULL, * sa = NULL;
    int csize = 1, ssize = 1, num = 0;
    double score;

    void conca() {
        if (this->csize <= 0) this->csize = 1;
        ca = new char[csize];
    }

    void consa() {
        if (this->ssize <= 0) this->ssize = 1;
        sa = new char[ssize];
    }

    void decon() {
        delete[] ca;
        delete[] sa;
    }

    void Stretch(char* &p, int &size) {
        char* temp = new char[size*2];
        for (int i = 0; i < size; ++i) {
            temp[i] = p[i];
        }
        for (int i = size; i < size*2; ++i) {
            temp[i] = '0';
        }
        delete[] p;
        p = temp;
        size *= 2;
    }

    void ReadAnswers() {
        std::ifstream file;
        file.open("CorrectAnswers.txt");
        if (!file) {
            std::cerr << "Error opening file!" << std::endl;
        }
        else {
            conca();
            file >> this->num;
            file.ignore(1000, '\n');
            for (int i = 0; i < num; ++i) {
                if (i >= this->csize) {
                    Stretch(this->ca, this->csize);
                }
                file >> ca[i];
            }
        }
        file.close();
    }

    void ReadStudentAnswers() {
        std::ifstream file;
        file.open("StudentAnswers.txt");
        if (!file) {
            std::cerr << "Error opening file!" << std::endl;
        }
        else {
            consa();
            file >> this->num;
            for (int i = 0; i < num; ++i) {
                if (i >= this->ssize) {
                    Stretch(this->sa, this->ssize);
                }
                file >> this->sa[i];
            }
        }
        file.close();
    }

    void Grade(double &score) {
        double check = 0;
        for (int i = 0; i < num; ++i) {
            if (this->ca[i] == this->sa[i]) {
                check++;
            }
        }
        score = (check /(int) num) * 100;
        std::cout << "Student's score: " << score << std::endl;
        if (score >= 70) {
            std::cout << "Student has passed!" << std::endl;
        }
        else {
            std::cout << "Student has failed!" << std::endl;
        }
    }

    void Missed() {
        std::cout << "Questions missed:\n";
        for (int i = 0; i < num; ++i) {
            if (this->ca[i] != this->sa[i]) {
                std::cout << (i + 1) << " (The student chose " << this->sa[i] << " while the correct answer is " << this->ca[i] << ")\n";
            }
        }
    }
};