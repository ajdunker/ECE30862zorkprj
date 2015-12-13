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

void Container::createContainer(xml_node<> * childNode){

	string xmlName;
	string xmlValue;
	Trigger* newTrigger;

	while (childNode != NULL) {
		xmlName = childNode->name();
		xmlValue = childNode->value();

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
