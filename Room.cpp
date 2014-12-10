#include "/home/shay/a/heath7/zork1/Room.h"
//#include "/home/shay/b/dpahuja/Desktop/ece 308-62/zork/Room.h"
/*
Room::Room()
{
name = "default";
description = "default";
status = "default";
type = "default";
} 
*/
string Room::getName()
{
  return name;
}

string Room::getDescription()
{
  return description;
}

string Room::getStatus()
{
  return status;
}

string Room::getType()
{
  return type;
}

void Room::setName(string newName)
{
name = newName;
}

void Room::setDescription(string newDescription)
{
description = newDescription;
}

void Room::setStatus(string newStatus)
{
status = newStatus;
}

void Room::setType(string newType)
{
type = newType;
}

void Room::addBorder(string dir, string borderRoom)
{
  Border* newBorder = new Border();
 newBorder->direction = dir;
 newBorder->name = borderRoom;
 borders.push_back(newBorder);
}

void Room::addItem(Item* newItem)
{
items.push_back(newItem);
}

Item* Room::getItem(string itemName)
{
  int i = 0;
  for(i = 0; i < items.size(); i++)
    {
      if(items[i]->getName().compare(itemName) == 0)
	{
	  return items[i];
	}
    }
  return NULL;
}

string Room::getBorderName(string dir){
  for(int i = 0; i < borders.size(); i++)
  {
    if(borders[i]->direction == dir)
      {
	return borders[i]->name;
      }
  } 
  return "nonexistant";
}


Container* Room::getContainer(string target){
  int i = 0;
  for(i = 0; i < containers.size(); i++ )
    {
      if(containers[i]->getName() == target)
	{
	  return containers[i];
	}
    }
  return NULL;
}

void Room::addContainer(Container* newContainer){
  (this->containers).push_back(newContainer);
}

Creature * Room::getCreature(string target){
  int i = 0;
  for(i = 0; i < creatures.size(); i++ )
    {
      if(creatures[i]->getName() == target)
	{
	  return creatures[i];
	}
    }
  return NULL;
}

void Room::addCreature(Creature* newCreature){
  (this->creatures).push_back(newCreature);
}

vector <Triggers*> Room::getTriggers()
{
  return triggers;
}

void Room::addTriggers(Triggers* newTriggers){
  (this->triggers).push_back(newTriggers);
}

/*
main()
{
Room* room1 = new Room();
room1->setName("entrance");
string tempName = room1->getName();
std::cout << tempName << std::endl;
}
*/
