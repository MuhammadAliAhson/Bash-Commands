# Student Average Calculator System

This program is a student average calculator system implemented in C++. It takes input from the user and writes it to a named pipe. The program calculates the average of the input values and outputs the result.

## Prerequisites

- C++ compiler
- Linux operating system (the code uses specific Linux system calls)

## Installation

1. Clone the repository or download the source code files.
2. Open a terminal and navigate to the directory where the code is located.

## Usage

1. Compile the code using a C++ compiler. For example, using g++:
   ```
   g++ task1.cpp -o student_avg_calculator
   ```
2. Run the executable:
   ```
   ./student_avg_calculator
   ```
3. The program will display the following message:
   ```
   Welcome to the student Average Calculator System:
   ```
4. Enter the input values for which you want to calculate the average. Separate each value with a space.
5. Press Enter to submit the input.
6. The program will create a named pipe called "pipe4" if it doesn't exist already.
7. The program will write the input values to the named pipe.
8. The program will display the following message upon successful writing:
   ```
   Writing successful!
   ```
9. The program will terminate.

Note: This code snippet only includes the writing part to the named pipe. The reading and calculation of the average are not included in this code.
