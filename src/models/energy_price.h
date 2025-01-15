#ifndef ENERGY_PRICE_H
#define ENERGY_PRICE_H

#include <iostream>
#include <string>
#include <nlohmann/json.hpp>

class EnergyPrice
{
public:
    double price;
    std::string currency;
    std::string timestamp;

    EnergyPrice(double p, const std::string &c, const std::string &ts)
        : price(p), currency(c), timestamp(ts) {}

    void display() const
    {
        std::cout << "Price: " << price << " " << currency << " at " << timestamp << std::endl;
    }

    static EnergyPrice parseFromJson(const nlohmann::json &jsonData)
    {
        double p = jsonData["price"];
        std::string c = "Euro";
        std::string ts = jsonData["readingDate"];
        return EnergyPrice(p, c, ts);
    }
};

#endif // ENERGY_PRICE_H