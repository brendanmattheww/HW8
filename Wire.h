#pragma once
using namespace std;
#include <string>
#include <vector>
class Gate;

class Wire {
public:
	Wire();
	Wire(int v, string n, int ind);
	void SetValue(int v);
	void setHistory(int v, int time);
	void setName(string s);
	void setIndex(int i);
	void addGate(Gate* i);

	int GetValue() const;           //{ return value;   }
	string GetName() const;         //{ return name;    }
	vector<Gate*> GetGates() const;  //{ return drives; }
	int GetIndex() const;           //{ return index;   }
	vector<int> GetHistory() const; //{ return history; }

	void printHistory() const;

private:
	int value;				// 1 = high;  0 = low;  -1 = unknown
	string name;			// ABC
	vector<Gate*> drives;	// gate
	int index;				// wire number
	vector<int> history;    // history of values (--__xx)

};