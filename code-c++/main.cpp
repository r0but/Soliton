#include <iostream>
#include <fstream>
#include "levelType.h"

using namespace std;

void gameLoop(levelType level){
	char userInput;
	while(true){
		level.drawMap();
		cin >> userInput;
		if (userInput == 'q')
			break;
		else
			level.iterateMap(userInput);
		cout << endl << endl;
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
