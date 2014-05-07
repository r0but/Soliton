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

#ifndef ENEMYTYPE_H
#define ENEMYTYPE_H

using namespace std;

struct actionType{
	char action;
	char direction;
};

class enemyType{
public:
	void moveUp(){
		yCoord--;
		heading = 'u';
	}
	void moveDown(){
		yCoord++;
		heading = 'd';
	}
	void moveLeft(){
		xCoord--;
		heading = 'l';
	}
	void moveRight(){
		xCoord++;
		heading = 'r';
	}
	int getXCoord(){
		return xCoord;
	}
	int getYCoord(){
		return yCoord;
	}
	char toDisplay(){
		if (heading == 'l')
			return '>';
		else if (heading == 'r')
			return '<';
		else if (heading == 'u')
			return 'v';
		else if (heading == 'd')
			return '^';
		else
			return 'O';
	}
	void setPosition(int x, int y, int headingSet){
		xCoord = x;
		yCoord = y;
		heading = headingSet;
	}
	
	bool checkRight(char levelArray[80][25], int pX, int pY) const{
		bool seePlayer = false;
		for (int i = 1; i <= 4; i++){
			if (xCoord + i == pX && (yCoord + (i - 1) >= pY &&
				yCoord - (i - 1) <= pY)){
					seePlayer = true;
			}
		}
		return seePlayer;
	}
	
	bool checkLeft(char levelarray[80][25], int pX, int pY) const{
		bool seePlayer = false;
		for (int i = 1; i <= 4; i++){
			if (xCoord - i == pX && (yCoord + (i - 1) >= pY &&
				yCoord - (i - 1) <= pY)){
					seePlayer = true;
			}
		}
		return seePlayer;
	}

	bool checkUp(char levelarray[80][25], int pX, int pY) const{
		bool seePlayer = false;
		for (int i = 1; i <= 4; i++){
			if (yCoord - i == pY && (xCoord + (i - 1) >= pX &&
				xCoord - (i - 1) <= pX)){
					seePlayer = true;
			}
		}
		return seePlayer;
	}

	bool checkDown(char levelarray[80][25], int pX, int pY) const{
		bool seePlayer = false;
		for (int i = 1; i <= 4; i++){
			if (yCoord + i == pY && (xCoord + (i - 1) >= pX &&
				xCoord - (i - 1) <= pX)){
					seePlayer = true;
			}
		}
		return seePlayer;
	}

	bool checkForPlayer(char levelArray[80][25], int pX, int pY){
		if (xCoord == pX && yCoord == pY){
			return 1;
		}
		
		switch(heading){
			case 'r':
				if (checkRight(levelArray, pX, pY))
					return 1;
				else
					return 0;
				break;
			case 'l':
				if (checkLeft(levelArray, pX, pY))
					return 1;
				else
					return 0;
				break;
			case 'd':
				if (checkDown(levelArray, pX, pY))
					return 1;
				else
					return 0;
				break;
			case 'u':
				if (checkUp(levelArray, pX, pY))
					return 1;
				else
					return 0;
				break;
			default:
				return 0;
		}
		return 0;
	}
	
	void moveAlongPath(){
		char direction = patrolPath[pathLoc].direction;
		char action = patrolPath[pathLoc].action;
		
		if (action == 'm'){
			switch (direction){
				case 'l':
					moveLeft();
					break;
				case 'r':
					moveRight();
					break;
				case 'u':
					moveUp();
					break;
				case 'd':
					moveDown();
					break;
				default:
					cout << "OH GOD";
			}
		}
		if (action == 'l'){
			switch (direction){
				case 'l':
					heading = 'l';
					break;
				case 'r':
					heading = 'r';
					break;
				case 'u':
					heading = 'u';
					break;
				case 'd':
					heading = 'd';
					break;
				default:
					cout << "OH GOD";
			}
		}	
		if (patrolPath[pathLoc + 1].action == '$')
			pathLoc = 0;
		else
			pathLoc++;
	}

	void loadPatrolPath(ifstream &levelFile){
		char currentChar = levelFile.get();
		
		int i = 0;
		do{
			while (currentChar == '#' ||  currentChar == ' ' || 
				   currentChar == '\n'){
				currentChar = levelFile.get();
			}
			
			patrolPath[i].action = currentChar;
			currentChar = levelFile.get();
			
			patrolPath[i].direction = currentChar;
			currentChar = levelFile.get();
			
			i++;
		} while (currentChar != '\n' && currentChar != '#' && !levelFile.eof());
	}
	
	enemyType(int xSet = 3, int ySet = 3, int headingSet = 'l'){
		xCoord = xSet;
		yCoord = ySet;
		headingSet = 'l';
		pathLoc = 0;
		for (int i = 0; i < 100; i++){
			patrolPath[i].action = '$';
			patrolPath[i].direction = '$';
		}
	}
	
private:
	int xCoord;
	int yCoord;
	actionType patrolPath[100];
	int pathLoc;
	char heading;
};

#endif
