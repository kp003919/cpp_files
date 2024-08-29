#include<stdio.h>
#include<iostream>
int fact(int n)
{
	if (n <0 )
	{ 
		return -1;
	}
	else if(n<=1)
	{
           return 1;
	}
	else
	return n*fact(n-1);
	
}
int main()
{
	count << "Hello worl" << endl;
	for (auto i =0; i<20; i++)
		cout<<fact(i)<<endl;
	return 0;
}
