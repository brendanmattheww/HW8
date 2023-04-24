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

	//For print
	int maxTime = 0;
	int eventCnt = 0;

	ifstream circuitFile;
	ifstream vectorFile;
	cout << "Enter circuit number" << endl;
	cin >> fileName;
	
	vfileName = fileName;
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
		if (currLine == "") {
			break;
		}
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

	while (!vectorFile.eof()) {  // creates initial events from vector file
		getline(vectorFile, currLine);
		if (currLine == "") {
			break;
		}
		stringstream ss(currLine);
		ss >> firstWord;

		if (firstWord == "INPUT") {
			ss >> wireName;
			ss >> wireTime;
			ss >> wireState;
			t = stoi(wireTime);
			s = stoi(wireState);

			for (int i = 1; i < vecWires.size(); i++) {
				if (vecWires.at(i) != nullptr) {
					if (wireName == vecWires.at(i)->GetName()) {
						wireNum = vecWires.at(i)->GetIndex();
						Event newEvent(vecWires.at(i), t, s, ++eventCnt);
						q.push(newEvent);
					}
				}
			}
		}
	}  
	
	while(!q.empty() && t <= 60) {				//goes through the queue until there are no more events
		Event currEvent = q.top();				// gets top event
		int currState  = currEvent.getState();	//setting some variables for easier to read code later on 
		int currTime   = currEvent.getTime();
		Wire* currWire = currEvent.getWire();
		currWire->SetValue(currState);              // sets value of the wire
		currWire->setHistory(currState, currTime);	// adds to history

		//for (int i = 0; i < currWire->GetGates().size(); i++) { // need to implement for wires driving multiple gates
		if (currWire->GetGates().size() != 0) {
			Gate* gateDriven = currWire->GetGates().at(0);
			int newTime = currTime + gateDriven->getDelay();
			maxTime = newTime;
			int newOutVal = gateDriven->Evaluate(newTime);
			if (gateDriven->getOutput()->GetValue() != newOutVal) {		// if the output wire of the gate does not have the same value as the new output value
				q.push(Event(gateDriven->getOutput(), newTime, newOutVal, ++eventCnt)); //push a new event into the queue
			}
		}																

		//}
		q.pop();
	}
	
		printResults(vecWires, maxTime);

	

	circuitFile.close();
	vectorFile.close();
	
	

	return 0;
}