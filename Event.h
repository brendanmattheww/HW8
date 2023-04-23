#pragma once
#include <string>;
#include "Wire.h";
#include "Gate.h";


using namespace std;

class Event {
public:
	Event(Wire* w, int t, int s, int cnt);
	Wire* getWire() const;
	int getState() const;
	int getTime() const;
private:
	Wire* eWire = nullptr;   //for event wire
	int time = 0;			 // time ns
	int count = 0;			 // Event number	 
	int state = 0;			 // state at Event

	friend bool operator<(const Event& lhs, const Event& rhs);
};
