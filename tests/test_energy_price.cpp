#include <gtest/gtest.h>
#include "../src/models/energy_price.h"
#include <nlohmann/json.hpp>

// Test the constructor and getters
TEST(EnergyPriceTest, ConstructorAndGetters)
{
    double price = 0.58;
    std::string currency = "EUR";
    std::string timestamp = "2025-01-15T00:00:00Z";

    EnergyPrice energyPrice(price, currency, timestamp);

    EXPECT_EQ(energyPrice.price, price);
    EXPECT_EQ(energyPrice.timestamp, timestamp);
}

// Test the display method
TEST(EnergyPriceTest, Display)
{
    double price = 0.58;
    std::string currency = "EUR";
    std::string timestamp = "2025-01-15T00:00:00Z";

    EnergyPrice energyPrice(price, currency, timestamp);

    testing::internal::CaptureStdout();
    energyPrice.display();
    std::string output = testing::internal::GetCapturedStdout();

    std::string expectedOutput = "Price: 0.58 EUR at 2025-01-15T00:00:00Z\n";
    EXPECT_EQ(output, expectedOutput);
}

// Test the parseFromJson method
TEST(EnergyPriceTest, ParseFromJson)
{
    std::string jsonString = R"({
        "price": 0.58,
        "currency": "EUR",
        "readingDate": "2025-01-15T00:00:00Z"
    })";

    nlohmann::json jsonData = nlohmann::json::parse(jsonString);
    EnergyPrice energyPrice = EnergyPrice::parseFromJson(jsonData);

    EXPECT_EQ(energyPrice.price, 0.58);
    EXPECT_EQ(energyPrice.timestamp, "2025-01-15T00:00:00Z");
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}