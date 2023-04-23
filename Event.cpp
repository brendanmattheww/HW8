#include "Event.h"
Event::Event(Wire* w, int t, int s, int cnt) {
	time = t;
	count = cnt;
	state = s;
	eWire = w;
}
// stop if(!q.empty && time <= 60)

bool operator<(const Event& lhs, const Event& rhs) {	// sets up priority queue with 2 keys
	if (lhs.time == rhs.time) {
		return lhs.count > rhs.count;
	}
	return lhs.time > rhs.time;
 }

Wire* Event::getWire() const {
	return eWire;
}

int Event::getState() const {
	return state;
}

int Event::getTime() const {
	return time;
}