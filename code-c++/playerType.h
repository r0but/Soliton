#ifndef PLAYERTYPE_H
#define PLAYERTYPE_H

using namespace std;

class playerType{
public:
	void moveUp(){
		yCoord -= 1;
	}
	void moveDown(){
		yCoord += 1;
	}
	void moveLeft(){
		xCoord -= 1;
	}
	void moveRight(){
		xCoord += 1;
	}
	
	void move(char input, char levelArray[80][25]){
		if (input == 'w' && (levelArray[xCoord][yCoord - 1] == '.' ||
						     levelArray[xCoord][yCoord - 1] == 'E'))
			moveUp();
		else if (input == 's' && (levelArray[xCoord][yCoord + 1] == '.' || 
								  levelArray[xCoord][yCoord + 1] == 'E'))
			moveDown();
		else if (input == 'a' && (levelArray[xCoord - 1][yCoord] == '.' || 
								  levelArray[xCoord - 1][yCoord] == 'E'))
			moveLeft();
		else if (input == 'd' && (levelArray[xCoord + 1][yCoord] == '.' ||
								  levelArray[xCoord + 1][yCoord] == 'E'))
			moveRight();
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
