#ifndef APARTMENT_H
#define APARTMENT_H

#include <memory>
#include "house.h"

class Apartment {
public:
    Apartment(std::shared_ptr<House> house, int apt_num, int apt_size, double monthly_rent);
    bool operator<(const Apartment &other) const;
    void Print() const;

private:
    std::shared_ptr<House> house;
    int apt_num;
    int apt_size;
    double monthly_rent;
};


#endif //APARTMENT_H
