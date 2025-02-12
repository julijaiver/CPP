#include <iostream>
#include <sstream>

int main() {
    std::string input;

    while (true) {
        std::cout << "Enter a string or \"stop\" to stop: " << std::endl;
        std::getline(std::cin, input);

        while (input.empty()) {
            std::cout << "Input empty." << std::endl;
            std::cout << "Enter a line with numbers or \"stop\" to stop: " << std::endl;
            std::getline(std::cin, input);
        }

        if (input == "stop") {
            break;
        }

        std::stringstream s(input);
        std:: string word;
        int int_count = 0, total_sum = 0;

        // Check each separated input for validation (is number?)
        while (s >> word) {
            bool is_num = true;
            for (const char c : word) {
                if (!isdigit(c)) {
                    is_num = false;
                }
            }
            // Break if non-number encountered, otherwise sum the numbers
            if (is_num == false) {
                break;
            }

            total_sum += std::stoi(word);
            ++int_count;
        }

        if (int_count > 0) {
            std::cout << "Total of " << int_count << " numbers is " << total_sum << std::endl;
        } else {
            std::cout << "Data invalid." << std::endl;
        }
    }

    return 0;
}
