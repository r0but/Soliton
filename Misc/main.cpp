#include <iostream>

using namespace std;

int main(){
	char userInput;
	cout << "Enter a key: ";
	cin.get(userInput);
	cout << endl << userInput;
	
	cin.ignore();
	return 0;
}