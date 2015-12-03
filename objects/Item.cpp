/*
 * Item.cpp
 *
 *  Created on: Nov 25, 2015
 *      Author: jklonows
 */

#include "Item.h"

Item::Item(xml_node<> * ItemNode) {
	createItem(ItemNode);
}

Item::~Item() {

}


void Item::createItem(xml_node<> * itemNode) {
	string xmlName;
	string xmlValue;
	string name;
	string writing;
	string status;
	xml_node<> * childNode = itemNode->first_node();

	while (childNode != NULL) {
		xmlName = childNode->name();
		xmlValue = childNode->value();

		if (xmlName == "Name") {
			name = xmlValue;

		} else if (xmlName == "Writing") {
			writing = xmlValue;
		}
		else if (xmlName == "Status") {
			status = xmlValue;
		}
		childNode = childNode->next_sibling();
	}
	//add to the map
	//this->items[writing] = name;
}

