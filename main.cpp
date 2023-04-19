#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <queue>
#include <sstream>
#include "Event.h"
#include "Gate.h"
#include "Wire.h"
#include "main.h"

using namespace std;

int main(){
	string currLine = ""; // First line 
	string fileName = "";
	ifstream circuitFile;
	
	circuitFile.open(fileName);
	
	if (!circuitFile) {
		cerr << "File did not open" << endl;
	}

	while(!circuitFile.eof()) {
		getline(circuitFile, currLine);
		if (currLine.substr(0, currLine.find("")) == "INPUT") {
			stringstream ss(currLine);
			string wireName = "";
			string wireNumber = "";
			ss >> wireName;
			ss >> wireNumber;
			Wire inputWire(-1, wireName, stoi(wireNumber));
		}
		
		
		


	}
	


	//readCircuitDesc(circDesc, gates, wires);    Shomper showed this in his main.cpp file
	//readVectorDesc(vecDesc, wires, q);			in class
	//simulate(gates, wires, q);
	//printResults(wires, maxtime);
	
	return 0;
}