#pragma once
#include <string>
using namespace std;
class Wire;

class Gate {
public:
	Gate(string t, int d, Wire* i1, Wire* i2, Wire* o);
	string getType() const { return type; }
private:
	string type;
	int delay;
	Wire* in1;
	Wire* in2;
	Wire* out;

};