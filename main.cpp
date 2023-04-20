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
	vector<Wire*> vecWire;
	vecWire.push_back(nullptr);
	
	circuitFile.open(fileName);
	
	if (!circuitFile) {
		cerr << "File did not open" << endl;
	}

	while(!circuitFile.eof()) {
		getline(circuitFile, currLine);
		string firstWord = currLine.substr(0, currLine.find("")); \
		Wire* inpw;
		
		if (firstWord == "INPUT" || firstWord == "OUTPUT") {
			stringstream ss(currLine);
			string wireName = "";
			string wireNumber = "";
			ss >> wireName;
			ss >> wireNumber;
			Wire inputWire(-1, wireName, stoi(wireNumber));
			inpw = &inputWire;
			int wn = stoi(wireNumber);

			if (wn > vecWire.size()) {
				for (int i = 0; i < wn - vecWire.size(); i++) {
					vecWire.push_back(nullptr);
				}
			}
			vecWire.push_back(inpw);
		}

		else if (firstWord != "CIRCUIT") {
			stringstream ss(currLine);
			string gateDelay = "";
			string wire = "";
			int wn = 0;
			int delay = 0;
			vector<int> wireInts;
			ss >> gateDelay;
			ss >> wire;
			wn = stoi(wire);
			wireInts.push_back(wn);
			string gateType = firstWord;
			delay = stoi(gateDelay.substr(0, gateDelay.length() - 2));
			Gate currGate(gateType, delay, vecWire.at(wireInts.at(0)), )
		}
		


	}
	


	//readCircuitDesc(circDesc, gates, wires);    Shomper showed this in his main.cpp file
	//readVectorDesc(vecDesc, wires, q);			in class
	//simulate(gates, wires, q);
	//printResults(wires, maxtime);
	
	return 0;
}