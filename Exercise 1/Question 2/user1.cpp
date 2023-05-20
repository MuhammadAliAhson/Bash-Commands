#include <iostream>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <wait.h>

using namespace std;

int main(int narg, char **arg)
{
    string sentence;

    int cd = (arg[1][0] - '0');
    if (cd == 0)
    {
    // creating shared memory
        key_t marker = ftok("Chat box", 65);
        int memory = shmget(marker, 1024, 0666 | IPC_CREAT);
        char *text = (char *)shmat(memory, NULL, 0);
        // adding text in opened memory
        text += strlen(text);
        // taking input from memory
        cout << "enter input for person 1" << endl;
        getline(cin, sentence);
        if (sentence == "exit"){
            exit(0);
           
            }
        string a = "user1: " + sentence + "\n";
        strcpy(text, a.c_str());
        shmdt(text);
    }
    else
    {
        cout << "-------------------------------->>>>>>READING FROM USER 3" << endl;
        key_t marker = ftok("Chat box", 65);
        int memory = shmget(marker, 1024, 0);
        char *text = (char *)shmat(memory, NULL, 0);
        cout<<text;
        shmdt(text);
        // shmctl(memory, IPC_RMID, NULL);
    }
    pid_t pid = fork();
    if (pid == 0)
    {
        execlp("./run", "run", NULL);
        exit(0);
    }
    else
        wait(NULL);
}
