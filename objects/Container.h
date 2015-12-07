/*
 * Container.h
 *
 *  Created on: Dec 6, 2015
 *      Author: Klonowski
 */

#ifndef CONTAINER_H_
#define CONTAINER_H_

#include <string>
#include <stdio.h>
#include <iostream>
#include <map>
#include <vector>
#include "trigger.h"
#include "../rapidxml-1.13/rapidxml.hpp"

using namespace std;
using namespace rapidxml;

class Container {
public:
	Container(xml_node<> *);
	virtual ~Container();

	map<string, string> items;
	string name;
	string status;
	string accept;
	map<string, Trigger*> triggers;

private:
	void createContainer(xml_node<> *);
};

#endif /* CONTAINER_H_ */
