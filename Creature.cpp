#include <iostream>
#include <string>
#include <vector>
#include "Creature.h"
#include "Attack.h"

Creature::Creature()
{
 
}

string Creature::getName()
  {
    return name;
  }

  void Creature::setName(string newName)
  {
    this->name = newName;
  }
  

string Creature::getDescription() 
  {
    return description;
  }

  void Creature::setDescription(string newDescription)
  {
    this->description = newDescription;
  }

string Creature::getStatus()
  {
    return status;
  }

  void Creature::setStatus(string newStatus)
  {
    this->status = newStatus;
  }
 
 void Creature::setVulnerability(string newVulnerability)
 {
   vulnerability = newVulnerability;
 }

string Creature::getVulnerability(){
return vulnerability;
}

void Creature::setAttack(Attack* newAttack)
{
	this->attack = newAttack;
}

Attack* Creature::getAttack()
{
return attack;
}

vector<Triggers> Creature::getTriggers(){
  return triggers;
}

void Creature::setTriggers(Triggers newTriggers){
  (this->triggers).push_back(newTriggers);
}

string Creature::getConditionSatisfy(){
  return condition_satisfy;
}

void Creature::setConditionSatisfy(string newCondition){
  this->condition_satisfy = newCondition;
}


