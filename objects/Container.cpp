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
	xmlName = containerNode->name();
	xmlValue = containerNode->value();
	this->items[xmlValue] = xmlValue;

}
