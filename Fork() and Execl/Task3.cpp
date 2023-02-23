#include <iostream>
#include <unistd.h>
#include <bits/stdc++.h>  
#include <sys/wait.h>
using namespace std;



int main(){
int a, b, max_num,hcf;  
  int status;
    a=42;
    b=63;
    
pid_t t1= fork();
	if(t1==0){

  
    
    max_num= max(a,b); 
          
    while (1)    
    {  
        if(max_num % a == 0 && max_num % b == 0)  
        {  
            cout << " The LCM of " <<a << " and " << b << " is " << max_num << endl;  
                break;  
        }  
        ++max_num; // increment by 1 on each iteration  
    }  
    
	}
	else{

wait(&status);
    for(int i = 1; i <= a || i <= b; i++)
    {
        if(a % i == 0 && b % i == 0)
            hcf = i;
    }

    cout<<"HCF of "<<a<<" and "<<b<<" is "<<hcf;


	}
	return 0;
}