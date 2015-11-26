#include <string.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include "rapidxml-1.13/rapidxml.hpp"

using namespace rapidxml;
using namespace std;

int main(void)
{
	cout << "Parsing my map..." << endl;
	xml_document<> doc;
	xml_node<> * root_node;
	// Read the xml file into a vector
	ifstream theFile ("sample.xml");
	vector<char> buffer((istreambuf_iterator<char>(theFile)), istreambuf_iterator<char>());
	buffer.push_back('\0');
	// Parse the buffer using the xml file parsing library into doc
	doc.parse<0>(&buffer[0]);
	// Find our root node
	root_node = doc.first_node("map");
	// Iterate over the brewerys
	for (xml_node<> * map_node = root_node->first_node("room"); map_node; map_node = map_node->next_sibling("room"))
	{
		xml_node<> * room_node = map_node->first_node("name");
	    printf("I have visited %s.", room_node->value());
	    cout << endl;
	}
}
