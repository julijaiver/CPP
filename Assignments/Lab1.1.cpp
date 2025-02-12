#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers;
    int num_of_elements, element;
    std::cout << "Enter the number of elements: ";
    std::cin >> num_of_elements;
    std::cout << std::endl;

    for (int i = 0; i < num_of_elements; ++i) {
        std::cout << "Enter nr[" << i + 1 << "]: ";
        std::cin >> element;
        numbers.push_back(element);
        std::cout << std::endl;
    }

    std::cout << "You entered: ";
    for (int i = 0; i < num_of_elements; ++i) {
        if (i < num_of_elements - 1) {
            std::cout << numbers[i] << ", ";
        } else {
            std::cout << numbers[i] << std::endl;
        }
    }
    std::cout << std::endl;

    return 0;
}