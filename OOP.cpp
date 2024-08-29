#include <iostream>
using namespace std;

// Base class
class Animal {
  protected:
    int counter; 
  public:
    virtual void animalSound() = 0 ; // a pure virtual method (--> abstract class, has at least one pure function)
    virtual void id()= 0;
    friend int getId(Animal *);
    friend void operator+=(Animal *name);
    
};

// Derived class
class Pig : public Animal {
  public:
    void animalSound() {
      cout << "The pig says: wee wee \n";
    }
    virtual void id() {
        counter = 1; 
    }
};

// Derived class
class Dog : public Animal {
  public:
    void animalSound() {
      cout << "The dog says: bow wow \n";
    }
    void printName()
    {
        cout << "Dog name is Waly  \n";
    }
    virtual void id() {
        counter = 2; 
    }
   
};

// Derived class
class Cat: public Animal {
  public:
    void animalSound() {
      cout << "The dog says: Meyw meyw .. \n";
    }
    virtual void id() {
        counter = 3; 
    }
};

int getId(Animal *name)
{
    cout<<name->counter<<endl;
}

int main() 
{
  Animal *myAnimal1 = new Dog(); 
  Animal *myAnimal2 = new Pig();
  Animal *myAnimal3 = new Cat();

 
   
   Animal *animals[4] = {myAnimal2,myAnimal3,myAnimal1,myAnimal2}; 

  for(int i =0; i< 4; i++)
  {
         animals[i]->animalSound();
         animals[i]->id();

  }

for(int i =0; i< 4; i++)
  {
        
    getId(animals[i]);
         
  }
   

myAnimal3 += myAnimal2;

  return 0;
}