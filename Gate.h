#pragma once
#include <string>
using namespace std;
class Wire;

class Gate {
public:
	//Default Constructor (5 parameters)
	Gate(string t, int d, Wire* i1, Wire* i2, Wire* o);
	
	// Accessors
	string getType() const { return type; }
	int getDelay() const { return delay; }
	Wire* getInput(int) const;
	Wire* getOutput() const;
	//Gate returnVal(string t, int d, Wire* i1, Wire* i2, Wire* o) const; // note: could be very wrong
	Wire* returnVal(int val, string h) const;							  // note: could be very wrong

private:
	string type;
	int delay;
	Wire* in1;
	Wire* in2;
	Wire* out;

};