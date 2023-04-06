#include "Wire.h"
#include <iostream>
using namespace std;
//default constructor
Wire::Wire(int v, string h) {
	value = v;
	history = h;
}

//Setters
void Wire::SetValue(int v) {
	value = v;
}								  // parms int time, int value
void Wire::setHistory(string h) { // appends the incoming string
	history += h;				  // may need to change this to take into account time
}
void Wire::addGate(Gate* i) {
	drives.push_back(i);
}

void Wire::printHistory() const {
	cout << history;
}

//Getters
int	 Wire::GetValue() const { 
	return value;   
}

string Wire::GetName() const { 
	return name;    
}

vector<Gate*> Wire::GetGate() const { 
	return drives;  
}

int Wire::GetIndex() const { 
	return index;   
}

string Wire::GetHistory() const {
	return history; 
}
