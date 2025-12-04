#pragma once
#include <fstream>

struct Node {
    int val;
    Node* pNext;
};

struct KeyVal {
    int* v;
    int store;
    
    void NodeGen() {
        v = new int[this->store];
    }

    void NodeClear(){
        delete[] v;
    }

    void valStretch() {
        int* temp = new int[this->store + 1];
        for (int i = 0; i < this->store; i++) {
            temp[i] = v[i];
        }
        temp[this->store] = 0;
        delete[] v;
        v = temp;
        this->store ++;
    }

    void valPush(int value) {
        valStretch();
        v[this->store - 1] = value;
    }

    int keySearch(int key) {
        for (int i = 0; i < this->store; i++) {
            if (v[i] == key) {
                return i;
            }
        }
        return -1;
    }
};

void genList(std::ifstream &fin, Node* &pHead);

void outList(std::ofstream &fout, Node* pHead);

void clearList(Node* &pHead);

void subList(Node* &pHead, int a);

void pSet(Node* pH, Node* &cur, int &a);

void revList(Node* &pHead);

void insertEven(Node* &pHead);

void removeDupe(Node* pHead, Node* &pRD);

void insertSorted(Node* &pHead);

void sumList(Node* pHead);

void joinedList(Node* &pHead1, Node* pHead2);

int NodeCount(Node* pHead);

void twoToOne(Node* &pHead1, Node* pHead2);