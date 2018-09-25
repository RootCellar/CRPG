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

//Grand All-Powerful class Definitions
vector<Type> classList = {
Type("WARRIOR",30,5,5), //Balanced stats
Type("GUARDIAN",40,3,10), //Bulky, swings a thin stick
Type("MAGE",20,10,3), //Glass Cannon
Type("BATTLEMAGE",30,7,3), //Less of a glass cannon
Type("PROTECTOR",50,1,15), //Very bulky, swings a pencil
Type("TITAN",1000,200,200), //Grand Being
};

Type getClassByName(string s) {

	for (Type t : classList) {
		if (t.getName() == s) return t;
	}

	Type default;
	return default;
}

vector<Type> getClassList() {
	return classList;
}