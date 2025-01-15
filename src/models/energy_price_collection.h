#ifndef ENERGY_PRICE_COLLECTION_H
#define ENERGY_PRICE_COLLECTION_H

#include <vector>
#include "energy_price.h"

/**
 * @class EnergyPriceCollection
 * @brief A class to manage a collection of energy prices.
 *
 * This class provides functionalities to set the average price, set the interval type,
 * add a price to the collection, display the collection, and write the prices to a file per day.
 *
 * @fn void setAverage(const double &avg)
 * @brief Set the average price.
 * @param avg The average price to be set.
 *
 * @fn void setIntervalType(const int &type)
 * @brief Set the interval type.
 * @param type The interval type to be set.
 *
 * @fn void addPrice(const EnergyPrice &price)
 * @brief Add a price to the collection.
 * @param price The energy price to be added to the collection.
 *
 * @fn void display() const
 * @brief Display the collection.
 *
 * @fn void writeToFilePerDay(const std::string &directory) const
 * @brief Write the prices to a file per day.
 * @param directory The directory where the files will be written.
 *
 * @var std::vector<EnergyPrice> prices
 * @brief A vector to store the collection of energy prices.
 *
 * @var double average
 * @brief The average price of the collection.
 *
 * @var int intervalType
 * @brief The interval type of the collection.
 */
class EnergyPriceCollection
{
public:
    /// @brief Set the average price
    /// @param avg
    void setAverage(const double &avg);

    /// @brief Set the interval type
    /// @param type
    void setIntervalType(const int &type);

    /// @brief Add a price to the collection
    /// @param price
    void addPrice(const EnergyPrice &price);

    /// @brief Display the collection
    void display() const;

    /// @brief Write the prices to a file per day
    /// @param directory
    void writeToFilePerDay(const std::string &directory) const;

private:
    std::vector<EnergyPrice> prices;
    double average;
    int intervalType;
};

#endif // ENERGY_PRICE_COLLECTION_H