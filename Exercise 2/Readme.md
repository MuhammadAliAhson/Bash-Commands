# Backery Lock (Question 1)

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


# Bridge Traffic Simulation (Question 2)

This code simulates the traffic on a bridge, where vehicles of different types arrive and depart based on certain conditions. The simulation uses multi-threading and synchronization mechanisms.

## Step-by-Step Explanation

1. The code includes the necessary libraries: `iostream`, `unistd.h`, `pthread.h`, `time.h`, and `semaphore.h`.

2. The code defines the following variables:
   - `pthread_mutex_t mutex1`: A mutex lock for thread synchronization.
   - `sem_t csem`: A semaphore to control the number of cars on the bridge.
   - `sem_t bsem`: A semaphore to control the number of buses on the bridge.
   - `struct carInfo`: A structure to hold information about a vehicle, including its direction and vehicle type.
   - `Queue`: A template class representing a queue data structure.

3. The code implements a queue data structure using a linked list for managing vehicles and thread IDs.

4. The code defines global variables to track the number of buses, cars, buses with cars, and their counts in different directions.

5. The `ExitTheBridge` function is called when a vehicle exits the bridge. It dequeues the next vehicle from the queue, updates the counts, and releases the locks if required.

6. The `ArriveAtBridge` function is called when a vehicle arrives at the bridge. It checks the conditions based on the direction and vehicle type, updates the counts, and prints the information about the vehicle on the bridge.

7. The `vehicle` thread function is responsible for simulating the behavior of each vehicle. It receives the direction and vehicle type as arguments, enqueues the thread ID, waits for a random amount of time, calls `ArriveAtBridge`, waits again, and finally exits the thread.

8. In the `main` function, the necessary mutex and semaphore variables are initialized.

9. The program prompts the user to enter the duration (in minutes) for which the simulation should run.

10. A loop is initiated to simulate the traffic within the specified duration. Random vehicle types and directions are generated, and a new vehicle thread is created for each iteration. The simulation runs for the specified duration.

11. After the simulation ends, the program waits for all vehicle threads to complete.

12. Finally, the program exits with a status of 0.

## Usage

1. Compile the code using a C++ compiler.
2. Run the executable.
3. Enter the duration (in minutes) for which you want to run the simulation.
4. Observe the simulation output, which includes information about vehicles arriving and exiting the bridge.
5. The program will terminate automatically after the specified duration.

Note: This code is a simplified simulation and may not accurately represent real-world traffic scenarios. It serves as an example to demonstrate the usage of threads and synchronization mechanisms in a traffic simulation context.




















## Note
In Every folder the detailed README is given for your assistence. If you get any problem then please let me know

Copyright Notice:
This script is created by Muhammad Ali Ahson. It is provided as-is without any warranty. If you find this script useful, please show your appreciation by including an acknowledgment or attribution when using or distributing this code.

Your support and recognition are greatly appreciated!

Author: Muhammad Ali Ahson
