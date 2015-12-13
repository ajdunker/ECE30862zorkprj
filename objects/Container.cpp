/*
 * Container.cpp
 *
 *  Created on: Dec 6, 2015
 *      Author: Klonowski
 */

#include "Container.h"

Container::Container(xml_node<> * containerNode) {
	createContainer(containerNode->first_node());
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
			this->name = xmlValue;
		} else if (xmlName == "item") {
			this->items[xmlValue] = xmlValue;
		} else if (xmlName == "accept") {
			this->accept = xmlValue;
		} else if (xmlName == "status") {
			this->status = xmlValue;
		} else if (xmlName == "trigger"){
			newTrigger = new Trigger(childNode);
			triggers[newTrigger->name] = newTrigger;
		}
		childNode = childNode->next_sibling();
	}
}
