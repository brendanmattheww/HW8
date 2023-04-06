#pragma once
using namespace std;
#include <string>
#include <vector>
class Gate;

class Wire {
public:
	Wire(int v, vector<int> h);
	void SetValue(int v);
	void setHistory(int v, vector<int> h);
	void addGate(Gate* i);

	int GetValue() const		   { return value;   }
	string GetName() const		   { return name;    }
	vector<Gate*> GetGate() const  { return drives;  }
	int GetIndex() const		   { return index;   }
	vector<int> GetHistory() const { return history; }

	void printHistory() const;

private:
	int value;				// 1 = high;  0 = low;  -1 = unknown
	string name;			// ABC
	vector<Gate*> drives;	// gate
	int index;				// wire number
	vector<int> history;  // history of values (--__xx)

};