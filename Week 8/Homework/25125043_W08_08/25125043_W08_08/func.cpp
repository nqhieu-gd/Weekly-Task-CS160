#include <fstream>
#include <iostream>
#include "func.h"

void genList(std::ifstream &fin, Node* &pHead) {
    int x;
    fin >> x;
    Node* cur = new Node;
    cur->val = x;
    cur->pNext = NULL;
    pHead = cur;
    while (fin >> x) {
        cur->pNext = new Node;
        cur = cur->pNext;
        cur->val = x;
        cur->pNext = NULL;
    }
}

void outList(std::ofstream &fout, Node* pHead) {
    Node* cur = pHead;
    while (cur != NULL) {
        fout << cur->val << " ";
        cur = cur->pNext;
    }
}

void clearList(Node* &pHead) {
    Node* cur = pHead;
    while (cur != NULL) {
        cur = cur->pNext;
        delete pHead;
        pHead = cur;
    }
}

void subList(Node* &pHead, int a) {
    Node* cur = pHead;
    if (cur == NULL) return;
    if (cur->val == a) {
        if (cur == pHead) {
            pHead = cur->pNext;
            delete cur;
            cur = pHead;
        }
    }
    else while (cur->pNext != NULL && cur->pNext->val != a) {
        cur = cur->pNext;
    }
    if (cur == NULL || cur->pNext == NULL && cur->val != a) {
        return;
    }
    Node* temp = NULL;
    if (cur->pNext->val == a) {
        temp = cur->pNext;
        if (cur->pNext->pNext != NULL) {
            cur->pNext = cur->pNext->pNext;
        }
        else cur->pNext = NULL;
        delete temp;
        temp = NULL;
    }
    subList(pHead, a);
}

void pSet(Node* pH, Node* &cur, int &a) {
    cur = pH;
    if (cur == NULL) return;
    for (int i = 0; i < a; i++) {
        if (cur->pNext != NULL) {
            cur = cur->pNext;
        }
    }
    a--;
}

void revList(Node* &pHead) {
    if (pHead == NULL || pHead->pNext == NULL || pHead->val == 0 || pHead->pNext->val == 0) return;
    int i = 0;
    Node *pLeft = pHead, *last, *prev = pHead, *pRight = pHead;
    while (pRight->pNext->pNext != NULL && pRight->pNext->pNext->val != 0) {
        pRight = pRight->pNext;
        i++;
    }
    pRight = pRight->pNext;
    pHead = pRight;
    last = pRight->pNext;
    while (i >= 0) {
        pSet(pLeft, prev, i);
        pRight->pNext = prev;
        pRight = prev;
    }
    pLeft->pNext = last;
}

void insertEven(Node* &pHead) {
    if (pHead == NULL || pHead->pNext == NULL || pHead->val == 0 || pHead->pNext->val == 0) return;
    Node* cur = new Node, *temp = NULL;
    cur->pNext = pHead;
    cur->val = 2;
    pHead = cur;
    while (cur->pNext->pNext != NULL && cur->pNext->pNext->val != 0) {
        temp = new Node;
        temp->val = cur->val + 2;
        cur = cur->pNext;
        temp->pNext = cur->pNext;
        cur->pNext = temp;
        cur = temp;
    }
}

void removeDupe(Node* &pHead) {
    if (pHead == NULL || pHead->pNext == NULL || pHead->val == 0 || pHead->pNext->val == 0) return;
    Node* cur = pHead,* curRD,* pRD;
    pRD = new Node;
    curRD = pRD;
    curRD->val = cur->val;
    cur = cur->pNext;
    int key;
    KeyVal kv;
    kv.store = 0;
    kv.NodeGen();
    kv.valPush(curRD->val);
    while (cur != NULL) {
        key = cur->val;
        int id = kv.keySearch(key);
        if (id == -1) {
            kv.valPush(key);
            curRD->pNext = new Node;
            curRD = curRD->pNext;
            curRD->val = key;
            curRD->pNext = NULL;
        }
        cur = cur->pNext;
    }
    kv.NodeClear();
    clearList(pHead);
    pHead = pRD;
}

void insertSorted(Node* &pHead) {
    int val;
    std::cout << "Enter a number to insert: ";
    std::cin >> val;
    Node* cur = pHead;
    if (pHead == NULL) {
        pHead = new Node;
        pHead->val = val;
        pHead->pNext = NULL;
        return;
    }
    if (val < pHead->val) {
        cur = new Node;
        cur->val = val;
        cur->pNext = pHead;
        pHead = cur;
        return;
    }
    while (cur->pNext != NULL && cur->pNext->val < val && cur->pNext->val != 0) {
        cur = cur->pNext;
    }
    Node* temp = new Node;
    temp->val = val;
    temp->pNext = cur->pNext;
    cur->pNext = temp;
}

void sumList(Node* pHead) {
    int sum = 0;
    while (pHead != NULL && pHead->val != 0) {
        sum += pHead->val;
        pHead->val = sum;
        pHead = pHead->pNext;
    }
}

void joinedList(Node* &pHead1, Node* pHead2) {
    if (pHead1 == NULL) {
        pHead1 = pHead2;
        return;
    }
    if (pHead1->val == 0) {
        delete pHead1;
        pHead1 = pHead2;
        return;
    }
    if (pHead2 == NULL || pHead2->val == 0) {
        return;
    }
    Node* cur = pHead1;
    while (cur->pNext != NULL && cur->pNext->val != 0) {
        cur = cur->pNext;
    }
    if (cur->pNext != NULL && cur->pNext->val == 0) {
        delete cur->pNext;
        cur->pNext = NULL;
    }
    cur->pNext = pHead2;
}

int NodeCount(Node* pHead) {
    int count = 0;
    Node* cur = pHead;
    while (cur != NULL && cur->val != 0) {
        count++;
        cur = cur->pNext;
    }
    return count;
}

void twoToOne(Node* &pHead1, Node* pHead2) {
    if (pHead1 == NULL) {
        pHead1 = pHead2;
        return;
    }
    if (pHead1->val == 0) {
        delete pHead1;
        pHead1 = pHead2;
        return;
    }
    if (pHead2 == NULL || pHead2->val == 0) {
        return;
    }
    int i = NodeCount(pHead1), j =  NodeCount(pHead2), k = (i - 1 > j)? j : (i - 1);
    Node* cur1 = pHead1, *cur2 = pHead2, *temp1 = NULL, *temp2 = NULL;
    if (i == 1) {
        if (cur1->pNext != NULL) delete cur1->pNext;
        cur1->pNext = cur2;
        return;
    }
    temp1 = cur1->pNext;
    if (j == 1) {
        if (cur2->pNext != NULL) delete cur2->pNext;
        cur2->pNext = cur1->pNext;
        cur1->pNext = cur2;
        return;
    }
    temp2 = cur2->pNext;
    for (int a = 0; a < k; a++) {
        cur1->pNext = cur2;
        cur2->pNext = temp1;
        cur1  = temp1;
        cur2 = temp2;
        temp1 = temp1->pNext;
        temp2 = temp2->pNext;
    }
    if (j < i) {
        if (temp2 != NULL && temp2->val == 0) {
            delete temp2;
            temp2 = NULL;
        }
    }
    if (i <= j) {
        if (cur1->pNext != NULL && cur1->pNext->val == 0) {
            delete cur1->pNext;
            cur1->pNext = NULL;
        }
        cur1->pNext = cur2;
    }
}