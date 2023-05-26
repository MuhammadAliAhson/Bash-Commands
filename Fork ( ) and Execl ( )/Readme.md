## Readme File Details are given below for every Question with name of the file.

![WhatsApp Image 2023-02-15 at 2 00 15 PM](https://github.com/MuhammadAliAhson/BASH_Coding/assets/105967134/ec83f210-ad6d-45fb-88aa-36193cc0cf42)


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


# ----------------------------------------------------------------------------

# LCM and HCF Calculation  (Task4(a).cpp)

This C++ program calculates the Least Common Multiple (LCM) and Highest Common Factor (HCF) of two given numbers. The program utilizes the fork() function to create a child process that calculates the LCM, while the parent process calculates the HCF.

```cpp
#include <iostream>
#include <unistd.h>
#include <bits/stdc++.h>
#include <sys/wait.h>
using namespace std;

int main() {
    int a, b, max_num, hcf;
    int status;
    a = 42;
    b = 63;

    pid_t t1 = fork();
    if (t1 == 0) {
        max_num = max(a, b);

        while (1) {
            if (max_num % a == 0 && max_num % b == 0) {
                cout << "The LCM of " << a << " and " << b << " is " << max_num << endl;
                break;
            }
            ++max_num;
        }
    } else {
        wait(&status);
        for (int i = 1; i <= a || i <= b; i++) {
            if (a % i == 0 && b % i == 0)
                hcf = i;
        }

        cout << "HCF of " << a << " and " << b << " is " << hcf << endl;
    }

    return 0;
}
```

## How it works

1. The program starts by declaring the required variables, including `a` and `b` for the input numbers, `max_num` for calculating the LCM, `hcf` for storing the HCF, and `status` for storing the child process status.
2. The program forks a child process using `fork()`.
3. In the child process (identified by `t1 == 0`), the LCM is calculated by finding the minimum common multiple that is divisible by both `a` and `b`. The result is displayed.
4. In the parent process, the HCF is calculated using a loop. The loop iterates from 1 to the maximum of `a` and `b`, checking if each number is a common factor. The largest common factor is stored in `hcf` and displayed.
5. The parent process waits for the child process to finish using `wait(&status)`.
6. The program terminates.

## Usage

1. Save the code in a file with a `.cpp` extension, such as `lcm_hcf.cpp`.
2. Compile the code using a C++ compiler: `g++ lcm_hcf.cpp -o lcm_hcf`.
3. Run the program: `./lcm_hcf`.

## Conclusion

This program efficiently calculates the LCM and HCF of two numbers using separate child and parent processes. It demonstrates the usage of `fork()` to create child processes and the wait function to synchronize their execution. The program can be useful in various mathematical calculations and number theory applications.

# ----------------------------------------------------

# Number Operations (Task-4(b).cpp)

This C++ program performs various operations on input numbers. The program uses multiple child processes created using the `fork()` function to execute different calculations concurrently.

```cpp
#include <iostream>
#include <unistd.h>
#include <bits/stdc++.h>
#include <sys/wait.h>
#include <algorithm>

using namespace std;

int main() {
    int a1, b, c, max_num;
    int status;

    pid_t t1 = fork();
    if (t1 == 0) {
        pid_t t2 = fork();

        if (t2 == 0) {
            pid_t t3 = fork();

            if (t3 == 0) {
                cout << "Please enter the numbers: " << endl;
                cin >> a1 >> b >> c;
                max_num = max({a1, b, c});
                exit(max_num);
            } else if (t3 > 0) {
                wait(&status);
                int a = WEXITSTATUS(status);
                a = a * a;
                exit(a);
            }
        } else if (t2 > 0) {
            wait(&status);
            int a = WEXITSTATUS(status);
            if (a % 2 == 0) {
                cout << "It's Even" << endl;
                exit(a);
            }
        }

    } else if (t1 > 0) {
        wait(&status);
        int a = WEXITSTATUS(status);
        cout << "Multiples are: ";
        for (int i = a; i < 50; i = i * 2) {
            cout << " " << i << " ";
        }
        cout << endl;
    }

    return 0;
}
```

## How it works

1. The program starts by declaring the required variables, including `a1`, `b`, `c` for input numbers, `max_num` for storing the maximum number, and `status` for storing the child process status.
2. The program forks the first child process using `fork()`.
3. In the first child process (identified by `t1 == 0`), it forks a second child process.
4. In the second child process (identified by `t2 == 0`), it forks a third child process.
5. In the third child process (identified by `t3 == 0`), it prompts the user to enter three numbers (`a1`, `b`, `c`), calculates the maximum number among them using the `max()` function, and exits with the maximum number as the status.
6. In the second child process (identified by `t2 == 0`), it waits for the third child process to finish using `wait(&status)`. It then calculates the square of the value received from the third child process (`WEXITSTATUS(status)`), exits with the squared value as the status if it is even, or continues to the next step if it is odd.
7. In the first child process (identified by `t1 == 0`), it waits for the second child process to finish using `wait(&status)`. It receives the value from the second child process (`WEXITSTATUS(status)`) and checks if it is even. If it is even, it prints "It's Even" and exits with the received value as the status. If it is odd, it continues to the next step.
8. In the parent process, it waits for the first child process to finish using `wait(&status)`. It receives the value from the first child process (`WEXITSTATUS(status)`) and prints the multiples of that value up to 50, doubling the value at each iteration.
9.

 The program terminates.

## Usage

1. Save the code in a file with a `.cpp` extension, such as `number_operations.cpp`.
2. Compile the code using a C++ compiler: `g++ number_operations.cpp -o number_operations`.
3. Run the program: `./number_operations`.

## Conclusion

This program showcases the usage of multiple child processes created using `fork()` to perform calculations concurrently. It demonstr# External Program Execution

This C++ program demonstrates the execution of an external program using the `execl()` function. It forks a child process and replaces its image with the specified external program, passing command-line arguments. 

```cpp
#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
using namespace std;

int main() {
    int status = 0;
    pid_t t1 = fork();
    if (t1 == 0) {
        execl("/home/lab/Desktop/task2", "task2", "my name", "Ali", NULL);
        //execlp("./task2", "my name", "Ali", NULL);
        cout << "After execl" << endl;
        exit(status);
    } else {
        wait(&t1);
    }
    return 0;
}
```

## How it works

1. The program starts by declaring the `status` variable to store the child process status.
2. The program forks a child process using `fork()`.
3. In the child process (identified by `t1 == 0`), it uses the `execl()` function to replace its image with the specified external program.
   - The first argument (`/home/lab/Desktop/task2`) is the path to the external program executable.
   - The second argument (`task2`) is the program name or a custom name.
   - The third and subsequent arguments (`my name`, `Ali`) are the command-line arguments to be passed to the external program.
   - The last argument (`NULL`) marks the end of the argument list.
   - Note: You can also use `execlp()` instead of `execl()` to search for the executable in the directories listed in the `PATH` environment variable.
4. If the `execl()` function is successful, the subsequent code after `execl()` is not executed. Therefore, the "After execl" message is not printed.
5. After executing the external program, the child process exits with the `status` value.
6. In the parent process, it waits for the child process to finish using `wait(&t1)`, allowing the parent to synchronize with the child process.
7. The parent process continues its execution, and the program terminates.

## Usage

1. Save the code in a file with a `.cpp` extension, such as `external_program_execution.cpp`.
2. Modify the path (`/home/lab/Desktop/task2`) in the code to the actual path of the external program executable.
3. Compile the code using a C++ compiler: `g++ external_program_execution.cpp -o external_program_execution`.
4. Ensure that the external program (`task2`) exists at the specified path.
5. Run the program: `./external_program_execution`.

## Conclusion

This program demonstrates how to execute an external program from a C++ program using the `execl()` function. By forking a child process and replacing its image with the desired program, it allows seamless integration of external functionalities. This approach enables communication and data exchange between the parent and child processes.ates the ability to communicate values between parent and child processes using exit status. The program can be used to find the maximum number, check if a number is even, and generate multiples of a number.

# ----------------------------------------------------


# External Program Execution  (Task-5(a).cpp)

This C++ program demonstrates the execution of an external program using the `execl()` function. It forks a child process and replaces its image with the specified external program, passing command-line arguments. 

```cpp
#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
using namespace std;

int main() {
    int status = 0;
    pid_t t1 = fork();
    if (t1 == 0) {
        execl("/home/lab/Desktop/task2", "task2", "my name", "Ali", NULL);
        //execlp("./task2", "my name", "Ali", NULL);
        cout << "After execl" << endl;
        exit(status);
    } else {
        wait(&t1);
    }
    return 0;
}
```

## How it works

1. The program starts by declaring the `status` variable to store the child process status.
2. The program forks a child process using `fork()`.
3. In the child process (identified by `t1 == 0`), it uses the `execl()` function to replace its image with the specified external program.
   - The first argument (`/home/lab/Desktop/task2`) is the path to the external program executable.
   - The second argument (`task2`) is the program name or a custom name.
   - The third and subsequent arguments (`my name`, `Ali`) are the command-line arguments to be passed to the external program.
   - The last argument (`NULL`) marks the end of the argument list.
   - Note: You can also use `execlp()` instead of `execl()` to search for the executable in the directories listed in the `PATH` environment variable.
4. If the `execl()` function is successful, the subsequent code after `execl()` is not executed. Therefore, the "After execl" message is not printed.
5. After executing the external program, the child process exits with the `status` value.
6. In the parent process, it waits for the child process to finish using `wait(&t1)`, allowing the parent to synchronize with the child process.
7. The parent process continues its execution, and the program terminates.

## Usage

1. Save the code in a file with a `.cpp` extension, such as `external_program_execution.cpp`.
2. Modify the path (`/home/lab/Desktop/task2`) in the code to the actual path of the external program executable.
3. Compile the code using a C++ compiler: `g++ external_program_execution.cpp -o external_program_execution`.
4. Ensure that the external program (`task2`) exists at the specified path.
5. Run the program: `./external_program_execution`.

## Conclusion

This program demonstrates how to execute an external program from a C++ program using the `execl()` function. By forking a child process and replacing its image with the desired program, it allows seamless integration of external functionalities. This approach enables communication and data exchange between the parent and child processes.

# ---------------------------------------


# Command Line Arguments  (Task-5(b).cpp)

This C++ program demonstrates the usage of command-line arguments. It displays the number of arguments passed and prints each argument individually.

```cpp
#include <iostream>
using namespace std;

int main(int num, char* arg[]) {
    cout << "Number of arguments: " << num << endl;

    for (int i = 0; i < num; i++) {
        cout << "Argument " << i << ": " << arg[i] << endl;
    }

    cout << "Hello Pakistan" << endl;

    return 0;
}
```

## How it works

1. The program defines the `main` function with two parameters: `int num` and `char* arg[]`.
   - `num` represents the number of command-line arguments.
   - `arg` is an array of C-style strings (`char*`) that contains the command-line arguments.
2. The program outputs the number of arguments passed using `cout`.
3. It uses a `for` loop to iterate over the `arg` array and print each argument individually.
   - The loop starts from `i = 0` and continues until `i < num`.
   - Inside the loop, it prints the argument number (`i`) and the corresponding argument value (`arg[i]`).
4. After printing all the arguments, the program displays the "Hello Pakistan" message.
5. Finally, the program returns 0 to indicate successful execution.

## Usage

1. Save the code in a file with a `.cpp` extension, such as `command_line_arguments.cpp`.
2. Compile the code using a C++ compiler: `g++ command_line_arguments.cpp -o command_line_arguments`.
3. Run the program with command-line arguments: `./command_line_arguments arg1 arg2 arg3 ...`.
   - Replace `arg1`, `arg2`, `arg3`, and so on with the desired command-line arguments.
   - You can pass any number of arguments.
   - The program will display the number of arguments and print each argument on a separate line.

## Conclusion

This program showcases the usage of command-line arguments in C++. By accessing the `num` and `arg` parameters in the `main` function, the program can handle and process the arguments passed during execution. This allows for dynamic input and customization of program behavior based on user-provided values.
