#ifndef HOUSE_H
#define HOUSE_H

#include <iostream>

class House {
friend std::ostream& operator<<(std::ostream& out, const House& house);
public:
    House(std::string address, double size, double price);

void setAddress(const std::string &address);
    [[nodiscard]] std::string getAddress() const;
    void setArea(double area);
    void setPrice(double price);
    bool operator<(const House& other) const;

private:
    std::string address;
    double size;
    double price;
};


#endif //HOUSE_H
