#pragma once

using namespace std;

class Event { // work in progress
public:
	void readCircDesc(string cd, string gates, Wire* w);
	void readVecDesc();
	void simulate();
	void printResults();
private:
	string circDesc; // 
	string vecDesc;	 // 
	string q;        // 
};