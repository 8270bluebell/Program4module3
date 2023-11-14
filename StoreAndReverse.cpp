#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

bool appendToFile(const std::string& filename) {
    std::ofstream file;
    file.open(filename, std::ios_base::app); // open file in append mode

    std::string userInput;
    std::cout << "Enter your input: ";
    std::getline(std::cin, userInput); // get user input

    // Check if the input length is not equal to 5
    if (userInput.length() != 5) {
        std::cout << "Input is not a 5 character string. Please try again." << std::endl;
        return false;
    }

    file << userInput << "\n"; // append user input to file
    file.close();
    return true;
}




void reverseFile(const std::string& filename, const std::string& outputFilename) {
    std::ifstream file(filename);
    std::ofstream outputFile(outputFilename, std::ios_base::app);

    std::string line;
    while (std::getline(file, line)) {
        std::reverse(line.begin(), line.end()); // reverse the line
        outputFile << line << "\n"; // write reversed line to output file
    }

    file.close();
    outputFile.close();
}

void printFile(const std::string& filename) {
    std::ifstream file(filename);
    std::string line;

    while (std::getline(file, line)) {
        std::cout << line << "\n";
    }

    file.close();
}

int main() {
    const std::string filename = "CSC450_CT5_mod5.txt";
    const std::string outputFilename = "CSC450-mod5-reverse.txt";

    if (appendToFile(filename)) {
        reverseFile(filename, outputFilename);
    }

    std::cout << "Contents of " << filename << ":\n";
    printFile(filename);

    std::cout << "\nContents of " << outputFilename << ":\n";
    printFile(outputFilename);

    return 0;
}
