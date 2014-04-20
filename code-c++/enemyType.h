#ifndef ENEMYTYPE_H
#define ENEMYTYPE_H

using namespace std;

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
	char spriteToDisplay(){
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
	
	enemyType(int xSet = 3, int ySet = 3, int headingSet = 'l'){
		xCoord = xSet;
		yCoord = ySet;
		headingSet = 'l';
	}
	
private:
	int xCoord;
	int yCoord;
	char heading;
};

#endif
