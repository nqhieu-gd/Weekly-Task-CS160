#include <iostream>
#include <fstream>
#include <vector>
#include <cstdint>

// Ensure structures are packed tightly (no compiler padding)
#pragma pack(push, 1)

struct BMPFileHeader {
    uint16_t file_type{0x4D42}; // "BM"
    uint32_t file_size{0};      // Size of file in bytes
    uint16_t reserved1{0};
    uint16_t reserved2{0};
    uint32_t offset_data{0};    // Offset to start of pixel data
};

struct BMPInfoHeader {
    uint32_t size{0};           // Size of this header (40 bytes)
    int32_t  width{0};          // Width in pixels
    int32_t  height{0};         // Height in pixels
    uint16_t planes{1};         // Number of color planes (must be 1)
    uint16_t bit_count{0};      // Bits per pixel (24 for RGB)
    uint32_t compression{0};    // 0 = uncompressed
    uint32_t size_image{0};     // Image size (can be 0 for uncompressed)
    int32_t  x_pixels_per_meter{0};
    int32_t  y_pixels_per_meter{0};
    uint32_t colors_used{0};
    uint32_t colors_important{0};
};

#pragma pack(pop)

void createEnglandFlagBMP(int width, int height) {
    // 1. Calculate format requirements
    // BMP rows must be padded to multiples of 4 bytes
    int padding_amount = (4 - (width * 3) % 4) % 4;
    int row_stride = width * 3 + padding_amount;
    uint32_t file_size = sizeof(BMPFileHeader) + sizeof(BMPInfoHeader) + (row_stride * height);

    // 2. Setup Headers
    BMPFileHeader fileHeader;
    fileHeader.file_size = file_size;
    fileHeader.offset_data = sizeof(BMPFileHeader) + sizeof(BMPInfoHeader);

    BMPInfoHeader infoHeader;
    infoHeader.size = sizeof(BMPInfoHeader);
    infoHeader.width = width;
    infoHeader.height = height;
    infoHeader.bit_count = 24; // 24-bit RGB

    // 3. Open file for binary writing
    std::ofstream file("england_flag.bmp", std::ios::binary);
    if (!file) {
        std::cerr << "Error: Could not open file for writing." << std::endl;
        return;
    }

    // 4. Write Headers
    file.write((const char*)&fileHeader, sizeof(fileHeader));
    file.write((const char*)&infoHeader, sizeof(infoHeader));

    // 5. Define Colors (BGR format for BMP)
    // White
    uint8_t white[] = {255, 255, 255}; 
    // Standard Flag Red (roughly RGB 206, 17, 36) -> BGR: 36, 17, 206
    uint8_t red[]   = {36, 17, 206};   

    // 6. Geometry logic for St George's Cross
    // The cross width is typically 1/5th of the flag's height
    int cross_thickness = height / 5;
    int center_x = width / 2;
    int center_y = height / 2;
    int half_thick = cross_thickness / 2;

    // 7. Write Pixel Data
    // Note: BMP stores pixels bottom-to-top
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            
            bool is_cross = false;

            // Check Vertical Bar bounds
            if (x >= (center_x - half_thick) && x <= (center_x + half_thick)) {
                is_cross = true;
            }
            // Check Horizontal Bar bounds
            // (Using standard coordinate logic, symmetrical so direction doesn't matter much)
            if (y >= (center_y - half_thick) && y <= (center_y + half_thick)) {
                is_cross = true;
            }

            if (is_cross) {
                file.write((char*)red, 3);
            } else {
                file.write((char*)white, 3);
            }
        }
        
        // Write row padding (must be 0s)
        uint8_t pad_zeros[3] = {0, 0, 0};
        file.write((char*)pad_zeros, padding_amount);
    }

    file.close();
    std::cout << "Successfully created 'england_flag.bmp' (" << width << "x" << height << ")" << std::endl;
}

int main() {
    // Standard flag ratio is 3:5. 
    // Example: 600 height, 1000 width.
    createEnglandFlagBMP(1000, 600);
    return 0;
}