//Definitions for the functions in Room class
#include <iostream>
#include "adventure.h"

Room::Room(std::string name, List<std::string> _commands, std::string desc, List<Weapon> _weapons, List<ActionObject> _actionObjects):Basic(name){
	initialize(commands);
	for(int i=0; i<getSize(_commands); i++)
		append(commands,getNth(_commands,i));
	description=desc;
	initialize(weapons);
    initialize(actionObjects);
	for(int i=0; i<getSize(_weapons); i++)
		append(weapons,getNth(_weapons,i));
    for(int i=0; i<getSize(_actionObjects); i++)
		append(actionObjects,getNth(_actionObjects,i));

	visited=false;
}

Room::~Room(){
	destroy(commands);
	for(int i=0; i<getSize(weapons); i++)
		~Weapon getNth(weapons,i);
	destroy(weapons);
    for(int i=0; i<getSize(actionObjects); i++)
		~ActionObject getNth(actionObjects,i);
	destroy(actionObjects);
}

//void Room::addItem(Item *item){
//	append(items,item);
//}
//
//void Room::removeItem(Item *item){
//	for(int i=0; i<getSize(items); i++)
//		if(getNth(items,i)==item){
//			removeNth(items,i);
//			break;
//		}
//}

void Room::addWeapon(Weapon *_weapon){
	append(weapons,_weapon);
}

void Room::removeWeapon(Weapon *_weapon){
	for(int i=0; i<getSize(weapons); i++)
		if(getNth(weapons,i)==_weapon){
			removeNth(weapons,i);
			break;
		}
}

void Room::addActionObject(ActionObject *_actionObject){
	append(actionObjects,_actionObject);
}

void Room::removeActionObject(ActionObject *_actionObject){
	for(int i=0; i<getSize(actionObjects); i++)
		if(getNth(actionObjects,i)==_actionObject){
			removeNth(actionObjects,i);
			break;
		}
}

void Room::updateDesc(std::string desc){
	description=desc;
}

void Room::addCommand(std::string com){
	append(commands,com);
}

void Room::removeCommand(std::string com){
	for(int i=0; i<getSize(commands); i++)
		if(getNth(commands,i)==com){
			removeNth(commands,i);
			break;
		}
}

void Room::visit(){
	visited=true;
}

void Room::itemsInRoom() const{
	for(int i=0; i<getSize(items); i++)
		std::cout<<getNth(items,i)<<std::endl;
}

void Room::commandsAvailable() const{
	for(int i=0; i<getSize(commands); i++)
		std::cout<<getNth(commands,i)<<std::endl;
}

void Room::descriptionOfRoom() const{
	std::cout<<description<<std::endl;
}

bool Room::ifVisited() const{
	return visited;
}

Room Room::westRoom() const{
	return *pWestRoom;
}

Room Room::northRoom() const{
	return *pNorthRoom;
}
Room Room::eastRoom() const{
	return *pEastRoom;
}

Room Room::southRoom() const{
	return *pSouthRoom;
}

void Room::westRoom(Room room){
	pWestRoom=room;
}

void Room::northRoom(Room room){
	pNorthRoom=room;
}

void Room::southRoom(Room room){
	pSouthRoom=room;
}

void Room::eastRoom(Room room){
	pEastRoom=room;
}