#ifndef _ROOM_H
#define _ROOM_H

#include <string>
#include <vector>
using std::string;

//#include "Item.h"

class Room {
  /* 
struct Border
{
  char direction;
  Room* room;  
}border;
  */ 
 public:
  Room(const string tempName);
  
  void addBorder(const string &dir, Room* const borderRoom);
  // void addItem(const Item &item);
  void removeItem(string itemName);
  Room* const getNextRoom(const string &dirName);

  string getDescription();
  string getName();
  string getType();

 private:

  // vector<Item> items;
  //vector<border> borders;
  string description;
  string name;
  string type;
  string status;
  

  

};
#endif
