/*
 * Item.cpp
 *
 *  Created on: Nov 25, 2015
 *      Author: jklonows
 */

#include "Item.h"

Item::Item(xml_node<> * ItemNode) {
	createItem(ItemNode);
}

Item::~Item() {

}

void Item::createItem(xml_node<> * childNode) {

}
