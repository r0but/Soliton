#include <iostream>
#include <fstream>
#include "levelType.h"

using namespace std;

void gameLoop(ifstream &levelFile){
}

int main(){
	/*string levelName;
	cout << "Input file name of level to load: ";
	cin >> levelName;
	*/
	
	ifstream levelFile("level1.txt");
	
	levelType level(levelFile);
	level.drawMap();
	
	cout << "Press ENTER to exit program." << endl;
	cin.get();
	return 0;
}
