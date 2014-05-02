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
		return 0;
	}
	
	void drawMap(){
		bool endOfMap = false;
		for (int y = 0; y < vertLevelSize; y++){
			for (int x = 0; x < horizLevelSize; x++){
				if (player.getYCoord() == y && player.getXCoord() == x)
					cout << player.getIcon();
				else if (levelArray[x][y] == '$'){
					endOfMap = true;
					break;
				}
				else
					cout << levelArray[x][y];
			}
			if (endOfMap)
				break;
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
	
		// Initialize array with ' ' (space) 
		// character, signifying an empty tile
		for (int y = 0; y < horizLevelSize; y++){
			for (int x = 0; x < vertLevelSize; x++){
				levelArray[x][y] = ' ';
			}
		}
		
		int enemyCount = 0;
		bool endOfFile = false;
		for (int y = 0; y < horizLevelSize; y++){
			if (endOfFile || levelFile.eof()){
				levelArray[0][y] = '$';
				break;
			}
			for (int x = 0; x < vertLevelSize; x++){
				bool endOfLine = false;
				char currentTile = levelFile.get();
				cout << currentTile << endl;
				if (levelFile.eof()){
					endOfFile = true;
					break;
				}
				
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
					case '\n':
						endOfLine = true;
						break;
					case '$':
						endOfFile = true;
						break;
					default:
						levelArray[x][y] = currentTile;
						break;
				}
				if (endOfLine)
					break;
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
