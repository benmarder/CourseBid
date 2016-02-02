#include "Terminal.h"

Terminal::Terminal() {}
Terminal::~Terminal() {}
Terminal::Terminal(string idVal, bool lockedVal) :id(idVal), locked(lockedVal) {}
string Terminal::getId() {
	return id;
}
void Terminal::setId(string val) {
	id = val;
}

bool Terminal::isLocked() {
	return locked;
}

void Terminal::setLocked(bool val) {
	locked = val;
}

