#ifndef PLAYERTYPE_H
#define PLAYERTYPE_H

using namespace std;

class playerType{
public:
	void moveUp(){
		if (yCoord > 0)
			yCoord -= 1;
	}
	void moveDown(int vertLevelSize){
		if (yCoord < vertLevelSize)
			yCoord += 1;
	}
	void moveLeft(){
		if (xCoord < 0)
			xCoord -= 1;
	}
	void moveRight(int horizLevelSize){
		if (xCoord < horizLevelSize)
			xCoord += 1;
	}
	void move(char input, int vertLevelSize, int horizLevelSize){
		if (input == 'w')
			moveUp();
		else if (input == 's')
			moveDown(vertLevelSize);
		else if (input == 'a')
			moveLeft();
		else if (input == 'd')
			moveRight(horizLevelSize);
	}
	int getXCoord(){
		return xCoord;
	}
	int getYCoord(){
		return yCoord;
	}
	void setPosition(int xSet, int ySet){
		xCoord = xSet;
		yCoord = ySet;
	}
	char getIcon(){
		return icon;
	}
	
	playerType(int xSet = 10, int ySet = 10){
		xCoord = xSet;
		yCoord = ySet;
		icon = '@';
	}	
private:
	int xCoord;
	int yCoord;
	char icon;
};

#endif
