#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

// Function to split a file based on specified criteria
// Returns true on success, false on failure
bool splitFile(const std::string& sourcePath, 
               const std::string& destinationDir, 
               const std::string& splitType, 
               long long splitValue) {
    
    // --- 1. Open Source File ---
    // Use std::ios::binary for binary IO
    std::ifstream sourceFile(sourcePath, std::ios::binary | std::ios::ate);
    if (!sourceFile.is_open()) {
        std::cerr << "Error: Could not open source file: " << sourcePath << std::endl;
        return false;
    }

    // Get the total size of the source file
    std::streamsize fileSize = sourceFile.tellg();
    sourceFile.seekg(0, std::ios::beg); // Rewind to the beginning
    
    if (fileSize <= 0) {
        std::cerr << "Error: Source file is empty or an error occurred while getting its size." << std::endl;
        return false;
    }

    // --- 2. Determine Part Size and Number of Parts ---
    long long numParts = 0;
    long long partSize = 0;
    
    if (splitType == "-numpart") {
        if (splitValue <= 0) {
            std::cerr << "Error: Number of parts must be a positive integer." << std::endl;
            return false;
        }
        numParts = splitValue;
        // Calculate the size of each part. The last part will take the remainder.
        partSize = static_cast<long long>(std::ceil(static_cast<double>(fileSize) / numParts));
        
    } else if (splitType == "-sizeapart") {
        if (splitValue <= 0) {
            std::cerr << "Error: Part size must be a positive integer (in bytes)." << std::endl;
            return false;
        }
        partSize = splitValue;
        // Calculate the number of parts needed.
        numParts = static_cast<long long>(std::ceil(static_cast<double>(fileSize) / partSize));
        
    } else {
        std::cerr << "Internal Error: Invalid split type." << std::endl;
        return false;
    }

    // Safety check for calculated values
    if (numParts <= 0 || partSize <= 0) {
         std::cerr << "Error: Calculation resulted in zero or negative part size/count." << std::endl;
        return false;
    }

    std::cout << "File Size: " << fileSize << " bytes" << std::endl;
    std::cout << "Number of Parts: " << numParts << std::endl;
    std::cout << "Target Part Size: " << partSize << " bytes" << std::endl;
    
    // --- 3. Split File Name Components ---
    // Extract the base name and extension from the source path
    size_t lastSlash = sourcePath.find_last_of("/\\");
    std::string filename = (lastSlash == std::string::npos) ? sourcePath : sourcePath.substr(lastSlash + 1);

    size_t lastDot = filename.find_last_of('.');
    std::string baseName;
    std::string extension;
    if (lastDot == std::string::npos) {
        baseName = filename;
        extension = "";
    } else {
        baseName = filename.substr(0, lastDot);
        extension = filename.substr(lastDot);
    }
    
    // --- 4. Read and Write Parts ---
    // Use a buffer for efficient IO
    const int BUFFER_SIZE = 1024 * 1024; // 1MB buffer
    std::vector<char> buffer(BUFFER_SIZE);
    
    for (int i = 1; i <= numParts; ++i) {
        // Calculate the actual size of the current part
        // It's the minimum of the calculated partSize and the remaining bytes in the file
        long long currentPartSize = std::min(partSize, (long long)fileSize - sourceFile.tellg());

        if (currentPartSize <= 0) {
             // This can happen if the file size was a perfect multiple of partSize 
             // and we already processed the last chunk. Break early.
             break; 
        }

        // Construct the output filename: baseName.ext.partXX
        std::string partNumber = std::to_string(i);
        // Pad the part number with leading zeros for sorting (e.g., 01, 02, 10)
        // Adjust the padding width based on numParts (e.g., if numParts=100, pad to 3 digits)
        int paddingWidth = static_cast<int>(std::floor(std::log10(numParts))) + 1;
        partNumber.insert(0, paddingWidth - partNumber.length(), '0');

        std::string partFileName = destinationDir + "/" + baseName + extension + ".part" + partNumber;
        
        // Open the destination part file
        std::ofstream partFile(partFileName, std::ios::binary);
        if (!partFile.is_open()) {
            std::cerr << "Error: Could not open destination part file: " << partFileName << std::endl;
            // Note: In a real application, you might want to try to close and clean up.
            return false;
        }

        // Write the data for the current part
        long long bytesWritten = 0;
        while (bytesWritten < currentPartSize) {
            // Determine how much to read: minimum of (current part remaining) and BUFFER_SIZE
            long long bytesToRead = std::min((long long)BUFFER_SIZE, currentPartSize - bytesWritten);
            
            // Read from the source file
            sourceFile.read(buffer.data(), bytesToRead);
            std::streamsize actualRead = sourceFile.gcount(); // Check how many bytes were actually read

            if (actualRead > 0) {
                // Write to the destination part file
                partFile.write(buffer.data(), actualRead);
                bytesWritten += actualRead;
            } else {
                // Should not happen unless there's an unexpected read error
                break;
            }
        }

        partFile.close();
        std::cout << "Created part " << i << ": " << partFileName << " (" << bytesWritten << " bytes)" << std::endl;
    }

    sourceFile.close();
    return true;
}

// --- Example of Command-Line Argument Parsing (Simulated) ---

void runExample(const std::string& command) {
    std::cout << "\n\n--- Executing Command: " << command << " ---\n";

    // In a real application, you would parse argv/argc.
    // For this example, we'll parse the command string directly (simplified).
    
    std::vector<std::string> args;
    std::string currentArg;
    for (char c : command) {
        if (c == ' ') {
            if (!currentArg.empty()) {
                args.push_back(currentArg);
            }
            currentArg.clear();
        } else {
            currentArg += c;
        }
    }
    if (!currentArg.empty()) {
        args.push_back(currentArg);
    }
    
    // Expected format: MYSPILTFILE -s source -d dest (-numpart X OR -sizeapart Y)
    if (args.size() != 6) {
        std::cerr << "Error: Invalid number of arguments in command: " << command << std::endl;
        return;
    }

    std::string sourcePath;
    std::string destinationDir;
    std::string splitType;
    long long splitValue = 0;

    try {
        for (size_t i = 1; i < args.size(); ++i) {
            if (args[i] == "-s" && i + 1 < args.size()) {
                sourcePath = args[++i];
            } else if (args[i] == "-d" && i + 1 < args.size()) {
                destinationDir = args[++i];
            } else if (args[i] == "-numpart" && i + 1 < args.size()) {
                splitType = "-numpart";
                splitValue = std::stoll(args[++i]);
            } else if (args[i] == "-sizeapart" && i + 1 < args.size()) {
                splitType = "-sizeapart";
                splitValue = std::stoll(args[++i]);
            }
        }
    } catch (const std::exception& e) {
        std::cerr << "Error parsing arguments: " << e.what() << std::endl;
        return;
    }

    if (sourcePath.empty() || destinationDir.empty() || splitType.empty() || splitValue <= 0) {
        std::cerr << "Error: Missing or invalid required arguments." << std::endl;
        return;
    }

    // Call the splitting function
    if (splitFile(sourcePath, destinationDir, splitType, splitValue)) {
        std::cout << "File splitting **completed** successfully." << std::endl;
    } else {
        std::cout << "File splitting **failed**." << std::endl;
    }
}

// Note: To make this code runnable, you must create a dummy source file
// (e.g., "D:/film.mkv") and ensure the destination directory exists
// (e.g., "D:/Level1/Level2/Level3").

/*
int main() {
    // --- To test this, you MUST create these files/directories first ---
    // Example 1: Split into 3 parts
    runExample("MYSPILTFILE -s D:/film.mkv -d D:/Level1/Level2/Level3 -numpart 3");

    // Example 2: Split by 1,000,000 bytes (1MB)
    runExample("MYSPILTFILE -s D:/film.mkv -d D:/Level1/Level2/Level3 -sizeapart 1000000");

    return 0;
}
*/