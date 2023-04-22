#pragma once
#include <string>
using namespace std;
class Wire;

class Gate {
public:
	//Default Constructor (5 parameters)
	Gate(string t, int d, Wire* i1, Wire* i2, Wire* o);
	
	// Accessors
	string getType() const; 
	int getDelay() const; 
	Wire* getInput(int) const;
	Wire* getOutput() const;
	Wire* Evaluate(int delay) const;

private:
	string type; // gate type
	int delay;   // gate delay
	Wire* in1;   // input 1 wire
	Wire* in2;   // input 2 wire
	Wire* out;   // output wire
};