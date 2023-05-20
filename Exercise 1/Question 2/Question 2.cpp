#include <iostream>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <wait.h>

using namespace std;

int main()
{
    srand(time(0));

    pid_t pi = fork();
    int a = rand() % 3;
    if (pi == 0)
    {
    // giving access of read and write to different user
        int arg = rand() % 2;
        cout << arg << endl;
        if (a == 0)
        {
        // calling user 1 
            execlp("./user1", "user1", to_string(arg).c_str(), NULL);
        }
        else if (a == 1)
        {
        // calling user 2
            wait(NULL);
            execlp("./user2", "user2", to_string(arg).c_str(), NULL);
        }
        else
        {
        //callling user 3
            wait(NULL);
            execlp("./user3", "user3", to_string(arg).c_str(), NULL);
        }
        exit(0);
    }
    else
    {
        wait(NULL);
    }
}

/*
A deadlock may occur when one program attempts to read from shared memory while another program is writing to it.
This is because both programs will need to wait for each other to finish their respective tasks before they can proceed, potentially causing a deadlock situation
this will solved my stopping the child to make more processes or using some statements that will stop reading before writing.
*/
