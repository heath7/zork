#ifndef CREATURE_H_
#define CREATURE_H_
#include <string>
#include <vector>
#include <iostream>
#include "Item.h"
#include "Attack.h"
#include "Triggers.h"

using namespace std;
//using namespace rapidxml;


class Creature {
private:
	vector<string> vulnerability;
	vector<Triggers> triggers;

	string condition;
	string name;
  	string description;
  	string status;
  	Attack attack;
  	string condition_satisfy;

public:
	Creature();
	
	string getName();
	void setName(string newName);

	string getDescription();
  	void setDescription(string newDescription);
  	
  	string getStatus();
  	void setStatus(string newStatus);

	void setVulnerability(string newVulnerability);
	vector<string> getVulnerability();

	void setAttack(Attack newAttack);
	Attack getAttack();

	vector<Triggers> getTriggers();
	void setTriggers(Triggers);

	string getConditionSatisfy();
	void setConditionSatisfy(string);

};

#endif