#pragma once
#include <string>;
#include "Wire.h";
#include "Gate.h";


using namespace std;

class Event {
public:
	Event(Wire* outWire, int t, int state, int cnt);
private:
	int time = 0;		 // time ns
	int count = 0;		 // count
	int oVal = -1;		 // output state
	int wireNum = 0;					

	friend bool operator<(const Event& lhs, const Event& rhs);
};
