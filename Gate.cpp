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

int ANDLogic(int inVal1, int inVal2) {  // Function that can be used for AND and NAND logic
	if (inVal1 == 0 || inVal2 == 0) {
		return 0;
	}
	else if (inVal1 == 1 && inVal2 == 1) {
		return 1;
	}
	else if ((inVal1 == -1 && (inVal2 == 1 || inVal2 == -1)) || (inVal1 == 1 && inVal2 == -1)) {
		return -1;
	}
}

Wire* Gate::returnVal(Wire* in1, Wire* in2) const {
	string history = "";
	int outVal = -1;			  // 1 = high; 0 = low; -1 = unknown
	int inVal1 = in1->GetValue(); // put wire values into integers for simplicity
	int inVal2 = in2->GetValue();
	
	
	if (type == "AND") {
		outVal = ANDLogic(inVal1, inVal2);
	}
	else if (type == "NAND") {
		outVal = ANDLogic(inVal1, inVal2);  // Nots AND Logic
		if (outVal == 1) {
			outVal = 0;
		}
		if (outVal == 0) {
			outVal = 1;
		}
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
	Wire* out;				// creates a wire and sets it members
	out->SetValue(outVal);
	out->setHistory(history);
	return out;
}

	