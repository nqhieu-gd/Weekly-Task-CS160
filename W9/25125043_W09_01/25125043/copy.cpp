#include <iostream>
#include <fstream>  // Required for file I/O
#include <string>   // Required for string manipulation
#include <cstring>  // Required for strcmp

using namespace std;

// Function to extract just the filename (e.g., "image.png") from a full path
string getFileName(const string& path) {
    // Find the last position of either '/' or '\'
    size_t found = path.find_last_of("/\\");
    
    // If a separator is found, return the substring after it
    if (found != string::npos) {
        return path.substr(found + 1);
    }
    
    // If no separator, the whole path is the filename
    return path;
}

int main(int argc, char* argv[]) {
    string sourcePath;
    string destDir;

    // --- Step 1: Parse Command Line Arguments ---
    // We iterate manually through argv
    for (int i = 1; i < argc; ++i) {
        if (strcmp(argv[i], "-s") == 0) {
            if (i + 1 < argc) {
                sourcePath = argv[i + 1];
                i++; // Skip next arg
            } else {
                cerr << "Error: Missing argument for -s" << endl;
                return 1;
            }
        } else if (strcmp(argv[i], "-d") == 0) {
            if (i + 1 < argc) {
                destDir = argv[i + 1];
                i++; // Skip next arg
            } else {
                cerr << "Error: Missing argument for -d" << endl;
                return 1;
            }
        }
    }

    if (sourcePath.empty() || destDir.empty()) {
        cerr << "Usage: MYCOPYFILE -s <source_file> -d <destination_directory>" << endl;
        return 1;
    }

    // --- Step 2: Construct Destination Path ---
    string filename = getFileName(sourcePath);
    string fullDestPath = destDir;

    // Check if destDir ends with a separator; if not, add one
    char lastChar = destDir.back();
    if (lastChar != '/' && lastChar != '\\') {
        // We default to forward slash, but Windows handles mixed slashes fine usually
        fullDestPath += '/'; 
    }
    fullDestPath += filename;

    cout << "Source:      " << sourcePath << endl;
    cout << "Destination: " << fullDestPath << endl;

    // --- Step 3: Binary File I/O ---
    
    // Open input file in Binary mode
    ifstream srcFile(sourcePath, ios::binary);
    if (!srcFile) {
        cerr << "Error: Could not open source file." << endl;
        return 1;
    }

    // Open output file in Binary mode
    ofstream destFile(fullDestPath, ios::binary);
    if (!destFile) {
        cerr << "Error: Could not create destination file." << endl;
        return 1;
    }

    // --- Step 4: The Copy Loop (No Vector) ---
    // We use a fixed-size buffer on the stack
    const int BUFFER_SIZE = 4096; // 4KB chunks
    char buffer[BUFFER_SIZE];

    while (srcFile.read(buffer, BUFFER_SIZE)) {
        // 'gcount' returns the number of characters extracted by the last read
        destFile.write(buffer, srcFile.gcount());
    }
    
    // Handle the remaining bytes (if the file size isn't a perfect multiple of BUFFER_SIZE)
    if (srcFile.gcount() > 0) {
        destFile.write(buffer, srcFile.gcount());
    }

    cout << "File copy successful!" << endl;

    // File streams close automatically in C++ when they go out of scope,
    // but you can close them explicitly if you wish.
    srcFile.close();
    destFile.close();

    return 0;
}