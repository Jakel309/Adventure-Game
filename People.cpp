//
//  People.cpp
//  
//
//  Created by Jackson Sorrells on 10/21/13.
//
//

#include "adventure.h"

People::People(std::string _name, Room* _room):Basic(_name){ //Initializes people with name and x,y-coordinates, and list of commands
    inRoom = _room;
}

People::~People(){
}

void People::setPosition(Room* roomToSet){
    inRoom = roomToSet;
}

Room* People::getRoom() const{
    return inRoom;
}

Player::Player(std::string _name, Room* _room):People(_name, _room){
    numItems = 0;
}

Player::~Player(){
}

void Player::addItem(Item *item){
	inventory.push_back(item);
}

void Player::removeItem(Item *item){
	inventory.remove(item);
}

Item* Player::getItem(std::string name){
    for(std::list<Item*>::iterator it=inventory.begin(); it!=inventory.end(); ++it)
		if((*it)->getName()==name)
			return *it;
}

bool Player::hasWeapon(){
    for(std::list<Item*>::iterator it=inventory.begin(); it!=inventory.end(); ++it){
		if(((it*)->getItemType())=="Weapon"){
			return true;
		}
	}
    return false;
}

NPC::NPC(std::string _name, Room* _room, bool _kill, bool _mega):People(_name, _room){
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
