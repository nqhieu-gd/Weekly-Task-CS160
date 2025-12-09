#pragma once
#include <iostream>

template <typename T>
struct DA {
public:
    T* p;
    int size = 1, store = 0;

    void alloc() {
        p = new T[this->size];
    }

    void dealloc() {
        delete[] p;
    }

    void stretch() {
        T* temp = new T[this->size*2];
        for (T t = 0; t < this->size; t++) {
            temp[t] = p[t];
        }
        delete[] p;
        p = temp;
        this->size*=2;
    }

    void push(T k) {
        while (this->store >= this->size) this->stretch();
        p[this->store] = k;
        this->store++;
    }

    void sub(T k, T x) {
        if (x > this->store) return;
        for (T i = x - 1; i < this->store - 1; i++) p[i] = p[i + 1];
        this->store--;
    }

    void display() {
        for (T i = 0; i < this->store; i++) {
            std::cout << p[i] << ' ';
        }
    }
};