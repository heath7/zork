#include<iostream>
#include<fstream>
#include<cstdlib>
#include<vector>
#include "rapidxml_utils.hpp"
#include "rapidxml.hpp"
#include <string>
#include "Room.h"
#include "Item.h"

using std::string;

using namespace std;
using namespace rapidxml;
string tempName;
string tempName2;
string tempName3;

string tempValue2;
string tempValue3;

string tempValue;
string borderDirection;
string borderName;
vector<Room*> rooms;
vector<Item*> items;


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
		  //  rooms[i]->addBorder(borderDirection, borderName);
		}
	      if(tempName2 == "container")
		{
		  //create new container
		  //add container to contianer array
		  //add container to room
		}
	      if(tempName2 == "creature")
		{
		  //create new creature
		  //add creature to creature array
		  //add creature to room
		}
	      if(tempName2 == "item")
		{
		  Item* newItem = new Item();//create new item

		       items.push_back(newItem);//add item to item array
		       tempValue2 = node2->value();
			   cout<< tempValue2 << endl;
			   items.back()->setName(tempValue2);
			   cout << items.back()->getName() << endl;
		       
		       //add item to room
		       rooms.back()->addItem(newItem);
		       // cout << "\n";
		     
		}
	      
	      
	      cout << "Node has name2 " << node2->name() << " ";
	      cout << "with value2 " << node2->value() << "\n";
	    }
	  
	}
      


      if(tempName == "item")
	{
	  //search item vector for item with same name
	  //setWriting
	  //setStatus
	  //set turnon
	     //setPrint
	     //setAction
	  
	} 
      if(tempName == "container")
	{
	  //search container vector for contianer with same name
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
	  //search creature vector for creature with same name
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

      
      cout << "Node has name1 " << node1->name() << " ";
      cout << "with value1 " << node1->value() << "\n";
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
