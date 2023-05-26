# Bank Account Management System (Task10.cpp)

This program is a simple bank account management system implemented in C++. It simulates concurrent withdrawals and deposits to a shared bank account using threads and semaphores.

## Prerequisites

- C++ compiler
- pthread library (POSIX threads)

## Installation

1. Clone the repository or download the source code files.
2. Open a terminal and navigate to the directory where the code is located.

## Usage

1. Compile the code using a C++ compiler. For example, using g++:
   ```
   g++ -lpthread task10.cpp -o bank_account_system 
   ```
   The `-lpthread` flag is required to link the pthread library.
2. Run the executable:
   ```
   ./bank_account_system
   ```
3. The program will simulate concurrent withdrawals and deposits to a shared bank account.
4. The initial account balance is set to 0.
5. The program creates two withdrawal threads and two deposit threads.
6. The withdrawal threads will attempt to withdraw 10 units from the account, and the deposit threads will deposit 11 units.
7. If the account balance is insufficient for a withdrawal, the program will output the following message and wait for a deposit:
   ```
   Insufficient balance for withdrawal, waiting for deposit.
   ```
8. If a withdrawal is successful, the program will output the following message along with the current balance:
   ```
   Withdrawal successful. Current balance: <balance>
   ```
9. If a deposit is successful, the program will output the following message along with the current balance:
   ```
   Deposit successful. Current balance: <balance>
   ```
10. The withdrawal threads use a semaphore (`withdrawal_sem`) to signal when a deposit is made.
11. The deposit threads use a semaphore (`deposit_sem`) to signal when a withdrawal can be made.
12. The program will run indefinitely until interrupted.
13. To stop the program, press `Ctrl + C`.

Note: This code snippet includes a basic implementation of the bank account management system. It may not cover all edge cases and error handling scenarios. Additional enhancements and error checking can be added as per requirements.

---

# =============================================================

# Student Grade Point Average Calculation  (Task9.cpp)

This program calculates the Grade Point Average (GPA) for a student based on the marks obtained in different subjects. The program takes input from the user, calculates the GPA, and writes the results to a file.

## Prerequisites

- C++ compiler

## Installation

1. Clone the repository or download the source code files.
2. Open a terminal and navigate to the directory where the code is located.

## Usage

1. Compile the code using a C++ compiler. For example, using g++:
   ```
   g++ main.cpp -o student_gpa_calculator -lpthread
   ```
   The `-lpthread` flag is required to link the pthread library.
2. Run the executable:
   ```
   ./student_gpa_calculator
   ```
3. The program will prompt you to enter the student's name.
4. Enter the marks obtained by the student in the following subjects:
   - Sports Analysis
   - Statistics
   - Entrepreneurship
   - Crowd Funding
   - Social Marketing
5. The program will create a thread (`Take_Input`) to collect the input marks from the user.
6. The program will display the entered marks.
7. The program will create another thread (`calculate_points`) to calculate the Grade Points based on the entered marks.
8. The program will display the calculated Grade Points.
9. The program will calculate the GPA based on the Grade Points and write the results to a file named "21I-2477_grade-points.txt".
10. The file will contain the student's name, the Grade Points obtained in each subject, and the calculated GPA.
11. The program will terminate.

Note: This code snippet assumes a basic implementation and does not include extensive error handling or input validation. Additional enhancements can be made as per requirements.

---
# -================================================

# Student Grade Point Average Calculation

This program calculates the Grade Point Average (GPA) for a student based on the marks obtained in different subjects. The program takes input from the user, calculates the GPA, and writes the results to a file.

## Prerequisites

- C++ compiler

## Installation

1. Clone the repository or download the source code files.
2. Open a terminal and navigate to the directory where the code is located.

## Usage

1. Compile the code using a C++ compiler. For example, using g++:
   ```
   g++ main.cpp -o student_gpa_calculator -lpthread
   ```
   The `-lpthread` flag is required to link the pthread library.
2. Run the executable:
   ```
   ./student_gpa_calculator
   ```
3. The program will prompt you to enter the student's name.
4. Enter the marks obtained by the student in the following subjects:
   - Sports Analysis
   - Statistics
   - Entrepreneurship
   - Crowd Funding
   - Social Marketing
5. The program will create a thread (`Take_Input`) to collect the input marks from the user.
6. The program will display the entered marks.
7. The program will create another thread (`calculate_points`) to calculate the Grade Points based on the entered marks.
8. The program will display the calculated Grade Points.
9. The program will calculate the GPA based on the Grade Points and write the results to a file named "21I-2477_grade-points.txt".
10. The file will contain the student's name, the Grade Points obtained in each subject, and the calculated GPA.
11. The program will terminate.

Note: This code snippet assumes a basic implementation and does not include extensive error handling or input validation. Additional enhancements can be made as per requirements.

--
© Muhammad Ali Ahson

If you find this code useful, please consider starring this repository to show your appreciation.
