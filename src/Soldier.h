#pragma once

#include <vector>
using namespace std;

class Soldier {

public:

	Soldier() {

	}

};

class Army {
	vector<Soldier> list;

public:
	Army() {

	}

	void addSoldier(int n) {
		for (int i = 0; i < n; i++) {
			list.push_back( Soldier() );
		}
	}

	int size() {
		return list.size();
	}

	void clear() {
		list.clear();
	}

};