cmake_minimum_required(VERSION 3.10)

project(EnergyPriceApp)

set(CMAKE_CXX_STANDARD 17)

# Include Conan build info
#include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
#conan_basic_setup()

find_package(curl REQUIRED)
find_package(nlohmann_json REQUIRED)

#include_directories(${nlohmann_json_INCLUDE_DIRS})

include_directories(src/models)
include_directories(src/utils)
include_directories(src/api)

file(GLOB SOURCES
    src/main.cpp
    src/api/energy_price_fetcher.cpp
    src/api/european_data_api.cpp
    src/models/energy_price_collection.h
    src/models/energy_price_collection.cpp
    src/models/energy_price.h
    src/utils/http_client.cpp
    src/utils/time_utils.h
    src/utils/time_utils.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

# Add Google Test
enable_testing()
add_subdirectory(external/googletest)
include_directories(external/googletest/googletest/include)

# Add test executable
add_executable(EnergyPriceAppTests
    tests/test_energy_price.cpp
)

target_link_libraries(${PROJECT_NAME} ${CONAN_LIBS} curl nlohmann_json::nlohmann_json)
#target_link_libraries(${PROJECT_NAME} PRIVATE nlohmann_json::nlohmann_json)
#target_link_libraries(${PROJECT_NAME} nlohmann_json::nlohmann_json)

target_link_libraries(EnergyPriceAppTests gtest gtest_main nlohmann_json::nlohmann_json)
add_test(NAME EnergyPriceAppTests COMMAND EnergyPriceAppTests)