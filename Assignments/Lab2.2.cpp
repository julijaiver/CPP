#include <iostream>
#include <vector>
#include <filesystem>
#include <fstream>

int main() {
    std::vector<std::string> path;
    std::string line;

    std::cout << "Enter directory names or blank line to stop: " << std::endl;
    while (std::getline(std::cin, line)) {
        if (line.empty()) {
            break;
        }
        path.push_back(line);
    }
    // Create file path from vector content
    std::filesystem::path dir;
    for (const auto &p : path) {
        dir /= p;
    }
    // Check if directory exists already and if not, create one
    if (!exists(dir)) {
        create_directories(dir);
        std::cout << "Directory created" << std::endl;
        //Create a new text file and open filestream for writing to file
        std::string filename = "result.txt";
        std::filesystem::path file = dir / filename;

        std::ofstream outfile(file);
        if (!outfile) {
            std::cout << "Could not open output file" << std::endl;
            return 1;
        }
        outfile << absolute(file) << std::endl;
        std::cout << absolute(file) << std::endl;

        for (const auto &p : path) {
            outfile << p << std::endl;
            std::cout << p << std::endl;
        }
        outfile << relative(file) << std::endl;
        std::cout << relative(file) << std::endl;

        outfile.close();
    } else {
        std::cout << "Directory already exists" << std::endl;
    }

    return 0;
}