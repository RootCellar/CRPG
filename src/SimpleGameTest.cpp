// SimpleGameTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string.h>

#include "Character.h"

using namespace std;

void out(char toOut[]);

int main()
{

	Character player( getClassByName("GUARDIAN"), 1);

	bool going = true;

	int input;

	while (going) {

		system("cls");

		player.calcStats();

		input = -1;
		
		//cout << "1. Something" << endl; //Let's try out new out function

		cout << "LEVEL: " << player.getLevel() << endl;
		cout << "CLASS: " << player.getType().getName().c_str() << endl;
		cout << "HP: " << player.getHp() << endl;
		cout << "ATK: " << player.getAtk() << endl;
		cout << "DEF: " << player.getDef() << endl;

		out("0. Quit");
		out("1. Level up");
		out("2. Level down");
		out("3. Up 10 levels");
		out("4. Down 10 levels");

		cout << ")";

		cin >> input;
		if (cin.fail()) { //Input failed, reset fail state, loop will ignore bytes until valid input is reached
			cin.clear();
			cin.ignore(1, '\n');
		}

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