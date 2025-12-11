#include "Header\BMPHeader.h"

HeaderFile :: HeaderFile(int width, int height, int padding)
: FSize(width*height*3 + fileHSize + infoHSize + padding*height)
{
    fh[0] = 'B';
    fh[1] = 'M';
    fh[2] = FSize;
    fh[3] = FSize >> 8;
    fh[4] = FSize >> 16;
    fh[5] = FSize >> 24;

    fh[10] = fileHSize + infoHSize;


    ih[0] = infoHSize;

    ih[4] = width;
    ih[5] = width >> 8;
    ih[6] = width >> 16;
    ih[7] = width >> 24;

    ih[8] = height;
    ih[9] = height >> 8;
    ih[10] = height >> 16;
    ih[11] = height >> 24;

    ih[12] = 1;

    ih[14] = 24;
}

HeaderFile :: ~HeaderFile() {}