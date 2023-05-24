
## Shared Memory and Process Communication (Question 2)

This program demonstrates process communication using shared memory in C++. It creates child processes and allows them to read and write data using shared memory.

## Prerequisites

- C++ compiler
- Linux operating system

## Usage

1. Compile the program along with the other user programs. For example:

```bash
g++ main.cpp -o main
g++ user1.cpp -o user1
g++ user2.cpp -o user2
g++ user3.cpp -o user3
```

2. Run the program:

```bash
./main
```

## Overview

The program follows these steps:

1. Creates a child process using `fork()`.
2. Generates a random value `a` to determine which user program to execute.
3. If the current process is the child process (pi == 0), it proceeds with the following steps:
   - Generates a random argument value `arg` to pass to the user program.
   - Executes the corresponding user program based on the value of `a`.
4. If the current process is the parent process, it waits for the child process to finish.
5. The program terminates.

## User Programs

- `user1`, `user2`, and `user3` are separate programs that are executed based on the value of `a`.
- Each user program performs specific tasks, such as reading from and writing to shared memory.

## Process Communication and Deadlock

The program demonstrates the potential for a deadlock when multiple processes attempt to read from and write to shared memory simultaneously. To avoid a deadlock scenario, the program includes comments that suggest stopping the child process from creating more processes or using statements to ensure that reading occurs before writing.

## Notes

- The program uses shared memory to allow multiple processes to communicate and share data.
- The `rand()` function is used to generate random values for `a` and `arg`. As a result, the output may vary on each run.
- The program illustrates the concept of process creation, execution, and synchronization using shared memory.
- Proper resource cleanup and error handling should be implemented in a production environment.


## Copyright Notice:

This script is created by Muhammad Ali Ahson. It is provided as-is without any warranty. If you find this script useful, please show your appreciation by including an acknowledgment or attribution when using or distributing this code.

Your support and recognition are greatly appreciated!

Author: Muhammad Ali Ahson
