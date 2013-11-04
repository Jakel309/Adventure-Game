//
//  Item.cpp
//  
//
//  Created by Jackson Sorrells on 10/21/13.
//
//

#include "adventure.h"

Item::Item(std::string _name, bool pickup, std::string desc):Basic(_name){ //Initializes the item with the name, whether or not it can be picked up, as well as it's decription.
    description = desc;
    canPickUp = pickup;
}

Item::~Item(){ //Deconstructor
}

std::string Item::getDescription() const{ //Returns the description.
    return description;
}

std::string Item::getItemType() const{
	return itemType;
}

bool Item::pickUp() const{
	return canPickUp;
}

void Item::setItemType(std::string type){
	itemType=type;
}

void Item::setDur(int i){
	durability=i;
}

Weapon::Weapon(std::string _name, bool pickup, std::string desc, int dur, bool _ultimate):Item(_name, pickup, desc){
    setDur(dur);
    ultimate = _ultimate;
	setItemType("Weapon");
}

Weapon::~Weapon(){ //Deconstructor.
}

int Item::getDurability() const{ //Returns the durability.
    return durability;
}

void Item::changeDurability(int i){ //Changes durability to passed value.
    durability += i;
}

ActionObject::ActionObject(std::string _name, bool pickup, std::string desc, std::string _effect):Item(_name, pickup, desc){
    effect = _effect;
	setItemType("ActionObject");
	opensRoom=NULL;
}

ActionObject::~ActionObject(){
    
}

std::string Item::getEffect() const{
    return effect;
}

void Item::addInteractWith(Item *item){
	canInteractWith.push_back(item);
}

bool Item::doesInteract(Item *item){
	for(std::list<Item*>::iterator it=canInteractWith.begin(); it!=canInteractWith.end(); ++it)
		if((*it)==item)
			return true;
	return false;
}

void Item::removeInteractWith(Item *item){
	canInteractWith.remove(item);
}

Room* Item::openRoom() const{
	return opensRoom;
}

void Item::setOpenRoom(Room* room){
	opensRoom=room;
}