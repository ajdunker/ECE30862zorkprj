/*
 * Trigger.h
 *
 *  Created on: Dec 3, 2015
 *      Author: Klonowski
 */

#ifndef TRIGGER_H_
#define TRIGGER_H_


#include <string>
#include <stdio.h>
#include <iostream>
#include <map>
#include <vector>
#include "../rapidxml-1.13/rapidxml.hpp"

using namespace std;
using namespace rapidxml;

class Trigger {
public:

	string type;
	string print;
	string command;
	string status;
	string owner;
	string name;//set equal to the object
	map<string, string> conditions;
	Trigger(xml_node<> *);
	virtual ~Trigger();

private:
	void createTrigger(xml_node<> *);
	void createCondition(xml_node<> *);

};

#endif /* TRIGGER_H_ */
