# Chatbox System using Named Pipes

This program is a simple chatbox system implemented in C++ using named pipes (FIFOs) for interprocess communication. It allows users to send and receive messages through the chatbox.

## Prerequisites

- C++ compiler
- Linux operating system (supporting named pipes)

## Setup

1. Compile the program using the C++ compiler. For example, using g++:

```bash
g++ user1.cpp -o user1
```

2. Run the program:

```bash
./user1
```

## Usage

1. Upon running the program, you will be greeted with a welcome message.

2. You will be prompted to enter a command:
   - Enter `1` to write and send a message.
   - Enter `2` to read incoming messages.

3. If you enter `1`:
   - Enter the message you want to send.
   - The message will be written to the named pipes `pipe1` and `pipe2`.
   - If you enter "Bye", the program will exit.
   - You will be prompted to enter a new command.

4. If you enter `2`:
   - The program will read the incoming messages from `pipe1` and `pipe2`.
   - The received messages will be displayed on the console.
   - If the received message is "Bye", the program will exit.
   - You will be prompted to enter a new command.

5. The program will continue running until the user chooses to exit.

## Notes

- The program uses three named pipes (`pipe1`, `pipe2`, `pipe3`) for communication between processes.
- Each process can write to and read from `pipe1` and `pipe2`.
- The program ensures continuous communication by using a loop that prompts the user for a command.
- Error handling and edge cases have not been extensively considered in this simplified implementation.

**Important**: Please make sure to handle the synchronization and cleanup of the named pipes appropriately to avoid any issues with file descriptors and resources.
