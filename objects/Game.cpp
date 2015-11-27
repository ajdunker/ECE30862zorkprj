/*
 * Game.cpp
 *
 *  Created on: Nov 26, 2015
 *      Author: adunk
 */

#include "Game.h"

Game::Game(string filename) {
	Game& game = *this;
	try {
		gameReady = loadXML(filename);
	} catch (int error) {
		cout << "Error parsing the XML." << endl;
	}
}

Game::~Game() {
	// TODO Auto-generated destructor stub
}

bool Game::loadXML(string filename) {
	xml_document<> doc;
	xml_node<> * root_node;
	// Read the xml file into a vector
	ifstream theFile (filename.c_str());
	if (!theFile.is_open()) {
		cout << "Error in opening file. Exiting now." << endl;
		return false;
	}
	vector<char> buffer((istreambuf_iterator<char>(theFile)), istreambuf_iterator<char>());
	buffer.push_back('\0');
	// Parse the buffer using the xml file parsing library into doc
	doc.parse<0>(&buffer[0]);
	root_node = doc.first_node();
	queue<xml_node<> *> rooms_xml;
	xml_node<> * node = root_node->first_node();
	splitXML(node, rooms_xml);

	//Add the rooms to the game
	Room * newRoom;
	while ((rooms_xml.size()) != 0) {
		newRoom = new Room(rooms_xml.front());
		rooms[newRoom->name] = newRoom;
		rooms_xml.pop();
	}
	return true;
}

void Game::splitXML(xml_node<> * node, queue<xml_node<> *>& rooms_xml) {
	while (node != NULL) {
		if (string((node->name())) == string("room")) {
			rooms_xml.push(node);
		}
		node = node->next_sibling();
	}
}

void Game::startGame() {
	//Always start at entrance
	currentRoom = "Entrance";
	cout << rooms.find(currentRoom)->second->description << endl;
	while(true) {
		cout << "What would you like to do?" << endl;
		getline(cin, input);
		if (input == "") {
			cout << "Please input a non-blank command:" << endl;
			continue;
		}
		doCommand(input);
		input = "";
	}
}

void Game::doCommand(string input) {

	if (input == "n" || input == "e" || input == "s" || input == "w") {
		moveRoom(input);
	} else if (input == "quit") {
		exit(EXIT_SUCCESS);
	} else {
		cout << "Command not recognized." << endl;
	}
}

void Game::moveRoom(string direction) {
	Room * curPtRoom = rooms.find(currentRoom)->second;
	string dir = "";
	string moveTo = "";

	if (direction == "n") {
		dir = "north";
	} else if (direction == "e") {
		dir = "east";
	} else if (direction == "s") {
		dir = "south";
	} else if (direction == "w") {
		dir = "west";
	}

	if(curPtRoom->borders.count(dir) > 0) {
		moveTo = (curPtRoom->borders.find(dir)->second);
		currentRoom = moveTo;
		cout << rooms.find(currentRoom)->second->description << endl;
	} else {
		cout << "Can't go that way." << endl;
	}
}
