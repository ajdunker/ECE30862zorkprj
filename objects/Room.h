/*
 * Room.h
 *
 *  Created on: Nov 25, 2015
 *      Author: adunk
 */

#ifndef Room_H_
#define Room_H_

#include <string>
#include <stdio.h>
#include "trigger.h"
#include <iostream>
#include <map>
#include <vector>
#include "../rapidxml-1.13/rapidxml.hpp"

using namespace std;
using namespace rapidxml;

class Room {

public:

	Room(xml_node<> *);
	virtual ~Room();

	string name;
	string type = "regular";
	string description;
	map<string, string> borders;
	map<string, string> items;
	map<string, string> containers;
	map<string, string> creatures;
	map<string, Trigger*> triggers;

private:
	void createRoom(xml_node<> *);
	void createBorder(xml_node<> *);
	void createItem(xml_node<> *);
};

#endif /* Room_H_ */
