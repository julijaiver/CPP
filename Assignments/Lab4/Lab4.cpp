#include <algorithm>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector>
#include <limits>

#include "item.h"

void print_items(const std::vector<Item>& items);
double calculate_net_worth(const std::vector<Item>& items);

int main() {
    std::vector<Item> items;

    while (true) {
        std::string input;
        std::cout << R"(Enter item information starting with the name, "json" to enter json data or "stop" to stop: )" << std::endl;
        std::getline(std::cin, input);

        if (input == "stop") {
            break;
        }
        if (input == "json") {
            std::cout << "Enter json data: ";
            std::getline(std::cin, input);
            std::istringstream json(input);
            Item item;
            if (json >> item) {
                items.push_back(item);
                std::cout << "Item added." << std::endl;
            } else {
                std::cerr << "Invalid input." << std::endl;
            }
        } else {
            std::string name = input;
            int weight, count;
            double price;

            std::cout << "Enter weight (g): ";
            while (!(std::cin >> weight) || weight <= 0) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cerr << "Invalid input. Enter weight (g): ";
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout << "Enter price: ";
            while (!(std::cin >> price) || price <= 0) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cerr << "Invalid input. Enter price: ";
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout << "Enter count: ";
            while (!(std::cin >> count) || count < 0) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cerr << "Invalid input. Enter count: ";
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            items.emplace_back(name, weight, price, count);
            std::cout << "Item added." << std::endl;
        }
    }

    if (items.empty()) {
        std::cout << "No items added." << std::endl;
        return 0;
    }

    std::sort(items.begin(), items.end());

    std::cout << "Sorted items:" << std::endl;
    print_items(items);
    double net_worth = calculate_net_worth(items);
    std::cout << "Net worth: " << std::setprecision(3) << net_worth << std::endl;

    while(true) {
        std::cout << "Enter item index to update the price or \"stop\" to stop: ";
        std::string input;
        std::cin >> input;

        if (input == "stop") {
            break;
        }
        std::istringstream iss(input);
        int index;

        if (!(iss >> index) || index <= 0 || index > static_cast<int>(items.size())) {
            std::cerr << "Invalid index. Enter index again: ";
        } else {
            double new_price;
            std::cout << "Enter new price: ";
            if (!(std::cin >> new_price) || new_price <= 0) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cerr << "Invalid input. Enter new price: ";
            } else {
                items[index-1].setPrice(new_price);
                std::cout << "Price updated" << std::endl;
            }
        }
    }

    std::sort(items.begin(), items.end());
    std::cout << "Sorted items:" << std::endl;
    print_items(items);
    net_worth = calculate_net_worth(items);
    std::cout << "Net worth: " << std::fixed << std::setprecision(2) << net_worth << std::endl;

    return 0;
}

void print_items(const std::vector<Item>& items) {
    for (size_t i = 0; i < items.size(); ++i) {
        std::cout << (i + 1) << " " << items[i] << std::endl;
    }
}

double calculate_net_worth(const std::vector<Item>& items) {
    double total_worth = 0.0;
    for (const auto& item : items) {
        total_worth += item.getPrice() * item.getCount();
    }
    return total_worth;
}