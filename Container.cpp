#include "Container.h"

Container::Container(string name, string decription,string status)
{
  this->name = name;
  this -> description = description;
  this ->status = status;
}

string Container::getName()
{
    return name;
  }
  
string Inventory::getDescription() 
  {
    return description;
  }
string Inventory::getStatus()
  {
    return status;
  }

/*
This method returns the list of the items
 */
string Inventory::toString() const
{
  if(items.empty())
    {
      return "You have no items.";
    }
  else
    {
      string ret = "You have: "; 
    
   list<Item>::const_iterator itr;
   for ( itr = items.begin(); itr != items.end(); ++itr )
     {
       ret += "\n\ta " + itr->toString();
     }
   return ret;
}
}

/*
This method adds an item to the inventory if list not full
 */
bool Inventory::put(const Item& item)
{
  if ( !isFull() )
    {
      items.push_back(item);
      return true;
    }
  else
    {
      return false;
    }
}

/*
This method examines the list and returns the item
 */
string Inventory::examine(const string& itemString) const throw (MissingItem)
{

}
