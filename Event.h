#pragma once
#include <string>;
#include "Wire.h";
#include "Gate.h";

using namespace std;

class Event { // work in progress
public:

private:
	int time;		 // time ns
	int count;		 // count
	int oVal = -1;	 // output state
};