#pragma once
//#include "main.cpp"

string circDesc; // could be different
string vecDesc;  // data types
string queue;    // 


/*bool readCircDesc(string cd, string gates, Wire* w) { doesn't compile

}

bool readVecDesc(string vd, Wire* w, string q) {

}

int simulate(string gates, Wire* w, string q) {

}

void printResults(Wire* w, int max) {

}
*/

//circuitFile.open("circuit" + vfileName + ".txt");  // now you only have to type the number in

/*if (!vectorFile) {
	cerr << "File did not open" << endl;
}
else {
	cout << "file opened" << endl;
}
while (!vectorFile.eof()) {)*/




/*
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
					Event newEvent(vecWires.at(i), t, s, eventCnt);
					q.push(newEvent);
					eventCnt++;
				}
			}

		}
	}
*/