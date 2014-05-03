#include <iostream>
#include <fstream>
#include "levelType.h"

using namespace std;

void drawWinScreen(){
	for (int i = 0; i < 25; i++){
		cout << endl;
	}
	
	cout << "Congratulate! You are winner!" << endl;
}

void gameLoop(levelType level){
	char userInput;
	while(true){
		int winOrLose = 0;
		level.drawMap();
		cin >> userInput;
		if (userInput == 'q')
			break;
		else
			winOrLose = level.iterateMap(userInput);
		cout << endl << endl;
		
		if (winOrLose == 1){
			drawWinScreen();
			break;
		}
	}
}

int main(){
	// string levelName;
	// cout << "Input file name of level to load: ";
	// cin >> levelName;
	
	ifstream levelFile("level1.txt");
	
	levelType level(levelFile);
	
	gameLoop(level);
	
	cout << endl;
	cout << "Press ENTER to exit program." << endl;
	cin.get();
	cin.ignore();
	return 0;
}
