#include <iostream>
#include <windows.h>
#include <ctime>
using namespace std;
int main() {
	int num;
	char stuff= 'a';
	cout << "I will now change the color" << endl;
	srand(time(NULL));
	num = rand() % 100 + 1;
	cout << num<<endl;
	while (stuff != 'q') {
		if (num < 25) {
			system("color 10");
			system("pause");
		}
		else if (num >= 25 && num < 50) {
			system("color 20");
			system("pause");
		}
		else if (num >= 50) {
			system("color 4D"); 
			system("pause");
		}
	}
}