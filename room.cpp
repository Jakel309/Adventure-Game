//Definitions for the functions in Room class
#include <iostream>
#include "adventure.h"

Room::Room(std::string name, List<std::string> _commands, std::string desc, List<Item*> _items):Basic(name){
	initialize(commands);
	for(int i=0; i<getSize(_commands); i++)
		append(commands,getNth(_commands,i));
	description=desc;
	initialize(items);
	for(int i=0; i<getSize(_items); i++)
		append(items,getNth(_items,i));
	visited=false;
}

Room::~Room(){
	destroy(commands);
	for(int i=0; i<getSize(items); i++)
		delete getNth(items,i);
	destroy(items);
}

void Room::addItem(Item *item){
	append(items,item);
}

void Room::removeItem(Item *item){
	for(int i=0; i<getSize(items); i++)
		if(getNth(items,i)==item){
			removeNth(items,i);
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

void Room::westRoom(Room *room){
	pWestRoom=room;
}

void Room::northRoom(Room *room){
	pNorthRoom=room;
}

void Room::southRoom(Room *room){
	pSouthRoom=room;
}

void Room::eastRoom(Room *room){
	pEastRoom=room;
}