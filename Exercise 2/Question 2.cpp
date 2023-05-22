#include<iostream>
#include<unistd.h>
#include<pthread.h>
#include<time.h>
#include<semaphore.h>
using namespace std;


pthread_mutex_t mutex1 ;
sem_t csem;
sem_t bsem;

struct carInfo{
int direction;
int vtype;
};

// QUEUE implementation 
template<class D>
struct Node {
    D qval;
    Node* next;

};

template<class F>
class Queue {
   

public:
 Node<F>* start;
    Queue()
    {
        start = NULL;
    }
    void enque(F val)
    {
        Node<F>* temp = new Node<F>;
        temp->qval = val;
        temp->next = NULL;

        if (start == NULL)
        {
            start = temp;
        }
        else
        {
            Node<F>* p = start;
            while (p->next != NULL)
            {
                p = p->next;
            }
            p->next = temp;

        }
    }
    F Deque()
    {
        F* ret = new F;
        Node<F>* p = start;
        if (start != NULL){
            start = start->next;
            
        *ret= p->qval;
        }
        return *ret;
    }
    bool isempty()
    {
        if (start == NULL)
        {
            return 1;
        }
        else
            return 0;
    }

};
//<<<<<<<---------------end of queue implementation ----------------->>>>>>>
Queue<pthread_t> que;
Queue<int> wait;
Queue<int> qd1;
Queue<int> qd2;

int buses=0;
int cars=0;
int bus_car=0;
int buses2=0;
int cars2=0;


void ExitTheBridge(int direction)
{

int pd= wait.Deque();

if(pd==0 && (cars2>0 || buses2>0)){
  pthread_mutex_lock(&mutex1);
         cars2=0;
         buses2=0;
  cout<<"exiting"<<endl;
   pthread_mutex_unlock(&mutex1);
}
 else if(buses>0 && cars>=4)
  {
    pthread_mutex_lock(&mutex1);
  cars=0;
  cout<<"cars exiting the bridge"<<endl;
  pthread_mutex_unlock(&mutex1);
  }
 else if (buses > 0 && buses+cars>2) {
    pthread_mutex_lock(&mutex1);
        buses=buses2=0;
        bus_car -= 2;
        cars=cars2=0;
        
        cout<<endl;
     cout<<"exiting"<<bus_car<<endl;
     pthread_mutex_unlock(&mutex1);
    } 
     if(cars>=4) {
        cars=cars2=0;
        cout<<endl;
     cout<<"exiting"<<cars<<endl;
    }
if(pd==1 && (cars>0|| buses>0)){
    pthread_mutex_lock(&mutex1);
    cars=0;
         buses=0;
  cout<<"exiting"<<endl;
  pthread_mutex_unlock(&mutex1);
}
 else if (buses2 > 0 && buses2+cars2>2) {
    pthread_mutex_lock(&mutex1);
        buses=buses2=0;
        cars=cars2=0;
        
        cout<<endl;
     cout<<"exiting"<<buses2+cars2<<endl;
      pthread_mutex_unlock(&mutex1);
    
    } 
    else if(cars2>=4) {
        pthread_mutex_lock(&mutex1);
        cars=cars2=0;
       
        cout<<endl;
     cout<<"exiting"<<cars2<<endl;
      pthread_mutex_unlock(&mutex1);
    }

}


void ArriveAtBridge(int direction, int vehicleType)
{

if(direction==0){

  if(vehicleType==0)
  {
    if(cars<=4)
    {
        pthread_mutex_lock(&mutex1);
        cars++;
         cout<<"car on bridge "<<cars<<" direction "<<direction<<endl;
         pthread_mutex_unlock(&mutex1);
    }
 
  }
  else
  {    
    if(buses<=1 && cars==2 && cars+buses<=3)
    {
         pthread_mutex_lock(&mutex1);
         buses++;
          bus_car=bus_car+2;
           cout<<"car and bus on bridge "<<bus_car<<" direction "<<direction<<endl;
            pthread_mutex_unlock(&mutex1);
    }

    

  }
}
else
{
 if(vehicleType==0)
  {

    if(cars2<=4)
    {
        pthread_mutex_lock(&mutex1);
        cars2++;
         cout<<"car on bridge "<<cars2<<" direction "<<direction<<endl;
          pthread_mutex_unlock(&mutex1);
    }

  }
  else
  {    
    if(buses2<=1 && cars2==2 && cars2+buses2<=3)
    {
         pthread_mutex_lock(&mutex1);
         buses2++;
           cout<<"car and bus on bridge "<<cars2+buses2<<" direction "<<direction<<endl;
            pthread_mutex_unlock(&mutex1);
    }

    
   
  }

}
}


void* vehicle(void* arg)
{


int* p=(int*)arg;
que.enque(pthread_self());
wait.enque(p[0]);
sleep(1);

ArriveAtBridge(p[0],p[1]);
ExitTheBridge(p[1]);
sleep(1);
pthread_exit(0);
}



int main()
{

pthread_mutex_init (&mutex1 ,NULL);
sem_init(&csem, 0, 4);
sem_init(&bsem, 0, 1);


    srand(time(0));
int mint=0;
long int actime=0;
// ask for time for which the program should run
cout<<"how much minutes do you want to run the program"<<endl;
cin>>mint;

int sec=mint*60;
actime=time(0);
long int btime=actime;

int count=0;
int move=0;
while(actime<btime+sec)
{
    int veh=(rand()%2);
    int dir=(rand()%2);
    int arr[2];
    arr[0]=dir;
    arr[1]=veh;
    pthread_t* id=new pthread_t;
    pthread_create(id,NULL,vehicle,arr);
sleep(2);
move++;
actime=time(0);

}
cout<<"hello world 2 "<<endl;
sleep(3);
for(int i=0;i<move;i++)
{
    pthread_join(que.Deque(),NULL);
}


return 0;
}
