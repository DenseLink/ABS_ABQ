# ABS_ABQ: Array-Based Stack and Queue Implementation

## Introduction

Welcome to the ABS_ABQ repository, where we explore the implementation and application of Array-Based Stacks (ABS) and Array-Based Queues (ABQ) in C++. This project is designed to demonstrate the efficiency and functionality of these data structures, providing a foundation for understanding their operations, usage, and underlying algorithms.

## Repository Structure

- **`ABQ.cpp` & `ABQ.h`**: Implementation of the Array-Based Queue, a dynamic queue structure allowing enqueue and dequeue operations.
- **`ABS.cpp` & `ABS.h`**: Implementation of the Array-Based Stack, a dynamic stack structure supporting push and pop operations.
- **`main.cpp`**: Contains test cases and performance benchmarks for ABS and ABQ implementations.
- **`leaker.cpp` & `leaker.h`**: Utilities for detecting and reporting memory leaks.
- **Documentation**: Includes `Lab3_ABS_ABQ (2).pdf` and `Extra Credit Lab 3.pdf` providing detailed project requirements and additional challenges.

## Features

- **Dynamic Resizing**: Both ABS and ABQ structures dynamically resize based on the number of elements, optimizing memory usage.
- **Template Implementation**: Utilizes C++ templates to allow stacks and queues to hold any data type.
- **Memory Leak Detection**: Incorporates a custom memory leak detector to ensure efficient memory management.
- **Performance Analysis**: Demonstrates the efficiency of ABS and ABQ through a series of benchmark tests.

## Getting Started

To compile and run the project, ensure you have a C++ compiler that supports C++11 or later. Use the following commands:

```
g++ -std=c++11 -o testApp main.cpp ABQ.cpp ABS.cpp leaker.cpp
./testApp
```
Follow the on-screen prompts to execute various tests on the ABS and ABQ data structures.

## Contributing
Your contributions are welcome! If you have suggestions for improvement or want to report a bug, please feel free to fork the repository, make your changes, and submit a pull request.

## License
This project is licensed under the MIT License - see the LICENSE file for more details.

## Acknowledgments
Special thanks to everyone who contributed to the development and testing of the ABS and ABQ data structures. This project was developed as part of a data structures course to provide hands-on experience with custom data structure implementation.
