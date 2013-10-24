//
//  People.cpp
//  
//
//  Created by Jackson Sorrells on 10/21/13.
//
//

#include "adventure.h"
#include "list.h"

People::People(string _name, Room * _room, string * _commands){ //Initializes people with name and x,y-coordinates, and list of commands
    name = _name;
    inRoom = _room;
    commands = _commands;
}

People::~People(){
    room = NULL;
    commands = NULL;
}

void People::setPosition(Room * roomToSet){
    inRoom = roomToSet;
}

string* People::getCommands() const{
    return commands;
}

Player::Player(string _name, Room* _room, string* _commands, bool _kill){
    numItems = 0;
    initialize(inventory);
}

Player::~Player(){
    destroy(inventory);
}

void Player::addItem(Item * newItem){
    add(newItem);
}

void Player::removeItem(Item * toRemove){
    for(int i=0; i<numItems; i++)
		if(getNth(inventory,i)==toRemove){
			removeNth(inventory,i);
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

NPC::NPC(string _name, Room * _room, string * _commands, bool _kill, bool _mega){
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
