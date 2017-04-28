#include<iostream>


using namespace std;

void Nuke(double orb, double atk);

int main() {
	double orb = 0;
	double attack = 0;



	cout << "Hello! Please give your weeaboo's statistics: " << endl;
	cout << "First, the amount of orbage: ";
	cin >> orb;
	cout << "Now, attack: ";
	cin >> attack;



	Nuke(orb, attack);

}

void Nuke(double orb, double atk) {

	double damage = (atk * (1 + (orb*.3)) + 3000);

	cout << "The attack does " << damage << " damage!" << endl;


}