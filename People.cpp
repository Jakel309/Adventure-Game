//
//  People.cpp
//  
//
//  Created by Jackson Sorrells on 10/21/13.
//
//

#include "adventure.h"

People::People(std::string _name, Room  _room, std::string * _commands):Basic(_name){ //Initializes people with name and x,y-coordinates, and list of commands
    inRoom = _room;
    commands = _commands;
}

People::~People(){
}

void People::setPosition(Room * roomToSet){
    inRoom = roomToSet;
}

std::string* People::getCommands() const{
    return commands;
}

Room* People::getRoom() const{
    return inRoom;
}

Player::Player(std::string _name, Room _room, std::string* _commands, bool _kill):People(_name, _room, _commands){
    numItems = 0;
    initialize(weapons);
    initialize(actionObjects);
}

Player::~Player(){
    destroy(weapons);
    destroy(actionObjects);
}

void Player::addWeapon(Weapon *_weapon){
	append(weapons,_weapon);
}

void Player::removeWeapon(Weapon *_weapon){
	for(int i=0; i<getSize(weapons); i++)
		if(getNth(weapons,i)==_weapon){
			removeNth(weapons,i);
			break;
		}
}

void Player::addActionObject(ActionObject *_actionObject){
	append(actionObjects,_actionObject);
}

void Player::removeActionObject(ActionObject *_actionObject){
	for(int i=0; i<getSize(actionObjects); i++)
		if(getNth(actionObjects,i)==_actionObject){
			removeNth(actionObjects,i);
			break;
		}
}

Item Player::getItem(Item *_item) const{
    for(int i=0; i<numItems; i++)
		if(getNth(inventory,i)==_item){
			return getNth(inventory, i);
		}
}

bool Player::hasWeapon() const{
    for(int i=0; i<numItems; i++)
		if(getNth(inventory,i).itemType=="Weapon"){
			return true;
		}
    return false;
}

NPC::NPC(std::string _name, Room  _room, std::string * _commands, bool _kill, bool _mega):People(_name, _room, _commands){
    kill = _kill;
    mega = _mega;
}

NPC::~NPC(){
    
}

bool NPC::ifKill() const{
    return kill;
}

void NPC::changeKill(bool _kill){
    kill = _kill;
}

bool NPC::isMega() const{
    return mega;
}
