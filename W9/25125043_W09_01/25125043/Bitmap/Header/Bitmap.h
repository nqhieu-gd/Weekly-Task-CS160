#pragma once
#include "..\..\25125043_W09_01\25125043\DynamicArray.h"

struct Color {
    float r, g, b;

    Color();
    Color(float r, float g, float b);
    ~Color();
};

class Image {
private:
    int width;
    int height;

    DA<Color> colors;
public:
    Image(int w, int h);
    ~Image();

    Color Getcolor(int x, int y) const;
    void Setcolor(const Color& color, int x, int y);
    void Export(const char* file) const;
};