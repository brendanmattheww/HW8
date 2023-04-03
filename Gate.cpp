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

Wire* Gate::returnVal(int val, string h) const { 
	if (type == "AND") {

	}
	if (type = ) {

	}
	else if (type == "OR") {

	}
	else if (type == "NOR") {

	}
	else if (type == "XOR") {

	}
	else if (type == "XNOR") {

	}
	else if (type == "NOT") {

	}
}