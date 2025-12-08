#pragma once
#include <iostream>

struct DA {
public:
    int* p;
    int size = 1, store = 0;

    void alloc() {
        p = new int[this->size];
    }

    void dealloc() {
        delete[] p;
    }

    void stretch() {
        int* temp = new int[this->size*2];
        for (int t = 0; t < this->size; t++) {
            temp[t] = p[t];
        }
        delete[] p;
        p = temp;
        this->size*=2;
    }

    void push(int k) {
        while (this->store >= this->size) this->stretch();
        p[this->store] = k;
        this->store++;
    }

    void sub(int k, int x) {
        if (x > this->store) return;
        for (int i = x - 1; i < this->store - 1; i++) p[i] = p[i + 1];
        this->store--;
    }

    void display() {
        for (int i = 0; i < this->store; i++) {
            std::cout << p[i] << ' ';
        }
    }
};