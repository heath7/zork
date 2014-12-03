#include<iostream>
#include<fstream>
#include<vector>
#include "rapidxml_utils.hpp"
#include "rapidxml.hpp"

using namespace std;
using namespace rapidxml;

int main(){
	file<> xmlFile("sample.txt.xml"); // Default template is char
	xml_document<> doc;

	doc.parse<0>(xmlFile.data());
	cout << "Name of my first node is: " << doc.first_node()->name() << "\n";
	xml_node<> *map = doc.first_node();
	//cout << "Node room has value " << node->value() << "\n";
	for (xml_node<> *node1 = map->first_node();
			node1; node1 = node1->next_sibling())
	{
		cout << "Node has name " << node1->name() << " ";
		cout << "with value " << node1->value() << "\n";
		for(xml_node<> *node2 = node1->first_node();
				node2; node2 = node2->next_sibling())
		{
		cout << "Node has name " << node2->name() << " ";
		cout << "with value " << node2->value() << "\n";

		}
	}
}
