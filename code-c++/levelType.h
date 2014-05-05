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
				char enemyHeading = isEnemyHere(x, y);
				if (player.getYCoord() == y && player.getXCoord() == x)
					cout << player.getIcon();
				else if (enemyHeading != ' ')
					cout << enemyHeading;
				else if (levelArray[x][y] == '%'){
					cout << endl;
					break;
				}
				else if (levelArray[x][y] == '#' || levelArray[x][y] == '$'){
					endOfMap = true;
					break;
				}
				else
					cout << levelArray[x][y];
			}
			if (endOfMap)
				break;
		}
		for (int i = 0; i < 24 - vertLevelSize; i++){
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
	
	char isEnemyHere(int x, int y){
		for (int i = 0; i < 25; i++){
			if (enemyArray[i].getXCoord() == x && 
					enemyArray[i].getYCoord() == y){
				return enemyArray[i].toDisplay();				
			}
		}
		return ' ';
	}
	
	/*void loadEnemyPaths(ifstream &levelFile){
		if (levelFile.eof())
			return;
			
		for (int i = 0; i < 25; i++){
			enemyArray[i].loadPatrolPath(levelFile);
		}
	}*/
	
	void buildLevel(ifstream &levelFile){
	
		// Initialize array with ' ' (space) 
		// character, signifying an empty tile
		for (int y = 0; y < 25; y++){
			for (int x = 0; x < 80; x++){
				levelArray[x][y] = ' ';
			}
		}
		
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
						enemyArray[numOfEnemies].setPosition(x, y, 'l');
						numOfEnemies++;
						levelArray[x][y] = '.';
						break;
					case '<':
						enemyArray[numOfEnemies].setPosition(x, y, 'r');
						numOfEnemies++;
						levelArray[x][y] = '.';
						break;
					case '^':
						enemyArray[numOfEnemies].setPosition(x, y, 'd');
						numOfEnemies++;
						levelArray[x][y] = '.';
						break;
					case 'v':
						enemyArray[numOfEnemies].setPosition(x, y, 'u');
						numOfEnemies++;
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
				if (endOfLine || endOfFile)
					break;
			}		
		}
		//loadEnemyPaths(levelFile);	
	}

	levelType(ifstream &levelFile){
		vertLevelSize = 25;
		horizLevelSize = 80;
		numOfEnemies = 0;
		buildLevel(levelFile);
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

