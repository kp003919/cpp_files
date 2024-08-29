#include<iostream>
#include<thread>

using namespace std;

void task1()
{  
    for(auto i=0; i<100; i++)
        cout<<'1'<<endl;
}

void task2()
{  
    for(auto i=0; i<100; i++)
        cout<<'2'<<endl;
}

int main()
{
    thread worker(task1); 
    thread worker2(task2); 

    worker.join();   
     
    cin.get();
    return 0;
}