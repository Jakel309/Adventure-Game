#include "adventure.h"

void moveNorth(Player* player){
	for(int i=0; i<50; i++)
		std::cout<<std::endl;
	if(player->getRoom()->northRoom()==NULL)
		std::cout<<"You can't go north"<<std::endl;
	else{
		player->setPosition((player->getRoom()->northRoom()));
		for(int i=0; i<50; i++)
			std::cout<<std::endl;
		player->getRoom()->descriptionOfRoom();
		for(int i=0; i<18; i++)
			std::cout<<std::endl;
	}
}
void moveSouth(Player* player){
	for(int i=0; i<50; i++)
		std::cout<<std::endl;
	if(player->getRoom()->southRoom()==NULL)
		std::cout<<"You can't go south"<<std::endl;
	else{
		player->setPosition((player->getRoom()->southRoom()));
		for(int i=0; i<50; i++)
			std::cout<<std::endl;
		player->getRoom()->descriptionOfRoom();
		for(int i=0; i<18; i++)
			std::cout<<std::endl;
	}
}
void moveEast(Player* player){
	for(int i=0; i<50; i++)
		std::cout<<std::endl;
	if(player->getRoom()->eastRoom()==NULL)
		std::cout<<"You can't go east"<<std::endl;
	else{
		player->setPosition((player->getRoom()->eastRoom()));
		for(int i=0; i<50; i++)
			std::cout<<std::endl;
		player->getRoom()->descriptionOfRoom();
		for(int i=0; i<18; i++)
			std::cout<<std::endl;
	}
}
void moveWest(Player* player){
	for(int i=0; i<50; i++)
		std::cout<<std::endl;
	if(player->getRoom()->westRoom()==NULL)
		std::cout<<"You can't go west"<<std::endl;
	else{
		player->setPosition((player->getRoom()->westRoom()));
		for(int i=0; i<50; i++)
			std::cout<<std::endl;
		player->getRoom()->descriptionOfRoom();
		for(int i=0; i<18; i++)
			std::cout<<std::endl;
	}
}
void use(std::string _input, Player* player){
	for(int i=0; i<50; i++)
		std::cout<<std::endl;
	std::string input=_input.erase(0,4);
	std::string iItem=input.substr(0,input.find("with")-1);
	std::string oItem=input.substr(6,input.size()-1);
	Item* item=player->getItem(iItem);
	Item* item2;
	std::list<Item*> items=player->getRoom()->itemsList();
	for(std::list<Item*>::iterator it=items.begin(); it!=items.end(); ++it)
		if((*it)->getName()==oItem){
			item2=*it;
			break;
		}else{
			std::cout<<"This item is not in the room"<<std::endl;
			return;
		}
	if(item==NULL)
		std::cout<<"You do not have that item"<<std::endl;
	else if(!item->doesInteract(item2)){
		std::cout<<"Nothing happened"<<std::endl;
	}else{
		if(item->getEffect()=="Unlocks"){
			if(item2->getEffect().find("West")!=std::string::npos){
				player->getRoom()->westRoom(item2->openRoom());
				player->removeItem(item2);
			}else if(item2->getEffect().find("North")!=std::string::npos){
				player->getRoom()->northRoom(item2->openRoom());
				player->removeItem(item2);
			}else if(item2->getEffect().find("South")!=std::string::npos){
				player->getRoom()->southRoom(item2->openRoom());
				player->removeItem(item2);
			}else{
				player->getRoom()->eastRoom(item2->openRoom());
				player->removeItem(item2);
			}
		}
	}
}

void eat(std::string _input, Player* player){
	for(int i=0; i<50; i++)
		std::cout<<std::endl;
	std::string input=_input.erase(0,4);
	if(player->getItem(input)==NULL){
		std::cout<<"You do not have that item."<<std::endl;
	}else if(player->getItem(input)->getEffect()!="Eat"){
		std::cout<<"You cannot eat that."<<std::endl;
	}else{
		std::cout<<"You eat "<<_input<<"."<<std::endl;
		player->removeItem(player->getItem(input));
	}
}

void pickUp(std::string _input, Player* player){
	for(int i=0; i<50; i++)
		std::cout<<std::endl;
	std::string input=_input.erase(0,8);
	if(player->getRoom()->getItem(input)==NULL){
		std::cout<<"That item is not in the room."<<std::endl;
	}else if(!player->getRoom()->getItem(input)->pickUp()){
		std::cout<<"You can't pick that up."<<std::endl;
	}else{
		std::cout<<input<<" has been added to your inventory"<<std::endl;
		player->addItem(player->getRoom()->getItem(input));
	}
}
void help(){
	for(int i=0; i<50; i++)
		std::cout<<std::endl;
	std::cout<<"The commands available to you are: North, South, East, West, Use (Item Name) with (Item Name), Pick up (Item Name), Eat (Item Name), Look. Everything is case sensitive as do spaces."<<std::endl;
}

void look(Player* player){
	for(int i=0; i<50; i++)
		std::cout<<std::endl;
	player->getRoom()->itemsInRoom();
}