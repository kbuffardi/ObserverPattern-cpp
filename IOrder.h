#ifndef IORDER_H
#define IORDER_H
#include <string>
#include "item.h"

class IOrder
{
public:
  //adds an item to the order
  virtual void addItem(item) = 0;
  
  //returns a vector of the items purchased
  virtual std::vector <item> getItems() = 0;
  
  //returns cost (before taxes)
  virtual double getSubtotal() = 0;

  //returns taxed amount (7.25 sales tax)
  virtual double getTax() = 0;

  //returns total amount with taxes included
  virtual double getTotal() = 0;

  //returns balance, given an amount paid
  virtual double balance(double) = 0;
};

#endif //end interface definition