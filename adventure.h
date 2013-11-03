//The following is created by Justin Foley and Jack Sorrells
#include <iostream>
#include <list>

class Basic{
public:
	Basic(std::string _name):name(_name){}//Initializes with the name of object
	virtual ~Basic(){}//Deconstructor
	std::string getName(){return name;}//returns name of object
private:
	std::string name;
};

class Item:public Basic{
public:
	Item(std::string _name, bool pickup, std::string desc);//Initializes item with the name, whether it can be picked up, and it's description
	virtual ~Item();//Deconstructor
	std::string getDescription() const;//Gets description
	std::string getItemType() const;
protected:
	void setItemType(std::string type);
private:
	std::string description;//Description of item
	bool canPickUp;//Variable to determine if item can be picked up
	std::string itemType;
};

class Weapon:public Item{
public:
	Weapon(std::string _name, bool pickup, std::string desc, int dur, bool ultimate);//Initializes weapon with name, whether it can be picked up, its description, its durability, and if it is the ultimate weapon
	~Weapon();//Destructor
	int getDurability() const;//Gets durability
	void changeDurability(int i);//Changes durability
	bool isUltimate() const;//Checks if weapon is ultimate
private:
	int durability;//Durability of weapon
	bool ultimate;//Value for if weapon is ultimate weapon
};

class ActionObject:public Item{
public:
	ActionObject(std::string _name, bool pickup, std::string desc, std::string _effect);//Initializes an action object with name, whether it can be picked up, its description, and its effect
	~ActionObject();//Destructor
	std::string getEffect() const;//Gets effect
	void addInteractWith(Item &item);//Adds an object it can interact with
	bool doesInteract(Item &item) const;//Checks if object can interact with another
	void removeInteractWith(Item &item);//Removes one of the objects this object can interact with
private:
	std::string effect;//The effect of object
	std::list<Item*> canInteractWith;//List of items this item can interact with
};

class Room:public Basic{
public:
	Room(std::string name, std::string desc, std::list<Item*> _items);//Initialize room with the name, a list of commands, the description of the room, and a list of items in the room
	~Room();//Deallocates memory
	void addItem(Item *item);//Adds an item to items array
	void removeItem(Item *item);//Removes an item from items array
	void updateDesc(std::string desc);//Changes description of room
	void visit();//Changes the visited variable to true
	void itemsInRoom();//Prints items in room
	void descriptionOfRoom() const;//Prints description of the room
	bool ifVisited() const;//Checks to see if room is visited
	Room westRoom() const;//Gets west room
	Room northRoom() const;//Gets north room
	Room eastRoom() const;//Gets east room
	Room southRoom() const;//Gets south room
	void westRoom(Room* room);//Sets west room
	void northRoom(Room* room);//Sets north room
	void southRoom(Room* room);//Sets south room
	void eastRoom(Room* room);//Sets east room
private:
	int numItems;
	std::list<Item*> items;//List of items in room
	std::string description;//Description of room
	bool visited;//Variable to determine if room has been visited
	Room *pWestRoom;//Room to the west
	Room *pNorthRoom;//Room to the north
	Room *pSouthRoom;//Room to south
	Room *pEastRoom;//Room to east
};



class People:public Basic{
public:
	People(std::string _name, Room* _room);//Initializes people with name, room it's in, and list of commands
	virtual ~People();//Deconstructor
	void setPosition(Room* _room);//Set position
    Room* getRoom() const;//Gets room
private:
	Room* inRoom;//Pointer to what room the person is in
};

class Player: public People{
public:
	Player(std::string _name, Room* _room);//Initializes with name of player, room player is in, and list of commands available to player
	~Player();//Deconstructor
	void addItem(Item *item);//Adds item to inventory
	void removeItem(Item *item);//Removes item from inventory
	Item* getItem(std::string name);
	bool hasWeapon();//Checks for weapon
private:
	int numItems;//Number of items player has
	std::list<Item*> inventory;//List of items in inventory
};

class NPC:public People{
public:
	NPC(std::string _name, Room* _room, bool _kill, bool _mega);//Initializes with name of enemy, room enemy is in, list of commands available, if it kills when encountered, and if it is boss
	~NPC();//Deconstructor
	bool ifKill() const;//Checks if the NPC kills
	void changeKill(bool _kill);//Changes if NPC kills
	bool isMega() const;//Checks if monster is boss
private:
	bool kill;//Variable to see if enemy kills
	bool mega;//Boss checker variable
};