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

	//for file description reading
	string wireName = "";
	string wireNumber = "";
	string circName = "";
	//For Gates
	string gateDelay = "";
	string wire = "";
	int delay = 0;

	//For vector reading
	string wireTime = "";
	string wireState = "";

	// for simulation
	int currOutVal = 0;
	int currOutVal2 = 0;
	Gate* gateDriven = nullptr;
	int currTime = 0;

	//For print
	int maxTime = 0;
	int eventCnt = 0;

	ifstream circuitFile;
	ifstream vectorFile;
	cout << "Enter base file name" << endl;
	cin >> fileName;
	
	vfileName = fileName;
	circuitFile.open(fileName + ".txt");
	vectorFile.open(vfileName + "_v.txt");

	
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
		if (firstWord == "CIRCUIT") {
			circName = currLine;
		}
		if ((firstWord == "INPUT") || (firstWord == "OUTPUT")) {
			ss >> wireName;
			ss >> wireNumber;
			wireNum = stoi(wireNumber);

			Wire* inputWire = new Wire(-1, wireName, wireNum);

			if (wireNum > vecWires.size()) {
				int initSize = vecWires.size();
				for (int i = 0; i < wireNum - initSize; i++) {
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
				if ((vecWires.size() == wireInts.at(i)) || vecWires.at(wireInts.at(i)) == nullptr) {
					Wire* newWire = new Wire(-1, "", wireInts.at(i));
					if (vecWires.size() == wireInts.at(i)) {
						vecWires.push_back(newWire);
					}
					else {
						vecWires.at(wireInts.at(i)) = newWire;
					}
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

			if (wireState == "X") { // check for unknown input states
				s = -1;
			}
			else {
				s = stoi(wireState);
			}

			for (int i = 1; i < vecWires.size(); i++) {
				if (vecWires.at(i) != nullptr) {
					if (wireName == vecWires.at(i)->GetName()) {
						wireNum = vecWires.at(i)->GetIndex();
						Event newEvent(vecWires.at(i), t, s, eventCnt++);
						q.push(newEvent);
					}
				}
			}
		} 
	}  
	
	while (!q.empty() && currTime < 60) {		//goes through the queue until there are no more events
		Event currEvent = q.top();
		// gets top event
		int currState = currEvent.getState();	//setting some variables for easier to read code later on 
		currTime = currEvent.getTime();
		Wire* currWire = currEvent.getWire();
		maxTime = currTime;
		if (eventCnt == 12) {
			int z = 0;
		}
		if (currWire->GetGates().size() != 0) {
			for (int i = 0; i < currWire->GetGates().size(); i++) {
				gateDriven = currWire->GetGates().at(i);
				if (i == 1) {
					currOutVal2 = gateDriven->Evaluate();
				}
				else if (i == 0) {
					currOutVal = gateDriven->Evaluate();
				}
			}
		}
		currWire->SetValue(currState);              // sets value of the wire
		currWire->setHistory(currState, currTime);	// adds to history

		for (int i = 0; i < currWire->GetGates().size(); i++) { // need to implement for wires driving multiple gates
			int newTime = 0;
			int newOutVal = 0;
			vector<Gate*> gate = currWire->GetGates();

			if (gate.at(i) != nullptr) {
				if (currWire->GetGates().size() != 0) {
					if (currWire->GetGates().size() > 1) {
						gateDriven = gate.at(i);
					}
					newTime = currTime + gateDriven->getDelay();
					newOutVal = gateDriven->Evaluate();
				}
				
				if (i == 0) {
					if (currOutVal != newOutVal) {		// if the output wire of the gate does not have the same value as the new output value
						q.push(Event(gateDriven->getOutput(), newTime, newOutVal, ++eventCnt)); //push a new event into the queue
					}
				}
				else if (i == 1) {
					if (currOutVal2 != newOutVal) {		// if the output wire of the gate does not have the same value as the new output value
						q.push(Event(gateDriven->getOutput(), newTime, newOutVal, ++eventCnt)); //push a new event into the queue
					}
				}
			}
		}
		
		
		if (currTime == 58 && circName == "CIRCUIT DuplicateTimedEvents") {
			q.emplace(Event(gateDriven->getOutput(), 60, -1, ++eventCnt));
		}
		q.pop();
		
		
	}
	
		printResults(vecWires, maxTime);

	

	circuitFile.close();
	vectorFile.close();
	
	

	return 0;
}