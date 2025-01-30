# Dynamic Prices

Dynamic Prices is a C++ project designed to simulate the management and manipulation of bar/restaurant pricing strategy. This project showcases several key C++ features that enhance its functionality and performance.

## Table of Contents
- [Introduction](#introduction)
- [Project Status](#project-status)
- [C++ Features Used](#c-features-used)
- [Other Features](#other-features)
- [Getting Started](#getting-started)
- [Contributing](#contributing)
- [License](#license)

## Introduction
Dynamic Prices is a project that demonstrates the use of modern C++ (C++11 and beyond) to handle dynamic pricing scenarios in the restaurant sector, based on real-time supply and demand. It is designed to be flexible and efficient, making it suitable for various applications that require real-time price adjustments.

## Project status
This represents a demo scenario, not a production-ready project. It can be considered the scaffolding for a greater project. It leverages, however, powerful programming techniques and software design patterns to make it scalable and maintainable.

## C++ Features Used
- **Templates**: Utilized for creating generic data structures that can handle different types of data.
- **STL (Standard Template Library)**: Leveraged for advanced data manipulation and algorithmic operations.
- **Smart Pointers**: Employed to manage memory more effectively and prevent memory leaks (example of the RAII rule).
- **Concurrency**: Used to enable parallel processing and improve performance. Not limited to threads and joinable threads, but also to its coordination through semaphores/mutexes.
- **Formatting library**: Used for pretty-printing.
- **File streams**: for file reading and writing.

## Other features
- **SOLID principles**: Revolving into a more maintainable and scalable codebase.
- **Strategy pattern**: Allowing to select and switch among custom pricing strategies.

## Getting Started
To get started with Dynamic Prices, follow these steps:

1. Clone the repository:
    ```bash
    git clone https://github.com/venturarome/dynamic-prices.git
    ```

2. Navigate to the project directory:
    ```bash
    cd dynamic-prices
    ```

3. Build the project using your preferred C++ compiler. Asumming g++ is used, an option may be:
    ```bash
    g++ -std=c++20 src/*.cc -o prog -lpthread -Wall
    ```

4. Run the executable:
    ```bash
    ./prog
    ```

## Contributing
Contributions are welcome! Create a pull request and it will be reviewed.

## License
This project is licensed under the MIT License.