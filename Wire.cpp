#include "Wire.h"
#include <iostream>
using namespace std;
//default constructor
Wire::Wire() {
	name = "";
	index = 0;
	value = -1;
}
Wire::Wire(int v, string n, int ind) { 
	value = v;
	name = n;
	index = ind;
}

//Setters
void Wire::SetValue(int v) {
	value = v;
}
void Wire::setHistory(int v, int time) {                   // appends the incoming string
	int initHistSize = history.size();
	int prevVal = 0;
	if (initHistSize == 0) {
		for (int i = 0; i < time - initHistSize; i++) {
			history.push_back(-1);				// pushes previous value for as long as it needs
		}
	}
	else  {
		prevVal = history.back();
	}
	
	for (int i = 0; i < time - initHistSize; i++) {      
			history.push_back(prevVal);				// pushes previous value for as long as it needs
	}
	history.push_back(v);							//pushes new value in
	
}
void Wire::setName(string s) {
	name = s;
}
void Wire::setIndex(int i) {
	index = i;
}
void Wire::addGate(Gate* i) {
	drives.push_back(i);
}

void Wire::printHistory() const {
	
	for (int i = 0; i < history.size(); i++) {
		if (history.at(i) == 0) { // will need to account for delays and
			cout << "_";		  // times at which the 1 or 0 doesn't change
		}
		if (history.at(i) == 1) {
			cout << "-";
		}
		if (history.at(i) == -1) {
			cout << "X";
		}
	}
}

//Getters
int	 Wire::GetValue() const { 
	return value;   
}

string Wire::GetName() const { 
	return name;    
}

vector<Gate*> Wire::GetGates() const { 
	return drives;  
}

int Wire::GetIndex() const { 
	return index;   
}

vector<int> Wire::GetHistory() const {
	return history; 
}
