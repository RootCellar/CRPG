#pragma once

#include <vector>
#include <string.h>

using namespace std;

class Type
{
	string name = "DEFAULT";
	double baseHp;
	double baseAtk;
	double baseDef;

public:
	Type() {
		baseHp = 30;
		baseAtk = 5;
		baseDef = 5;
	}

	Type(string n, double h, double a, double d) {
		name = n;
		baseHp = h;
		baseAtk = a;
		baseDef = d;
	}

	double getBaseHp() { return baseHp; }
	double getBaseAtk() { return baseAtk; }
	double getBaseDef() { return baseDef; }
	string getName() { return name; }
};

vector<Type> classList = {  Type("WARRIOR",30,5,5),
							Type("GUARDIAN",40,3,15),
							Type("MAGE",20,15,3),
							};

Type getClassByName(string s) {

	for (Type t : classList) {
		if (t.getName() == s) return t;
	}

	Type default;
	return default;
}