#include <iostream>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/types.h>
using namespace std;
int main()
{
int input;

pid_t pid = fork();

if (pid >= 0)
{
	if (pid == 0)
		{
			int id = getpid();
			cout<< "child process id : " <<id<<endl;
			//child process

			int id2 = getppid();
			cout<<"parent id : "<<id2<<endl;
			//child process
			int g=111;
			exit(g);
		}

	else
		{
			int id = getpid();
			cout<<"parent id : "<<id<<endl;
			wait(&input); //stop here and check child process 
			cout<<"Value is "<<WEXITSTATUS(input)<<endl;
			cout<<"after waiting....."<<endl;


		}




}




}

