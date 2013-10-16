//The following is created by Justin Foley and Jack Sorrells
#include <iostream>

class Level{
public:
	Level(){}
	~Level();
	void addRooms(Room *room);
private:
	Rooms **rooms;//Array of rooms
};

class Room{
public:
	Room(int xCoord, int yCoord, string *_commands, string desc);
	~Room();
	void addItem(Item item);
	void moveItem(Item item);
	void addDoors(int x, int y);
	void removeDoors(int x, int y);
	void updateDesc(string desc);
	void addCommand(string com);
	void removeCommand(string com);
	void visited();
	string itemsInRoom();
	string commandsAvailable();
	string descriptionOfRoom();
	bool ifVisited();

private:
	int position[2];//Position of room in the level
	Item *items;//List of items in room
	int *doors;//List of coordinates that point to where the player can go
	string *commands;//List of commands
	string description;//Description of room
	bool visited;
};