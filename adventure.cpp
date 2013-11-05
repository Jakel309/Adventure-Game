#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <list>
#include "adventure.h"
using namespace std;

int main(){
    //Random Rooms
	list<Room> randRooms;
	list<NPC*> monsters;
	for(int i=0; i<10; i++){
		int random=rand()%3;
		//Create monster room if random number is 1
		if(random==1){
			string desc="You enter a rather eery room";
			Room ranRoom("Random Room: Monster Room", desc);
			randRooms.push_back(ranRoom);
			NPC ranMons("Giant Spider", &ranRoom, true, false);
			monsters.push_back(&ranMons);
		}else if(random==2){
			string desc="You enter a rather bright room for being in a cave.";
			Room ranRoom("Random Room: Item Room", desc);
			randRooms.push_back(ranRoom);
			int random2=rand()%2;
			if(random2==1){
				Weapon weapon("Sword", true, "A low quality sword", 3, false);
				ranRoom.addItem(&weapon);
			}else{
				ActionObject actionObject("Dirty cheese", true, "A piece of dirty cheese.", "Eat");
				ranRoom.addItem(&actionObject);
			}
		}else{
			string desc="You enter a rather dull room";
			Room ranRoom("Random Room: Empty Room", desc);
			randRooms.push_back(ranRoom);
		}
	}
	Room ranRoom1=randRooms.front();
	randRooms.pop_front();
	Room ranRoom2=randRooms.front();
	randRooms.pop_front();
	Room ranRoom3=randRooms.front();
	randRooms.pop_front();
	Room ranRoom4=randRooms.front();
	randRooms.pop_front();
	Room ranRoom5=randRooms.front();
	randRooms.pop_front();
	Room ranRoom6=randRooms.front();
	randRooms.pop_front();
	Room ranRoom7=randRooms.front();
	randRooms.pop_front();
	Room ranRoom8=randRooms.front();
	randRooms.pop_front();
	Room ranRoom9=randRooms.front();
	randRooms.pop_front();
	Room ranRoom10=randRooms.front();
	randRooms.pop_front();
	//Starting Room
	string desc="You enter a dark cave.";
	Room startRoom("Starting Room", desc);
	Weapon basicSword("Basic Sword", true, "Your first sword; better find a new one soon.", 2, false);
	startRoom.addItem(&basicSword);
	//First Random Room
	startRoom.northRoom(&ranRoom1);
	ranRoom1.southRoom(&startRoom);
	//Second Random Room
	ranRoom1.eastRoom(&ranRoom2);
	//Third Random Room
	ranRoom1.westRoom(&ranRoom3);
	//Room with ultimate sword
	desc="A mighty power eminates from this room when you enter.";
	Room ultRoom("Ultimate Sword Room", desc);
	//Ultimate Sword
	Weapon ultSword("Ultimate Sword", true, "The almighty dragon slaying sword.", 0, true);
	ultRoom.addItem(&ultSword);
	ultRoom.northRoom(&ranRoom3);
	ranRoom3.southRoom(&ultRoom);
	//First Door Room
	desc="You enter a dark room";
	Room fDoorRoom("First Door Room", desc);
	ranRoom1.northRoom(&fDoorRoom);
	fDoorRoom.southRoom(&ranRoom1);
	//Fourth Random Room
	ranRoom4.southRoom(&fDoorRoom);
	//Door 1
	ActionObject door1("Metal Door",false, "A huge metal door that is locked.", "Opens South");
	door1.setOpenRoom(&ranRoom4);
	//Fifth Random Room
	fDoorRoom.westRoom(&ranRoom5);
	ranRoom5.eastRoom(&fDoorRoom);
	//End Room
	desc="You enter a magnificently decorated room. There is a huge treasure chest in the middle of the room and you smile prouldy as you have now found what you were looking for.";
	Room endRoom("Treasure Room", desc);
	//Door Two
	ActionObject door2("Golden Door", false, "A magnificent golden door", "Opens West");
	door2.setOpenRoom(&endRoom);
	ranRoom5.addItem(&door2);
	//Key Room For Door 1
	desc="A room with a pedestal in the center.";
	Room keyRoom("Key Room", desc);
	ActionObject key1("Metal Key", true, "A metal key that unlocks one door.", "Unlocks");
	key1.addInteractWith(&door1);
	keyRoom.addItem(&key1);
	//Sixth Random Room
	ranRoom4.eastRoom(&ranRoom6);
	ranRoom6.westRoom(&ranRoom4);
	//Seventh Random Room
	ranRoom6.eastRoom(&ranRoom7);
	ranRoom7.westRoom(&ranRoom6);
	//Good Weapon Room
	desc="A semi-decently decorated room";
	Room gWeapRoom("Good Weapon Room", desc);
	ranRoom7.southRoom(&gWeapRoom);
	gWeapRoom.northRoom(&ranRoom7);
	//Good Weapon
	Weapon goodWeapon("A Might Sword", true, "A pretty decent sword that will last a while.", 7, false);
	gWeapRoom.addItem(&goodWeapon);
	//Eight Random Room
	ranRoom7.northRoom(&ranRoom8);
	ranRoom8.southRoom(&ranRoom7);
	//Ninth Random Room
	ranRoom8.northRoom(&ranRoom9);
	ranRoom9.southRoom(&ranRoom8);
	//Tenth Random Room
	ranRoom9.westRoom(&ranRoom10);
	ranRoom10.eastRoom(&ranRoom9);
	//Dragon Room
	Room dragRoom("Dragon Room", "The room smells of ash and death.");
	//Key for Door 2
	ActionObject key2("Gold Key", true, "A golden key that unlocks an apparently impressive door.", "Unlocks");
	key2.addInteractWith(&door2);
	dragRoom.addItem(&key2);
	NPC dragon("Dragon", &dragRoom, true, true);
	monsters.push_back(&dragon);
	ranRoom6.northRoom(&dragRoom);
	dragRoom.southRoom(&ranRoom6);
	ranRoom10.southRoom(&dragRoom);
	dragRoom.northRoom(&ranRoom10);
	bool win=false;
	bool defeated=false;
	cout<<"Welcome to the cave of death.";
	cout<<"Within, you will most likely die, unless you are really lucky and the cave decides you can win the treasure, but that is quite unlikely."<<endl<<endl;
	cout<<"What is your name, ye who is about to die?"<<endl;
	for(int i=0; i<19; i++)
		cout<<endl;
	string name="Black";
	getline(cin,name);
	Player player(name, &startRoom);
	for(int i=0; i<50; i++)
		cout<<endl;
	player.getRoom()->descriptionOfRoom();
	player.getRoom()->itemsInRoom();
	while(true){
		if(player.getRoom()==&endRoom){
			win=true;
			break;
		}
		for(std::list<NPC*>::iterator it=monsters.begin(); it!=monsters.end(); ++it){
			if((*it)->getRoom()==player.getRoom()){
				cout<<"You are attacked by a "<<(*it)->getName()<<"!"<<endl;
				if(player.hasWeapon()){
					monsters.remove(*it);
					player.getWeapon()->changeDurability(-1);
					cout<<"You had an useful weapon, so you survived."<<endl;
					break;
				}else{
					defeated=true;
					break;
				}
			}
		}
		cout<<"What will you do?"<<endl;
		string input;
		getline(cin, input);
		if(input.find("North")!=string::npos){
			moveNorth(&player);
		}else if(input.find("East")!=string::npos){
			moveEast(&player);
		}else if(input.find("West")!=string::npos){
			moveWest(&player);
		}else if(input.find("South")!=string::npos){
			moveSouth(&player);
		}else if(input.find("Pick up")!=string::npos){
			pickUp(input,&player);
		}else if(input.find("Use")!=string::npos){
			use(input,&player);
		}else if(input.find("Help")!=string::npos){
			help();
		}else if(input.find("Eat")!=string::npos){
			eat(input,&player);
		}else if(input.find("Look")!=string::npos){
			look(&player);
		}else{
			cout<<"I don't recognize that command"<<endl;
		}
		if(defeated)
			break;
	}
	if(win)
		cout<<"Congratulations! The cave granted you the treasures within and you have survived!"<<endl;
	else
		cout<<"You were killed! What a surprise..."<<endl;
}