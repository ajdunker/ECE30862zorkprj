/*
 * Container.cpp
 *
 *  Created on: Dec 6, 2015
 *      Author: Klonowski
 */

#include "Container.h"

Container::Container(xml_node<> * containerNode) {
	createContainer(containerNode);
}

Container::~Container() {
	// TODO Auto-generated destructor stub
}

void Container::createContainer(xml_node<> * containerNode){

	string xmlName;
	string xmlValue;
	Trigger* newTrigger;
	xmlName = containerNode->name();
	xmlValue = containerNode->value();
	xml_node<> * childNode = containerNode->first_node();

	while (childNode != NULL) {
		if (xmlName == "name") {
			name = xmlValue;
		} else if (xmlName == "item") {
			this->items[xmlValue] = xmlValue;
		} else if (xmlName == "accept") {
			accept = xmlValue;
		} else if (xmlName == "trigger"){
			newTrigger = new Trigger(childNode);
			triggers[newTrigger->name] = newTrigger;
		}
		childNode = childNode->next_sibling();
	}
}
