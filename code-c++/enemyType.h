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
		yCoord -= 1;
		heading = 'u';
	}
	void moveDown(){
		yCoord += 1;
		heading = 'd';
	}
	void moveLeft(){
		xCoord -= 1;
		heading = 'l';
	}
	void moveRight(){
		xCoord += 1;
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
		for (int i = 1; i <= 4; i++){
			if (xCoord + i == pX && (yCoord + (i - 1) >= pY &&
				yCoord - (i - 1) <= pY)){
					return 1;
			}
		}
		return 0;
	}
	
	bool checkLeft(char levelarray[80][25], int pX, int pY) const{
		for (int i = 1; i <= 4; i++){
			if (xCoord - i == pX && (yCoord + (i - 1) >= pY &&
				yCoord - (i - 1) <= pY)){
					return 1;
			}
		}
		return 0;
	}
	
	bool checkUp(char levelarray[80][25], int pX, int pY) const{
		for (int i = 1; i <= 4; i++){
			if (yCoord - i == pY && (xCoord + (i - 1) >= pX &&
				xCoord - (i - 1) <= pX)){
					return 1;
			}
		}
		return 0;
	}
	
	bool checkDown(char levelarray[80][25], int pX, int pY) const{
		for (int i = 1; i <= 4; i++){
			if (yCoord + i == pY && (xCoord + (i - 1) >= pX &&
				xCoord - (i - 1) <= pX)){
					return 1;
			}
		}
		return 0;
	}
	
	bool checkForPlayer(char levelArray[80][25], int pX, int pY) const{
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
			currentChar = levelFile.get();
			if (currentChar == ' ' || currentChar == '#')
				currentChar = levelFile.get();
			if (levelFile.eof())
				break;
			patrolPath[i].action = currentChar;
			currentChar = levelFile.get();
			patrolPath[i].direction = currentChar;
			i++;
		} while (currentChar != '#');
		
		// Terminating
		patrolPath[i].action = '$';
		patrolPath[i].direction = '$';
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
