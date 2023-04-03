#include "Gate.h"
#include "Wire.h"

Gate::Gate(string t, int d, Wire* i1, Wire* i2, Wire* o) {
	type = t;
	delay = d;
	in1 = i1;
	in2 = i2;
	out = o;
}

string Gate::getType() const {
	return type;
}

int Gate::getDelay() const {
	return delay;
}

Wire* Gate::getInput(int inp) const {
	Wire* w;

	if (inp == 0) {
		w = returnVal(0,"0");
	}
	else if (inp == 1) {
		w = returnVal(1,"1");
	}
	return w;
}

Wire* Gate::getOutput() const {
	return out;
}

Wire* Gate::returnVal(int val, string h) const {
	Wire* w;
	w->SetValue(val);
	w->setHistory(h);
	return w;
}