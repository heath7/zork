#include<iostream>
#include<fstream>
#include<cstdlib>
#include<vector>
#include "rapidxml_utils.hpp"
#include "rapidxml.hpp"
#include <string>
#include "Room.h"
#include "Item.h"
#include "Container.h"
#include "Creature.h"
#include "Triggers.h"


using std::string;

using namespace std;
using namespace rapidxml;
string tempName;
string tempName2;
string tempName3;
string tempName4;
string tempValue2;
string tempValue3;
string tempValue4;
string tempValue;
string borderDirection;
string borderName;
string trigHas;
string trigStatus;
string trigOwner;
string trigObject;
vector<Room*> rooms;
vector<Item*> items;
vector<Container*> containers;
vector<Creature*> creatures;
vector<Triggers*> triggers;


//vector<Creature*> cretures;
//vector<
int i = 0;


int main(){
  //Room* room1 = new Room("blah");
  
  file<> xmlFile("sample.txt.xml"); // Default template is char
  xml_document<> doc;
  
  doc.parse<0>(xmlFile.data());
  cout << "Name of my first node is: " << doc.first_node()->name() << "\n";
  xml_node<> *map = doc.first_node();
  //cout << "Node room has value " << node->value() << "\n";
  for (xml_node<> *node1 = map->first_node();
       node1; node1 = node1->next_sibling())
    {
      tempName = node1->name();
      tempValue = node1->value();
      if(tempName == "room")
	{
	  
	  Room* room1 = new Room();//create a room
	  rooms.push_back(room1);
	  // tempValue = room1.getName(); 
	  // cout << room1.getName() << "/n";
	  for(xml_node<> *node2 = node1->first_node();
	      node2; node2 = node2->next_sibling())
	    {
	      
	      tempName2 = node2->name();
	      if(tempName2 == "name")
		{
		  tempValue2 = node2->value();
		  rooms[i]->setName(tempValue2);
		  // cout << rooms[i]->getName() << endl;
		}
	      if(tempName2 == "description")
		{
		  tempValue2 = node2->value();
		  rooms[i]->setDescription(tempValue2);
		}
	      if(tempName2 == "status")
		{
		  tempValue2 = node2->value();
		  rooms[i]->setStatus(tempValue2);
		}
	      if(tempName2 == "type")
		{
		  tempValue2 = node2->value();
		  rooms[i]->setType(tempValue2);
		}
	      if(tempName2 == "border")
		{
		  
		  for(xml_node<> *node3 = node2->first_node();
		      node3; node3 = node3->next_sibling())
		    {
		      tempName3 = node3->name();
		      if(tempName3 == "direction")
			{
			  tempValue3 = node3->value();
			  borderDirection = tempValue3;
			}
		      if(tempName3 == "name")
			{
			  tempValue3 = node3->value();
			  borderName = tempValue3;
			}
		    }
		    rooms[i]->addBorder(borderDirection, borderName);
		    cout << borderDirection << endl;
		     cout << rooms[i]->getBorderName(borderDirection) << endl;
		}
	      if(tempName2 == "container")
		{
		  Container* newContainer = new Container();  //create new container
		  containers.push_back(newContainer);
		  tempValue2 = node2->value();
		  containers.back()->setName(tempValue2);   //add container to contianer array
		  rooms.back()->addContainer(newContainer); //add container to room
		}
	      if(tempName2 == "creature")
		{
		  Creature* newCreature = new Creature(); //create new creature
		  tempValue2 = node2->value();
		  newCreature->setName(tempValue2);
		  creatures.push_back(newCreature); //add creature to creature array
		  rooms[i]->addCreature(newCreature);//add creature to room
		}
	      if(tempName2 == "item")
		{
		  Item* newItem = new Item();//create new item
		  items.push_back(newItem);//add item to item array
		  tempValue2 = node2->value();
		  items.back()->setName(tempValue2);
		  rooms.back()->addItem(newItem);	  //add item to room
		}
	      
	      if(tempName2 == "trigger")
		{
		  Triggers* newTriggers = new Triggers();
		  triggers.push_back(newTriggers);
		  rooms[i]->addTriggers(newTriggers);
		  
		  for(xml_node<> *node3 = node2->first_node();
		      node3; node3 = node3->next_sibling())
		    {
		      tempName3 = node3->name();
		      tempValue3 = node3->value();
		      
		      if(tempName3 == "type")
			{
			  cout << tempName3 << endl;
			  newTriggers->setType(tempValue3);
			  cout << newTriggers->getType() << endl;
			}
		      if(tempName3 == "command")
			{
			  cout << tempName3 << endl;
			  newTriggers->setCommand(tempValue3);
			  cout << newTriggers->getCommand() << endl;
			}
		      if(tempName3 == "print")
			{
			  cout << tempName3 << endl;
			  newTriggers->setPrint(tempValue3);
			  cout << rooms[i]->getTriggers()[0]->getPrint() << endl;
			}
		      if(tempName3 == "condition")
			{
			  trigHas = "default";
			  trigObject = "default";
			  trigOwner = "default";
			  trigStatus = "default";
			  for(xml_node<> *node4 = node3->first_node();
			      node4; node4 = node4->next_sibling())
			    {
			      tempName4 = node4->name();
			      tempValue4 = node4->value();
			      if(tempName4 == "has" )
				{
				  trigHas = tempValue4;
				}
			      if(tempName4 == "object")
				{
				  trigObject = tempValue4; 
				}
			      if(tempName4 == "owner")
				{
				  trigOwner = tempValue4;
				}
			      if(tempName4 == "status")
				{
				  trigStatus = tempValue4;
				}
			      
			    }
			  newTriggers->setCondition(trigObject, trigStatus, trigHas, trigOwner);
			  cout << "trigger" << endl << "object" << endl;
			  cout << rooms[i]->getTriggers()[0]->getCondition()->object << endl;
			  cout << "has" << endl;
			  cout << newTriggers->getCondition()->has << endl;
			  cout << "owner" << endl;
			  cout << newTriggers->getCondition()->owner << endl;
			  cout << "status" << endl;
			  cout << newTriggers->getCondition()->status << endl;
			}
		    }
		}
	      cout << "Node has name2 " << node2->name() << " ";
	      cout << "with value2 " << node2->value() << "\n";
	    }
	}
      
      
      
      if(tempName == "item")
	{
	  xml_node<> *tempNode2 = node1->first_node();
	  
	  tempValue2 = tempNode2->value();
	  cout << tempValue2 << "!!!!!!!!!"  <<endl;
	  int found = 0;
	  int i = 0;
	  for(i = 0; i < items.size(); i++)
	    {
	      if(items[i]->getName().compare(tempValue2) == 0)
		{
		  found = 1;
		  for(xml_node<> *node2 = node1->first_node();
		      node2; node2 = node2->next_sibling())
		    {
		      tempName2 = node2->name();

		      tempValue2 = node2->value();
	
		      if(tempName2 == "writing")//set writing
			{
			  cout << tempName2 << endl;
			  items[i]->setWriting(node2->value());
			  cout << items[i]->getWriting() << endl;
			}
	
		      if(tempName2 == "status")//set status
			{
			  cout << tempName2 << endl;
			  items[i]->setStatus(node2->value());
			  cout << items[i]->getStatus() << endl;
			}
		      
		      if(tempName2 == "turnon")
			{
			  for(xml_node<> *node3 = node2->first_node();
			      node3; node3 = node3->next_sibling())
			    {
			      tempName3 = node3->name();
			      tempValue3 = node3->value();
			      if(tempName3 == "print")
				{
				  cout << tempName3 << endl;
				  items[i]->setPrint(tempValue3);
				  cout << items[i]->getPrint() << endl;
				}
			      if(tempName3 == "action")
				{
				  cout << tempName3 << endl;
				  items[i]->addAction(tempValue3);
				  for(int q =0; q < items[i]->getActions().size(); q++)
				    {
				      cout << items[i]->getActions()[q] << endl;
				    }
				  
				}
			    }
			}
		    }
		}
	    }
	      if(found == 0)
		{
		  Item* tempItem = new Item();
		  items.push_back(tempItem);
		  tempItem->setName(tempValue2);


		  for(xml_node<> *node2 = node1->first_node();
		      node2; node2 = node2->next_sibling())
		    {
		      tempName2 = node2->name();
		      
		      tempValue2 = node2->value();
		      
		      if(tempName2 == "writing")//set writing
			{
			  cout << tempName2 << endl;
			  tempItem->setWriting(node2->value());
			  cout << tempItem->getWriting() << endl;
			  // cout << tempItem->getWriting() << endl;
			}
		      if(tempName2 == "status")//set status
			{
			  cout << tempName2 << endl;
			  tempItem->setStatus(node2->value());
			  cout << tempItem->getStatus() << endl;
			}

		      if(tempName2 == "turnon")
			{
			  for(xml_node<> *node3 = node2->first_node();
			      node3; node3 = node3->next_sibling())
			    {
			      tempName3 = node3->name();
			      tempValue3 = node3->value();
			      if(tempName3 == "print")
				{
				  cout << tempName3 << endl;
				  tempItem->setPrint(tempValue3);
				  cout << tempItem->getPrint() << endl;
				}
			      if(tempName3 == "action")
				{
				  cout << tempName3 << endl;
				  tempItem->addAction(tempValue3);
				  for(int q =0; q < tempItem->getActions().size(); q++)
				    {
				      cout << tempItem->getActions()[q] << endl;
				    }
				  
				}
			    }
			}
		      
		      //set turnon
		      //setPrint
		      //setAction
		    }
		}
	    } 
	
	  if(tempName == "container")
	    {
	      //search container vector for container with same name
	      xml_node<> *tempNode2 = node1->first_node();
	      
	      tempValue2 = tempNode2->value();
	      cout << tempValue2 << "!!!!!!!"  <<endl;
	      int found = 0;
	      int i = 0;
	      for(i = 0; i < containers.size(); i++)
		{
		  if(containers[i]->getName().compare(tempValue2) == 0)
		    {
		      found = 1;
		      
		      for(xml_node<> *node2 = node1->first_node();
		      node2; node2 = node2->next_sibling())
			{
			  tempName2 = node2->name();
			  
			  tempValue2 = node2->value();
			  
			  if(tempName2 == "accept")
			    {
			      cout << tempName2 << endl;
			      containers[i]->setAccept(node2->value());
			      cout << containers[i]->getAccept() << endl;
			    }
			  if(tempName2 == "status")
			    {
			      cout << tempName2 << endl;
			      containers[i]->setStatus(node2->value());
			      cout << containers[i]->getStatus() << endl;
			    }
			  if(tempName2 == "item")
			    {
			      tempValue2 = node2->value();
			      //cout << tempValue2 << endl;
			      int j = 0;
			      for(j = 0; j < items.size(); j++)
				{	
				  //cout << items[j]->getName() << endl;		      
				  if(items[j]->getName() == tempValue2)
				    {
				      //cout << "!!!!!!!!"<< endl;
				      //cout << tempValue2 << endl;
				      containers[i]->addItem(items[j]);//////
				      cout << containers[i]->getItem(tempValue2)->getName() << endl;
				    }					      
				}
			    }    
			}
		    }
		}
	   //setStatus
	   //setAccept
	   //addTrigger
	   //condition
	       //has
	       //object
	       //owner
	   //print
	   //setAction
	   
	   
	   
	}
      
      if(tempName == "creature")
	{
	  xml_node<> *tempNode2 = node1->first_node();
	  
	  tempValue2 = tempNode2->value();
	  cout << tempValue2 << "!!!!!!!"  <<endl;
	  
	  //search creature vector for creature with same name
	  
	  int i = 0;
	  for(i= 0 ; i < creatures.size(); i ++)
	    {
	      if(creatures[i]->getName() == tempValue2)
		{
		  for(xml_node<> *node2 = node1->first_node();
		      node2; node2 = node2->next_sibling())
		    {
		      tempName2 = node2->name();
		      tempValue2 = node2->value();
		      
		      if(tempName2 == "vulnerability")
			{
			  cout << tempName2 << endl;
			  creatures[i]->setVulnerability(tempValue2);
			   cout << creatures[i]->getVulnerability() << endl;
			}
		      if(tempName2 == "attack")
			{
			  cout << tempName2 << endl;
			  creatures[i]->setAttack(new Attack());
			  for(xml_node<> *node3 = node2->first_node();
			      node3; node3 = node3->next_sibling())
			    {
			      tempName3 = node3->name();
			      tempValue3 = node3->value();
			      if(tempName3 == "print")
				{
				  cout << tempName3 << endl;
				  creatures[i]->getAttack()->setPrint(tempValue3);
				  cout << creatures[i]->getAttack()->getPrint() << endl;
				}
			      if(tempName3 == "action")
				{
				  cout << tempName3 << endl;
				  creatures[i]->getAttack()->addAction(tempValue3);
				  for(int q = 0; q < (creatures[i]->getAttack())->getActions().size(); q++)
				    {
				      cout << ((creatures[i]->getAttack())->getActions())[q] << endl;
				    }
				}
			      if(tempName3 == "condition")
				{
				  for(xml_node<> *node4 = node3->first_node();node4; node4 = node4->next_sibling())
				    {
				      tempName4 = node4->name();
				      tempValue4 = node4->value();
				      if(tempName4 == "object")
					{
					  cout << tempName4 << endl;
					  creatures[i]->getAttack()->setObject(tempValue4);
					  cout << creatures[i]->getAttack()->getObject() << endl;
					}
				      if(tempName4 == "status")
					{
					  cout << tempName4 << endl;
					  creatures[i]->getAttack()->setStatus(tempValue4);
					  cout << creatures[i]->getAttack()->getStatus() << endl;
					}
				    }
				}
			    }
			}
		      if(tempValue2 == "trigger")
			{	
			  //triggers also have condition
			}
		      
		    }
		}
	    }
	  //add vulnerabilty
	  //add attack
	  //condition
	  //object
	  //status
	  //print
	  //add action
	  //add trigger
	  //setType
	  //condition
	  //object
	  //status
	  //print
	  
	}
      
      // cout << "Node has name1 " << node1->name() << " ";
      //cout << "with value1 " << node1->value() << "\n";
      /*
	for(xml_node<> *node2 = node1->first_node();
	node2; node2 = node2->next_sibling())
	{
	cout << "Node has name2 " << node2->name() << " ";
	cout << "with value2 " << node2->value() << "\n";
	
	}
      */
      i++;
	}
      
      
    }
  

