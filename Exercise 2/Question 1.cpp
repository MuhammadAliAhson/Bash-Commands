#include<iostream>
#include<pthread.h>
#include <unistd.h>
#include<wait.h>

using namespace std;

//initializing data structure for ticket and running threads
int tnum;
int* ticket;
pthread_t* tids;
bool* running;
int counter=0;


// function to calculate the max in array
int maxval()
{
    int ret =ticket[0];
        for(int i=0;i<tnum;i++)
         if (ticket[i]>ret)
            ret =ticket[i];
    return ret;
}

class backerylock
{
    public:
    // lock function that will give the lock privilige to thread
    void lock(int i)
    {

        running[i]=1;
     ticket[i]=maxval()+1;
        running[i]=0;

        for(int j=0;j<tnum;j++)
        {
            while(running[j]!=0)
            {

            }
                while(ticket[j]!=0 && (ticket[j] < ticket[i] ||  (ticket[j] == ticket[i] && j < i)))
                {

                }

        }
        running[i]=1;
        cout<<"LOCK ACQUIRED by "<<i<<endl;
    }
    // unlock function will take lock priviliges from the thread and remove it from array
    void unlock()
    {
        int index=0;
        for(int i=0;i<tnum;i++){
        if(running[i]==1)
        index=i;
        }
        running[index]=0;
     ticket[index]=0;
     cout<<"LOCK RELEASED by "<<index<<endl;
    }
};
// thread function accessing the critical section and using lock and unlock
backerylock block;


void* functional(void* arg)
{

    int* p=(int*)arg;
    int num=*p;
    cout<<"thread : "<<num<<" with id "<<pthread_self()<<endl;
    tids[num]=pthread_self();
    block.lock(num);
        sleep(3);
    counter++;
    cout<<"critical section increasing shared resource "<<counter<<endl;

    block.unlock();
pthread_exit(0);
}

int main()
{
    cout<<"how many threads do you want to create"<<endl;
    cin>>tnum;
 ticket=new int[tnum];
    running=new bool[tnum];
    tids=new pthread_t[tnum];
        for(int i=0;i<tnum;i++)
 ticket[i]=running[i]=0;
    pthread_t id[tnum];

    for(int i=0;i<tnum;++i)
    {
         int* send=new int;
         *send=i;
        pthread_create(&id[i],NULL,functional,(void*)send);
       //sleep(1);
    }
    for(int i=0;i<tnum;i++)
    pthread_join(id[i],NULL);

return 0;
}
