#include "..\..\..\25125043_W09_01\25125043\Bitmap\Header\Bitmap.h"
#include <iostream>
#include <fstream>

Color :: Color() 
    : r(0), g(0), b(0)
{
}

Color :: Color(float r, float g, float b)
    : r(r), g(g), b(b)
{
}

Color :: ~Color()
{
}

Image :: Image(int w, int h)
    : width(w), height(h)
{
}

Image :: ~Image()
{
}

void Image :: Setcolor(const Color& color, int x, int y) {
    colors.p[y*width + x].r = color.r;
    colors.p[y*width + x].g = color.g;
    colors.p[y*width + x].b = color.b;
}

void Image :: Export(const char* file) const {
    std::ofstream fout;
    fout.open(file, std::ios::binary);
    if (!fout.is_open()) {
        std::cerr << "Error opening file.";
        return;
    }
}