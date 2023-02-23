#include <iostream>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
using namespace std;
int i = 0;
int main()
{

cout<<i<<endl;
fork();
i = i+1;
//cout<<i<<endl;
if ( fork() || fork() || fork() )
{
 i = i+1;
 fork();

 cout<<i<<endl;
}

cout<<"*"<<endl;

return 0;



}


