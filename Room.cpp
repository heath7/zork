#include "/home/shay/a/heath7/zork1/Room.h"

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
  // Border newBorder;
  
  // newBorder.direction = dir;
  // newBorder.name = borderRoom;
  // borders.push_back(newBorder);
  //borders[borderIndex] = newBorder;
  //borderIndex++;
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
