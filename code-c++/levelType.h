#ifndef LEVELTYPE_H
#define LEVELTYPE_H

#include <iostream>
#include <fstream>
#include "playerType.h"
#include "enemyType.h"

using namespace std;

class levelType{
public:
	int iterateMap(char input){
		
		player.move(input, vertLevelSize, horizLevelSize);
		
	}
	
	void drawMap(){
		for (int y = 0; y < vertLevelSize; y++){
			for (int x = 0; x < horizLevelSize; x++){
				if (player.getYCoord() == y && player.getXCoord() == x)
					std::cout << player.getIcon();
			}	
		}
	}
	
	bool checkIfWall(int xCoord, int yCoord){
		// Returns true if tile at given coordinates is a wall
		
		if (levelArray[xCoord][yCoord] != '.')
			return true;
		else
			return false;
	}
	
	//bool checkEnemyPositions(int x, int y){
	//	for (int i = 0; i < numOfEnemies
	
	void buildLevel(ifstream &levelFile){
		int enemyCount = 0;
		int tileCount = 0;
		
		// Going to use tileCount to figure out how many tiles there are
		// left when EoF hits, then fill the rest with spaces.
		while(!levelFile.eof()){
			for (int y = 0; y < horizLevelSize; y++){
				for (int x = 0; x < vertLevelSize; x++){
					char currentTile = levelFile.get();
					if (currentTile == '\n')
						break;
					switch (currentTile){
						case '@':
							player.setPosition(x, y);
							levelArray[x][y] = '.';
							break;
						case '>':
							enemyArray[enemyCount].setPosition(x, y, 'l');
							enemyCount++;
							levelArray[x][y] = '.';
							break;
						case '<':
							enemyArray[enemyCount].setPosition(x, y, 'r');
							enemyCount++;
							levelArray[x][y] = '.';
							break;
						case '^':
							enemyArray[enemyCount].setPosition(x, y, 'd');
							enemyCount++;
							levelArray[x][y] = '.';
							break;
						case 'v':
							enemyArray[enemyCount].setPosition(x, y, 'u');
							enemyCount++;
							levelArray[x][y] = '.';;
							break;
						default:
							levelArray[x][y] = currentTile;
							break;
					}
					tileCount++;
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
