#include <iostream>
//#include <ostream>
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

	getline(circuitFile, currLine);
	while(!circuitFile.eof()) {
		getline(circuitFile, currLine);
		string firstWord = currLine.substr(0, currLine.find(" ")); 
		
		
		if ((firstWord == "INPUT") || (firstWord == "OUTPUT")) {
			
			stringstream ss(currLine);
			string firstWord = "";
			string wireName = "";
			string wireNumber = "";
			
			ss >> firstWord;
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
			int wireNum = 0;
			string firstWord = "";
			//int wn = 0;
			int delay = 0;
			ss >> firstWord;
			ss >> gateDelay;
			for (int i = 0; i < 3; i++) {
				ss >> wire;
				wireNum = stoi(wire);
				wireInts.push_back(wireNum);
				Wire* currWire = vecWires.at(wireInts.at(wireNum - 1));
				tempWires.push_back(currWire);
			}
			string gateType = firstWord;
			delay = stoi(gateDelay.substr(0, gateDelay.length() - 2));
			
			
			
			if (tempWires.size() == 3) {   // need to check for NOT gate
				Gate currGate(gateType, delay, tempWires.at(0), tempWires.at(1), tempWires.at(2));
				vecGates.push_back(&currGate);
				tempWires.at(0)->addGate(&currGate);		// Tells the wires which gate they are driving
				tempWires.at(1)->addGate(&currGate);
			}
										// puts the gates into the vector
			
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