#include <iostream>
#include <ostream>
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

int main() {
	string currLine = ""; 
	string fileName = "";
	vector<Wire*> vecWires;
	vector<Gate*> vecGates;
	vector<Wire*> tempWires;
	vector<int> wireInts;
		vecWires.push_back(nullptr);

	//For everything
	string firstWord = "";
	int wireNum = 0;

	//for INPUT / OUTPUT
	string wireName = "";
	string wireNumber = "";

	//For Gates
	string gateDelay = "";
	string wire = "";
	int delay = 0;
	
	ifstream circuitFile;
	cout << "Enter circuit description file name" << endl;
	cin >> fileName;
	circuitFile.open("circuit"+ fileName + ".txt");  // now you only have to type the number in
	
	if (!circuitFile) {
		cerr << "File did not open" << endl;
	}
	else {
		cout << "file opened" << endl;
	}
	while(!circuitFile.eof()) {
		getline(circuitFile, currLine);
		stringstream ss(currLine);
		ss >> firstWord;
		if ((firstWord == "INPUT") || (firstWord == "OUTPUT")) {
			ss >> wireName;
			ss >> wireNumber;
			wireNum = stoi(wireNumber);
			
			Wire* inputWire = new Wire(-1, wireName, wireNum);
		  
			if (wireNum > vecWires.size()) {    
				for (int i = 0; i < wireNum - vecWires.size(); i++) {
					vecWires.push_back(nullptr);
				}
			}
			vecWires.push_back(inputWire); 
		}
		
		else if (firstWord != "CIRCUIT") {
			string gateType = firstWord;

			ss >> gateDelay;
			delay = stoi(gateDelay.substr(0, gateDelay.length() - 2));

			for (int i = 0; i < 3; i++) {		// puts the three wires into a vector so they can be used to initialize the gate
				ss >> wire;
				wireNum = stoi(wire);
				wireInts.push_back(wireNum);
				Wire* currWire = vecWires.at(wireInts.at(wireNum - 1));
				tempWires.push_back(currWire);				
			}
			
			if (tempWires.size() == 3) {					// need to check for NOT gate
				Gate currGate(gateType, delay, tempWires.at(0), tempWires.at(1), tempWires.at(2));
				vecGates.push_back(&currGate);
				tempWires.at(0)->addGate(&currGate);		// Tells the wires which gate they are driving
				tempWires.at(1)->addGate(&currGate);
			}
		}
	}
	circuitFile.close();
	cout << "file closed" << endl;

	//readCircuitDesc(circDesc, gates, wires);    Shomper showed this in his main.cpp file
	//readVectorDesc(vecDesc, wires, q);			in class
	//simulate(gates, wires, q);
	//printResults(wires, maxtime);
	
	return 0;
}