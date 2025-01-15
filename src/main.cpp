#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <string>

#include "api/energy_price_fetcher.h"
#include "api/european_data_api.h"
#include "models/energy_price.h"
#include "models/energy_price_collection.h"
#include "utils/time_utils.h" // Include the new time_utils header

const int USAGE_TYPE_ELECTRICITY = 1;
const int USAGE_TYPE_GAS = 3;

void fetchHistoricalData()
{
    std::tm *time = getTimeInHistory(365);
    time = setToMidnight(time);
    std::string fromDate = formatDate(*time);

    std::tm *till = getLocalTime();
    till = setToEndOfDay(till);
    std::string tillDate = formatDate(*till);

    // fetch electricity and gas prices for historical data
    EnergyPriceFetcher fetcher;
    EnergyPriceCollection electricityPrices = fetcher.fetchPrices(fromDate, tillDate, USAGE_TYPE_ELECTRICITY);
    EnergyPriceCollection gasPrices = fetcher.fetchPrices(fromDate, tillDate, USAGE_TYPE_GAS);

    // write these collections into a file per day
    electricityPrices.writeToFilePerDay("EnergyPrices/electricity");
    gasPrices.writeToFilePerDay("EnergyPrices/gas");
}

void fetchTomorrowsData()
{
    std::tm *now_tm = getLocalTime();
    now_tm = setToMidnight(now_tm);
    now_tm->tm_mday += 1;

    printTime(now_tm);

    std::string fromDate = formatDate(*now_tm);

    // Add one day to the current date
    now_tm = setToEndOfDay(now_tm);
    std::mktime(now_tm); // Normalize the tm structure

    printTime(now_tm);

    std::string tillDate = formatDate(*now_tm);

    EnergyPriceFetcher fetcher;
    EnergyPriceCollection electricityPrices = fetcher.fetchPrices(fromDate, tillDate, USAGE_TYPE_ELECTRICITY);
    EnergyPriceCollection gasPrices = fetcher.fetchPrices(fromDate, tillDate, USAGE_TYPE_GAS);

    electricityPrices.writeToFilePerDay("EnergyPrices/electricity");
    gasPrices.writeToFilePerDay("EnergyPrices/gas");

    std::cout << "Electricity Prices:" << std::endl;
    electricityPrices.display();

    std::cout << "Gas Prices:" << std::endl;
    gasPrices.display();
}

int main()
{
    std::cout << "Energy Price App" << std::endl;

    fetchHistoricalData();
    fetchTomorrowsData();

    return 0;
}