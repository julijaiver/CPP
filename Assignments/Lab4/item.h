#ifndef ITEM_H
#define ITEM_H

#include <iostream>

class Item {
    // overloaded operators
    friend std::istream& operator>>(std::istream& in, Item &item);
    friend std::ostream& operator<<(std::ostream& out, const Item &item);
public:
    // constructors
    Item();
    Item(const std::string &name, int weight_g, double price, int available);
    bool operator<(const Item &other) const;
    // member functions
    int getCount() const;
    void setCount(int count);
    double getPrice() const;
    void setPrice(double price);

private:
    std::string name;
    int weight_g;
    double price;
    int available;
};

#endif //ITEM_H
