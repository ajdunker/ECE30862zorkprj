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
	Trigger* newTrigger;
	xml_node<> * childNode = itemNode->first_node();

	while (childNode != NULL) {
		xmlName = childNode->name();
		xmlValue = childNode->value();

		if (xmlName == "name") {
			name = xmlValue;
		} else if (xmlName == "writing") {
			writing = xmlValue;
		} else if (xmlName == "status") {
			status = xmlValue;
		} else if (xmlName == "trigger"){
			newTrigger = new Trigger(childNode);
			triggers[newTrigger->name] = newTrigger;
		}
		childNode = childNode->next_sibling();
	}
}

