/*
 * Creature.cpp
 *
 *  Created on: Dec 13, 2015
 *      Author: Alex
 */

#include "Creature.h"

Creature::Creature(xml_node<> * creatureNode) {
	// TODO Auto-generated constructor stub
	createCreature(creatureNode->first_node());
}

Creature::~Creature() {
	// TODO Auto-generated destructor stub
}

void Creature::createCreature(xml_node<> * childNode) {
	string xmlName;
	string xmlValue;
	Trigger* newTrigger;

	while (childNode != NULL) {
		xmlName = childNode->name();
		xmlValue = childNode->value();

		if (xmlName == "name") {
			this->name = xmlValue;
		} else if (xmlName == "vulnerability") {
			this->vulnerability = xmlValue;
		} else if (xmlName == "trigger") {
			newTrigger = new Trigger(childNode);
			triggers[newTrigger->name] = newTrigger;
		} else if (xmlName == "attack") {
			//createAttack(childNode->first_node());
		}
		childNode = childNode->next_sibling();
	}
}

void Creature::createAttack(xml_node<> * childNode) {
	string Name;
	string Value;

	while(childNode != NULL) {
		Name = childNode->name();
		Value = childNode->value();

		if(Name == "print") { this->attack[Name] = Value; }
		else if(Name == "action") { this->attack[Name] = Value; }
		else if(Name == "condition") { createcCondition(childNode->first_node()); }
	}
}

void Creature::createcCondition(xml_node<> * childNode) {
	//check if status or has condition
	string Name;
	string Value;

	while (childNode != NULL) {
		Name = childNode->name();
		Value = childNode->value();

		if(Name == "object") { this->conditions[Name] = Value; }
		else if(Name == "action") { this->conditions[Name] = Value; }

		childNode = childNode->next_sibling();
	}

}