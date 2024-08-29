
#include<iostream>
#include<stdio.h>
#include<list>
#include<array>
#include<string>
#include<vector>
#include<set>
#include<map>

using namespace std;

 
int main()
{   

    // arrays 
    int  n = 10;

    int a[10];
    vector<int> v = {1,2,3,4}; 
    list<int> l = {1,2,3,4,5};
    set<int> s = {1,2,3,5};
    map<int,int> m;

    array<int,10> b;
    int i; 
    for (i =0; i<n; i++)
        a[i] = i; 

    for(i= 0; i<n; i++)
    {
         cout<<a[i]<<endl;
         b[i] = a[i];
    }


    cout<<"Vetors"<<endl;
    // vectors 
    v.insert(v.begin(),9);  // insert number 9 to the begin of the vector 
    v.insert(v.end(),99);   // insert number 99 to the end of the vector
    v.insert(v.end()-1,77);   // insert number 77 to the position before end 
    v[3] = 44;  // change item 4 with 44. 
    // pritning vectors 
    for (i =0; i<v.size(); i++)
        cout<<v[i]<<endl;
    
    for(auto it = v.begin(); it != v.end(); it++)
      cout<<*it<<endl;
     
    //v.erase(v.end()); // remove the last element 
    //v.erase(v.begin()); // remove the last element 
    
    for(auto it = v.begin(); it != v.end(); it++)
      cout<<*it<<endl;

    

    cout<<"Maps"<<endl;
    // maps 
    m.insert(pair<int,int>(1,2));
    m.insert(pair<int,int>(4,6));
    m.insert(pair<int,int>(7,20));
    for( auto it = m.begin(); it != m.end(); it++)
        cout<<it->first<<" : "<<it->second<<endl;
    
     // lists 
     cout<<"Lists"<<endl;
     for(i = 0; i<n; i++)
       l.push_back(i*2);

    l.insert(l.end(),11);
    l.insert(l.begin(),91);

    auto start = l.begin();
    start = next(start,2); // move iterator to the index 2 and then insert a number 
    l.insert(start,44);    
    
    cout<<"List "<<endl;
    for(auto item:l)
        cout<<item<<endl;
    
     cout<<"Reverse list "<<endl;
    for( auto it = l.rbegin(); it != l.rend(); ++it)
        cout<<*it<<endl;

    // SETS 
    cout<<"Sets"<<endl;
    s.insert(s.end(),38);

    for(auto item:s)
        cout<<item<<endl;
     cout<<"Reverse set "<<endl;
    for( auto it = s.rbegin(); it != s.rend(); it++)
        cout<<*it<<endl;


    return 0; 
}