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
		if (input == 'w' && levelArray[xCoord][yCoord - 1] == '.')
			moveUp();
		else if (input == 's' && levelArray[xCoord][yCoord + 1] == '.')
			moveDown();
		else if (input == 'a' && levelArray[xCoord - 1][yCoord] == '.')
			moveLeft();
		else if (input == 'd' && levelArray[xCoord + 1][yCoord] == '.')
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
