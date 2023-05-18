#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

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
mkfifo("pipe4",0660);
if	(mkfifo("pipe4",0660)){

cout<<"Value received from pipe:  "<<endl;

	char buff[30] = "/0";

	int rd_mode =open("pipe4",O_CREAT|O_RDWR);

	read(rd_mode,buff,30);
cout<<"Value received from pipe:  " <<buff<<endl;
	for(int i=0;i<30;i++){

    if(isdigit(buff[i])){
    avg = int(buff[i]) - 48;
    avg = avg*10;
    int demmy=0;
    demmy=int(buff[i+1]) - 48;
     avg += demmy;
i++;
}
cout<< "The number of the students are : " <<avg<<endl;
total +=avg;
count++;
avg=0;
}
cout<< "The Average of the students is : " <<float(total/count)<<endl;




}
//	close(rd_mode);

return 0;
}
