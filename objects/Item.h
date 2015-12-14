/*
 * Item.h
 *
 *  Created on: Nov 28, 2015
 *      Author: Klonowski
 */

#ifndef ITEM_H_
#define ITEM_H_

#include <string>
#include <stdio.h>
#include <iostream>
#include <map>
#include <vector>
#include "Trigger.h"
#include "../rapidxml-1.13/rapidxml.hpp"

using namespace std;
using namespace rapidxml;

class Item {
public:

	Item(rapidxml::xml_node<> *);
	virtual ~Item();

	string name;
	string description;
	string writing;
	string status;
	string debug;
	map<string, string> turnOn;
	map<string, Trigger*> triggers;

private:
	void createItem(xml_node<> *);
	void createTurnOn(xml_node<> * );
};



#endif /* ITEM_H_ */
