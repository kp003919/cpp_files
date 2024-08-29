#include<iostream>
#include<fstream>
#include<string>
using namespace std; 

class A {
  protected: 
  int a; 
  public:
   A(){
    cout<<"A is called "<<endl;
    a = 99; 
   }
   void printA()
   {
        cout<<" A "<<endl;
   }
//friend operator <<();
};

class B: public A 
{  
    public:
    B()
    {
        cout<<"B is called "<<endl;
    }
    void printA()
   {
        cout<<" B "<<endl;
   }

};

void print()
{

}
class C: public B {
    public:
    C()
    {
        cout<<"C is called "<<endl;
    }

    void printA()
   {
        cout<<"C"<<endl;
   }


};

int main()
{

    A a; // 
    B b; 
    C c; 
    c.printA();
    b.printA();
    a.printA();
    
    // using file in c++
    fstream file; 
    cout<<"1- Writing to file "<<endl;
    file.open("myfileName.txt",ios::out); // open file for writing 
    if (file.is_open())
    {  
        for(int i=0; i<10; i++)
          file<<"Line:"+to_string(i)+"\n";
    
        file.close();
    }
    
    cout<<"2- Appending text  to file "<<endl;
    file.open("myfileName.txt",ios::app); // open file for appending 
    if (file.is_open())
    {  
        for(int i=10; i<20; i++)
          file<<"Line:"+to_string(i)+"\n";
    
        file.close();
    }
    
    cout<<"3- Reading from file "<<endl;
    file.open("myfileName.txt",ios::in); // open file for reading
    if (file.is_open())
    {  
       string line; 
       while (getline(file,line))
       {
          cout<<line<<endl;
       }
    
        file.close();
    }


    return 0; 
}