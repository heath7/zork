#ifndef _ITEM_H
#define _ITEM_H
#include<iostream>
#include <vector>
#include <string>
using std::vector;
using std::string;
using namespace std;

class Item
{
 public:
  Item();
  string getName();
  string getDescription();
  string getStatus();
  string getWriting();

  void setName(string newName);
  void setDescription(string newDescription);
  void setStatus(string newStatus);
  void setWriting(string newWriting);
  bool isOn();

 private:
  string name;
  string description;
  string status;
  string writing;
  bool on;
  
};

#endif
