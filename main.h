#pragma once
//#include "main.cpp"

string circDesc; // could be different
string vecDesc;  // data types
string queue;    // 


bool readCircDesc(string cd, string gates, Wire* w) { 
	return false;
}

/*bool readVecDesc(string vd, Wire* w, string q) {

}

int simulate(string gates, Wire* w, string q) {

}
*/

void printResults(vector<Wire*> allWires, int max) {
	int num = allWires.size();
	for (int i = 1; i < num; i++) {
		if (allWires.at(i) != nullptr) {
			if (allWires.at(i)->GetName() != "") {
				vector<int> histVec = allWires.at(i)->GetHistory();
				cout << allWires.at(i)->GetName() << ": ";
				for (int j = 0; j < histVec.size(); j++) {
					if (histVec.at(j) == -1) {
						cout << "x";
					}
					else if (histVec.at(j) == 1) {
						cout << "-";
					}
					else {
						cout << "_";
					}
				}
				if (histVec.size() < max) {
					for (int i = histVec.size(); i <= max; i++) {
						if (histVec.back() == -1) {
							cout << "x";
						}
						else if (histVec.back() == 1) {
							cout << "-";
						}
						else {
							cout << "_";
						}
					}
				}
				cout << endl;
			}
		}
	}
	cout << "   ";
	for (int i = 0; i <= max; i++) {
		
		if (i % 5 == 0) {
			cout << i;
		}
		else {
			cout << "-";
		}
	}
	cout << endl;
}









