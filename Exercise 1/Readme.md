# Matrix Multiplication with Child Processes

This program performs matrix multiplication using child processes in C++. It generates a random matrix, saves it to a text file, and then creates multiple child processes to calculate the resultant matrix.

## Prerequisites

- C++ compiler
- Linux operating system

## Usage

1. Compile the program using the C++ compiler. For example, using g++:

```bash
g++ Question1.cpp -o q1
```

2. Run the program:

```bash
./q1
```

## Overview

The program follows these steps:

1. Generates a random value `n` to determine the size of the matrix.
2. Populates a matrix of size `n x n` with random values.
3. Saves the matrix to a text file named "matrix.txt".
4. Creates `n` child processes to perform matrix multiplication.
5. Each child process calculates a row of the resultant matrix and saves it to a text file.
6. The parent process waits for all child processes to finish.
7. The parent process reads the result files and displays the resultant matrix.

## Output

The program displays the following information:

- The size of the matrix generated.
- The original matrix filled with random values.
- The resultant matrix obtained from the multiplication.

## Notes

- The program uses random values to generate the matrix and perform the multiplication. As a result, the output may vary on each run.
- The program creates multiple child processes using `fork()` to parallelize the matrix multiplication process.
- Each child process performs the multiplication for a specific row of the matrix.
- The program saves the resultant rows in separate files named "result_i.txt" where `i` represents the row number.
- After all child processes have completed, the program reads the result files and displays the final matrix.

**Important**: Make sure to handle resource cleanup and error handling appropriately for production use.
