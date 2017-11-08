#include <iostream>
#include "ObserverPattern.hpp"

///////////////////EXAMPLE USAGE IN SIMPLISTIC PSEUDO-MVC ARCHITECTURE:
class AnInt: public Observable
{
private:
  int num;

public:
  AnInt(){ num = 0; }
  void setInfo(int num)
  {
    this->num = num;
    notifyObservers();
  }
  int getNum(){ return num; }
};

class NumWatcherView
{
public:
  void showNum(int num) //interface override
  {
    std::cout<<"There is a new number: "<<num<<std::endl;
  }
};

class AlertView
{
private:
  bool isNegative(int num)
  {
    return num < 0;
  }
public:
  void checkAlerts(int num)
  {
    if(isNegative(num))
    {
      std::cout<<"ALERT! "<<num<<" is negative!"<<std::endl;
    }
  }
};

class NumberController: public IObserver
{
private:
  AnInt current;
  AlertView alerts;
  NumWatcherView output;

public:
  NumberController()
  {
    current.addObserver(this);
  }
  void set(int x)
  {
    current.setInfo(x);
  }
  void update()
  {
    output.showNum(current.getNum());
    alerts.checkAlerts(current.getNum());
  }
};

//the user's actions
int main()
{
  NumberController example;
  example.set(100);
  example.set(10);
  example.set(-1);
  example.set(0);
  return 0;
}