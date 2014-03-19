#ifndef LEVELTYPE_H
#define LEVELTYPE_H

#include <iostream>
#include <fstream>

using namespace std;

class levelType{
public:
	void iterateMap(char input){
		if (input == 'w')
			player.moveUp();
		else if (input == 's')
			player.moveDown();
		else if (input == 'a')
			player.moveLeft();
		else if (input == 'd')
			player.moveRight();
		
		// Code for enemy movement goes here. Will likely
		// have to use a linked list, or possibly a dynamic array.
	}
	
	bool checkIfWall(int xCoord, int yCoord){
		// Returns true if tile at given coordinates is a wall
		
		if (levelArray[xCoord] != '.' && levelArray[yCoord] != '.')
			return true;
		else
			return false;
	}
	
	levelType(&ifstream levelFile){
		for (int y = 0; y < 25; y++){
			for (int x = 0; x < 80; x++){
				char currentTile = ifstream.get();
				if (currentTile == '\n'){
					break;
				}
				else if (currentTile == '@'){
					player(x, y);
				}
				// PROGRESS MARKER -- STOPPED HERE 3/19/2014
			}
		}
	}
private:
	playerType player;
	levelArray[80][25];
};

#endif
