#pragma once
#include "..\..\DynamicArray.h"

struct Color {
    unsigned char r, g, b;

    Color();
    Color(int r, int g, int b);
    ~Color();
};

class Image {
private:
    unsigned int width;
    unsigned int height;
    unsigned int padding;

public:
    Image(int w, int h);
    ~Image();
    DA<Color> colors;

    Color Getcolor(int x, int y) const;
    void Setcolor(const Color& color, int x, int y);
    void Export(const char* file) const;
    void FlagGen();
};