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
		player.move(input, levelArray);
		
		if (levelArray[player.getXCoord()][player.getYCoord()] == 'E'){
			return 1;
		}
		else{
			return 0;
		}
	}
	
	void drawMap(){
		bool endOfMap = false;
		for (int y = 0; y < vertLevelSize; y++){
			for (int x = 0; x < horizLevelSize; x++){
				if (player.getYCoord() == y && player.getXCoord() == x)
					cout << player.getIcon();
				else if (levelArray[x][y] == '%'){
					cout << endl;
					break;
				}
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
		for (int i = 0; i < 25 - vertLevelSize; i++){
			cout << endl;
		}
	}
	
	bool checkIfWall(int xCoord, int yCoord){
		// Returns true if tile at given coordinates is a wall
		
		if (levelArray[xCoord][yCoord] != '.')
			return true;
		else
			return false;
	}
	
	void buildLevel(ifstream &levelFile){
	
		// Initialize array with ' ' (space) 
		// character, signifying an empty tile
		for (int y = 0; y < 25; y++){
			for (int x = 0; x < 80; x++){
				levelArray[x][y] = ' ';
			}
		}
		
		int enemyCount = 0;
		bool endOfFile = false;
		for (int y = 0; y < 25; y++){
			vertLevelSize = y;
			if (endOfFile || levelFile.eof()){
				levelArray[0][y] = '$';
				break;
			}
			for (int x = 0; x < 80; x++){
				bool endOfLine = false;
				char currentTile = levelFile.get();
				if (levelFile.eof()){
					endOfFile = true;
					levelArray[x][y] = '$';
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
						levelArray[x][y] = '.';
						break;
					case '\n':
						levelArray[x][y] = '%';
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
