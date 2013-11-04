//Definitions for the functions in Room class
#include "adventure.h"

Room::Room(std::string _name, std::string desc):Basic(_name){
	description=desc;
	visited=false;
	pWestRoom=NULL;
	pNorthRoom=NULL;
	pEastRoom=NULL;
	pSouthRoom=NULL;
}

Room::~Room(){
}

void Room::addItem(Item *item){
	items.push_back(item);
}

void Room::removeItem(Item *item){
	items.remove(item);
}

void Room::updateDesc(std::string desc){
	description=desc;
}

void Room::visit(){
	visited=true;
}

void Room::itemsInRoom(){
	std::cout<<"This room contains:"<<std::endl;
	for(std::list<Item*>::iterator it=items.begin(); it!=items.end(); ++it)
		std::cout<<(*it)->getName()<<std::endl;
}

Item* Room::getItem(std::string _name){
    for(std::list<Item*>::iterator it=items.begin(); it!=items.end(); ++it)
		if((*it)->getName()==_name)
			return *it;
	return NULL;
}

std::list<Item*> Room::itemsList(){
	return items;
}

void Room::descriptionOfRoom() const{
	std::cout<<description<<std::endl;
}

bool Room::ifVisited() const{
	return visited;
}

Room* Room::westRoom() const{
	return pWestRoom;
}

Room* Room::northRoom() const{
	return pNorthRoom;
}
Room* Room::eastRoom() const{
	return pEastRoom;
}

Room* Room::southRoom() const{
	return pSouthRoom;
}

void Room::westRoom(Room* room){
	pWestRoom=room;
}

void Room::northRoom(Room* room){
	pNorthRoom=room;
}

void Room::southRoom(Room* room){
	pSouthRoom=room;
}

void Room::eastRoom(Room* room){
	pEastRoom=room;
}