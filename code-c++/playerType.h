#ifndef PLAYERTYPE_H
#define PLAYERTYPE_H

using namespace std;

class playerType{
public:
	void moveUp(){
		if (yCoord > 0)
			yCoord -= 1;
	}
	void moveDown(){
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
	
	playerType(xSet = 10, ySet = 10){
		xCoord = xSet;
		yCoord = ySet;
	}	
private:
	int xCoord;
	int yCoord;
};

#endif
