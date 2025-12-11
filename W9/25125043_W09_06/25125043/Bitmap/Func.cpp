#include "Header\Bitmap.h"
#include "BitH.cpp"
#include <iostream>
#include <fstream>

Color :: Color() 
    : r(0), g(0), b(0)
{
}

Color :: Color(int r, int g, int b)
    : r(r), g(g), b(b)
{
}

Color :: ~Color()
{
}

Image :: Image(int w, int h)
    : width(w), height(h), padding((4 - ((width *3) % 4)) % 4)
{ 
    colors.alloc();
    colors.setsize(w*h);
}

Image :: ~Image()
{ 
    if (colors.p) colors.dealloc();
}

void Image :: Setcolor(const Color& color, int x, int y) {
    colors.p[y*width + x].r = color.r;
    colors.p[y*width + x].g = color.g;
    colors.p[y*width + x].b = color.b;
}

void Image :: Export(const char* file) const {
    std::ofstream fout;
    fout.open(file, std::ios::binary);
    if (!fout) {
        std::cerr << "Error opening file.";
        return;
    }
    HeaderFile hf(width, height, padding);
    unsigned char col[3] = {0, 0, 0};
    unsigned char pad[] = {0, 0, 0};
    fout.write((char*) hf.fh, hf.fileHSize);
    fout.write((char*) hf.ih, hf.infoHSize);    
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            col[0] = colors.p[i*width + j].b;
            col[1] = colors.p[i*width + j].g;
            col[2] = colors.p[i*width + j].r;
            fout.write((char*) col, 3);
        }
        fout.write((char*) pad, padding);
    }
    fout.close();
    std::cout << "Successfully create flag of England as .bmp file.";
}

void Image :: FlagGen() {
    unsigned char white[3] = {0, 0, 0};
    unsigned char red[3] = {0, 0, 255};
    unsigned char pad[] = {0, 0, 0};
    int mid = width/2, midh = height/2, clh = height/10;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            colors.p[i*width + j].b = 255;
            colors.p[i*width + j].g = 255;
            colors.p[i*width + j].r = 255;
            if (i >= midh - clh && i <= midh + clh || j >= mid - clh && j <= mid + clh) {
                colors.p[i*width + j].b = 0;
                colors.p[i*width + j].g = 0;
            }
        }
    }
}