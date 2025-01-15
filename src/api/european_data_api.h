#ifndef EUROPEANDATAAPI_H
#define EUROPEANDATAAPI_H

#include <iostream>
#include <curl/curl.h>
#include <string>

#include "../models/energy_price.h"

class EuropeanDataAPI
{
public:
    static std::string fetchEnergyPrices(const std::string &url);

private:
    static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp);
};

#endif // EUROPEANDATAAPI_H