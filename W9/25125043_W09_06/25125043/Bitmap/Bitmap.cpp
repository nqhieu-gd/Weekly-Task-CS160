#include "Func.cpp"
#include <fstream>
#include <iostream>

int main() {
    Image img(1000, 600);
    img.FlagGen();
    img.Export("Bitmap.bmp");

    return 0;
}