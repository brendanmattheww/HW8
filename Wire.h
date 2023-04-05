#pragma once
using namespace std;
#include <string>
#include <vector>
class Gate;

class Wire {
public:
	Wire(int v, string h);
	void SetValue(int v);
	void setHistory(string h);
	void addGate(Gate* i);

	int GetValue() const		   { return value;   }
	string GetName() const		   { return name;    }
	vector<Gate*> GetGate() const  { return drives;  }
	int GetIndex() const		   { return index;   }
	string GetHistory() const	   { return history; }

	void printHistory() const;

private:
	int value;			  // // 1 = high;  0 = low;  -1 = unknown
	string name;		  // ABC
	vector<Gate*> drives; // gate
	int index;			  // wire number
	string history;		  // history of values (--__xx)

};