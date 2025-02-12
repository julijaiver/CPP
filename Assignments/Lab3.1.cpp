#include <iostream>
#include <map>

void print_map(const std::map<std::string, int> &names);

int main() {
    std::map<std::string, int> names;

    while (true) {
        std::string input;

        std::cout << R"(Enter name or "stop" or "print": )";
        std::cin >> input;

        if (input == "stop") {
            break;
        } else if (input == "print") {
            print_map(names);
        } else {
            int number;
            std::cout << "Enter integer: ";
            std::cin >> number;
            names[input] = number;
        }
    }
    return 0;
}

void print_map(const std::map<std::string, int> &names) {
    for (auto it = names.begin(); it != names.end(); ++it) {
        std::cout << it->first << ": " << it->second << std::endl;
    }
}
