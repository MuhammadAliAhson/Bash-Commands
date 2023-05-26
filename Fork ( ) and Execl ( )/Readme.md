# Process Forking Example (Process1.cpp)

This code demonstrates the concept of process forking using the `fork()` function in C++. It creates a child process from the parent process and displays the process IDs for both the parent and child processes. The child process exits with a predefined exit status, which is then captured by the parent process using the `wait()` function.

## Prerequisites

- C++ compiler (e.g., GCC)

## Getting Started

To compile and run the code, follow these steps:

1. Open a terminal or command prompt.
2. Navigate to the directory where the code file is located.
3. Run the following command to compile the code:
   
   ```bash
   g++ process_forking.cpp -o process_forking
   ```

4. Execute the compiled program:
   
   ```bash
   ./process_forking
   ```

## Code Explanation

1. The necessary header files are included:

   ```cpp
   #include <iostream>
   #include <unistd.h>
   #include <stdlib.h>
   #include <sys/wait.h>
   #include <sys/types.h>
   using namespace std;
   ```

2. The `main()` function is defined:

   ```cpp
   int main()
   {
     int input;
   
     pid_t pid = fork();
   
     if (pid >= 0)
     {
       if (pid == 0)
       {
         // Child process
         int id = getpid();
         cout << "Child process id: " << id << endl;
   
         int id2 = getppid();
         cout << "Parent id: " << id2 << endl;
   
         int g = 111;
         exit(g);
       }
       else
       {
         // Parent process
         int id = getpid();
         cout << "Parent id: " << id << endl;
   
         wait(&input); // Stop here and check child process
         cout << "Value is " << WEXITSTATUS(input) << endl;
         cout << "After waiting..." << endl;
       }
     }
   }
   ```

3. Inside the `main()` function, a child process is created using the `fork()` function:

   ```cpp
   pid_t pid = fork();
   ```

4. If the `fork()` function succeeds (returns a non-negative value), the code differentiates between the child and parent processes using the returned value:

   - If the value is 0, it means the code is executing in the child process.
   - If the value is non-zero, it means the code is executing in the parent process.

5. In the child process, the child process ID (`getpid()`) and parent process ID (`getppid()`) are displayed, and then the child process exits with a predefined exit status:

   ```cpp
   int id = getpid();
   cout << "Child process id: " << id << endl;
   
   int id2 = getppid();
   cout << "Parent id: " << id2 << endl;
   
   int g = 111;
   exit(g);
   ```

6. In the parent process, the parent process ID is displayed, and the parent process waits for the child process to complete using the `wait()` function:

   ```cpp
   int id = getpid();
   cout << "Parent id: " << id << endl;
   
   wait(&input); // Stop here and check child process
   ```

7. The exit status of the child process is obtained using the `WEXITSTATUS()` macro and displayed by the parent process:

   ```cpp
   cout << "Value is " << WEXITSTATUS(input) << endl;
   ```

8. Finally

, a message is displayed indicating that the parent process has finished waiting:

   ```cpp
   cout << "After waiting..." << endl;
   ```

## Output

The output of the program will vary depending on the system, but it will generally display the process IDs of the parent and child processes, along with the exit status of the child process.

```
Parent id: 1234
Child process id: 5678
Parent id: 5678
Value is 111
After waiting...
```

## Conclusion

This program demonstrates how to use the `fork()` function to create child processes and obtain their process IDs. It also shows how the parent process can wait for the child process to complete and capture its exit status. Understanding process forking is essential in operating system concepts and can be applied in various scenarios where parallel execution or task distribution is required.

# ------------------------------------------------------

# Forking and Increment Example (Process2.cpp)

This code demonstrates the concept of process forking and incrementing a variable using the `fork()` function in C++. It shows how multiple child processes are created and how the value of the variable is incremented in each process. The code uses conditional statements and loops to control the forking and incrementing behavior.

## Prerequisites

- C++ compiler (e.g., GCC)

## Getting Started

To compile and run the code, follow these steps:

1. Open a terminal or command prompt.
2. Navigate to the directory where the code file is located.
3. Run the following command to compile the code:
   
   ```bash
   g++ forking_and_increment.cpp -o forking_and_increment
   ```

4. Execute the compiled program:
   
   ```bash
   ./forking_and_increment
   ```

## Code Explanation

1. The necessary header files are included:

   ```cpp
   #include <iostream>
   #include <unistd.h>
   #include <stdlib.h>
   #include <sys/wait.h>
   using namespace std;
   ```

2. The `i` variable is declared and initialized to 0:

   ```cpp
   int i = 0;
   ```

3. The `main()` function is defined:

   ```cpp
   int main()
   {
     cout << i << endl;
     fork();
     i = i + 1;
   
     if (fork() || fork() || fork())
     {
       i = i + 1;
       fork();
       cout << i << endl;
     }
   
     cout << "*" << endl;
   
     return 0;
   }
   ```

4. Inside the `main()` function, the initial value of `i` is displayed:

   ```cpp
   cout << i << endl;
   ```

5. The code forks a child process using the `fork()` function:

   ```cpp
   fork();
   ```

6. The `i` variable is incremented:

   ```cpp
   i = i + 1;
   ```

7. The code enters a conditional statement that creates multiple child processes using the `fork()` function:

   ```cpp
   if (fork() || fork() || fork())
   {
     i = i + 1;
     fork();
     cout << i << endl;
   }
   ```

8. Inside the conditional statement, the `i` variable is incremented again, and another child process is forked. The value of `i` is then displayed:

   ```cpp
   i = i + 1;
   fork();
   cout << i << endl;
   ```

9. Finally, an asterisk symbol is displayed:

   ```cpp
   cout << "*" << endl;
   ```

## Output

The output of the program will vary depending on the system and the number of processes created. The `i` variable represents the number of times the process has been forked and incremented.

Example output:

```
0
1
2
*
2
2
3
*
3
3
4
*
4
```

## Conclusion

This program demonstrates how the `fork()` function can be used to create multiple child processes and how a variable can be incremented in each process. Understanding process forking and how it affects variables is essential in understanding parallel execution and the behavior of concurrent programs.

# 0-----------------------------------------------------------------------------------------

# Simple Grade Calculation and Arithmetic Operations (Task3.sh)

This script provides two functionalities: calculating a grade based on user input and performing arithmetic operations. The script is written in Bash.

## Grade Calculation

The first part of the script calculates a grade based on the user's input. The user is prompted to enter a number, and the script determines the corresponding grade. The grades and their respective ranges are defined in the `case` statement.

```bash
read choice

case $choice in
  0[0-9]|1[0-9]|2[0-9]|3[0-9]|4[0-9])
    echo "Grade is D"
    ;;
  5[1-9])
    echo "Grade is C"
    ;;
  6[0-9])
    echo "Grade is B"
    ;;
  7[0-9])
    echo "Grade is B+"
    ;;
  8[0-9]*)
    echo "Grade is A"
    ;;
  *)
    echo "Wrong Input"
    ;;
esac
```

## Arithmetic Operations

The second part of the script performs arithmetic operations on two user-inputted values. The user is prompted to enter two numbers and then select an operation by entering a number from 1 to 4. The script uses a `case` statement to execute the selected operation and display the result.

```bash
read a1
read a2

echo "Enter 1 for Addition"
echo "Enter 2 for Subtraction"
echo "Enter 3 for Multiplication"
echo "Enter 4 for Division"

read choice

case $choice in
  1)
    a3=$(($a1+$a2))
    echo "Value is $a3"
    ;;
  2)
    a3=$(($a1-$a2))
    echo "Value is $a3"
    ;;
  3)
    a3=$(($a1*$a2))
    echo "Value is $a3"
    ;;
  4)
    a3=$(($a1/$a2))
    echo "Value is $a3"
    ;;
esac
```

## Usage

To run the script:

1. Save the script in a file with a `.sh` extension (e.g., `grade_arithmetic.sh`).
2. Open a terminal or command prompt.
3. Navigate to the directory where the script file is located.
4. Make the script file executable using the command: `chmod +x grade_arithmetic.sh`
5. Execute the script using the command: `./grade_arithmetic.sh`

## Conclusion

This script allows users to calculate grades based on input and perform basic arithmetic operations. It can be used for quick grade calculations or simple arithmetic calculations in a command-line environment.


# ------------------------------------------------------------------------------------
