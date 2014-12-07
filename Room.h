#ifndef _ROOM_H
#define _ROOM_H
#include <iostream>
#include <string>
#include <vector>

#include "Item.h"
//#include "Creature.h"
//#include "Trigger.h"
//#include "Container.h"

using std::vector;
using std::string;
using namespace std;

class Room {
  
typedef struct _border
{
  string direction;
  string name;  
}Border;
 
 public:
  Room()
      {
       name = "default";
       description = "default";
       status = "default";
       type = "default";
       bordersIndex = 0;
       };
  void setName(string newName);
  void setDescription(string newDescription);
  void setStatus(string newStatus);
  void setType(string newType);
  string getName();
  string getDescription();
  string getStatus();
  string getType();

  void addBorder(string newDirection, string newName);
  void addItem(Item* newItem);
  Item* getItem(string itemName);
  // void removeItem(string itemName);
  // Room* const getNextRoom(const string &dirName);

  //string getDescription();
  /*
  string getName()
  {
    return name;
  };
  
  
   string getType();
  */
 private:

  vector<Item*> items;
  vector<Border> borders;
  // vector<Creature> creatures;
  // vector<Trigger> triggers;
  // vector<Container> containers;

  string description;
  string name;
  string type;
  string status;
  int bordersIndex;
  
  

  

};
#endif
