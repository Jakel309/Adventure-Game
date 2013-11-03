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

void Item::setItemType(std::string type){
	itemType=type;
}

Weapon::Weapon(std::string _name, bool pickup, std::string desc, int dur, bool ultimate):Item(_name, pickup, desc){
    durability = dur;
    ultimate = ultimate;
	setItemType("Weapon");
}

Weapon::~Weapon(){ //Deconstructor.
}

int Weapon::getDurability() const{ //Returns the durability.
    return durability;
}

void Weapon::changeDurability(int i){ //Changes durability to passed value.
    durability = i;
}

ActionObject::ActionObject(std::string _name, bool pickup, std::string desc, std::string _effect):Item(_name, pickup, desc){
    effect = _effect;
	setItemType("ActionObject");
}

ActionObject::~ActionObject(){
    
}

std::string ActionObject::getEffect() const{
    return effect;
}

