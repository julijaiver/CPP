#include <string>
#include <iostream>

void replace_occurrence(std::string&, const char&);

int main() {

    while (true) {
        std::string input, c;
        std::cout << "Enter a string: ";
        getline(std::cin, input);
        while (input.empty()) {
            std::cout << std::endl << "String is empty, enter again: ";
            getline(std::cin, input);
        }

        std::cout << std::endl << "Enter a character to replace or \"stop\" to stop: ";
        getline(std::cin, c);
        while (c.empty()) {
            std::cout << "No character was entered. Enter again: ";
            getline(std::cin, c);
        }

        if (c == "stop") {
            break;
        }
        replace_occurrence(input, c[0]);
        std::cout << "Result: " << input << std::endl;
    }

    return 0;
}

void replace_occurrence(std::string &input, const char &c) {
    for (auto &ch : input) {
        if (ch == c) {
            ch = '_';
        }
    }
}
