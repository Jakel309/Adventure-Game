//The following is created by Justin Foley and Jack Sorrells
#include <iostream>

class Level{
public:
	Level(int x, int y){}//Initializes with the size of the grid of the map
	~Level();//Deconstructor
	//void addRooms(Room *room);//Add room to rooms array
	//Room getRoom(int x, int y);//Get room according to x,y-coordinates
private:
	//Room **roomsX;//Array of rooms according to x coordinate
	//Room **roomsY;//Array of rooms according to y coordinate
};

class Room{
public:
	Room(int _xCoord, int _yCoord, string *_commands, string desc);//Initialize room with the x,y-coordinates, a list of commands, and the description of the room
	~Room();//Deallocates memory
	void addItem(Item *item);//Adds an item to items array
	void removeItem(Item *item);//Removes an item from items array
	void updateDesc(string desc);//Changes description of room
	void addCommand(string com);//Adds a command from commands array
	void removeCommand(string com);//Removes a command from commands array
	void visit();//Changes the visited variable to true
	void itemsInRoom() const;//Prints items in room
	void commandsAvailable() const;//Prints commands available in room
	void descriptionOfRoom() const;//Prints description of the room
	bool ifVisited() const;//Checks to see if room is visited
	Room westRoom() const;//Gets west room
	Room northRoom() const;//Gets north room
	Room eastRoom() const;//Gets east room
	Room southRoom() const;//Gets south room
	void westRoom(Room *room);//Sets west room
	void northRoom(Room *room);//Sets north room
	void southRoom(Room *room);//Sets south room
	void eastRoom(Room *room);//Sets east room
private:
	Item **items;//List of items in room
	string *commands;//List of commands
	string description;//Description of room
	bool visited;//Variable to determine if room has been visited
	Room **westRoom;
	Room **northRoom;
	Room **southRoom;
	Room **eastRoom;
};

class Item{
public:
	Item(string _name, bool pickup, string desc);//Initializes item with the name, whether it can be picked up, and it's description
	~Item();//Deconstructor
	string getName() const;//Gets name
	string getDescription() const;//Gets description
private:
	string name;//Name of item
	string description;//Description of item
	bool canPickUp;//Variable to determine if item can be picked up
	Item **canInteractWith;//List of items this item can interact with
}

class People{
public:
	People(string _name, Room *_room, string *_commands);//Initializes people with name and x,y-coordinates, and list of commands
	~People();//Deconstructor
	void setPosition(int x, int y);//Set position
	string getName() const;//Gets name
	void getCommands() const;//Prints commands available
private:
	Room **inRoom;
	string name;//Name of people
	int xCoord;//X position
	int yCoord;//Y position
	string *commands;//List of commands available
}

class Player: public People{
public:
	Player(string _name, Room *_room, string *_commands);//Initializes with name of player, x,y-coordinates, and list of commands available to player
	~Player();//Deconstructor
	void addItem(Item *newItem);//Adds item to inventory
	void removeItem(Item *toRemove);//Removes item from inventory
private:
	Item **inventory;//List of items in inventory
}

class NPC:public People{
public:
	NPC(string _name, Room *_room, string *_commands, bool _kill);//Initializes with name of enemy, x,y-coordinates, list of commands available, and if it kills when encountered
	~NPC();//Deconstructor
	bool ifKill() const;//Checks if the NPC kills
	void changeKill(bool _kill);//Changes if NPC kills
private:
	bool kill;//Variable to see if enemy kills
}