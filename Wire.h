#pragma once
using namespace std;
#include <string>
#include <vector>
class Gate;

class Wire {
public:
	Wire(int v, string h);
	int SetValue(int v);
	string setHistory(string h);
	Gate* setDrives()
private:
	int value;
	string name;
	vector<Gate*> drives;
	int index;		 //wire number
	string history;
};