#include "Event.h"
Event::Event(Wire* outWire, int t, int state, int cnt) {
	time = t;
	count = cnt;
	oVal = outWire->GetValue();
	wireNum = outWire->GetIndex();
}
// stop if(!q.empty && time <= 60)

bool operator<(const Event& lhs, const Event& rhs) {	// sets up priority queue with 2 keys
	if (lhs.time == rhs.time) {
		return lhs.count > rhs.count;
	}
	return lhs.time > rhs.time;
 }

