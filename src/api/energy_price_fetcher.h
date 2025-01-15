#ifndef ENERGY_PRICE_FETCHER_H
#define ENERGY_PRICE_FETCHER_H

#include <string>
#include <nlohmann/json.hpp>
#include "../models/energy_price.h"
#include "../models/energy_price_collection.h"

class EnergyPriceFetcher
{
public:
    EnergyPriceCollection fetchPrices(const std::string &fromDate, const std::string &tillDate, int usageType);

private:
    std::string fetchPriceUrl(const std::string &fromDate, const std::string &tillDate, int usageType);
};

#endif // ENERGY_PRICE_FETCHER_H