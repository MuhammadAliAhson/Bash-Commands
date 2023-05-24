# Matrix Multiplication with Child Processes (Question 1)

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


##  Bash Script (Question 3)

This Bash script provides various functionalities related to user administration, application management, IP configuration, and more. It can be executed with different command-line options to perform specific tasks. Below is an overview of the available options and their respective functionalities:

## User Administration

### Option: `--uc`
- Description: Create a new user and assign administrator privileges.
- Usage: `--uc`
- Example: `./OS_Assignment_1.sh --uc`
- Prompts for the username and password of the new user.
- Creates a new user account, sets the password, and assigns administrator privileges.

## Application Management

### Option: `--ld`
- Description: List all installed applications.
- Usage: `--ld`
- Example: `./OS_Assignment_1.sh --ld`
- Displays a list of all installed applications using the `dpkg -l` command.

### Option: `--ins`
- Description: Install Dropbox.
- Usage: `--ins`
- Example: `./OS_Assignment_1.sh --ins`
- Updates the package list using `apt-get update`.
- Installs the Dropbox package (`nautilus-dropbox`) using `apt-get install`.

## IP Configuration

### Option: `--ipcon`
- Description: Set IP address, subnet mask, default gateway, and DNS server.
- Usage: `--ipcon IP MASK GATEWAY DNS`
- Example: `./OS_Assignment_1.sh --ipcon 192.168.0.100 255.255.255.0 192.168.0.1 8.8.8.8`
- Configures the network interface (`eth0`) with the provided IP address, subnet mask, default gateway, and DNS server.
- Updates the `/etc/resolv.conf` file with the specified DNS server.

## Help

### Option: `--help`
- Description: Display help information.
- Usage: `--help`
- Example: `./OS_Assignment_1.sh --help`
- Displays a help message with usage instructions and a description of all available options.

## Execution

To execute the script, open a terminal and navigate to the directory containing the script file. Then, use the following command:

```
./OS_Assignment_1.sh [OPTIONS]
```

Replace `[OPTIONS]` with the desired option according to the functionalities mentioned above.

**Note:** The script requires root privileges for certain operations. Make sure to run the script as a superuser or with sudo privileges.

Author: Muhammad Ali Ahson
