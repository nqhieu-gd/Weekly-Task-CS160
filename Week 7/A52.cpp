int* DoublingSize(int p[], int& size) {
    int* temp = new int[size * 2];
    for (int i = 0; i < size; i++) {
        temp[i] = p[i];
    }
    for (int i = size; i < size * 2; i++) {
        temp[i] = 0;
    }
    delete[] p;
    size *= 2;
    return temp;
}
