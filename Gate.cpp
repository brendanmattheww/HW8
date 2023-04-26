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
	Wire* w = nullptr;
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
	return -1;
}

int ORLogic(int inVal1, int inVal2) {
	if (inVal1 == 1 || inVal2 == 1) {
		return 1;
	}
	else if (inVal1 == 0 && inVal2 == 0) {
		return 0;
	}
	return -1;
}

int XORLogic(int inVal1, int inVal2) {
	if ((inVal1 == 1 && inVal2 == 1) || (inVal1 == 0 && inVal2 == 0)) {
		return 0;
	}
	else if ((inVal1 == 1 && inVal2 == 0) || (inVal1 == 0 && inVal2 == 1)) {
		return 1;
	}
	return -1;
}

int NOTLogic(int inVal) {
	if (inVal == 1) {
		return 0;
	}
	else if (inVal == 0) {
		return 1;
	}
	return -1;
}

int Gate::Evaluate() const {   //changed this to return int, may not be right.
	int out = 0;					  // makes wire named out
	int outVal = -1;			  // 1 = high;  0 = low;  -1 = unknown
	int inVal1 = in1->GetValue();
	int inVal2 = 0;				 // puts wire values into integers for simplicity
	if (in2 != nullptr) {
		inVal2 = in2->GetValue();
	}
	

	vector<int> high;
	vector<int> low;
	vector<int> unknown;
		
	if (type == "AND") {
		outVal = ANDLogic(inVal1, inVal2);
	}
	else if (type == "NAND") {
		outVal = NOTLogic(ANDLogic(inVal1, inVal2));  // Nots AND Logic
	}
	else if (type == "OR") {
		outVal = ORLogic(inVal1, inVal2);
	}
	else if (type == "NOR") {
		outVal = NOTLogic(ORLogic(inVal1, inVal2));
	}
	else if (type == "XOR") {
		outVal = XORLogic(inVal1, inVal2);
	}
	else if (type == "XNOR") {
		outVal = NOTLogic(XORLogic(inVal1, inVal2));
	}
	else if (type == "NOT") {
		outVal = NOTLogic(inVal1); // Just takes in in1
	}
	
	// sets wire members
	//out->SetValue(outVal);
	out = outVal;
	/*if (outVal == 1) {
		out->setHistory(1, time);
	}
	else if (outVal == 0) {
		out->setHistory(0, time);
	}
	else {
		out->setHistory(-1, time);
	}
	*/
	return out;
}

	