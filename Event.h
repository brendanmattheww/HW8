#pragma once
#include <string>;
#include "Wire.h";
#include "Gate.h";

using namespace std;
class Event {
private:
	int time = 0;		 // time ns
	int count;		 // count
	int oVal = -1;	 // output state
};
