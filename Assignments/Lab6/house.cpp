#include "house.h"

#include <utility>

House::House(std::string address, double size, double price) :
    address(std::move(address)), size(size), price(price) {}

std::string House::getAddress() const {
    return address;
}

void House::setAddress(const std::string &address) {
    this->address = address;
}

void House::setArea(const double area) {
    size = area;
}

void House::setPrice(const double price) {
    this->price = price;
}

bool House::operator<(const House &other) const {
    return price/size < other.price/other.size;
}

std::ostream &operator<<(std::ostream &out, const House &house) {
    out << house.address << " " << house.size << "sq.m " << house.price << "eur";
    return out;
}



