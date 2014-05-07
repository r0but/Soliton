/*
The MIT License (MIT)

Copyright (c) 2014 Joshua Trahan

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/

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
		int pX = player.getXCoord();
		int pY = player.getYCoord();
		
		for (int i = 0; i < numOfEnemies; i++){
			enemyArray[i].moveAlongPath();
		}
		
		for (int i = 0; i < numOfEnemies; i++){
			bool isCaught = enemyArray[i].checkForPlayer(levelArray, pX, pY);
			if (isCaught)
				return 2;
		}
		
		if (levelArray[pX][pY] == 'E'){
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
				else if (levelArray[x][y] == '#' || levelArray[x][y] == '$'){
					endOfMap = true;
					break;
				}
				else if (isEnemyHere(x, y)){
					for (int i = 0; i < numOfEnemies; i++){
						if (enemyArray[i].getXCoord() == x &&
								enemyArray[i].getYCoord() == y){
							cout << enemyArray[i].toDisplay();
						}
					}
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
	
	bool isEnemyHere(int x, int y){
		for (int i = 0; i < numOfEnemies; i++){
			if (enemyArray[i].getXCoord() == x && 
					enemyArray[i].getYCoord() == y){
				return true;				
			}
		}
		return false;
	}

	void loadEnemyPaths(ifstream &levelFile){
		if (levelFile.eof())
			return;

		for (int i = 0; i < numOfEnemies; i++){
			enemyArray[i].loadPatrolPath(levelFile);
		}
	}
	
	void buildLevel(ifstream &levelFile){
	
		// Initialize array with ' ' (space) 
		// characters, signifying an empty tile
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
		loadEnemyPaths(levelFile);
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
