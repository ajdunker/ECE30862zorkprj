/*
 * Game.h
 *
 *  Created on: Nov 26, 2015
 *      Author: adunk
 */

#ifndef OBJECTS_Game_H_
#define OBJECTS_Game_H_

#include <string>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iterator>
#include <vector>
#include <map>
#include <queue>
#include "Room.h"
#include "Item.h"
#include "Trigger.h"
#include "Container.h"
#include "../rapidxml-1.13/rapidxml.hpp"

using namespace std;
using namespace rapidxml;

class Game {
public:

	map<string, Room*> rooms;
	map<string, Item*> items;
	map<string, string> inventory;
	map<string, Container*> containers;

	Game(string);
	Game(Game&);
	virtual ~Game();
	void startGame();

	string currentRoom = "";
	string input = "";
	bool gameReady = false;

private:
	bool loadXML(string filename);
	void splitXML(xml_node<> *, queue<xml_node<> *>&, queue<xml_node<> *>&, queue<xml_node<> *>&, queue<xml_node<> *>&);
	void doCommand(string);
	void moveRoom(string);
	void takeItem(string);
	void printInventory();
	void printInventory(string);
	void dropInventory(string);
	void addObject(string,string);
	void openContainer(string);
	void deleteWidget(string);
	void addWidget(string, string);
	void putItem(string, string);

};

#endif /* OBJECTS_Game_H_ */
