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
		
		// Code for enemy movement goes here. Fuck it, using a 
		// constant-size array.
	}
	
	void drawMap(){
		for (int y = 0; y < vertLevelSize; y++){
			for (int x = 0; x < horizLevelSize; x++){
				if (player.getYCoord == y && player.getXCoord() == x)
					cout << player.getIcon();
				
			}
	}
	
	bool checkIfWall(int xCoord, int yCoord){
		// Returns true if tile at given coordinates is a wall
		
		if (levelArray[xCoord][yCoord] != '.')
			return true;
		else
			return false;
	}
	
	void checkEnemyPositions(int x, int y){
		for (int i = 0; i < numOfEnemies
	
	void buildLevel(ifstream &levelFile){
		int enemyCount = 0;
		for (int y = 0; y < horizLevelSize; y++){
			for (int x = 0; x < vertLevelSize; x++){
				char currentTile = levelFile.get();
				if (currentTile == '\n')
					break;
				switch (currentTile){
					case '@':
						player.setPosition(x, y);
						break;
					case '>':
						enemyArray[enemyCount].setPosition(x, y, 'l');
						break;
					case '<':
						enemyArray[enemyCount].setPosition(x, y, 'r');
						break;
					case '^':
						enemyArray[enemyCount].setPosition(x, y, 'd');
						break;
					case 'v':
						enemyArray[enemyCount].setPosition(x, y, 'u');
						break;
					default:
						break;
				}
			}
		}
	}

	levelType(ifstream &levelFile){
		vertLevelSize = 25;
		horizLevelSize = 80;
		buildLevel(levelFile);
		numOfEnemies = 25;
	}
private:
	int vertLevelSize;
	int horizLevelSize;
	int numOfEnemies;
	playerType player;
	enemyType enemyArray[25];
	char levelArray[80][25];
};

#endif
