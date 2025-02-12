#include <algorithm>
#include <iostream>
#include <vector>

#include "apartment.h"
#include "house.h"

int main() {
    auto house1 = std::make_shared<House>("Lehtovuorenkatu 6", 1650, 9800000);
    auto house2 = std::make_shared<House>("Leikosaarenkuja 12", 2540, 14000000);

    std::vector<Apartment> apartments;

    apartments.emplace_back(house1, 5, 47, 883);
    apartments.emplace_back(house1, 7, 52, 980);
    apartments.emplace_back(house1, 24, 30, 695);

    apartments.emplace_back(house2, 1, 42, 790);
    apartments.emplace_back(house2, 11, 75, 1320);
    apartments.emplace_back(house2, 7, 31, 705);
    apartments.emplace_back(house2, 31, 56, 1133);

    std::sort(apartments.begin(), apartments.end());

    for (const auto &apartment : apartments) {
        apartment.Print();
        std::cout << std::endl;
    }

    return 0;
}
