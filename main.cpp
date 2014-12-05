#include<iostream>
#include<fstream>
#include<cstdlib>
#include<vector>
#include "rapidxml_utils.hpp"
#include "rapidxml.hpp"
#include <string>
#include "Room.h"

using std::string;

using namespace std;
using namespace rapidxml;
string tempName;
string tempName2;
string tempName3;

string tempValue;
string borderDirection;
string borderName;
vector<Room *> rooms;
int i = 0;


int main(){
  //Room* room1 = new Room("blah");
  rooms.resize(5);
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
	  rooms[i] = room1;
	  // tempValue = room1.getName(); 
	  // cout << room1.getName() << "/n";
	  for(xml_node<> *node2 = node1->first_node();
	       node2; node2 = node2->next_sibling())
	     {
	       	
	       tempName2 = node2->name();
	       if(tempName2 == "name")
		 {
		   //	rooms[i].setName(node2->value());
		 }
	       if(tempName2 == "description")
		 {
		   //	room[i].setDescription(node2->value());
		 }
	       if(tempName2 == "status")
		 {
		   //   room[i].setStatus(node2->value());
		 }
	       if(tempName2 == "type")
		 {
		   //   room[i].setType(node2->value());
		 }
	       if(tempName2 == "border")
		 {

		     for(xml_node<> *node3 = node2->first_node();
		    node3; node3 = node3->next_sibling())
		       {
			 tempName3 = node3->name();
			 if(tempName3 == "direction")
			   {
			     borderDirection = node3->value();
			   }
			 if(tempName3 == "name")
			   {
			      borderName = node3->value();
			   }
		       }
		     //  room[i].addBorder(borderDirection, borderName);
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
		   //create new item 
		   //add item to item array
		   //add item to room
		 }
	         cout << "Node has name2 " << node2->name() << " ";
	         cout << "with value2 " << node2->value() << "\n";   
	     }
	  
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
