#pragma once
#include <string>;
#include "Wire.h";
#include "Gate.h";

using namespace std;

class Event { // work in progress
public:
	bool readCircDesc(string cd, string gates, Wire* w);
	bool readVecDesc(string vd, Wire* w, string q);
	int simulate(string gates, Wire* w, string q);
	void printResults(Wire* w, int max);
private:
	string circDesc; // could be different
	string vecDesc;  // data types
	string queue;    // 
	int time;		 // time ns
	int count;		 // count
	int oVal = -1;	 // output state
};