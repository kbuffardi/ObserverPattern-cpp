#include <iostream>
#include "ObserverPattern.h"

// A data model that other modules are interested in when its state changes
class DataModel: public Observable
{
private:
  int num;

public:
  DataModel(){ num = 0; }
  void setNumber(int num)
  {
    this->num = num;
    notifyObservers(); // let interested Observers know that the state changed
  }
  int getNumber(){ return num; }
};

// one presentation of data that always shows its current state
class Logger
{
public:
  void showNumber(const int number) 
  {
    std::cout<<"There is a new number: "<<number<<std::endl;
  }
};


// controller that 
class IOController: public IObserver
{
private:
  DataModel current;
  Logger output;

public:
  IOController()
  {
    current.addObserver(this);
  }
  void input(int x)
  {
    current.setNumber(x);
  }
  void update()
  {
    output.showNumber(current.getNumber());
  }
};


int main()
{
  IOController example;
  ErrorLogController 

  // simulate the user's actions that change state
  example.input(100);
  example.input(10);
  example.input(-1);
  example.input(0);

  return 0;
}