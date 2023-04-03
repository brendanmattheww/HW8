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
	vector<Gate*> setDrives(vector<Gate*> d);

	int GetValue() const		   { return value;   }
	string GetName() const		   { return name;    }
	vector<Gate*> GetGate() const  { return drives;  }
	int GetIndex() const		   { return index;   }
	string GetHistory() const	   { return history; }

	void printHistory() const;

private:
	int value; 
	string name;
	vector<Gate*> drives;
	int index;		 //wire number
	string history;

};