#include <iostream>

using namespace std;

// Define a simple Number class
class Number
{

public:
  int n;
  // default const 
  Number()
  {
      n = 0; 
  }
  // parametrised cost 
  Number(int set_n)
  {
    n = set_n;
  }
  
  // Overload the + operator, the function header must follow a particular 
  // format, and the exact format depends on the operator.  The left operand 
  // of the + operator will become the "this" object for which this member
  // function is being called, and the right operand of the + operator will
  // be provided as an argument to the function.  The function is expected 
  // to return a Number object. 
  Number operator+(const Number &numA)
  {
    // create and return a new Number object with it's n member variable 
    // initialized to the sum of the two operand object's n member variables
    return Number(this->n + numA.n);

    // We *could* provide a definition of the overloaded operator that does not
    // make sense, such as always returning a Number object with an n member 
    // variable value of 0.  But we should not do this as it will make our 
    // program more difficult to understand, we should try to provide 
    // definitions that make sense given the operator's standard purpose.
    //
    // return Number(0);
  }
  
  // Overload the equality operator ==, which is expected to return a bool 
  // (given what the equality operator does, this makes sense).  Again the 
  // left operand of the equality operator will be the "this" object for which
  // this member function is called, and the right operand of the equality 
  // operator will be provided as an argument to this function.
  bool operator==(const Number &numA)
  {
    // return true if the n member variable's of the two objets are equal, 
    // and false otherwise
    if (this->n == numA.n) return true;
    else return false;
  }

  friend Number operator*(const Number &org, const Number &numA); // friend function to do * 
  friend Number operator-(const Number &org, const Number &numA);
  
};

 Number operator*(const Number &org,const Number &numA)
  {
     Number newNum; 
     newNum.n = org.n * numA.n;
     return newNum;
  }

  Number operator-(const Number &org,const Number &numA)
  {
     Number newNum; 
     newNum.n = org.n - numA.n;
     return newNum;
  }


int main()
{
  // Create two number objects
  Number a(5);
  Number b(10);
  
  // if we didn't overload the + operator, this would cause an error, but 
  // instead our member function runs and c is set to the return value 
  // of that function ('a' becomes the 'this object', and 'b' becomes the 

  cout << "a.n: " << a.n << endl;
  cout << "b.n: " << b.n << endl;
  // parameter object).
  Number c = a + b;
  
  // output the result, we will get c.n: 15
  cout << "c.n: (a+b) " << c.n << endl;
  
  // test the overloaded equality operator (case where two objects aren't equal)
  if (a == c) cout << "a == c" << endl;
  else cout << "a != c" << endl;
  
  // test the overloaded equality operator (case where two objects are equal)
  Number d(15);
  if (c == d) cout << "c == d" << endl;
  else cout << "c != d" << endl;
  
  Number e = a*c;
  cout << "e.n(a*c): " << e.n << endl;

  Number f = a*b*c;
  cout << "f.n(a*b*c): " << f.n << endl;

   Number t = c-b-a;
   cout << "t.n(c-b-a): " << t.n << endl;
  // unique_ptr
  //shared_ptr
  return 0;
}