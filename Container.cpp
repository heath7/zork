#include "Container.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

Container::Container()
{
 
}

string Container::getName()
  {
    return name;
  }

  void Container::setName(string newName)
  {
    name = newName;
  }
  

string Container::getDescription() 
  {
    return description;
  }

  void Container::setDescription(string newDescription)
  {
    this->description = newDescription;
  }

string Container::getStatus()
  {
    return status;
  }

  void Container::setStatus(string newStatus)
  {
    status = newStatus;
  }

  string Container::getSatisfyCondition()
  {
    return condition;
  }

void Container::setSatisfyCondition(string newCondition)
{
    this->condition = newCondition;
} 

vector<Item*> Container::getItems()
{
  return items;
}

Item* Container::getItem(string target)
{
  int i = 0;
  for(i = 0; i < items.size(); i++ )
    {
      if(items[i]->getName() == target)
	{
	  return items[i];
	}
    }
}

void Container::addItem(Item* newItem)
{
  items.push_back(newItem);
}


vector<Triggers> Container::getTrigger(){
  return triggers;
}

void Container::setTrigger(Triggers newTrigger){
  (this->triggers).push_back(newTrigger);
}

  string Container::getAccept(){
  return accept;
}

void Container::setAccept(string newAccept){
  accept = newAccept;
}



