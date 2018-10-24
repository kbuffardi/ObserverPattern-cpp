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

class Alert
{
public:
  void sendAlert(const int number, const char* alert)
  {
    std::cout<<"ALERT! "<<number<<" is "<<alert<<std::endl;
  }
};


// controller that gathers input to change data model and drives log updates
class IOController: public IObserver
{
private:
  DataModel* current;
  Logger output;

public:
  IOController(DataModel* data)
  {
    current = data;
    current->addObserver(this);
  }
  void input(int x)
  {
    current->setNumber(x);
  }
  void update()
  {
    output.showNumber(current->getNumber());
  }
};

//controller that displays alerts under certain conditions
class AlertController: public IObserver
{
private:
  DataModel* dataState;
  Alert display;

public:
  AlertController(DataModel* data)
  {
    dataState = data;
    dataState->addObserver(this);
  }
  void update()
  {
    int num = dataState->getNumber();
    if( num < 0 )
    {
      display.sendAlert(num,"negative");
    }
    else if( num == 0 )
    {
      display.sendAlert(num,"zero");
    }
  }
};

//Program run
int main()
{
  DataModel persistant;
  IOController io(&persistant);
  AlertController notifications(&persistant);

  // simulate the user's actions that change state
  io.input(100);
  io.input(10);
  io.input(-1);
  io.input(0);

  return 0;
}