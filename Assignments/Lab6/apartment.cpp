#include "apartment.h"

#include <utility>

Apartment::Apartment(std::shared_ptr<House> house, const int apt_num, const int apt_size, double monthly_rent) :
    house(std::move(house)), apt_num(apt_num), apt_size(apt_size), monthly_rent(monthly_rent) {}

bool Apartment::operator<(const Apartment &other) const {
    return monthly_rent < other.monthly_rent;
}

void Apartment::Print() const {
    std::cout << house->getAddress() << " - " << apt_size << "m2 - " << monthly_rent << "eur";
}
