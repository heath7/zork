#include "Item.h"

Item::Item()
{
  name = "default";
  description = "default";
  status = "default";
  writing = "default";
}

string Item::getName()
  {
    return name;
  }
  
string Item::getDescription() 
  {
    return description;
  }
string Item::getStatus()
  {
    return status;
  }

string Item::getWriting()
{
  return writing;
}

void Item::setName(string newName)
{
  name = newName;
}

void Item::setDescription(string newDescription)
{
  description = newDescription;
}

void Item::setStatus(string newStatus)
{
  status = newStatus;
}

void Item::setWriting(string newWriting )
{
  writing = newWriting;
}
bool Item::isOn()
{
  //
} 

