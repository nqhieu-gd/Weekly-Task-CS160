#include <iostream>

struct DyArray {
    int* p;
    int size;
    int store;
    void constructor() {
        p = new int[size];
    }
    void DA() {
        delete[] p;
    }
    void add(int val) {
        if (store == size) {
            int* temp = new int[size + 1];
            for (int i = 0; i < size; i++) {
                temp[i] = p[i];
            }
            delete[] p;
            p = temp;
            size += 1;
        }
        p[store++] = val;
    }
    int get(int index) const {
        if (index >= 0 && index < store) {
            return p[index];
        };
    }
    int getSize() const {
        return store;
    }
    void Sub(int index) {
        if (index >= 0 && index < store) {
            for (int i = index; i < store - 1; i++) {
                p[i] = p[i + 1];
            }
            store--;
        }
    }
    void display() const {
        for (int i = 0; i < store; i++) {
            std::cout << p[i] << " ";
        }
        std::cout << std::endl;
    }
    int sum() {
        int total = 0;
        for (int i = 0; i < store; i++) {
            total += p[i];
        }
        return total;
    }
    int max() {
        int maximum = p[0];
        for (int i = 1; i < store; i++) {
            if (p[i] > maximum) {
                maximum = p[i];
            }
        }
        return maximum;
    }
    void insert(int index, int val) {
        if (index >= 1 && index <= store) {
            if (store == size) {
                int* temp = new int[size + 1];
                for (int i = 0; i < size; i++) {
                    temp[i] = p[i];
                }
                delete[] p;
                p = temp;
                size += 1;
            }
            for (int i = store; i > index; i--) {
                p[i] = p[i - 1];
            }
            p[index] = val;
            store++;
        }
    }
    void rev() {
        for (int i = 0; i < store / 2; i++) {
            int temp = p[i];
            p[i] = p[store - i - 1];
            p[store - i - 1] = temp;
        }
    }
};

int main() {
    int n, sum, max, k, temp;
    std::cin >> n;
    DyArray ar;
    ar.size = n;
    ar.store = 0;
    ar.constructor();
    for (int i = 0; i < ar.size; i++) {
        std::cin >> n;
        ar.add(n);
    }
    sum = ar.sum();
    max = ar.max();
    ar.display();
    std::cout << "Sum: " << sum << "\nMax: " << max << std::endl;
    std::cin >> k;
    ar.Sub(k - 1);
    ar.display();
    std::cin >> k >> n;
    ar.insert(k - 1, n);
    ar.display();
    ar.rev();
    ar.display();
    ar.DA();

    return 0;
}