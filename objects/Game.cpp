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
	queue<xml_node<> *> items_xml;
	queue<xml_node<> *> triggers_xml;
	queue<xml_node<> *> containers_xml;
	queue<xml_node<> *> creatures_xml;
	xml_node<> * node = root_node->first_node();


	splitXML(node, rooms_xml, items_xml, triggers_xml, containers_xml, creatures_xml);

	//Add the rooms to the game
	Item * newItem;
	Room * newRoom;
	Trigger * newTrigger;

	while ((items_xml.size()) != 0) {
		newItem = new Item(items_xml.front());
		items[newItem->name] = newItem;
		items_xml.pop();
	}
	while ((triggers_xml.size()) != 0) {
		newTrigger = new Trigger(triggers_xml.front());
		triggers[newTrigger->name] = newTrigger;
		triggers_xml.pop();
	}

	while ((rooms_xml.size()) != 0) {
		newRoom = new Room(rooms_xml.front());
		rooms[newRoom->name] = newRoom;
		rooms_xml.pop();
	}

	return true;
}

void Game::splitXML(xml_node<> * node, queue<xml_node<> *>& rooms_xml, queue<xml_node<> *>& items_xml, queue<xml_node<> *>& triggers_xml, queue<xml_node<> *>& containers_xml, queue<xml_node<> *>& creatures_xml) {
	while (node != NULL) {
		if (string((node->name())) == string("room")) {
			rooms_xml.push(node);
		}
		else if (string((node->name())) == string("item")) {
			items_xml.push(node);
		}
		else if (string((node->name())) == string("trigger")){
			triggers_xml.push(node);
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

		//check triggers



		doCommand(input);
		input = "";
	}
}

void Game::doCommand(string input) {

	  // construct a stream from the string
	  stringstream strstr(input);

	  // use stream iterators to copy the stream to the vector as whitespace separated strings
	  istream_iterator<string> it(strstr);
	  istream_iterator<string> end;
	  vector<string> results(it, end);


	if (input == "n" || input == "e" || input == "s" || input == "w") {
		moveRoom(input);
	} else if (input == "quit") {
		exit(EXIT_SUCCESS);
	} else if (input == "i") {
		printInventory();
	} else if (results[0] == "take") {
		takeItem(results[1]);
	} else if (results[0] == "open") {
		//open container
	} else if (results[0] == "read") {
		//read writing on item
	} else if (results[0] == "drop") {
		//drop item fron inventory
	} else if (results[0] == "put") {
		//put item in container
	} else if (results[0] == "turn") {
		//turns on an item
	} else if (results[0] == "attack") {
		//attacks creature with item
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
void Game::takeItem(string new_item){
	Room * curPtRoom = rooms.find(currentRoom)->second;
	if (curPtRoom->items.count(new_item) > 0){
		inventory[new_item] = new_item;
		curPtRoom->items.erase(new_item);
		cout << new_item << " has been added to your inventory"<<endl;
	}
	else{
		cout <<"Cannot take "<< new_item << endl;
	}
}

void Game::printInventory()
{
	if( inventory.empty() ){
		cout<<"There is nothing in your inventory" << endl;
	}
	else {

		for(map<string,string>::iterator cnt = inventory.begin(); cnt != inventory.end(); cnt++){
			cout<<cnt->second<<", ";
		}
		cout <<endl;
	}

}
