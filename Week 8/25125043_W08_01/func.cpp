#include <fstream>

struct Node {
    int val;
    Node* pNext;
};

void genList(std::ifstream &fin, Node* &pHead) {
    int x;
    fin >> x;
    Node* cur = new Node;
    cur->val = x;
    cur->pNext = nullptr;
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
    while (cur != nullptr) {
        fout << cur->val << " ";
        cur = cur->pNext;
    }
}

void clearList(Node* &pHead) {
    Node* cur = pHead;
    while (cur != nullptr) {
        cur = cur->pNext;
        delete pHead;
        pHead = cur;
    }
}

void subList(Node* &pHead, int a) {
    Node* cur = pHead;
    if (cur == nullptr) return;
    if (cur->val == a) {
        if (cur == pHead) {
            pHead = cur->pNext;
            delete cur;
            cur = pHead;
        }
    }
    else while (cur->pNext != nullptr && cur->pNext->val != a) {
        cur = cur->pNext;
    }
    if (cur == nullptr || cur->pNext == nullptr && cur->val != a) {
        return;
    }
    if (cur->pNext->val == a) {
        Node* temp = cur->pNext;
        if (cur->pNext->pNext != nullptr) {
            cur->pNext = cur->pNext->pNext;
        }
        delete temp;
    }
    subList(pHead, a);
}