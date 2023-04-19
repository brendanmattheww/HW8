#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <queue>

#include "Event.h"
#include "Gate.h"
#include "Wire.h"

using namespace std;

int main(){
	string fileName = "";
	ofstream circuitFile;
	
	circuitFile.open(fileName);
	
	if (!circuitFile) {
		cerr << "File did not open" << endl;
	}

	while(!circuitFile.eof()) {
		getline(cin, )
	}
	


	//readCircuitDesc(circDesc, gates, wires);    Shomper showed this in his main.cpp file
	//readVectorDesc(vecDesc, wires, q);			in class
	//simulate(gates, wires, q);
	//printResults(wires, maxtime);
	
	
	return 0;
}