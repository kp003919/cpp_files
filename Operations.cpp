#include<iostream>
using namespace std; 

int fact(int n)
{
    if (n <= 1)
        return 1;
    else
        return n*fact(n-1);
}

int power(int a, int b)
{
    if (b == 0)
       return a; 
    else
      return a*power(a,b-1);
}
int fib(int n)
{   
    if (n <=2 )
      return n; 
    else
      return fib(n-1)+fib(n-2);
}
int main()
{
    
    for(auto i =0; i<50; i++)
    {
        //cout<<" fact of "<<i<< " is: "<< fact(i)<<endl;
        //cout<<" Power of ("<<i<< ","<<3<<") is: "<< fact(i)<<endl;
        cout<<i<<" : "<<fib(i)<<endl;
    }
       
       
    return 0; 
}