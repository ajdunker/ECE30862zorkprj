/*
 * Room.cpp
 *
 *  Created on: Nov 25, 2015
 *      Author: adunk
 */

#include "Room.h"

Room::Room(xml_node<> * RoomNode) {
	createRoom(RoomNode->first_node());
}

Room::~Room() {

}

void Room::createRoom(xml_node<> * childNode) {
	string xmlName;
	string xmlValue;

	while (childNode != NULL) {
		xmlName = childNode->name();
		xmlValue = childNode->value();

		if (xmlName == "name") {
			this->name = xmlValue;
		} else if (xmlName == "description") {
			this->description = xmlValue;
		} else if (xmlName == "type") {
			this->type = xmlValue;
		} else if (xmlName == "border") {
			createBorder(childNode);
		} else if (xmlName == "item") {
			createItem(childNode);
		}

		childNode = childNode->next_sibling();

	}
}

void Room::createItem(xml_node<> * itemNode) {
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
	this->items[writing] = name;
}

void Room::createBorder(xml_node<> * borderNode) {
	string xmlName;
	string xmlValue;
	string direction;
	string name;
	xml_node<> * childNode = borderNode->first_node();

	while (childNode != NULL) {
		xmlName = childNode->name();
		xmlValue = childNode->value();

		if (xmlName == "direction") {
			direction = xmlValue;
		} else if (xmlName == "name") {
			name = xmlValue;
		}

		childNode = childNode->next_sibling();
	}
	//add to the map
	this->borders[direction] = name;
}
