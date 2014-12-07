#ifndef _CONTAINER_H
#define _CONTAINER_H

#include <list>
using std::list;

#include "Exceptions.h"

#include "Item.h"

class Inventory
{
 public:
  Container(string name, string description, string status);
  string getName();
  string getDescription();
  string getStatus();
  string toString() const;
  bool put(const Item& item); //insert
  string examine( const string &itemString ) const throw (MissingItem);

 private:
  //const unsigned int MAX_ITEMS;
  string name;
  string description;
  string status;
};

#endif
