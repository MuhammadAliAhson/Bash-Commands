# Backery Lock

This code implements the Backery Lock algorithm using pthreads in C++. The Backery Lock algorithm provides a mutual exclusion mechanism for threads accessing a critical section.

## Step-by-Step Explanation

1. The code begins by including the necessary libraries: `iostream`, `pthread.h`, `unistd.h`, and `wait.h`.

2. The code defines the required global variables:
   - `tnum`: An integer representing the number of threads.
   - `ticket`: An integer array storing the ticket numbers of each thread.
   - `tids`: An array of pthread_t objects to store thread IDs.
   - `running`: A boolean array indicating whether a thread is running.
   - `counter`: An integer to simulate a shared resource accessed within the critical section.

3. The `maxval()` function is defined to calculate the maximum value in the `ticket` array.

4. The `backerylock` class is declared, which contains the `lock()` and `unlock()` functions to acquire and release the lock, respectively.

5. The `functional()` function is the entry point for the threads. It takes an argument `arg` representing the thread number. Within this function, each thread calls `lock()` to acquire the lock, simulates a critical section by incrementing the `counter`, and then calls `unlock()` to release the lock.

6. The `main()` function is the entry point of the program. It prompts the user to enter the number of threads (`tnum`), initializes the `ticket` and `running` arrays, and creates `tnum` threads using `pthread_create()`. Each thread calls the `functional()` function with a unique thread number. The main thread then waits for all the threads to complete using `pthread_join()`.

7. Finally, the program exits with a status of 0.

## Usage
1. Compile the code using a C++ compiler.
2. Run the executable.
3. Enter the desired number of threads.
4. Observe the execution of the threads, their IDs, and the output messages indicating the acquisition and release of locks, as well as the incrementing of the shared resource within the critical section.

Note: This code demonstrates the Backery Lock algorithm and its usage in a multithreaded environment.























## Note
In Every folder the detailed README is given for your assistence. If you get any problem then please let me know

Copyright Notice:
This script is created by Muhammad Ali Ahson. It is provided as-is without any warranty. If you find this script useful, please show your appreciation by including an acknowledgment or attribution when using or distributing this code.

Your support and recognition are greatly appreciated!

Author: Muhammad Ali Ahson
