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
		int y = 0;
		
		// checking straight forward
		for (int x = 1; x <= 4; x++){
			int seeX = xCoord + x;
			if (xCoord + x == pX){
				seePlayer = true;
				break;
			}
			if (levelArray[seeX][yCoord] != '.'){
				break;
			}
		}
		
		// diagonal down
		y = 0;
		for (int x = 1; x <= 4; x++){
			int seeX = xCoord + x;
			int seeY = yCoord + y;
			
			if (seeX == pX && seeY == pY){
				seePlayer = true;
				break;
			}
			if (levelArray[seeX][seeY] != '.'){
				break;
			}
			y++;
		}
		
		// diagonal up
		y = 0;
		for (int x = 1; x <= 4; x++){
			int seeX = xCoord + x;
			int seeY = yCoord + y;
			
			if (seeX == pX && seeY == pY){
				seePlayer = true;
				break;
			}
			if (levelArray[seeX][seeY] != '.'){
				break;
			}
			y--;
		}
		
		// 3 spaces between straight forward and diagonal down
		y = 1;
		for (int x = 3; x <= 4; x++){
			int seeX = xCoord + x;
			int seeY = yCoord + y;
			
			if (x == 4){
				if (seeX == pX && seeY == (yCoord + 1)){
					seePlayer = true;
					break;
				}
			}
			
			if (seeX == pX && seeY == pY){
				seePlayer = true;
				break;
			}
			if (levelArray[seeX][seeY] != '.'){
				break;
			}
			y++;
		}
		
		// 3 spaces between straight forward and diagonal up
		y = 1;
		for (int x = 3; x <= 4; x++){
			int seeX = xCoord + x;
			int seeY = yCoord - y;
			
			if (x == 4){
				if (seeX == pX && seeY == (yCoord - 1)){
					seePlayer = true;
					break;
				}
			}
			
			if (seeX == pX && seeY == pY){
				seePlayer = true;
				break;
			}
			if (levelArray[seeX][seeY] != '.'){
				break;
			}
			y++;
		}
		
		return seePlayer;
	}

	bool checkLeft(char levelarray[80][25], int pX, int pY) const{
		bool seePlayer = false;
		int y = 0;
		
		// checking straight forward
		for (int x = 1; x <= 04; x++){
			int seeX = xCoord - x;
			if (seeX == pX){
				seePlayer = true;
				break;
			}
			if (levelArray[seeX][yCoord] != '.'){
				break;
			}
		}
		
		// diagonal down
		y = 0;
		for (int x = 1; x <= 4; x++){
			int seeX = xCoord - x;
			int seeY = yCoord + y;
			
			if (seeX == pX && seeY == pY){
				seePlayer = true;
				break;
			}
			if (levelArray[seeX][seeY] != '.'){
				break;
			}
			y++;
		}
		
		// diagonal up
		y = 0;
		for (int x = 1; x <= 4; x++){
			int seeX = xCoord - x;
			int seeY = yCoord - y;
			
			if (seeX == pX && seeY == pY){
				seePlayer = true;
				break;
			}
			if (levelArray[seeX][seeY] != '.'){
				break;
			}
			y++;
		}
		
		// 3 spaces between straight forward and diagonal down
		y = 1;
		for (int x = 3; x <= 4; x++){
			int seeX = xCoord - x;
			int seeY = yCoord + y;
			
			if (x == 4){
				if (seeX == pX && seeY == (yCoord + 1)){
					seePlayer = true;
					break;
				}
			}
			
			if (seeX == pX && seeY == pY){
				seePlayer = true;
				break;
			}
			if (levelArray[seeX][seeY] != '.'){
				break;
			}
			y++;
		}
		
		// 3 spaces between straight forward and diagonal up
		y = -1;
		for (int x = 3; x <= 4; x++){
			int seeX = xCoord - x;
			int seeY = yCoord + y;
			
			if (x == 4){
				if (seeX == pX && seeY == (yCoord - 1)){
					seePlayer = true;
					break;
				}
			}
			
			if (seeX == pX && seeY == pY){
				seePlayer = true;
				break;
			}
			if (levelArray[seeX][seeY] != '.'){
				break;
			}
			y++;
		}
		
		return seePlayer;
	}

	bool checkUp(char levelarray[80][25], int pX, int pY) const{
		bool seePlayer = false;
		int x = 0;
		
		// checking straight forward
		for (int y = 1; y <= 04; y++){
			int seeY = yCoord - y;
			if (seeY == pY){
				seePlayer = true;
				break;
			}
			if (levelArray[xCoord][seeY] != '.'){
				break;
			}
		}
		
		// diagonal right SHOULD WORK
		x = 0;
		for (int y = 1; y <= 4; y++){
			int seeX = xCoord + x;
			int seeY = yCoord - y;
			
			if (seeX == pX && seeY == pY){
				seePlayer = true;
				break;
			}
			if (levelArray[seeX][seeY] != '.'){
				break;
			}
			x++;
		}
		
		// diagonal left SHOULD WORK
		x = 0;
		for (int y = 1; y <= 4; y++){
			int seeX = xCoord - x;
			int seeY = yCoord - y;
			
			if (seeX == pX && seeY == pY){
				seePlayer = true;
				break;
			}
			if (levelArray[seeX][seeY] != '.'){
				break;
			}
			x++;
		}
		
		// 3 spaces between straight forward and diagonal right SHOULD WORK
		x = 1;
		for (int y = 3; y <= 4; y++){
			int seeX = xCoord + x;
			int seeY = yCoord - y;
			
			if (y == 4){
				if (seeY == pY && seeX == (xCoord + 1)){
					seePlayer = true;
					break;
				}
			}
			
			if (seeX == pX && seeY == pY){
				seePlayer = true;
				break;
			}
			if (levelArray[seeX][seeY] != '.'){
				break;
			}
			x++;
		}
		
		// 3 spaces between straight forward and diagonal left SHOULD WORK
		x = 1;
		for (int y = 3; y <= 4; y++){
			int seeX = xCoord - x;
			int seeY = yCoord - y;
			
			if (y == 4){
				if (seeY == pY && seeX == (xCoord - 1)){
					seePlayer = true;
					break;
				}
			}
			
			if (seeX == pX && seeY == pY){
				seePlayer = true;
				break;
			}
			if (levelArray[seeX][seeY] != '.'){
				break;
			}
			x++;
		}
		
		return seePlayer;
	}

	bool checkDown(char levelarray[80][25], int pX, int pY) const{
		bool seePlayer = false;
		int x = 0;
		
		// checking straight forward SHOULD WORK
		for (int y = 1; y <= 04; y++){
			int seeY = yCoord + y;
			if (seeY == pY){
				seePlayer = true;
				break;
			}
			if (levelArray[xCoord][seeY] != '.'){
				break;
			}
		}
		
		// diagonal right SHOULD WORK
		x = 0;
		for (int y = 1; y <= 4; y++){
			int seeX = xCoord + x;
			int seeY = yCoord + y;
			
			if (seeX == pX && seeY == pY){
				seePlayer = true;
				break;
			}
			if (levelArray[seeX][seeY] != '.'){
				break;
			}
			x++;
		}
		
		// diagonal left SHOULD WORK
		x = 0;
		for (int y = 1; y <= 4; y++){
			int seeX = xCoord - x;
			int seeY = yCoord + y;
			
			if (seeX == pX && seeY == pY){
				seePlayer = true;
				break;
			}
			if (levelArray[seeX][seeY] != '.'){
				break;
			}
			x++;
		}
		
		// 3 spaces between straight forward and diagonal right SHOULD WORK
		x = 1;
		for (int y = 3; y <= 4; y++){
			int seeX = xCoord + x;
			int seeY = yCoord + y;
			
			if (y == 4){
				if (seeY == pY && seeX == (xCoord + 1)){
					seePlayer = true;
					break;
				}
			}
			
			if (seeX == pX && seeY == pY){
				seePlayer = true;
				break;
			}
			if (levelArray[seeX][seeY] != '.'){
				break;
			}
			x++;
		}
		
		// 3 spaces between straight forward and diagonal left SHOULD WORK
		x = 1;
		for (int y = 3; y <= 4; y++){
			int seeX = xCoord - x;
			int seeY = yCoord + y;
			
			if (y == 4){
				if (seeY == pY && seeX == (xCoord - 1)){
					seePlayer = true;
					break;
				}
			}
			
			if (seeX == pX && seeY == pY){
				seePlayer = true;
				break;
			}
			if (levelArray[seeX][seeY] != '.'){
				break;
			}
			x++;
		}
		
		return seePlayer;
	}

	bool checkForPlayer(char levelArray[80][25], int pX, int pY){
		if (xCoord == pX && yCoord == pY){
			return 1;
		}
		
		// just need to have return(checkDirection()), will fix later.
		// All this sight code is hacky garbage. I'm sorry to whoever reads this.
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
