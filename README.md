# Energy Price App

This project is a C++ application that fetches energy prices from the European Data API. It provides a simple interface to retrieve and display current energy prices.

## Project Structure

```
energy-price-app
├── src
│   ├── main.cpp               # Entry point of the application
│   ├── api
│   │   └── european_data_api.cpp # Functions to interact with the European Data API
│   ├── models
│   │   └── energy_price.h     # Class definition for energy price data
│   └── utils
│       └── http_client.cpp     # Utility functions for HTTP requests
├── CMakeLists.txt             # CMake configuration file
└── README.md                   # Project documentation
```

## Setup Instructions

1. Install prerequisites
   ```sh
   brew install cmake
   brew install conan
   ```

2. Clone the repository:
   ```sh
   git clone <repository-url>
   cd energy-price-app
   ```

3. Create a build directory:
   ```sh
   mkdir build
   ```

4. Conan installation
   ```sh
   conan install . --output-folder=build --build=missing
   ```

5. Navigate to the build directory
   ```sh
   cd build
   ```

6. Run CMake to configure the project:
   ```sh
   cmake .. -DCMAKE_TOOLCHAIN_FILE=conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Release
   cmake --build .
   ```

7. Build the application:
   ```sh
   make
   ```

## Usage

After building the application, you can run it using:
```
./energy-price-app
```

The application will fetch and display the current energy prices from the European Data API.

## European Data API

This application interacts with the European Data API to retrieve energy pricing information. Ensure you have access to the API and any necessary credentials or tokens required for authentication.

