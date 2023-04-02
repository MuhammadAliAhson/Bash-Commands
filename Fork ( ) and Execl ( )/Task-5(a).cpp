#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
using namespace std;



int main(){
int status=0;
pid_t t1= fork();
	if(t1==0){

	execl("/home/lab/Desktop/task2","task2","my name","Ali" ,NULL);
	//execlp("./task2","my name","Ali" ,NULL);
	
	cout<<"After Excel"<<endl;
	exit(status);

	}
	else{

	wait(&t1);
	}
	return 0;
}