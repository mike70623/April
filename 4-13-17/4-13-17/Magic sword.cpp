#include <iostream>
#include <string>
#include <Windows.h>
#include <ctime>
#include <cstdlib>
using namespace std;
int main() {
	string input;
	string inventory[4];
	for (int i = 0; i < 4; i++)
		inventory[i] = "";
	cout << "do you want magic (not really)sword?" << endl;
	getline(cin, input);
	if (input.compare("yes") == 0) {
		cout << "You got B. Sword." << endl;
		inventory[1] = "B. Sword";
	}
	else if (input.compare("no") == 0) {
		cout << "Do you want to die. lose" << endl;
		PlaySound(TEXT("death.wav"), NULL, SND_ALIAS | SND_APPLICATION);
		return 0;
	}
	cout << "groovy ganon appears" << endl;
	if (inventory[1].compare("B. Sword") == 0)
		cout << "kill. you win" << endl;
	else {
		cout << "you couldn't get your groove on. he danced you to death." << endl;
		PlaySound(TEXT("death.wav"), NULL, SND_ALIAS | SND_APPLICATION);
		return 0;
	}
}