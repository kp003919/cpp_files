#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main()
{ 
    
    // using file in c++
    fstream file;  // define a new file 

    cout<<"1- Writing to file "<<endl;
    file.open("myfileName.txt",ios::out); // open file for writing 
    if (file.is_open()) // check if file is opened 
    {  
        for(int i=0; i<10; i++)
          file<<"Line:"+to_string(i)+"\n";
    
        file.close();
    }
    
    cout<<"2- Appending text to file "<<endl;
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