#include <iostream>
#include "adventure.h"
using namespace std;

int main(){
	List<sting> room1Commands;
	initialize(room1Commands);
	append(room1Commands,"Pickup");
	append(room1Commands,"East");
	string desc="You are in the entrance of a dark cave. There is nothing behind you, so you can only go forward. There is a sword on the ground.";
	Room 1 ("Starting Room", room1Commands, desc,
}