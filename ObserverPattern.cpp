/**
 * Adapted from Observer Pattern, as defined by Gamma, Helm, Johnson, Vlissides
 * ("Gang of Four") book: 
 *    "Design Patterns: Elements of Reusable Object-Oriented Software" (1994)
 * and partially designed around the Java API for the libraries:
 *   java.util.Observer and java.util.Observable
 *
 * Designed to be compliant back to (at least) C++03
 * 
 * Author: Kevin Buffardi
 * Source: https://github.com/kbuffardi/ObserverPattern-cpp
 * MIT License
**/
#ifndef OBSERVER_PATTERN
#define OBSERVER_PATTERN
#include <set>

/**
 * Interface to create an observer for subscribing to an Observable (below)
 * subject, which will automatically trigger the observer's update() function
 * when its state changes.
 **/
class IObserver {
public:
  virtual void update() = 0;
};

/**
 * Allows a derived class (sometimes called the "subject") to accept observers
 * (which implemented IObserver interface) to subscribe in order to trigger
 * automatic updates whenever the state of the subject changes.
 *
 * Any observer is only able to maintain a single subscription to an Observable
 * subject.
 **/
class Observable
{
private:
  //set structure used to avoid redundant observers
  std::set<IObserver *> observerSet; 

public:
  //Adds a concrete observer to the subject class
  void addObserver(IObserver *obs) 
  { 
    observerSet.insert(obs); 
  }

  //Removes a concrete observer from observing the subject class
  void deleteObserver(IObserver *obs) 
  { 
    observerSet.erase(obs); 
  }

  //Removes all concrete observers from the subject class
  void deleteObservers()
  { 
    observerSet.clear(); 
  }

  //Triggers update() for each concrete observer
  void notifyObservers()
  {
    std::set<IObserver *>::iterator i;
    for( i=observerSet.begin(); i != observerSet.end(); ++i)
    {
      IObserver *obs = *i;
      obs->update();
    }
  }
};

#endif