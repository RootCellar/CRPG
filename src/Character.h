#pragma once

//#include <string.h> //Not necessary
#include "Class.h"


/* Reduce damage by proportion
 * Example: 50 damage vs. 100 defense.
 * 50 / 100 = 0.5, 0.5 * 50 = 25 damage.
 * If damage is 1/2 armor, damage is multiplied by 1/2
 * If damage is 1/7 armor, damage is multiplied by 1/7
 * If damage is less than 1/10 armor, deals 0 damage (blocked entirely)
 * If damage > armor, damage doesn't change
 */
double calcDamage(double a, double d) {
	if (a > d) return a;

	double m = a / d;

	if (m < 0.1) return 0;

	return a * m;
}

class Character {

	double LEVEL_MULT = 1.1;

	Type type;
	int level = 5;
	double hp;
	double atk;
	double def;

public:

	Character() {
		calcStats();
	}

	Character(Type t) {
		type = t;

		calcStats();
	}

	Character(int lvl) {
		level = lvl;

		calcStats();
	}

	Character(Type t, int lvl) {
		type = t;
		level = lvl;
		calcStats();
	}

	void calcStats() {
		hp = type.getBaseHp();
		atk = type.getBaseAtk();
		def = type.getBaseDef();

		if (level > 100) level = 100;
		if (level < 1 ) level = 1;

		for (int i = 0; i < level - 1; i++) {
			hp *= 1.1;
			atk *= 1.1;
			def *= 1.1;
		}

	}

	double getHp() { return hp; }
	double getAtk() { return atk; }
	double getDef() { return def; }

	int getLevel() { return level; }
	Type getType() { return type; }

	void levelUp() { level++; calcStats(); }
	void levelDown() { level--; calcStats(); }

};