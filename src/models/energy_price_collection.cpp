#include "energy_price_collection.h"
#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <iomanip>

void EnergyPriceCollection::setAverage(const double &avg)
{
    average = avg;
}

void EnergyPriceCollection::setIntervalType(const int &type)
{
    intervalType = type;
}

void EnergyPriceCollection::addPrice(const EnergyPrice &price)
{
    prices.push_back(price);
}

void EnergyPriceCollection::display() const
{
    std::cout << "Average: " << average << std::endl;
    std::cout << "Interval type: " << intervalType << std::endl;

    for (const auto &price : prices)
    {
        price.display();
    }
}

void EnergyPriceCollection::writeToFilePerDay(const std::string &directory) const
{
    std::map<std::string, std::vector<EnergyPrice>> pricesPerDay;

    // Group prices by day
    for (const auto &price : prices)
    {
        std::string day = price.timestamp.substr(0, 10); // Extract the date part (YYYY-MM-DD)
        pricesPerDay[day].push_back(price);
    }

    // Ensure the directory exists
    std::filesystem::create_directories(directory);

    // Write each day's prices to a separate file
    for (const auto &entry : pricesPerDay)
    {
        std::string day = entry.first;
        const auto &dayPrices = entry.second;

        std::ostringstream filename;
        filename << directory << "/" << day << "_prices.csv";

        std::ofstream file(filename.str());
        if (!file.is_open())
        {
            std::cerr << "Failed to open file: " << filename.str() << std::endl;
            continue;
        }

        // Write the header
        file << "Price,Timestamp\n";

        // Write the data
        for (const auto &price : dayPrices)
        {
            file << price.price << "," << price.timestamp << "\n";
        }

        file.close();
    }
}