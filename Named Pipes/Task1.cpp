#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>
#include <cctype>
#include <cstring>
#include <string>
using namespace std;



int main(){
cout <<"Welcome to the student Average Calculator System :  "<<endl<<endl;

string b;
int avg=0;
int count=0;
int total=0;
mkfifo("pipe4",0640);
if(mkfifo("pipe4",0640)){
int wr_mode;


	string s;
	getline(cin,s);

	wr_mode = open("pipe4",O_RDWR);
	write(wr_mode, s.c_str(),s.length());
	cout << "writing successfull!!"<<endl;


//close(wr_mode);

}
return 0;
}
