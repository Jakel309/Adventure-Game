#include <iostream>
#include "adventure.h"
using namespace std;

int main(){
    //Room 1
	List<string> room1Commands;
	initialize(room1Commands);
    string command = "Pickup";
	append(room1Commands, command);
    command = "North";
	append(room1Commands,command);
	string desc="You are in the entrance of a dark cave. There is nothing behind you, so you can only go forward, north. There is a sword on the ground.";
    List<Weapon> room1Weapons;
    initialize(room1Weapons);
    Weapon basicSword("Basic Sword", true, "A basic sword.", "Weapon", 2, false);
    append(room1Weapons, basicSword);
    List<ActionObject> room1ActionObjects;
    initialize(room1ActionObjects);
	Room room1 ("Starting Room", room1Commands, desc, room1Weapons, room1ActionObjects);
    
    //Room 2
    List<string> room2Commands;
	initialize(room2Commands);
    command = "Pickup";
	append(room2Commands,command);
    command = "North";
	append(room2Commands,command);
    command = "East";
    append(room2Commands,command);
    command = "West";
    append(room2Commands,command);
    command = "South";
    append(room2Commands,command);
    desc="You enter the next room, and immeaditely see a partiularly delicionus looking ham sandwich sitting on a table in the center. You see doors leading forwards, north, as well as to the west and east.";
    List<Weapon> room2Weapons;
    initialize(room2Weapons);
    List<ActionObject> room2ActionObjects;
    initialize(room2ActionObjects);
    ActionObject hamSandwich("Ham Sandwich", true,  "A super delicious looking ham sandwich. Mustard too!", "ActionObject", "You feel turbo refreshed!!");
    append(room2ActionObjects, hamSandwich);
	Room room2 ("Ham Room", room2Commands, desc, room2Weapons, room2ActionObjects);
    
    //Room 3
    List<string> room3Commands;
	initialize(room3Commands);
    command = "Pickup";
	append(room3Commands,command);
    command = "East";
	append(room3Commands,command);
	desc="You walk into the room, and see a particularly large menacing looking sword hanging above the incredibly out of place fireplace mantle on the cave wall. Aside from the door leading out behind you to the east, the room is bare.";
    List<Weapon> room3Weapons;
    initialize(room3Weapons);
    Weapon ultimateSword("Ultimate Sword", true, "The biggest, cutest, most deadly sword you have ever seen.", "Weapon", 0, true);
    append(room3Weapons, ultimateSword);
    List<ActionObject> room3ActionObjects;
    initialize(room3ActionObjects);
	Room room3 ("Ultimate Room", room3Commands, desc, room3Weapons, room3ActionObjects);
    
    //Room 4
    List<string> room4Commands;
	initialize(room4Commands);
    command = "Pickup";
	append(room4Commands,command);
    command = "West";
	append(room4Commands,command);
	desc="You walk into a room and immeaditely notice the lucious shag carpeting. Also quite noticeable is the large scary-looking dragon standing in the middle of the room. The dragon appears to be wearing an ornate key  held around his neck by an old welcome week lanyard.";
    List<Weapon> room4Weapons;
    initialize(room4Weapons);
    List<ActionObject> room4ActionObjects;
    initialize(room4ActionObjects);
    ActionObject key("Gold Key", true, "This key is crazy awesome.", "ActionObject", "Opens door");
    append(room4ActionObjects, key);
	Room room4 ("Dragon Room", room4Commands, desc, room4Weapons, room4ActionObjects);
    
    //Room 5
    List<string> room5Commands;
	initialize(room5Commands);
    command = "Pickup";
	append(room5Commands,command);
    command = "North";
	append(room5Commands,command);
    command = "South";
    append(room5Commands,command);
	desc="You walk into another room. You first see a large gross looking monster. Behind the monster is a door with a rather ornate looking lock.";
    List<Weapon> room5Weapons;
    initialize(room5Weapons);
    List<ActionObject> room5ActionObjects;
    initialize(room5ActionObjects);
    ActionObject door("Door", false, "A large door with a gold lock in the direct center.", "ActionObject", "Opens");
    append(room5ActionObjects, door);
	Room room5 ("Door Room", room5Commands, desc, room5Weapons, room5ActionObjects);
    
    //Room 6
    List<string> room6Commands;
	initialize(room6Commands);
	desc="You walk into a room with a large treasure chest in the middle. The top is off and golden dubloons overflow from the top. Whoever decided to store all of the gold here clearly didn't get a big enough chest.";
    List<Weapon> room6Weapons;
    initialize(room6Weapons);
    List<ActionObject> room6ActionObjects;
    initialize(room6ActionObjects);
	Room room6("Tresure Room", room6Commands, desc, room6Weapons, room6ActionObjects);
    
    //Creating a list of monsters.
    List<NPC> monsters;
    initialize(monsters);
    string dragonCommands [0];
    NPC dragon("Dragon", room4, dragonCommands, true, true);
    append(monsters, dragon);
    string monsterCommands [0];
    NPC skeleton("Skeleton", room5, monsterCommands, true, false);
    append(monsters, skeleton);
    
    //Create a player.
    string userCommands [4] = {"Use", "Eat", "Inspect", "Inventory"};
    Player user("Jon", room1, userCommands);
    
    //Directions are going to be last.
    room1.northRoom(room2);
    room2.northRoom(room5);
    room2.eastRoom(room4);
    room2.westRoom(room3);
    room2.southRoom(room1);
    room3.eastRoom(room2);
    room4.westRoom(room3);
    room5.northRoom(room6);
    room5.southRoom(room2);
    
    //Game loop
    while(true){
        user.getRoom()->descriptionOfRoom();
        
        
    }
}