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

int main() {
	string currLine = ""; 
	string fileName = "";
	vector<Wire*> vecWires;
	vector<Gate*> vecGates;
	vector<int> wireInts;
		vecWires.push_back(nullptr);
	
	ifstream circuitFile;
	cout << "Enter circuit description file name" << endl;
	cin >> fileName;
	circuitFile.open(fileName);
	
	if (!circuitFile) {
		cerr << "File did not open" << endl;
	}
	else {
		cout << "file opened" << endl;
	}
	while(!circuitFile.eof()) {
		getline(circuitFile, currLine);
		string firstWord = currLine.substr(0, currLine.find("")); 
		
		if (firstWord == "INPUT" || firstWord == "OUTPUT") {
			stringstream ss(currLine);
			string wireName = "";
			string wireNumber = "";
			ss >> wireName;
			ss >> wireNumber;
			Wire inputWire(-1, wireName, stoi(wireNumber));
			int wn = stoi(wireNumber);

			if (wn > vecWires.size()) {
				for (int i = 0; i < wn - vecWires.size(); i++) {
					vecWires.push_back(nullptr);
				}
			}
			vecWires.push_back(&inputWire); // took out the line where inpw = &inputWire and just did it in the push_back
		}

		else if (firstWord != "CIRCUIT") {
			stringstream ss(currLine);
			string gateDelay = "";
			string wire = "";
			int wn = 0;
			int delay = 0;
			
			ss >> gateDelay;
			ss >> wire;
			wn = stoi(wire);
			wireInts.push_back(wn);
			string gateType = firstWord;
			delay = stoi(gateDelay.substr(0, gateDelay.length() - 2));

			Wire* Wire1 = vecWires.at(wireInts.at(0));
			Wire* Wire2 = vecWires.at(wireInts.at(1));
			Wire* Wire3 = vecWires.at(wireInts.at(3));
			Gate currGate(gateType, delay, Wire1, Wire2, Wire3);
			vecGates.push_back(&currGate);	// puts the gates into the vector
			Wire1->addGate(&currGate);		// Tells the wires which gate they are driving
			Wire2->addGate(&currGate);
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