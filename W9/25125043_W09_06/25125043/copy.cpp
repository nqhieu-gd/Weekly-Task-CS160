#include <iostream>
#include <fstream>  // For file I/O
#include <cstring>  // For strcmp
#include <string>   // For std::string path manipulation

using namespace std;

// Helper function: Extracts "film.mkv" from "D:/film.mkv"
string getFileName(const string& path) {
    size_t found = path.find_last_of("/\\");
    if (found != string::npos) {
        return path.substr(found + 1);
    }
    return path;
}

int main(int argc, char* argv[]) {
    string sourcePath;
    string destDir;

    // --- 1. Parse Command Line Arguments ---
    for (int i = 1; i < argc; ++i) {
        if (strcmp(argv[i], "-s") == 0) {
            if (i + 1 < argc) {
                sourcePath = argv[i + 1];
                i++; // Skip next arg
            }
        } else if (strcmp(argv[i], "-d") == 0) {
            if (i + 1 < argc) {
                destDir = argv[i + 1];
                i++; // Skip next arg
            }
        }
    }

    if (sourcePath.empty() || destDir.empty()) {
        cerr << "Usage: MYCOPYFILE -s <source_path> -d <dest_path>" << endl;
        return 1;
    }

    // --- 2. Construct Full Destination Path ---
    // Example: destDir is "D:/Level1..." and filename is "film.mkv"
    // Result should be "D:/Level1.../film.mkv"
    
    string filename = getFileName(sourcePath);
    string fullDestPath = destDir;

    // Check if destDir needs a separator added to the end
    if (!fullDestPath.empty()) {
        char lastChar = fullDestPath.back();
        if (lastChar != '/' && lastChar != '\\') {
            fullDestPath += '/';
        }
    }
    fullDestPath += filename;

    cout << "Copying: " << sourcePath << endl;
    cout << "To:      " << fullDestPath << endl;

    // --- 3. Binary File I/O ---
    // Use "ios::binary" to handle non-text files like .mkv correctly
    ifstream srcFile(sourcePath, ios::binary);
    if (!srcFile) {
        cerr << "Error: Could not open source file '" << sourcePath << "'" << endl;
        return 1;
    }

    ofstream destFile(fullDestPath, ios::binary);
    if (!destFile) {
        cerr << "Error: Could not create destination file '" << fullDestPath << "'" << endl;
        return 1;
    }

    // --- 4. The Copy Loop (Using Fixed Array) ---
    // We use a 4KB buffer instead of vector
    const int BUFFER_SIZE = 4096; 
    char buffer[BUFFER_SIZE];

    while (srcFile.read(buffer, BUFFER_SIZE)) {
        destFile.write(buffer, srcFile.gcount());
    }
    // Handle any remaining bytes
    if (srcFile.gcount() > 0) {
        destFile.write(buffer, srcFile.gcount());
    }

    cout << "File copy completed successfully." << endl;

    // Cleanup (optional as destructors handle this, but good practice)
    srcFile.close();
    destFile.close();

    return 0;
}