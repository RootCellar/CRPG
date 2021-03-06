//Darian Marvel, 9/23/2018
//Learning C++ by creating a simple RPG game

#include "stdafx.h"

#include <cstdio>
#include <cstdlib>
#include <iostream>
//#include <string.h> //Not needed

#include "Character.h"

using namespace std;

void out(char toOut[]);

int getInt();

void printCharInfo(Character c);

int main()
{

	Character player( getClassByName("TITAN") , 5 );
	Character enemy( getClassByName("GUARDIAN") , 5 );

	bool going = true;

	int input;

	while (going) {

		system("cls");

		player.calcStats();

		input = -1;

		printCharInfo(player);

		printCharInfo(enemy);

		out("0. Quit");
		out("1. Level up");
		out("2. Level down");
		out("3. Up 10 levels");
		out("4. Down 10 levels");

		cout << ")";

		input = getInt();

		if (input == 0) {
			going = false;
		}

		if (input == 1) {
			player.levelUp();
		}

		if (input == 2) {
			player.levelDown();
		}

		if (input == 3) {
			for (int i = 0; i < 10; i++) {
				player.levelUp();
			}
		}

		if (input == 4) {
			for (int i = 0; i < 10; i++) {
				player.levelDown();
			}
		}

		
	}

    return 0;
}

void out(char toOut[]) {
	cout << toOut << endl;
	return;
}

int getInt() {
	int in;
	while (true) {
		cin >> in;
		if (cin.fail()) { //Input failed, reset fail state, loop will ignore bytes until valid input is reached
			cin.clear();
			cin.ignore(1, '\n');
		}
		else {
			return in;
		}
	}
}

void printCharInfo(Character c) {
	cout << "LEVEL: " << c.getLevel() << endl;
	cout << "CLASS: " << c.getType().getName().c_str() << endl;
	cout << "HP: " << (int)c.getHp() << endl;
	cout << "ATK: " << (int)c.getAtk() << endl;
	cout << "DEF: " << (int)c.getDef() << endl;
}