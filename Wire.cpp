#include "Wire.h"
#include <iostream>
using namespace std;
//default constructor
Wire::Wire(int v, string h) {
	value = v;
	history = h;
}

//Setters
int Wire::SetValue(int v) {
	value = v;
}
string Wire::setHistory(string h) {
	history = h;
}
vector<Gate*> Wire::setDrives(vector<Gate*> d) {
	drives = d;
}

void Wire::printHistory() const {
	cout << history;
}

//Getters
int	 Wire:: GetValue() const		{ return value;   }
string Wire::GetName() const		{ return name;    }
vector<Gate*> Wire::GetGate() const { return drives;  }
int Wire::GetIndex() const			{ return index;   }
string Wire::GetHistory() const		{ return history; }