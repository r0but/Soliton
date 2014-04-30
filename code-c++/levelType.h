#ifndef LEVELTYPE_H
#define LEVELTYPE_H

#include <iostream>
#include <fstream>
#include "playerType.h"
#include "enemyType.h"

using namespace std;

class levelType{
public:
	void iterateMap(char input){
		player.move(input, vertLevelSize, horizLevelSize);
		
		
		// Code for enemy movement goes here. Will likely
		// have to use a linked list, or possibly a dynamic array.
	}
	
	bool checkIfWall(int xCoord, int yCoord){
		// Returns true if tile at given coordinates is a wall
		
		if (levelArray[xCoord][yCoord] != '.')
			return true;
		else
			return false;
	}
	
	void buildLevel(ifstream &levelFile){
		int enemyCount = 0;
		for (int y = 0; y < horizLevelSize; y++){
			for (int x = 0; x < vertLevelSize; x++){
			
				// Should probably put this stuff in its own function
				char currentTile = levelFile.get();
				if (currentTile == '\n')
					break;
				switch (currentTile){
					case '@':
						player.setPosition(x, y);
						break;
					case '>':
						enemyArray[enemyCount].setPosition(x, y, 'l');
						enemyCount++;
						break;
					case '<':
						enemyArray[enemyCount].setPosition(x, y, 'r');
						enemyCount++;
						break;
					case '^':
						enemyArray[enemyCount].setPosition(x, y, 'd');
						enemyCount++;
						break;
					case 'v':
						enemyArray[enemyCount].setPosition(x, y, 'u');
						enemyCount++;
						break;
					default:
						levelArray[x][y] = currentTile;
						break;
				}
			}
		}
	}

	levelType(ifstream &levelFile){
		vertLevelSize = 25;
		horizLevelSize = 80;
		buildLevel(levelFile);
	}
private:
	int vertLevelSize;
	int horizLevelSize;
	playerType player;
	enemyType enemyArray[25];
	char levelArray[80][25];
};

#endif
