# Dynamic Prices

Dynamic Prices is a C++ project designed to simulate the management and manipulation of bar/restaurant pricing strategy. This project showcases several key C++ features that enhance its functionality and performance.

## Table of Contents
- [Introduction](#introduction)
- [Project Status](#project-status)
- [C++ Features Used](#c-features-used)
- [Other Features](#other-features)
- [Possible improvements](#possible-improvements)
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
- **Timers**: As a mean of coordinating threads and logging price history.
- **Formatting library**: Used for pretty-printing.
- **File streams**: for file reading and writing.

## Other features
- **SOLID principles**: Revolving into a more maintainable and scalable codebase.
- **Strategy pattern**: Allowing to select and switch among custom pricing strategies.
- **Command line tool**: Parse of arguments for a more advanced usage of the program.

## Possible improvements
- **Integrate with a GUI**: So far, this is a terminal-based program. It is already prepared to accept different types of renderers.
- **Orders list in shared memory**: instead of updating prices after each order, it could make sense to update prices in fixed intervals. To do so, past orders should be placed in a shared memory container, and updating strategies should be able to accept several orders for a single update.
- **Coordination of historic and update**: currently as independent processes, it would make sense to have them synchronized.
- **Customization of subproducts**: meaning adding specific logic to classes such as `Meal` or `Beverage`.
- **`Restaurant` entity**: another level of abstraction, which will allow for further customization, ability to have several menus, ...
- **Restocking**: logic to update prices after restocking.

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

[Back to top](#dynamic-prices)