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
	string vfileName = "";
	vector<Wire*> vecWires;
	vector<Gate*> vecGates;
	vector<Wire*> tempWires;
	vector<string> vecNames;
	vector<int> vecTimes;
	vector<int> vecStates;
	vector<int> wireInts;
	priority_queue<Event> q;
	vecWires.push_back(nullptr);

	Wire* wire1;
	Wire* wire2;
	Wire* wire3;
	//For everything
	string firstWord = "";
	string currName = "";
	int wireNum = 0;
	int t = 0; //time
	int s = 0; //state

	//for INPUT / OUTPUT
	string wireName = "";
	string wireNumber = "";

	//For Gates
	string gateDelay = "";
	string wire = "";
	int delay = 0;

	//For Logic
	string wireTime = "";
	string wireState = "";

	int eventCnt = 0;

	ifstream circuitFile;
	ifstream vectorFile;
	cout << "Enter circuit description file name" << endl;
	cin >> fileName;
	cout << "Enter vector description file name" << endl;
	cin >> vfileName;
	circuitFile.open("circuit" + fileName + ".txt");
	vectorFile.open("circuit" + vfileName + "_v.txt");

	if (!circuitFile || !vectorFile) {
		cerr << "File did not open" << endl;
	}
	else {
		cout << "files opened" << endl;
	}
	while (!circuitFile.eof()) { // parsing circuit file
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
			vector<int> wireInts;
			wireInts.push_back(0);

			ss >> gateDelay;
			delay = stoi(gateDelay.substr(0, gateDelay.length() - 2));

			int numOfWires = 0;
			if (gateType == "NOT") {
				numOfWires = 2;
			}
			else {
				numOfWires = 3;
			}

			for (int i = 0; i < numOfWires; i++) {		// puts the three wires into a vector so they can be used to initialize the gate
				ss >> wire;
				wireNum = stoi(wire);
				wireInts.push_back(wireNum);
								
			}
			for (int i = 1; i < wireInts.size(); i++) {
				if (vecWires.at(wireInts.at(i)) == nullptr) {
					Wire* newWire = new Wire(-1, "", wireInts.at(i));
					vecWires.at(wireInts.at(i)) = newWire;
				}
			}
			wire1 = vecWires.at(wireInts.at(1));
			if (numOfWires == 3) {
				wire2 = vecWires.at(wireInts.at(2));
				wire3 = vecWires.at(wireInts.at(3));
			}
			else {
				wire2 = nullptr;
				wire3 = vecWires.at(wireInts.at(2));
			}
			Gate* currGate = new Gate(gateType, delay, wire1, wire2, wire3);
			vecGates.push_back(currGate);
			wire1->addGate(currGate);	// Tells the wires which gate they are 
			if (numOfWires == 3) {
				wire2->addGate(currGate);	// not adding the second gate for a wire correctly
			}
		}
	}

	while (!vectorFile.eof()) {
		getline(vectorFile, currLine);
		stringstream ss(currLine);
		ss >> firstWord;

		if (firstWord == "INPUT") {
			ss >> wireName;
			ss >> wireTime;
			ss >> wireState;
			t = stoi(wireTime);
			s = stoi(wireState);

			for (int i = 1; i < vecWires.size(); i++) {

				if (wireName == vecWires.at(i)->GetName()) {
					wireNum = vecWires.at(i)->GetIndex();
					Event newEvent(vecWires.at(i), t, s, ++eventCnt);
					q.push(newEvent);
				}
			}
		}
	}

	/*
	while (!vectorFile.eof()) { // parsing vector file
		getline(vectorFile, currLine);
		stringstream ss(currLine);
		ss >> firstWord;
		if ((firstWord == "INPUT") || (firstWord == "OUTPUT")) {
			ss >> wireName;
			ss >> wireTime;
			ss >> wireState;
			t = stoi(wireTime);
			s = stoi(wireState);

			vecTimes.push_back(t);				// vector of times for loops below
			vecStates.push_back(s);				// vector of states for loops below
			vecNames.push_back(wireName);		// vector of names for loops below
		}

		if (vectorFile.eof()) {
			currLine = "";
			getline(vectorFile, currLine);

			for (int i = 0; i < vecWires.size(); i++) {					// iterate through each wire

				if (vecWires.at(i) != nullptr) {						// first wire is null

					for (int c = 0; c < vecNames.size(); c++) {			// iterate through wire names in _v.txt file
						// for each wire
						currName = vecNames.at(c);

						if (currName == vecWires.at(i)->GetName()) {	// if the _v.txt wire name is equal to the
							// current wire name at i
							vecWires.at(i)->setHistory(vecStates.at(c), vecTimes.at(c)); // set history accordingly
						}
					}
				}
			}
		}
	}
	*/
	circuitFile.close();
	vectorFile.close();
	cout << "file closed" << endl;
	

	return 0;
}