#include "energy_price_fetcher.h"
#include "european_data_api.h"
#include <iostream>

std::string EnergyPriceFetcher::fetchPriceUrl(const std::string &fromDate, const std::string &tillDate, int usageType)
{
    std::string url = "https://api.energyzero.nl/v1/energyprices?&fromDate=" + fromDate + "&tillDate=" + tillDate + "&interval=4&usageType=" + std::to_string(usageType) + "&inclBtw=true";
    return url;
}

EnergyPriceCollection EnergyPriceFetcher::fetchPrices(const std::string &fromDate, const std::string &tillDate, int usageType)
{
    EnergyPriceCollection collection;
    std::string url = fetchPriceUrl(fromDate, tillDate, usageType);
    std::string jsonData = EuropeanDataAPI::fetchEnergyPrices(url);

    try
    {
        nlohmann::json json = nlohmann::json::parse(jsonData);

        auto prices = json["Prices"];
        auto average = json["average"];
        auto intervalType = json["intervalType"];

        if (!average.is_null())
        {
            collection.setAverage(average);
        }

        if (!intervalType.is_null())
        {
            collection.setIntervalType(intervalType);
        }

        if (prices.is_array() && !prices.empty())
        {
            for (const auto &item : prices)
            {
                EnergyPrice energyPrice = EnergyPrice::parseFromJson(item);
                collection.addPrice(energyPrice);
            }
        }
        else
        {
            std::cerr << "Unexpected JSON structure" << std::endl;
        }
    }
    catch (const nlohmann::json::exception &e)
    {
        std::cerr << "JSON parsing error: " << e.what() << std::endl;
    }

    return collection;
}