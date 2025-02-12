#include "item.h"
#include <sstream>
#include <vector>

Item::Item() : weight_g(0), price(0.0), available(0) {}

Item::Item(const std::string &name, int weight_g, double price, int available)
    : name(name), weight_g(weight_g), price(price), available(available) {}

// get functions
int Item::getCount() const {
 return available;
}

double Item::getPrice() const {
    return price;
}

// set functions
void Item::setCount(const int count) {
    available = count;
}

void Item::setPrice(const double new_price) {
    price = new_price;
}

// overloaded output
std::ostream &operator<<(std::ostream &os, const Item &item) {
    os << "{ \"Name\":\"" << item.name
    << "\", \"Weight\":" << item.weight_g
    << ", \"Price\":" << item.price
    << ", \"Count\":" << item.available << "}";

    return os;
}

std::istream &operator>>(std::istream &is, Item &item) {
    std::string input;
    char ch;
    bool json = false;

    while(is.get(ch)) {
        if(ch == '{') {
            json = true;
        }
        if (json) {
            input += ch;
        }
        if (json && ch == '}') {
            break;
        }
    }
    //std::getline(is, input);

    if (input.empty() && input.front() == '{' || input.back() != '}') { // check for json input
            is.setstate(std::ios::failbit);
            return is;
    }
    input = input.substr(1, input.size() - 2);
    std::istringstream iss(input);
    std::string pair;
    // storing values
    std::string name;
    int weight = 0, count = 0;
    double price = 0.0;

    auto trim = [](std::string &s) {
        s.erase(0, s.find_first_not_of(" \""));
        s.erase(s.find_last_not_of(" \"") + 1);
    };

    while (std::getline(iss, pair, ',')) {
        std::istringstream pair_stream(pair);
        std::string key, value;
        if (std::getline(pair_stream, key, ':') && std::getline(pair_stream, value)) {
            trim(key);
            trim(value);

            if (key == "Name") {
                name = value;
            } else if (key == "Weight") {
                weight = std::stoi(value);
            } else if (key == "Price") {
                price = std::stod(value);
            } else if (key == "Count") {
                count = std::stoi(value);
            }
        }
    }
    item = Item(name, weight, price, count);
    return is;
}

bool Item::operator<(const Item &other) const {
    double price_kg_itemA = price / (weight_g / 1000.0);
    double price_kg_itemB = other.price / (other.weight_g / 1000.0);
    return price_kg_itemA < price_kg_itemB;
}






