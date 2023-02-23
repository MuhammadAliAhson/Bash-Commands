#include <iostream>
#include <unistd.h>
#include <bits/stdc++.h>  
#include <sys/wait.h>
#include <algorithm>

using namespace std;



int main(){
int a1, b, c,max_num;  
  int status;
    
    
pid_t t1= fork();
	if(t1==0){
	
	
	pid_t t2= fork();
	
		if(t2==0){
		
		
		pid_t t3= fork();
	
		if(t3==0){
		
		cout<<"Please Enter the numbers  :"<<endl;
		cin>>a1;
		cin>>b;
		cin>>c;
		max_num= max(a1,b,c);
		exit(max_num);
		
		}
		else if(t3>0){
		wait(&status);
		int a=WEXITSTATUS(status);
		a= a*a;
		exit(a);
		}
		
		
		
		}
		else if(t2>0){
		wait(&status);
		int a=WEXITSTATUS(status);
		if(a%2==0){
		cout<<"It's Even"<<endl;
		exit(a);
		}
	}
   
	else if(t1>0) {
	wait(&status);
	int a=WEXITSTATUS(status);
	cout<<"Multiple is :";
	for(int i=a;i<50;i=i*2){
	cout<<"   "<<i<<"   ";

	}

	}
	}
	return 0;
}
