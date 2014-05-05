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
		if (yCoord > 0)
			yCoord -= 1;
		heading = 'u';
	}
	void moveDown(int vertLevelSize){
		if (yCoord < vertLevelSize)
			yCoord += 1;
		heading = 'd';
	}
	void moveLeft(){
		if (xCoord < 0)
			xCoord -= 1;
		heading = 'l';
	}
	void moveRight(int horizLevelSize){
		if (xCoord < horizLevelSize)
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
	
	// NOT FINISHED
	/*void loadPatrolPath(ifstream &levelFile){
		int i = 0;
		do{
			if (currentChar == ' ')
				currentChar = levelFile.get();
			patrolPath[i].action = currentChar;
			currentChar = levelFile.get();
			patrolPath[i].direction = currentChar();
		} while (currentChar != '#');		
	}*/
	
	enemyType(int xSet = 3, int ySet = 3, int headingSet = 'l'){
		xCoord = xSet;
		yCoord = ySet;
		headingSet = 'l';
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

