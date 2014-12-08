#ifndef _ITEM_H
#define _ITEM_H
#include<iostream>
#include <vector>
#include <string>
#include "Triggers.h"

using std::vector;
using std::string;

using namespace std;

class Item
{
public:
	Item();
	string getName();
	void setName(string newName);

	string getDescription();
	void setDescription(string newDescription);


	string getStatus();
	void setStatus(string newStatus);

	string getWriting();
	void setWriting(string newWriting);
	
	void turnOn();
	void turnOff();

	string getIsOn();
	void setIsOn(string);

	Triggers * getTriggers();
	void setTriggers(Triggers*);


private:
	string name;
	string description;
	string status;
	string writing;
	string on;
	int onFlag;
	Triggers * triggers;
};
#endif