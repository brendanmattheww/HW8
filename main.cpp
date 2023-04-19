#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <queue>

#include "Event.h"
#include "Gate.h"
#include "Wire.h"
#include "main.h"

using namespace std;

int main(){
	ofstream file;
	file.open();
	
	//readCircuitDesc(circDesc, gates, wires);    Shomper showed this in his main.cpp file
	//readVectorDesc(vecDesc, wires, q);			in class
	//simulate(gates, wires, q);
	//printResults(wires, maxtime);
	
	bool MainFunctions::readCircDesc(string cd, string gates, Wire * w) {

	}

	bool MainFunctions::readVecDesc(string vd, Wire * w, string q) {

	}

	int MainFunctions::simulate(string gates, Wire * w, string q) {

	}

	void MainFunctions::printResults(Wire * w, int max) {

	}
	
	return 0;
}