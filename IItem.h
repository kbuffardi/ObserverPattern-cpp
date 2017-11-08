#ifndef IITEM_H
#define IITEM_H
#include <string>

class IItem
{
public:
  //gets the name of the item (e.g. "Banana")
  virtual std::string getName() = 0;

  //gets the price of the item (e.g. 0.5)
  virtual double getPrice() = 0;

  //get the sku unique number
  virtual int getSKU() = 0;
};

#endif //end interface definition