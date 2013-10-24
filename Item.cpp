//
//  Item.cpp
//  
//
//  Created by Jackson Sorrells on 10/21/13.
//
//

#include "adventure.h"

Item::Item(string _name, bool pickup, string desc){ //Initializes the item with the name, whether or not it can be picked up, as well as it's decription.
    name = _name;
    description = desc;
    canPickUp = pickup;
}

Item::~Item(){ //Deconstructor
}

string Item::getName() const{ //Returns the name.
    return name;
}

string Item::getDescription() const{ //Returns the description.
    return description;
}

Weapon::Weapon(string _name, bool pickup, string desc, int dur, bool ultimate){
    durability = dur;
    ultimate = ultimate;
}

Weapon::~Weapon(){ //Deconstructor.
    
}

int Weapon::getDurability(){ //Returns the durability.
    return durability;
}

void Weapon::changeDurability(int i){ //Changes durability to passed value.
    durability = i;
}

ActionObject::ActionObject(string _name, bool pickup, string desc, string _effect){
    effect = _effect;
}

ActionObject::~ActionObject(){
    
}

string ActionObject::getEffect(){
    return effect;
}

