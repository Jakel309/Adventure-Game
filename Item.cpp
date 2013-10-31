//
//  Item.cpp
//  
//
//  Created by Jackson Sorrells on 10/21/13.
//
//

#include "adventure.h"

Item::Item(std::string _name, bool pickup, std::string desc, std::string _itemType):Basic(_name){ //Initializes the item with the name, whether or not it can be picked up, as well as it's decription.
    description = desc;
    canPickUp = pickup;
    itemType = _itemType;
}

Item::~Item(){ //Deconstructor
}

std::string Item::getDescription() const{ //Returns the description.
    return description;
}

Weapon::Weapon(std::string _name, bool pickup, std::string desc, std::string itemType, int dur, bool ultimate):Item(_name, pickup, desc, itemType){
    durability = dur;
    ultimate = ultimate;
}

Weapon::~Weapon(){ //Deconstructor.
    
}

int Weapon::getDurability() const{ //Returns the durability.
    return durability;
}

void Weapon::changeDurability(int i){ //Changes durability to passed value.
    durability = i;
}

ActionObject::ActionObject(std::string _name, bool pickup, std::string desc, std::string _itemType, std::string _effect):Item(_name, pickup, desc, _itemType){
    effect = _effect;
}

ActionObject::~ActionObject(){
    
}

std::string ActionObject::getEffect() const{
    return effect;
}

