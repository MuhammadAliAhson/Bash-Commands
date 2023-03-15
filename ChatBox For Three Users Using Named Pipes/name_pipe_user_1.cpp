#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>
using namespace std;



int main(){
cout <<"Welcome to the fast chatbox system :  "<<endl<<endl;

int b =0;
int v =	mkfifo("pipe1",0666);
int v1 =mkfifo("pipe2",0666);
int v2 =mkfifo("pipe3",0666);
	while(1){

	a:

	cout <<"Enter 1 for write the message and Enter 2 for read the incoming texts   "<<endl<<endl;

	cin>>b;




	if(b == 1){

	cout<<"wewesdasfsdf"<<endl;



	string s;
	getline(cin,s);

	int wr_mode = open("pipe1",O_WRONLY);
	int wr_mode1 = open("pipe2",O_WRONLY);

	write(wr_mode, s.c_str(),s.length());
	write(wr_mode1, s.c_str(),s.length());
	cout << "writing successfull!!"<<endl;


	close(wr_mode);

	if(s.compare("Bye")){

	break;

	goto b;
	}
	else{

	goto a;

	}
}
	else if(b == 2){

	char buff[30] = "/0";

	int rd_mode =open("pipe1",O_RDONLY);
	int rd_mode1 = open("pipe2",O_RDONLY);
	read(rd_mode,buff,30);


	cout<<"Value received from pipe:  " <<buff<<endl;
	read(rd_mode1,buff,30);
cout<<"Value received from pipe:  " <<buff<<endl;



	close(rd_mode);
 if(buff[0] == 'B' && buff[0] == 'y' && buff[2] == 'e'){

	break;

	goto b;
	}
	else{

	goto a;

	}

 }


	}





b:
return 0;
}
