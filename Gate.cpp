#include "Gate.h"
#include "Wire.h"

// Constructor
Gate::Gate(string t, int d, Wire* i1, Wire* i2, Wire* o) {
	type = t;
	delay = d;
	in1 = i1;
	in2 = i2;
	out = o;
}

// Accessor Functions
string Gate::getType() const {
	return type;
}

int Gate::getDelay() const {
	return delay;
}

Wire* Gate::getInput(int inp) const {
	Wire* w;
	if (inp == 1) {
		w = this->in1;
	}
	if (inp == 2) {
		w = this->in2;
	}
	return w;
}

Wire* Gate::getOutput() const {
	return out;
}

Wire* Gate::returnVal(Wire* in1, Wire* in2) const { 
	if (type == "AND") {
		if(in1->GetValue() == 0 || in2 =
	}
	if(type == )
	
}