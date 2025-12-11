struct HeaderFile {
    static constexpr int fileHSize = 14;
    static constexpr int infoHSize = 40;
    unsigned char fh[fileHSize] = {0};
    unsigned char ih[infoHSize] = {0};
    const int FSize;

    HeaderFile(int width, int height, int padding);
    ~HeaderFile();
};