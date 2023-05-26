# Student Average Calculator System (Question 1)

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

# ==================================================

# Student Average Calculator System (Question 2)

This program is a student average calculator system implemented in C++. It reads input values from a named pipe, calculates the average, and displays the result. The code snippet provided here focuses on the reading and calculation part of the system.

## Prerequisites

- C++ compiler
- Linux operating system (the code uses specific Linux system calls)

## Installation

1. Clone the repository or download the source code files.
2. Open a terminal and navigate to the directory where the code is located.

## Usage

1. Compile the code using a C++ compiler. For example, using g++:
   ```
   g++ task2.cpp -o student_avg_calculator
   ```
2. Run the executable:
   ```
   ./student_avg_calculator
   ```
3. The program will display the following message:
   ```
   Welcome to the student Average Calculator System:
   ```
4. Ensure that the named pipe "pipe4" exists. If it doesn't exist, the program will create it with appropriate permissions (0660).
5. The program will read the input values from the named pipe.
6. The program will display the received values from the pipe.
7. The program will calculate the average of the received values.
8. The program will display the following message:
   ```
   The Average of the students is: <average_value>
   ```
   where `<average_value>` is the calculated average.
9. The program will terminate.

Note: This code snippet assumes that the writing part to the named pipe has already been implemented. Make sure to refer to the relevant code snippet or file for the writing part. 

---
© Muhammad Ali Ahson

If you find this code useful, please consider starring this repository to show your appreciation.






