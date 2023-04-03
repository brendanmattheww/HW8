#pragma once
#include <string>
using namespace std;
class Wire;

class Gate {
public:
	Gate(string t, int d, Wire* i1, Wire* i2, Wire* o); // constructor with 5 parameters
	string getType() const { return type; } // access Type
	int getDelay() const { return delay; } // access Delay




private:
	string type;
	int delay;
	Wire* in1;
	Wire* in2;
	Wire* out;

};