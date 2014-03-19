#ifndef ENEMYTYPE_H
#define ENEMYTYPE_H

using namespace std;

class playerType{
public:
	void moveUp(){
		if (yCoord > 0)
			yCoord -= 1;
	}
	void moveDown(vertLevelSize){
		if (yCoord < vertLevelSize)
			yCoord += 1;
	}
	void moveLeft(){
		if (xCoord < 0)
			xCoord -= 1;
	}
	void moveRight(){
		if (xCoord < horizLevelSize)
			xCoord += 1;
	}
	int getXCoord(){
		return xCoord;
	}
	int getYCoord(){
		return yCoord;
	}
	
	playerType(xSet = 3, ySet = 3){
		xCoord = xSet;
		yCoord = ySet;
	}	
private:
	int xCoord;
	int yCoord;
};

#endif
