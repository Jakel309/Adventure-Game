//The following is created by Justin Foley and Jack Sorrells
#include <iostream>

class Level{
public:
	Level(int x, int y){}//Initializes with the size of the grid of the map
	~Level();//Deconstructor
	void addRooms(Room *room);//Add room to rooms array
	Room getRoom(int x, int y);//Get room according to x,y-coordinates
private:
	Room **roomsX;//Array of rooms according to x coordinate
	Room **roomsY;//Array of rooms according to y coordinate
};

class Room{
public:
	Room(int _xCoord, int _yCoord, string *_commands, string desc);//Initialize room with the x,y-coordinates, a list of commands, and the description of the room
	~Room();//Deallocates memory
	void addItem(Item item);//Adds an item to items array
	void removeItem(Item item);//Removes an item from items array
	void addDoors(int x, int y);//Adds a door to doors array
	void removeDoors(int x, int y);//Removes a door from doors array
	void updateDesc(string desc);//Changes description of room
	void addCommand(string com);//Adds a command from commands array
	void removeCommand(string com);//Removes a command from commands array
	void visit();//Changes the visited variable to true
	void itemsInRoom() const;//Prints items in room
	void commandsAvailable() const;//Prints commands available in room
	void descriptionOfRoom() const;//Prints description of the room
	bool ifVisited() const;//Checks to see if room is visited
	int getXCoord() const;//Gets x-coordinate
	int getYCoord() const;//Gets y-coordinate
private:
	int xCoord;//Position of room in the level according to x coordinate
	int yCoord;//Position of room in the level according to y coordinate
	Item **items;//List of items in room
	int *doorsX;//List of x-coordinates that point to where the player can go
	int *doorsY;//List of y-coordinates that point to where the player can go
	string *commands;//List of commands
	string description;//Description of room
	bool visited;//Variable to determine if room has been visited
};

class Item(){
public:
	Item(string _name, bool pickup, string desc);//Initializes item with the name, whether it can be picked up, and it's description
	~Item();//Deconstructor
	string getName() const;//Gets name
	void setName(string name);//Sets name
	string getDescription() const;//Gets description
	void setDescription(string desc);//Sets description
	void InteractWith(Item *toInteract);//Adds item to list of items this item can interact with
private:
	string name;//Name of item
	string description;//Description of item
	bool canPickUp;//Variable to determine if item can be picked up
	Item **canInteractWith;//List of items this item can interact with
}

class People(){
public:
	People(string _name, int x, int y, string *_commands);//Initializes people with name and x,y-coordinates, and list of commands
	~People();//Deconstructor
	int getXCoord() const;//Gets x-coordinate
	int getYCoord() const;//Gets y-coordinate
	void setPosition(int x, int y);//Set position
	string getName() const;//Gets name
	void setName(string name);//Sets name
	void getCommands() const;//Prints commands available
private:
	string name;//Name of people
	int xCoord;//X position
	int yCoord;//Y position
	string *commands;//List of commands available
}

class Player: public People(){
public:
	Player(string _name, int x, int y, string *_commands);//Initializes with name of player, x,y-coordinates, and list of commands available to player
	~Player();//Deconstructor
	void addItem(Item *newItem);//Adds item to inventory
	void removeItem(Item *toRemove);//Removes item from inventory
private:
	Item **inventory;//List of items in inventory
}

class NPC:public People(){
public:
	NPC(string _name, int x, int y, string *_commands, bool _kill);//Initializes with name of enemy, x,y-coordinates, list of commands available, and if it kills when encountered
	~NPC();//Deconstructor
	bool ifKill() const;//Checks if the NPC kills
	void changeKill(bool _kill);//Changes if enemy kills
private:
	bool kill;//Variable to see if enemy kills
}